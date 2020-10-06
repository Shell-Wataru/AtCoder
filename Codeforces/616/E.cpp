#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int main()
{
    ll N;
    cin >> N;
    map<pair<ll, ll>, ll> edges;
    vector<set<ll>> G(N);
    vector<ll> Nodes(N, 1);
    for (int i = 0; i < N-1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].insert(v);
        G[v].insert(u);
    }

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            if (G[i].size() == 1)
            {
                int j = *G[i].begin();
                edges[{min(i, j), max(i, j)}] = Nodes[i] * (N - Nodes[i]);
                Nodes[j] += Nodes[i];
                G[i].erase(j);
                G[j].erase(i);
            }
        }
    }
    cout << edges.size() << endl;
    vector<pair<ll,pair<ll,ll>>> weights;
    ll sum = 0;
    for(auto p: edges){
        weights.push_back({p.second,p.first});
    }
    sort(weights.begin(),weights.end());
    return 0;
}