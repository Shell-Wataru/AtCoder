#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll N;
    cin >> N;
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i <= 60;i++){
        ll c = N % (1ll<<i);
        ll a = (N-c )/(1ll<<i);
        ans = min(ans,a+i+c);
    }
    cout << ans << endl;
    return 0;
}