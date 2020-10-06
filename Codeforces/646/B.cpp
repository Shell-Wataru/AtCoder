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

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(),A.end());
    ll min_diff = BASE_NUM;
    for(int i = 0;i < n- 1;i++){
        min_diff = min(min_diff, A[i+1] - A[i]);
    }
    cout << min_diff << endl;
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
    return 0;
}
