#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int solve()
{
    int n;
    cin >> n;
    // cout << n << endl;
    vector<int> A(n);
    vector<vector<int>> Indexes(200, vector<int>(0));
    vector<vector<int>> Sums(200, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        int a;
        scanf("%intd",&a);
        a--;
        A[i] = a;
        Indexes[a].push_back(i);
        Sums[a][i] += 1;
    }
    // cout << "==" << endl;
    for (int i = 0; i < 200; i++)
    {
        for (int j = 1; j < n; j++)
        {
            Sums[i][j] += Sums[i][j - 1];
        }
    }

    int max_length = 0;
    for (int j = 0; j < 200; j++)
    {
        max_length = max(max_length, Sums[j][n - 1]);
    }
    for (int i = 0; i < 200; i++)
    {
        int start = 0;
        int end = (int)Indexes[i].size() - 1;
        // cout << start << "="<< end << endl;
        while (start < end)
        {
            int center_start = Indexes[i][start] + 1;
            int center_end = Indexes[i][end] - 1;
            // cout << center_start << "-" << center_end << endl;
            for (int j = 0; j < 200; j++)
            {
                max_length = max(max_length, 2 * (start + 1) + Sums[j][center_end] - Sums[j][center_start - 1]);
            }
            start++;
            end--;
        }
    }
    cout << max_length << endl;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}