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

void warshall_floyd(int n, vector<vector<ll>> &d)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main()
{
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> G(10,vector<ll>(10,0));
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            cin >> G[i][j];
        }
    }
    warshall_floyd(10,G);
    ll ans = 0;
    for(int i = 0;i < H;i++){
        for(int j = 0;j < W;j++){
            ll a;
            cin >> a;
            if (a != -1){
                ans += G[a][1];
            }
        }
    }
    cout << ans << endl;
   return 0;
}