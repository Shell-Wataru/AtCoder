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

int solve()
{

    ll n,m;
    cin >> n >> m;
    vector<pair<ll,ll>> edges(m);
    for(int i = 0;i < m;i++){
        cin >> edges[i].second >> edges[i].first;
    }
    sort(edges.begin(),edges.end());
    ll ans = 0;
    for(int i = 0;i < m;i++){
        ll new_n = gcd(n,edges[i].second);
        ans += (n - new_n)* edges[i].first;
        n = new_n;
    }
    if (n != 1){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}

int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}