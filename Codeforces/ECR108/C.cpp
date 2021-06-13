#define _USE_MATH_DEFINES
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

void add(vector<ll> &s, vector<ll> &answer)
{
    ll n = s.size();
    vector<ll> ruisekiwa(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        ruisekiwa[i + 1] = ruisekiwa[i] + s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        // cout <<  n - n % i << ruisekiwa[n - n % i] << endl;
        answer[i] += ruisekiwa[n - n % i];
    }
}
int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> u(n);
    vector<vector<ll>> us(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &u[i]);
        u[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        ll s;
        scanf("%lld", &s);
        us[u[i]].push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        sort(us[i].rbegin(), us[i].rend());
    }

    vector<ll> answer(n+1, 0);

    for (int i = 0; i < n; i++)
    {
        // for(auto s:us[i]){
        //     cout << s << ",";
        // }
        // cout << endl;
        add(us[i], answer);
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != 0)
        {
            cout << " ";
        }
        cout << answer[i];
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
    cout << flush;
    return 0;
}
