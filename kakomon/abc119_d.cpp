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
    ll A,B,Q;
    cin >> A >> B >> Q;
    vector<ll> S(A);
    vector<ll> T(B);
    for (size_t i = 0; i < A; i++)
    {
        cin >> S[i];
    }

    for (size_t i = 0; i < B; i++)
    {
        cin >> T[i];
    }

    sort(S.begin(),S.end());
    sort(T.begin(),T.end());
    for(int i = 0;i < Q;i++){
        ll x;
        cin >> x;
        auto s_big_iter = lower_bound(S.begin(),S.end(),x);
        auto t_big_iter = lower_bound(T.begin(),T.end(),x);
        auto s_small_iter = lower_bound(S.rbegin(),S.rend(),x,greater<ll>());
        auto t_small_iter = lower_bound(T.rbegin(),T.rend(),x,greater<ll>());
        ll s_big = numeric_limits<ll>::max()/4;
        ll t_big = numeric_limits<ll>::max()/4;
        ll s_small = numeric_limits<ll>::min()/4;
        ll t_small = numeric_limits<ll>::min()/4;
        if (s_big_iter != S.end()){
            s_big = *s_big_iter;
        }
        if (s_small_iter != S.rend()){
            s_small = *s_small_iter;
        }
        if (t_big_iter != T.end()){
            t_big = *t_big_iter;
        }
        if (t_small_iter != T.rend()){
            t_small = *t_small_iter;
        }
        // cout << "s" << s_small << "~" << s_big << endl;
        // cout << "t" << t_small << "~" << t_big << endl;
        ll ans = numeric_limits<ll>::max();
        ans = min(ans, max(s_big,t_big) -x);
        ans = min(ans, t_big - s_small +  (t_big - x));
        ans = min(ans, t_big - s_small +  (x - s_small));

        ans = min(ans, s_big - t_small +  (s_big - x));
        ans = min(ans, s_big - t_small +  (x - t_small));

        ans = min(ans, x - min(s_small,t_small));

        cout << ans << endl;
    }
    return 0;

}