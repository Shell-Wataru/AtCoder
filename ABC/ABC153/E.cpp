#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

struct Magic
{
    ll a, b;
};
int main()
{
    // 整数の入力
    ll H, N;
    vector<Magic> A;
    cin >> H >> N;
    vector<vector<ll>> DP(N, vector<ll>(H + 1, BASE_NUM));

    for (int i = 0; i < N; i++)
    {
        Magic m;
        cin >> m.a >> m.b;
        A.push_back(m);
    }
    DP[0][0] = 0;
    for (int i = 0; i < N; i++)
    {
        Magic m = A[i];
        for (int j = 0; j <= H; j++)
        {
            // cout << i << j << endl;
            if (j < m.a)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        DP[i][j] = 0;
                    }
                    else
                    {
                        DP[i][j] = m.b;
                    }
                }
                else
                {
                    DP[i][j] = min(DP[i - 1][j], m.b);
                }
            }
            else
            {
                if (i == 0)
                {
                    DP[i][j] = DP[i][j - m.a] + m.b;
                }
                else
                {
                    DP[i][j] = min(DP[i - 1][j], DP[i][j - m.a] + m.b);
                }
            }
        }
    }
    cout << DP[N - 1][H] << endl;
    return 0;
}
