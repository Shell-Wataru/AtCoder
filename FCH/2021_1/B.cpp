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
    ll N, M, A, B;
    cin >> N >> M >> A >> B;
    if (A < N + M - 1 || B < N + M - 1)
    {
        return "Impossible\n";
    }
    else
    {
        vector<vector<ll>> G(N, vector<ll>(M, 1));
        G[0][0] = A - (N + M - 2);
        G[N - 1][0] = B - (N + M - 2);
        string ans = "Possible\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (j != 0)
                {
                    ans += " ";
                }
                ans += to_string(G[i][j]);
            }
            ans += "\n";
        }
        return ans;
    }
}
int main()
{
    ll T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << flush;
    }

    return 0;
}