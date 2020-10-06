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
    ll n,x;
    scanf("%lld", &n);
    scanf("%lld", &x);
    vector<ll> A(n);
    ll total = 0;
    ll infected_accounts = 0;
    ll not_infected_accounts = 0;
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
        total += A[i];
        if (A[i] == x){
            infected_accounts++;
        }else{
            not_infected_accounts++;
        }
    }
    if (infected_accounts == n){
        cout << 0 << endl;
        return 0;
    }else if (infected_accounts == 0){
        if (total == n * x){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
        return 0;
    }else if(infected_accounts >= 1){
        cout << 1 << endl;
        return 0;
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
    // cout << flush;
    return 0;
}
