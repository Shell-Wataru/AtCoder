#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    cin >> n;
    vector<vector<bool>> S;
    vector<ll> A, B;
    S.push_back(vector<bool>(3, false));
    // cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        vector<bool> s(S.back());
        ll a;
        cin >> a;
        s[a + 1] = true;
        // for(int j = 0;j< 3;j++){
        //     cout << s[j];
        // }
        // cout << endl;
        A.push_back(a);
        S.push_back(s);
    }

    for (int i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        B.push_back(b);
    }
    bool can_make = true;
    for (int i = n - 1; i >= 0; i--)
    {
        if (B[i] > A[i])
        {
            if (!S[i][2])
            {
                // cout << i << endl;
                can_make = false;
            }
        }
        else if (B[i] < A[i])
        {
            if (!S[i][0])
            {
                // cout << i << endl;
                can_make = false;
            }
        }
    }
    if (can_make)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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
