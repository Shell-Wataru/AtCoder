#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

map<ll,ll> cache;

ll count(ll Y, ll A, ll B,ll C,ll D ){
    if (cache.find(Y) != cache.end()){
        return cache[Y];
    }else if (Y == 0){
        return 0;
    }else{
        ll ans;
        if (Y >= numeric_limits<ll>::max()/D){
            ans = numeric_limits<ll>::max();
        }else{
            ans = Y*D;
        }
        for(ll i = -4;i <= 4;i++){
            ll y = Y+i;
            if (y < 0){
                continue;
            }
            if (y % 2 == 0 && y/2 < Y){
                ans = min(ans,count(y/2,A,B,C,D) + A + abs(i)*D);
            }
            if (y % 3 == 0 && y/3 < Y){
                ans = min(ans,count(y/3,A,B,C,D) + B + abs(i)*D);
            }
            if (y % 5 == 0 && y/5 < Y){
                ans = min(ans,count(y/5,A,B,C,D) + C + abs(i)*D);
            }
        }
        cache[Y] = ans;
        return ans;
    }
}


int solve(){
    ll N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    cache.clear();
    cout << count(N,A,B,C,D) << endl;
    // for(int i = 0;i <= N;i++){
    //     cout << i << ":" << cache[i] << endl;
    // }
    return 0;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;
    for(int i = 0;i < T;i++){
        solve();
    }
    return 0;
}