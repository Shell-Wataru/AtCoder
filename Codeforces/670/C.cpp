#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int dfs(vector<vector<ll>> &G, ll current ,ll parent, vector<ll> &max_sub_segments){
    ll children_nodes = 0;
    ll max_sub = 0;
    for(auto to: G[current]){
        if (to != parent){
            ll segments = dfs(G,to,current,max_sub_segments);
            children_nodes += segments;
            max_sub = max(max_sub,segments);
        }
    }
    max_sub = max(max_sub, (ll)G.size() - (children_nodes+1));
    max_sub_segments[current] = max_sub;
    return children_nodes+1;
}
int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<vector<ll>> G(n) ;
    for (size_t i = 0; i < n-1; i++)
    {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<ll> max_sub_segments(n,0);
    dfs(G,0,-1,max_sub_segments);
    ll min_sub = numeric_limits<ll>::max();
    vector<ll> min_sub_segments_indexes;
    for(int i = 0;i < n;i++){
        if (max_sub_segments[i] < min_sub){
            min_sub_segments_indexes.clear();

            min_sub = max_sub_segments[i];
            min_sub_segments_indexes.push_back(i);
        }else if (max_sub_segments[i] == min_sub){
            min_sub_segments_indexes.push_back(i);
        }
    }

    if (min_sub_segments_indexes.size() == 1){
        cout << 1 << " " << G[0][0]+1 << endl;
        cout << 1 << " " << G[0][0]+1 << endl;
    }else{
        ll a = min_sub_segments_indexes[0];
        ll b = min_sub_segments_indexes[1];
        ll next_a;
        if (G[a][0] != b){
            next_a = G[a][0];
        }else{
            next_a = G[a][1];
        }
        cout << a + 1 << " " << next_a + 1 << endl;
        cout << b + 1 << " " << next_a + 1<< endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
        }
    // cout << flush;
    return 0;
}
