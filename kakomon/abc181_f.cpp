#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

ll answer(vector<vector<ll>> &G, ll l, ll r){
    if (l+1 == r){
        return l;
    }
    ll center = (r+l)/2;
    ll N = G.size();
    vector<bool> is_top(N,false);
    vector<ll> tops = {0};
    is_top[0] = true;
    bool changed = true;
    while(changed){
        changed = false;
        for(int i = 0;i < N;i++){
            if(!is_top[i]){
                for(auto j:tops){
                    if (G[i][j] < center){
                        tops.push_back(i);
                        is_top[i] = true;
                        changed = true;
                        break;
                    }
                }
                if (changed){
                    break;
                }
            }
        }
    }
    if (!is_top[N-1]){
        return answer(G,center,r);
    }else{
        return answer(G,l,center);
    }
}
int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<pair<ll, ll>> P(n);
    for (int i = 0; i < n; i++)
    {
        cin >> P[i].first >> P[i].second;
    }
    vector<vector<ll>> G(n + 2, vector<ll>(n + 2));
    G[0][n+1] = 200*200;
    G[n+1][0] = 200*200;
    for (int i = 0; i < n; i++)
    {
        G[i + 1][0] = (100 - P[i].second)*(100 - P[i].second);
        G[0][i + 1] = (100 - P[i].second)*(100 - P[i].second);
        G[i + 1][n+1] = (P[i].second + 100)*(P[i].second + 100);
        G[n+1][i + 1] = (P[i].second + 100)*(P[i].second + 100);
        for (int j = 0; j < n; j++)
        {
            G[i + 1][j + 1] = (P[i].first - P[j].first)*(P[i].first - P[j].first) + (P[i].second - P[j].second) * (P[i].second - P[j].second);
            G[j + 1][i + 1] = (P[i].first - P[j].first)*(P[i].first - P[j].first) + (P[i].second - P[j].second) * (P[i].second - P[j].second);
        }
    }
    // cout << answer(G,0,200*200) << endl;
    cout << fixed << setprecision(12) << sqrt(answer(G,0,200*200))/2 << endl;
    return 0;
}

int main()
{
    // cout << "!" << endl;
    // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    cout << flush;
    return 0;
}
