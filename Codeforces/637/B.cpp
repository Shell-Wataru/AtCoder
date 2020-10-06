#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n, k;
    cin >> n >> k;
    vector<bitset<7>> numbers = {
        0b1110111,
        0b0010010,
        0b1011101,
        0b1011011,
        0b0111010,
        0b1101011,
        0b1101111,
        0b1010010,
        0b1111111,
        0b1111011};
    vector<bitset<7>> inputs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inputs[i];
    }
    vector<vector<string>> DP(2, vector<string>(k + 1, "empty"));
    DP[0][0] = "";
    vector<ll> min_uses(n);
    vector<ll> max_uses(n);
    for (int i = 0; i < n; i++)
    {
        ll min_use = 8;
        ll max_use = -1;
        for (ll j = 0; j < 10; j++)
        {
            bitset<7> xors = inputs[i] ^ numbers[j];
            if ((xors & numbers[j]) != xors)
            {
                continue;
            }
            else
            {
                min_use = min(min_use,(ll)xors.count());
                max_use = max(max_use,(ll)xors.count());
            }
        }
        if(i == 0){
            min_uses[i] = min_use;
            max_uses[i] = max_use;
        }else{
            min_uses[i] = min_uses[i-1] +  min_use;
            max_uses[i] = max_uses[i-1] + max_use;
        }
    }
    for (int i = 0; i < n; i++)
    {
        // DP[(i+1) % 2] = vector<string>(k + 1,"empty");
        map<ll, char> using_ks;
        for (ll j = 0; j < 10; j++)
        {
            bitset<7> xors = inputs[i] ^ numbers[j];
            // cout << j << ":"<< (xors & numbers[j])  << " " << xors << endl;
            if ((xors & numbers[j]) != xors)
            {
                continue;
            }
            else
            {
                // cout << xors.count() << " " << j << endl;
                using_ks[xors.count()] = to_string(j)[0];
            }
        }
        // cout << i << endl;
        // cout << max(0ll, k - (max_uses[n-1] - max_uses[i])) << "~" << k - (min_uses[n-1] - min_uses[i]) << endl;
        for (int j = max(0ll, k - (max_uses[n-1] - max_uses[i])); j <= k - (min_uses[n-1] - min_uses[i]); j++)
        {
            DP[(i + 1) % 2][j] = "empty";
            for (auto &p : using_ks)
            {
                if (j - p.first >= 0)
                {
                    if (DP[i % 2][j - p.first] != "empty")
                    {
                        if (DP[(i + 1) % 2][j] == "empty")
                        {

                            DP[(i + 1) % 2][j] = DP[i % 2][j - p.first];
                            DP[(i + 1) % 2][j] += p.second;
                        }
                        else
                        {
                            if (DP[(i + 1) % 2][j] <= DP[i % 2][j - p.first])
                            {
                                DP[(i + 1) % 2][j] = DP[i % 2][j - p.first];
                                DP[(i + 1) % 2][j] += p.second;
                            }
                        }
                    }
                }
            }
        }
    }
    if (DP[n % 2][k] == "empty")
    {
        cout << -1 << endl;
    }
    else
    {
        cout << DP[n % 2][k] << endl;
    }
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (int i = 1; i <= t; i++)
    // {
    solve();
    // }
    return 0;
}
