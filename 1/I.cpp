#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;


int main()
{
    // 整数の入力
    ll N,Q;
    cin >> N >> Q;
    vector<vector<ll>> Rows(N,vector<ll>(2,0));
    vector<vector<ll>> Columns(N,vector<ll>(2,0));
    for(int i = 0;i < N;i++){
        Columns[i][0] = i;
        Columns[i][1] = 1;
        Rows[i][0] = 1;
        Rows[i][1] = N*i;
    }
    for(int i = 0;i < Q;i++){
        ll type;
        cin >> type;
        if (type == 1){
            ll a,b;
            cin >> a >> b;
            a--;b--;
            swap(Rows[a],Rows[b]);
        }else if(type == 2){
            ll a,b;
            cin >> a >> b;
            a--;b--;
            swap(Columns[a],Columns[b]);
        }else if (type == 3){
            swap(Columns,Rows);
        }else{
            ll a,b;
            cin >> a >> b;
            a--;b--;
            cout << Rows[a][0]*Columns[b][0] + Rows[a][1]*Columns[b][1] << endl;
        }
    }
    return 0;
}