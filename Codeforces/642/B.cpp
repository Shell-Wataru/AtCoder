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
    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    vector<ll> B(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    for (size_t i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i = 0;i < k;i++){
        if (A[i] < B[n - i -1] ){
            swap(A[i],B[n-i-1]);
        }
    }
    ll total = 0;
    for(int i = 0;i < n;i++){
        total+= A[i];
    }
    cout << total << endl;
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
