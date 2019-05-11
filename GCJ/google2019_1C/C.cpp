#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

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

ll patterns(ll N,ll K,vector<ll> cs,vector<ll> ds){
    RMQ c_query(N);
    RMQ d_query(N);
    for (int i = 0;i < N;i++){
        // cout << cs[i] << ds[i] << endl;
        c_query.update(i,-cs[i]);
        d_query.update(i,-ds[i]);
    }

    ll total = 0;

    for (int i = 0;i < N;i++){

        for (int j = i;j < N;j++){
            ll cmin = c_query.query(i,j+1);
            ll dmin = d_query.query(i,j+1);
            // cout << cmin << " " << dmin << endl;
            if (abs(cmin - dmin) <= K){
                total++;
            }
        }
    }
    return total;
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll N, K,ci,di;
        cin >> N >> K;
        vector<ll> cs;
        vector<ll> ds;
        for (int j = 0; j < N; j++)
        {
            cin >> ci;
            cs.push_back(ci);
        };
        for (int j = 0; j < N; j++)
        {
            cin >>  di;
            ds.push_back(di);
        };

        ll p = patterns(N,K,cs,ds);
        cout << "Case #" << i << ": " <<  p << endl;
    }

    return 0;
}