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

using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;
    map<ll,ll> counts;
    counts[0] = 1;
    ll ans = 0;
    ll total = 0;
    for(int i =0;i < N;i++){
        ll a;
        cin >> a;
        total += a;
        ans += counts[total];
        counts[total]++;
    }
    cout << ans << endl;
    return 0;

}