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
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

pair<ll,ll> dfs(vector<vector<ll>> &G,ll current, ll parent){
    pair<ll,ll> ret = {0,current};
    for(auto to:G[current]){
        if (to != parent){
            auto p = dfs(G,to,current);
            p.first++;
            ret = max(ret,p);
        }
    }
    return ret;
}
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    for(int i = 0;i < N-1;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    auto p1 = dfs(G,0,-1);
    auto p2 = dfs(G,p1.second,-1);
    // cout << p2.first << endl;
    if ((p2.first-1) % 3 == 0){
        cout << "Second" << endl;
    }else{
        cout << "First" << endl;
    }
   return 0;
}