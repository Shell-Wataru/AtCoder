#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    vector<pair<ll, ll>> Robots(N);
    for (int i = 0; i < N; i++)
    {
        ll x, d;
        cin >> x >> d;
        Robots[i] = {x, d};
    }

    sort(Robots.rbegin(), Robots.rend());
    Robots.push_back({-1000000001, 3000000001});
    vector<ll> lasts(N+1);
    vector<ll> patterns(N+1,1);
    iota(lasts.begin(),lasts.end(),0);
    patterns[0] = 2;
    for(int i = 1;i <= N;i++){
        ll current = lasts[i];
        ll p = 1;
        // cout << Robots[i].first << "," << Robots[i].second << endl;
        while(current > 0 && Robots[i].first + Robots[i].second > Robots[current-1].first){
            p *= patterns[current-1];
            p %= 998244353;
            current = lasts[current-1];
        }
        lasts[i] = current;
        patterns[i] += p;
        // cout << patterns[i] << endl;;
        patterns[i] %= 998244353;
    }
    cout << (998244353 +patterns[N] - 1) % 998244353 << endl;
    return 0;
}

int main()
{
    // cout << "!" << endl;
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
