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
#include <numeric>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    string S;
    cin >> n;
    cin >> S;
    vector<vector<bool>> used(26, vector<bool>(26, false));
    for (int i = 0; i + 1 < n; i++)
    {
        if (used[S[i] - 'a'][S[i + 1] - 'a'])
        {
            cout << "Yes\n";
            return 0;
        }
        if (i - 1 >= 0)
        {
            used[S[i - 1] - 'a'][S[i] - 'a'] = true;
        }
    }
    cout << "No\n";
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
