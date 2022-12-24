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

ll moves(ll count,ll center, ll left,ll right){
    if (center < left){
        return (left - center + left - center + count -1) * count/2;
    }else if (center < right){
        count--;
        ll min_width = min(right - center,center - left);
        ll max_width = max(right - center,center - left);
        if (count - min_width <= min_width){
            ll a = count/2;
            ll b = (count+1)/2;
            return (a+1)*a/2 + (b+1)*b/2;
        }else{
            ll a = min_width;
            ll b = count - min_width;
            return (a+1)*a/2 + (b+1)*b/2;
        }

    }else{
        return (center - right + center - right + count -1) * count/2;
    }
}
int main()
{
    ll R,G,B;
    cin >> R >> G >> B;
    ll ans = numeric_limits<ll>::max();
    ll min_move = numeric_limits<ll>::max();
    for(int i = -300;i <= 300;i++){
        ll l = i;
        ll r = i+G-1;
        ll move = moves(R,-100,-1000,l-1) +moves(G,0,l,r) + moves(B,100,r+1,1000);
        min_move = min(min_move,move);
    }
    cout << min_move << endl;
    return 0;
}