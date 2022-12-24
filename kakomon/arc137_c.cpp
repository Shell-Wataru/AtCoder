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

int solve()
{
    ll N;
    cin >> N;
    ll target_xor = 0;
    ll initial_xor = 0;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        initial_xor ^= a;
        target_xor ^= i;
    }
    if ( target_xor== initial_xor){
        cout << "Bob"<< endl;
    }else{
        cout << "Alice"<< endl;
    }
    return 0;
}
int main()
{
    // ll T;
    // cin >> T;
    // while (T--)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}