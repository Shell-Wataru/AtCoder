#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

int solve()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>> G;
    ll pair_value;
    if (n % 2 == 1){
        pair_value = n;
    }else{
        pair_value = n + 1;
    }
    for(int i = 1; i <= n;i++){
        for(int j = i+1;j <= n;j++){
            if (i+j == pair_value || i == j){
                continue;
            }else{
                G.push_back({i,j});
            }
        }
    }
    cout << G.size() << endl;
    for(int i = 0;i < G.size();i++){
        cout << G[i].first <<  " " << G[i].second << endl;
    }
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
