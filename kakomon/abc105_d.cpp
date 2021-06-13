#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

int main()
{
    ll N,M;
    scanf("%lld", &N);
    scanf("%lld", &M);
    map<ll,ll> counts;
    counts[0] += 1;
    ll current = 0;
    ll ans = 0;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        current =  (current +  a) % M;
        ans += counts[current];
        counts[current]++;
    }
    cout << ans << endl;
    return 0;
}