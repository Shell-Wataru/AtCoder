#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <unordered_map>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }
    ll ans = 0;
    for (int i = 1; i < 1ll << H; i++)
    {
        unordered_map<ll, ll> counts;
        ll width = __builtin_popcountll(i);
        for (int j = 0; j < W; j++)
        {
            bool all_same = true;
            ll initial_number = -1;
            for (int k = 0; k < H; k++)
            {
                if (i & 1ll << k)
                {
                    if (initial_number == -1)
                    {
                        initial_number = A[k][j];
                    }
                    else if (initial_number != A[k][j])
                    {
                        all_same = false;
                        break;
                    }
                }
            }
            if (all_same)
            {
                counts[initial_number] += width;
            }
        }
        for (auto p : counts)
        {
            ans = max(ans, p.second);
        }
    }
    cout << ans << endl;
    return 0;
}