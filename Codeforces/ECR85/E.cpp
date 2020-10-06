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

ll BASE_NUM = 1000000007;

int solve()
{
    ll D;
    cin >> D;
    map<ll,ll> counts;
    vector<ll> primes;
    for(int i = 1;i * i <= D;i++){
        if (D % i == 0){
            counts[i] = 1;
            for(auto p:primes){
                if (i % p  == 0){
                    counts[i]
                }
            }
        }
    }
    return 0;
}
int main()
{
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    return 0;
}