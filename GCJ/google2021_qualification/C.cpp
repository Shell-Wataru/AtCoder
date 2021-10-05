#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;

ll maximum(ll N)
{
    return (N - 1) * (N + 2) / 2;
}
string solve()
{
    ll N, C;
    cin >> N;
    cin >> C;
    ll minimum_cost = N - 1;
    ll maximum_cost = maximum(N);
    vector<ll> ans(N);
    iota(ans.begin(), ans.end(), 1);
    if (minimum_cost <= C && C <= maximum_cost)
    {
        vector<ll> changes;
        for (int i = 0; i < N - 1; i++)
        {
            ll change = max(C - maximum(N - 1 - i),1ll);
            C -= change;
            changes.push_back(change);
        }
        // reverse(changes.begin(),changes.end());
        for (int i = N - 2; i >= 0; i--)
        {
            reverse(ans.begin() + i, ans.begin() + i + changes[i]);
        }
        string ans_string = "";
        for (int i = 0; i < N; i++)
        {
            if (i != 0)
            {
                ans_string += ' ';
            }
            ans_string += to_string(ans[i]);
        }
        return ans_string;
    }
    else
    {
        return "IMPOSSIBLE";
    }
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}