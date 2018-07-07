#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>

using namespace std;
using ll = long long;

class BinarySegmentTree{
    int highestOneBit(int i) {
        i |= (i >>  1);
        i |= (i >>  2);
        i |= (i >>  4);
        i |= (i >>  8);
        i |= (i >> 16);
        return i - (i >> 1);
    }

    public:
        bool *part;
        int MAX_N;

        BinarySegmentTree(int size = 100000){
            int HOB = highestOneBit(size);
            if (HOB != size){
                MAX_N = HOB<<1;
            }else{
                MAX_N = HOB;
            }
            part = new bool[MAX_N*2];
            for (int i =1;i< MAX_N*2;i++){
                part[i] = false;
            }
        }

        void add(int a, int b,bool x,int index,int l,int r){
            if (a<= l && r <= b){
                part[index] = x;
            }else if (l < b && a < r){
                add(a,b,x,index *2,l,(l+r)/2);
                add(a,b,x,index *2 + 1,(l+r)/2,r);
                part[index] = query(l,r,1,0,MAX_N);
            }
        }

        bool query(int a, int b,int index,int l,int r){
            if (b<= l || r<= a){
                return true;
            }else if(l <= a && b<= r && part[index]){
                return true;
            }else if(a <= l && r<= b){
                return part[index];
            }else{
                return query(a,b,index*2,l,(l+r)/2) && query(a,b,index*2+1,(l+r)/2,r);
            }
        }
};

int main()
{
    // 整数の入力
    ll N,start,end,i;
    string input;
    BinarySegmentTree BTree(24*60+1);
    deque<ll> rainStartEnd;

    cin >> N;
    for (i = 0;i< N ;i++){
        cin >> input;
        start = (stoi(input.substr(0,2)) * 60 + stoi(input.substr(2,2)));
        end = (stoi(input.substr(5,2)) * 60 + stoi(input.substr(7,2)));
        BTree.add(start,end+1,true,1,0,BTree.MAX_N);
    }

    start = -1;
    for (i = 0;i<24*60+1;i++){
        if (start == -1 && BTree.query(i,i+1,1,0,BTree.MAX_N)){
            if (!rainStartEnd.empty() && i/60 * 100 + (i%60)/5*5 <= rainStartEnd.back()){
                rainStartEnd.pop_back();
                start =rainStartEnd.back();
            }else{
                rainStartEnd.push_back(i/60 * 100 + (i%60)/5*5);
                start = i;
            }
        }else if (start != -1 && !BTree.query(i,i+1,1,0,BTree.MAX_N)){
            ll hour = (i-1)/60 + (((((i-1)%60)/5 + !((i-1)%5==0))*5) == 60 );
            ll minute = ((((i-1)%60)/5 + !((i-1)%5==0))*5)%60;
            rainStartEnd.push_back(hour * 100 + minute);
            start = -1;
        }
    }

    if (start != -1){
        rainStartEnd.push_back(2400);
    }

    for (i=0;i<rainStartEnd.size();i++){
        if(i%2==0){
            cout << setw(4) << setfill('0') << rainStartEnd[i];
        }else{
            cout << "-" << setw(4) << setfill('0') << rainStartEnd[i] << endl;
        }
    }

    return 0;
}