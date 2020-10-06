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
const ll BASE_NUM = 1000000007;


int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> A(n);
    ll total = 0;
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
        total += A[i];
    }
    if (total % n != 0){
        cout << -1 << "\n";
        return 0;
    }else{
        ll target = total/n;
        cout << 3 * (n-1) << endl;
        for(int i = 1;i < n;i++){
            ll num = i+1;
            ll remain = (num -  A[i] % num) % num;
            cout << 1  << " " << num << " " << remain << "\n";
            A[0] =  A[0] - remain;
            A[i] =  A[i] + remain;
            cout << num  << " " << 1 << " " << A[i]/num << "\n";
            A[0] = A[0] + A[i];
            A[i] = 0;
        }

        for(int i = 1;i < n;i++){
            ll num = i+1;
            ll remain = (num -  A[i] % num) % num;
            cout << 1  << " " << num << " " << target << "\n";
        }
    }
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
    cout << flush;
    return 0;
}
