#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

ll solve()
{
    string S;
    ll N, K;
    cin >> N >> K;
    cin >> S;
    ll goodness = 0;
    for (int i = 0; i < N/2; i++)
    {
        if (S[i] != S[N - 1 - i])
        {
            goodness++;
        }
    }
    return abs(K - goodness);
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}