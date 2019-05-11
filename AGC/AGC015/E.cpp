#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
typedef long long ll;

class XV            //クラス宣言
{
public:
    ll x;
    ll v;
};


int main()
{
    // 整数の入力
    long long N,M,Q,i,j;
    cin >> N;
    vector<XV> Data;

    for (i = 0;i<N ;i++){
        XV tempXV = XV();
        cin >> tempXV.x >> tempXV.v;
        Data.push_back(tempXV);
    }
    sort(Data.begin(),Data.end(),[](XV a,XV b){return a.v < b.v;});
    for (i = 0;i<N ;i++){
        Data[i].v = i;
    }

    sort(Data.begin(),Data.end(),[](XV a,XV b){return a.x < b.x;});
    pair<ll,ll>* LRData = new pair<ll,ll>[N];
    priority_queue<int> queLeft;

    for (i = 0;i<N ;i++){
        cout << Data[i].x << "," << Data[i].v << endl;
        queLeft.push(Data[i].v);
        LRData[i].first = queLeft.top();
    }

    priority_queue<int> queRight;
    for (i = N -1;i>=0 ;i--){
        queRight.push( - Data[i].v);
        LRData[i].second = - queRight.top();
    }
    for (i = 0;i<N ;i++){
        cout << LRData[i].first << "," << LRData[i].second << endl;
    }

    return 0;
}