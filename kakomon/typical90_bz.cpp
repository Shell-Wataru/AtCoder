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

int main()
{
    ll N,M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ll ans = 0;
    for(int i  = 0;i < N;i++){
        sort(G[i].begin(),G[i].end());
        if ((G[i].size() == 1 && G[i][0] < i) || (G[i].size() >= 1 && G[i][0] < i && G[i][1] >= i)){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}