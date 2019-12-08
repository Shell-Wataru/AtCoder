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

void warshall_floyd(int n, vector<vector<ll>> &d)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void warshall_floyd2(int n, vector<vector<ll>> &d)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j] + 1);
            }
        }
    }
}

int main()
{
    // 整数の入力
    ll N, M, L;
    cin >> N >> M >> L;
    vector<vector<ll>> D(N, vector<ll>(N, BASE_NUM));
    vector<vector<ll>> D_HOKYU(N, vector<ll>(N, BASE_NUM));
    for (int i = 0; i < M; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        D[a - 1][b - 1] = c;
        D[b - 1][a - 1] = c;
    }
    warshall_floyd(N, D);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (D[i][j] <= L)
            {
                D_HOKYU[i][j] = 0;
            }
        }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         if (D_HOKYU[i][j] == BASE_NUM)
    //         {
    //             cout << 9;
    //         }
    //         else
    //         {
    //             cout << D_HOKYU[i][j];
    //         }
    //     }
    //     cout << endl;
    // }
    warshall_floyd2(N, D_HOKYU);
// for (int i = 0; i < N; i++)
//     {
//         for (int j = 0; j < N; j++)
//         {
//             if (D_HOKYU[i][j] == BASE_NUM)
//             {
//                 cout << 9;
//             }
//             else
//             {
//                 cout << D_HOKYU[i][j];
//             }
//         }
//         cout << endl;
//     }
        ll Q;
    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        ll s, t;
        cin >> s >> t;
        s--;
        t--;
        if (D_HOKYU[s][t] == BASE_NUM)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << D_HOKYU[s][t] << endl;
        }
    }
    return 0;
}