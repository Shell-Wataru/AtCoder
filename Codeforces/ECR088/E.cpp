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

long long BASE_NUM = 998244353;

long long extGCD(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

vector<ll> inverse_array(ll n){
    vector<ll> inverse(n,-1);
    inverse[1] = 1;
    for(int i = 2;i<n;i++){
        inverse[i] = BASE_NUM - inverse[BASE_NUM % i] * (BASE_NUM/i) % BASE_NUM;
    }
    return inverse;
}

int solve()
{

    ll n,k;
    cin >> n >>k;
    vector<ll> inverse = inverse_array(n);
    vector<ll> factorial;
    factorial.push_back(1);
    for (int i = 1; i <= n; i++)
    {
        factorial.push_back(factorial[i - 1] * i % BASE_NUM);
    }

    vector<ll> inverse_factorial;
    inverse_factorial.push_back(1);
    for (int i = 1; i <= n; i++)
    {
        inverse_factorial.push_back(inverse_factorial[i - 1] * inverse[i] % BASE_NUM);
    }
    ll total = 0;
    for(int i = 1; i <= n;i++){
        ll others = n/i - 1;
        ll chooses = k -1;
        if (others >= chooses){
            total =  total + (factorial[others] * inverse_factorial[chooses] % BASE_NUM) * inverse_factorial[others - chooses] % BASE_NUM;
            total %= BASE_NUM;
        }
    }
    cout << total << endl;
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
    return 0;
}