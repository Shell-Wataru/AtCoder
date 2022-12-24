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

int main()
{
    // 整数の入力
    ll R, C;
    cin >> R >> C;
    vector<vector<ll>> A(R, vector<ll>(C - 1, numeric_limits<ll>::max()));
    vector<vector<ll>> B(R - 1, vector<ll>(C, numeric_limits<ll>::max()));
    vector<vector<ll>> D(R, vector<ll>(C, numeric_limits<ll>::max()));
    for (int i = 0; i < R; i++)
    {
        for (size_t j = 0; j < C - 1; j++)
        {
            cin >> A[i][j];
        }
    }
    // cout << "!!!" << endl;
    for (int i = 0; i < R - 1; i++)
    {
        for (size_t j = 0; j < C; j++)
        {
            cin >> B[i][j];
        }
    }

    priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> q;
    q.push({0, {0, 0}});
    while (!q.empty())
    {
        auto p = q.top();
        q.pop();
        ll d = p.first;
        ll r = p.second.first;
        ll c = p.second.second;
        // cout << r << " "<< c << endl;
        if (d < D[r][c])
        {
            D[r][c] = d;
            // cout << d << endl;
            if (0 < c && D[r][c] + A[r][c-1] < D[r][c-1])
            {
                q.push({D[r][c] + A[r][c-1], {r, c - 1}});
            }
            if (c < C - 1 && D[r][c] + A[r][c] < D[r][c+1])
            {
                q.push({D[r][c] + A[r][c], {r, c + 1}});
            }
            if (r < R - 1 && D[r][c] + B[r][c] < D[r+1][c])
            {
                q.push({D[r][c] + B[r][c], {r + 1, c}});
            }
            // cout << "?" << endl;
            for (int i = 1; i <= r; i++)
            {
                if (D[r][c] + i + 1 < D[r - i][c])
                {
                    D[r - i][c] = min(D[r - i][c],D[r][c] + i + 2);
                    q.push({D[r][c] + i + 1, {r - i, c}});
                }else if (D[r - i][c] < numeric_limits<ll>::max()){
                    break;
                }
            }
        }
        if (r == R -1 && c == C - 1){
            break;
        }
    }
    cout << D[R - 1][C - 1] << endl;
    return 0;
}