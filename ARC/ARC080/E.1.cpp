#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>

using namespace std;
class RMQ{
    static const int INT_MAX = 2147483647;
    int MAX_N;
    int highestOneBit(int i) {
        i |= (i >>  1);
        i |= (i >>  2);
        i |= (i >>  4);
        i |= (i >>  8);
        i |= (i >> 16);
        return i - (i >> 1);
    }
    public:
        int *dat;
        int *datIndexes;

        RMQ(int size = 100000){
            int HOB = highestOneBit(size);
            if (HOB != size){
                MAX_N = HOB<<1;
            }else{
                MAX_N = HOB;
            }
            dat = new int[MAX_N*2];
            datIndexes = new int[MAX_N*2];
            for (int i =1;i< MAX_N*2;i++){
                dat[i] = INT_MAX;
                datIndexes[i] = -1;
            }
        }

        void update(int index,int x){
            for (int i= index+MAX_N; i>0; i>>=1) {
            //iが対応するインデックス
                if (i >= MAX_N){
                    dat[i] = x;
                    datIndexes[i] = i-MAX_N;
                }else{
                    if (dat[i*2] <= dat[i*2+1]){
                        dat[i] = dat[i*2];
                        datIndexes[i] = datIndexes[i*2];
                    }else{
                        dat[i] = dat[i*2+1];
                        datIndexes[i] = datIndexes[i*2+1];
                    }
                }
            }
        }

        int query(int L,int R){
            L += MAX_N;
            R += MAX_N;
            int minValue = INT_MAX;
            for (;L<R; L>>=1, R>>=1) {
                if(R&1) {
                    --R;
                    if (dat[R] < minValue){
                        minValue = dat[R];
                    }
                } //--Rが対応するインデックス
                if(L&1){
                    if (dat[L] < minValue){
                        minValue = dat[L];
                    }
                    L++;
                }//L++が対応するインデックス
            }
            return minValue;
        }

        pair<int,int> queryWithIndex(int L,int R){
            L += MAX_N;
            R += MAX_N;
            int minValue = INT_MAX;
            int minIndex = -1;
            for (;L<R; L>>=1, R>>=1) {
                if(R&1) {
                    --R;
                    if (dat[R] < minValue){
                        minValue = dat[R];
                        minIndex = datIndexes[R];
                    }
                } //--Rが対応するインデックス
                if(L&1){
                    if (dat[L] < minValue){
                        minValue = dat[L];
                        minIndex = datIndexes[L];
                    }
                    L++;
                }//L++が対応するインデックス
            }
            return make_pair(minValue,minIndex);
        }
};

int main()
{
    int N,temp;
    vector<int> answer;

    cin >> N;
    RMQ RMQOdd(N/2);
    RMQ RMQEven(N/2);
    for (int i = 0;i<N;i++){
        cin >> temp;
        if(i %2 == 0){
            RMQEven.update(i/2,temp);
        }else{
            RMQOdd.update(i/2,temp);
        }
    }

    auto c = [&](pair<int,int> l,pair<int,int> r){
        int lvalue = l.first % 2 == 0 ? RMQEven.query(l.first/2,l.second/2):RMQOdd.query(l.first/2,l.second/2);
        int rvalue = r.first % 2 == 0 ? RMQEven.query(r.first/2,r.second/2):RMQOdd.query(r.first/2,r.second/2);
        return lvalue > rvalue;
    };

    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(c)> pq(c);
    pq.push(make_pair(0,N));
    while(pq.size()!=0){
        pair<int,int> p = pq.top();
        pq.pop();
        if (p.first % 2 == 0){
            pair<int,int> p0 = RMQEven.queryWithIndex(p.first/2,p.second/2);
            pair<int,int> p1 = RMQOdd.queryWithIndex(p0.second,p.second/2);
            if (p.first != 2 * p0.second){
                pq.push(make_pair(p.first,2 * p0.second));
            }
            if (p0.second != p1.second){
                pq.push(make_pair(2 * p0.second + 1,2 * p1.second + 1));
            }

            if (2 * p1.second + 2 != p.second){
                pq.push(make_pair(2 * p1.second + 2,p.second));
            }
            answer.push_back(p0.first);
            answer.push_back(p1.first);

        }else{
            pair<int,int> p0 = RMQOdd.queryWithIndex(p.first/2,p.second/2);
            pair<int,int> p1 = RMQEven.queryWithIndex(p0.second + 1,p.second/2+1);

            if (p.first != 2 * p0.second + 1){
                pq.push(make_pair(p.first,2 * p0.second + 1));
            }
            if (p0.second + 1!= p1.second){
                pq.push(make_pair(2 * p0.second + 2,2 * p1.second));
            }

            if (2 * p1.second + 1 != p.second){
                pq.push(make_pair(2 * p1.second + 1,p.second));
            }

            answer.push_back(p0.first);
            answer.push_back(p1.first);
        }

    }

    for (int i=0;i<N;i++){
        if (i== N -1){
            cout << answer[i] << endl;
        }else{
            cout << answer[i] << " ";
        }
    }
    return 0;
}