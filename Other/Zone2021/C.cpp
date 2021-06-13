#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

ll value(vector<vector<ll>> &S, ll l, ll r)
{
    if (l + 1 == r)
    {
        return l;
    }
    ll center = (l + r) / 2;
    vector<vector<bool>> DP(4, vector<bool>(1 << 5, false));
    DP[0][0] = true;
    for (auto &s : S)
    {
        ll clear = 0;
        for (int i = 0; i < 5; i++)
        {
            if (s[i] >= center)
            {
                clear = clear | (1 << i);
            }
        }
        for (int i = 0; i <= 2; i++)
        {
            for (int j = 0; j < 1 << 5; j++)
            {
                DP[i + 1][j | clear] = DP[i + 1][j | clear] || DP[i][j];
            }
        }
    }

    if (DP[3][(1 << 5) - 1])
    {
        return value(S, center, r);
    }
    else
    {
        return value(S, l, center);
    }
}
int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> S(N, vector<ll>(5));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> S[i][j];
        }
    }
    cout << value(S, 0, BASE_NUM) << endl;
    return 0;
}