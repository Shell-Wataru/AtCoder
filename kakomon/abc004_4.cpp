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

ll moves(ll count, ll left,ll right){

}
int main()
{
    ll R,G,B;
    cin >> R >> G >> B;
    ll ans = numeric_limits<ll>::max();
    for(int i = -99;i <= 0;i++){
        for(int j = 0;j <= 99;j++){
            ll r_moves = moves(R,numeric_limits<ll>::max(),i - (-100) - 1);
            ll g_moves = moves(G,-i,j);
            ll b_moves = moves(G,100 - j - 1,numeric_limits<ll>::max());
            ans = max(ans, r_moves + g_moves + b_moves);
        }
    }
    return 0;
}