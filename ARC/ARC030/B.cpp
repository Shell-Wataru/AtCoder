#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

bool dfs(vector<vector<ll>> &G, vector<ll> &H, ll from, ll parent, deque<ll> &q)
{

    bool has_star = H[from] == 1;
    bool children_has_star = false;
    for (auto to : G[from])
    {
        if (to != parent)
        {
            children_has_star = dfs(G, H, to, from, q) || children_has_star;
        }
    }
    if (has_star || children_has_star)
    {
        q.push_front(from);
        q.push_back(from);
    }
    // cout << from << ":" << has_star << children_has_star << endl;
    return has_star || children_has_star;
}
int main()
{
    // 整数の入力
    ll n, x;
    cin >> n >> x;
    x--;
    vector<vector<ll>> G(n);
    vector<ll> H(n);
    for (int i = 0; i < n; i++)
    {
        cin >> H[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    deque<ll> q;
    dfs(G, H, x, -1, q);
    // for(auto i:q){
    //     cout << i;
    // }
    // cout << endl;
    if (q.size() == 0){
        cout << q.size() << endl;
    }else{
        cout << q.size() - 2 << endl;
    }

    return 0;
}