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
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

ll dfs(vector<vector<ll>> &G,ll current){
    ll min_v = numeric_limits<ll>::max();
    ll max_v = numeric_limits<ll>::min();
    for(auto to:G[current]){
        ll v = dfs(G,to);
        min_v = min(min_v,v);
        max_v = max(max_v,v);
    }
    if (min_v == numeric_limits<ll>::max()){
        return 1;
    }else{
        return min_v + max_v + 1;
    }
}
int main()
{
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    for (size_t i = 0; i < N-1; i++)
    {
        ll a;
        cin >> a;
        a--;
        G[a].push_back(i+1);
    }
    cout << dfs(G,0) << endl;
  return 0;
}
