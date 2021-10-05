#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

ll MAX_N = 1000000;
vector<ll> max_counts(MAX_N, 0);

string solve()
{
    ll N;
    cin >> N;
    ll ans = 1;
    // cout << N << endl;
    for (int i = 3; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            ll a = i;
            ll b = N / i;
            ans = max(ans, max_counts[(N - a) / a] + 1);
            ans = max(ans, max_counts[(N - b) / b] + 1);
            // cout << i << endl;
            // cout << (i - a) / a << endl;
            // cout << (i - b) / b << endl;
        }
    }
    return to_string(ans);
}
int main()
{
    // 整数の入力
    for (int i = 2; i <= MAX_N; i++)
    {
        max_counts[i] = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                ll a = j;
                ll b = i / j;
                max_counts[i] = max(max_counts[i], max_counts[(i - a) / a] + 1);
                max_counts[i] = max(max_counts[i], max_counts[(i - b) / b] + 1);
            }
        }
        // cout << i << ":" << max_counts[i] << endl;
    }
    ll T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}