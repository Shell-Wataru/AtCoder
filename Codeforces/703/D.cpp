#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    vector<ll> options;
    for (int i = 1; i * i * i * i <= 1000000; i++)
    {
        cout << i << endl;
        options.push_back(i*i*i*i);
    }
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> A(n, vector<ll>(m));
    vector<vector<ll>> B(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << i << " " << j << endl;
            if (i == 0 && j == 0)
            {
                B[i][j] = A[i][j] * 10001;
            }
            else if (i == 0)
            {
                for (auto o : options)
                {
                    if (B[i][j - 1] + o <= 1000000 && (B[i][j - 1] + o) % A[i][j] == 0)
                    {
                        B[i][j] = B[i][j - 1] + o;
                        break;
                    }
                    else if (B[i][j - 1] - o >= 1 && (B[i][j - 1] - o) % A[i][j] == 0)
                    {
                        B[i][j] = B[i][j - 1] - o;
                        break;
                    }
                }
            }
            else if (j == 0)
            {
                for (auto o : options)
                {
                    if (B[i - 1][j] + o <= 1000000 && (B[i - 1][j] + o) % A[i][j] == 0)
                    {
                        B[i][j] = B[i - 1][j] + o;
                        break;
                    }
                    else if (B[i - 1][j] - o >= 1 && (B[i - 1][j] - o) % A[i][j] == 0)
                    {
                        B[i][j] = B[i - 1][j] - o;
                        break;
                    }
                }
            }
            else
            {
                for (auto o : options)
                {
                    if (B[i - 1][j] + o <= 1000000 &&
                        (B[i - 1][j] + o) % A[i][j] == 0 &&
                        binary_search(options.begin(), options.end(), abs(B[i - 1][j] + o - B[i][j - 1])))
                    {
                        B[i][j] = B[i - 1][j] + o;
                        // cout << "found!!" << o << endl;
                        break;
                    }
                    else if (B[i - 1][j] - o >= 1 &&
                            (B[i - 1][j] - o) % A[i][j] == 0 &&
                            binary_search(options.begin(), options.end(), abs(B[i - 1][j] - o - B[i][j - 1])))
                    {
                        // cout << "found!!" << o << endl;
                        B[i][j] = B[i - 1][j] - o;
                        break;
                    }
                }
            }
            // cout << B[i][j] << endl;
        }
    }
    cout << "!!!!" << endl;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (j != 0){
                cout << " ";
            }
            cout << B[i][j] ;
        }
        cout << "\n";
    }

    return 0;
}

int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    cout << flush;
    return 0;
}
