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

    ll n;
    scanf("%lld",&n);
    vector<vector<ll>> A(n,vector<ll>(n,0));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
          A[i][j] = 1<<(2*i);
        }
    }


    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}