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
    ll total_hp = 0;;
    cin >> n;
    vector<pair<ll,ll>> Enemies(n);
    for(int i = 0;i < n;i++){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        Enemies[i] = {a,b};
    }
    for(int i = 0;i < n;i++){
        total_hp += max(Enemies[i].first -  Enemies[(i + n - 1) % n].second,0ll);
    }

    // cout << total_hp << endl;
    ll min_bullets = numeric_limits<ll>::max();
    // cout << min_bullets << endl;
    for(int i = 0;i < n;i++){
        ll bomb_hp = max(Enemies[i].first -  Enemies[(i + n - 1) % n].second,0ll);
        min_bullets = min(min_bullets, total_hp + Enemies[i].first - bomb_hp);
    }
    cout << min_bullets << endl;
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
    return 0;
}
