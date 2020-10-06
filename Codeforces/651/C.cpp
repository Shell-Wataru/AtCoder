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

map<long long, long long> decomposite(long long N, map<long long, long long> &primes, long long next_p = 2)
{
    if (N == 1)
    {
        return primes;
    }

    while (next_p * next_p <= N)
    {
        if (N % next_p == 0)
        {
            primes[next_p] += 1;
            return decomposite(N / next_p, primes, next_p);
        }
        else
        {
            next_p++;
        }
    }
    primes[N] += 1;
    return primes;
}

int solve()
{
    // cout << "==" << endl;
    string S;
    ll n;
    cin >> n;
    map<ll, ll> factors;
    decomposite(n, factors);
    ll other_factor_count = 0;
    for (auto p : factors)
    {
        if (p.first != 2)
        {
            other_factor_count += p.second;
        }
    }
    // cout << other_factor_count << endl;
    if (n == 1)
    {
        cout << "FastestFinger" << endl;
    }
    else if (factors[2] == 0)
    {
        cout << "Ashishgup" << endl;
    }
    else if (factors[2] == 1)
    {
        if (other_factor_count == 0){
            cout << "Ashishgup" << endl;
        }else if (other_factor_count == 1){
            cout << "FastestFinger" << endl;
        }else{
            cout << "Ashishgup" << endl;
        }
    }
    else{
        if (other_factor_count == 0){
            cout << "FastestFinger" << endl;
        }else{
            cout << "Ashishgup" << endl;
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
    // cout << flush;
    return 0;
}
