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
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A, B;
    ll SS = 1 << N;
    ll MAX_VALUE = 50;
    vector<vector<ll>> DP(SS, vector<ll>(MAX_VALUE+1, BASE_NUM));
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    }

    for (int i = 0; i < N; i++)
    {
        ll b;
        cin >> b;
        B.push_back(b);
    }
    DP[0][0] = 0;

    for (int s = 0; s < SS; s++)
    {
        for (int i = 0; i < N; i++)
        {
            if (s & (1 << i))
            {
                continue;
            }
            ll s_count = 0;
            ll moves = 0;
            for (int j = 0; j < N; j++)
            {
                if (s & (1 << j))
                {
                    s_count++;
                }
                else if (j < i)
                {
                    moves++;
                }
            }
            ll value;
            if (abs(i - s_count) % 2 == 0)
            {
                value = A[i];
            }
            else
            {
                value = B[i];
            }

            for (int j = 0; j <= value; j++)
            {
                // cout << s << "-" << i  << "-" << j << "!" << DP[s][j] + moves << endl;
                DP[s | 1 << i][value] = min(DP[s | 1 << i][value], DP[s][j] + moves);
            }
        }
    }

    ll min_value = BASE_NUM;
    for (int i = 0; i <= MAX_VALUE; i++)
    {
        // cout << DP[SS-1][i] << endl;
        min_value = min(min_value, DP[SS - 1][i]);
    }
    if (min_value == BASE_NUM)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min_value << endl;
    }
    return 0;
}