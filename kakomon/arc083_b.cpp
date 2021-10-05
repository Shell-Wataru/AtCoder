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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

bool is_valid(int n, vector<vector<ll>> &G)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (G[i][j] > G[i][k] + G[k][j]){
                    return false;
                }
            }
        }
    }
    return true;
}

int restore(int n, vector<vector<ll>> &G)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (G[i][j] == -1 || G[i][k] == -1 || G[k][j] == -1 || i == j || j == k || k == i){
                    continue;
                }
                if (G[i][j] == G[i][k] + G[k][j]){
                    // cout << i << "," << j << ":" << k << endl;
                    G[i][j] = -1;;
                }
            }
        }
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> G(N,vector<ll>(N,0));
    for(int i = 0;i < N;i++){
        for (int j = 0; j < N; j++)
        {
            scanf("%lld",&G[i][j]);
        }
    }
    if (!is_valid(N,G)){
        cout << -1 << endl;
    }else{
        ll ans = 0;
        restore(N,G);
        for(int i = 0;i < N;i++){
            for (int j = i+1; j < N; j++)
            {
                // cout << G[i][j] << ",";
                if (G[i][j] != -1){
                    ans += G[i][j];
                }
            }
            // cout << endl;
        }
        cout << ans << endl;
    }
   return 0;
}