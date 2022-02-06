#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
    string S;
    string K;
    cin >> S >> K;
    set<char> found;
    for (auto k : K)
    {
        found.insert(k);
    }
    vector<vector<double>> DP(36, vector<double>(2*36 + S.size()));
    DP[0][0] = 1;
    for (auto s : S)
    {
        if (found.find(s) != found.end())
        {
            vector<vector<double>> newDP(36, vector<double>(2*36 + S.size()));
            for (int i = 0; i < 36; i++)
            {
                for (int j = 0; j < 2*36 + S.size(); j++)
                {
                    if (j + 1 < 2*36 + S.size()){
                        newDP[i][j+1] = DP[i][j];
                    }
                }
            }
            DP = newDP;
        }
        else
        {
            vector<vector<double>> newDP(36, vector<double>(2*36 + S.size()));
            ll unknown = 36 - found.size();
            for (int i = 0; i < 36; i++)
            {
                for (int j = 0; j < 2*36 + S.size(); j++)
                {
                    if (i > 0 && j + 1 < 2*36 + S.size())
                    {
                        newDP[i - 1][j + 1] += DP[i][j] * i / unknown;
                    }

                    for (int k = 0; k < unknown - i; k++)
                    {
                        if (i+k < 36 && j + 2 * k + 1 < 2*36 + S.size()){
                            newDP[i + k][j + 2 * k + 1] += 1.0 / unknown * DP[i][j];
                        }

                    }
                }
            }
            found.insert(s);
            DP = newDP;
        }
    }
    double ans = 0;
    for (auto row : DP)
    {
        for(int i = 0; i < row.size();i++){
            // cout << row[i] << ",";
            ans += row[i]*i;
        }
        // cout << endl;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
