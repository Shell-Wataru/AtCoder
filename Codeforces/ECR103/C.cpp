#define _USE_MATH_DEFINES
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
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    vector<ll> B(n);
    vector<ll> C(n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&C[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&B[i]);
    }
    ll current_max = 0;
    ll current = 0;
    for(int i = 1;i < n;i++){
        if (i == 1){
            current = abs(A[i] - B[i]) + 2;
        }else if (A[i] == B[i]){
            current = 2;
        }else
        {
            current = max(current + C[i-1]- 1 - abs(A[i] - B[i]),abs(A[i] - B[i])) + 2;
        }
        current_max = max(current_max,current + C[i] - 1);
    }
    cout << current_max << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
