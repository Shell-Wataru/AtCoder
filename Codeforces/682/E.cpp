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
const int BASE_NUM = 1000000007;

int solve()
{
    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    vector<ll> maxDP(n+1,0);
    vector<ll> minDP(n+1,0);
    return 0;
}
int main()
{
    // 整数の入力
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
        // }
    // cout << flush;
    return 0;
}
