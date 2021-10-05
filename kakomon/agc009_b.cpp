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

int dfs(vector<vector<ll>> &G,ll current){
    ll n = G[current].size();
    if (n == 0){
        return 0;
    }

    vector<ll> min_depthes;
    for(auto to:G[current]){
        min_depthes.push_back(dfs(G,to));
    }
    sort(min_depthes.begin(),min_depthes.end());

    ll max_depth = 0;
    for(int i = 0;i < n;i++){
        max_depth = max(max_depth,min_depthes[n-i-1] + i + 1);
    }
    // cout << current << ":" << max_depth << endl;
    return max_depth;
}
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    for (size_t i = 1; i < N; i++)
    {
        ll a;
        cin >> a;
        a--;
        G[a].push_back(i);
    }
    cout << dfs(G,0) << endl;
   return 0;
}