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

struct group
{
    ll k, total, i;
    vector<ll> students;
};
int solve()
{

    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
    }
    vector<group> b(m);
    for (int i = 0; i < m; i++)
    {
        scanf("%lld", &b[i].k);
        b[i].students = vector<ll>(b[i].k);
        b[i].i = i;
        b[i].total = 0;
        for (int j = 0; j < b[i].k; j++)
        {
            scanf("%lld", &b[i].students[j]);
            b[i].total += b[i].students[j];
        }
    }
    sort(a.rbegin(), a.rend());
    a.resize(m);
    sort(b.begin(),b.end(),[](group &l,group &r){
        l.total *r.k > r.total *l.k;
    };

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