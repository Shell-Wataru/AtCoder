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

int solve()
{
    ll n;
    ll m;
    ll x;
    scanf("%lld", &n);
    scanf("%lld", &m);
    scanf("%lld", &x);
    vector<pair<ll,ll>> h(n);
    vector<ll> y(n);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > q;
    for(int i = 0;i < n;i++){
        scanf("%lld",&h[i].first);
        h[i].second = i;
    }
    sort(h.rbegin(),h.rend());
    for(ll i = 0;i < m;i++){
        q.push({h[i].first,i});
        y[h[i].second] = i;
    }
    for(int i = m;i < n;i++){
        auto current = q.top();
        q.pop();
        q.push({current.first + h[i].first,current.second});
        y[h[i].second] = current.second;
    }
    ll smallest = q.top().first;
    q.pop();
    while(!q.empty()){
        if (q.top().first - smallest > x){
            cout << "NO\n" ;
            return 0;
        }
        smallest = q.top().first;
        q.pop();
    }
    cout << "YES\n";
    for(int i = 0;i < n;i++){
        if (i!= 0){
            cout << " ";
        }
        cout << y[i] + 1;
    }
    cout << "\n";
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
