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

int main()
{
    ll n, m;
    vector<ll> A, B;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        ll b;
        cin >> b;
        B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll min_diff = m;
    for (int i = 0; i < n; i++)
    {
        ll diff = (m + B[i] - A[0]) % m;
        // cout << diff << endl;
        ll is_ok = true;
        for (int j = 0; j < n; j++)
        {
            // cout << (A[j] + diff) % m << " " << B[(i + j) % n] << endl;
            if ((A[j] + diff) % m != B[(i + j) % n])
            {
                // cout << "NG" << endl;
                is_ok = false;
                break;
            }
        }
        if (is_ok)
        {
            min_diff = min(min_diff, diff);
        }
    }
    cout << min_diff << endl;
    return 0;
}
