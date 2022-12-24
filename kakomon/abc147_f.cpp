#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
    ll N,X,D;
    cin >> N >> X >> D;
    if (X == 0 && D== 0){
        cout << 1 << endl;
    }else if (X == 0){
        cout << N*(N-1)/2 + 1  << endl;
    }else if (D == 0){
        cout << 2*(N-1)+1;
    }else{
        ll lca = abs(X*D/gcd(X,D));
        ll x_add = abs(lca/X);
        ll d_add = x_add*X/D;
        cout << x_add << endl;
        unordered_map<ll,vector<pair<ll,ll>>> ranges;
        for(int i = 0;i <= N;i++){
            ll a = N-2*i;
            ll l = (N-i)*(N-1-i)/2 - (N-i+N-1)*i/2;
            ll r = N*(N-1)/2 - (0+i-1)*i/2 * 2 + 1;
            cout << a << ":" << l << "~" << r << endl;
            if (a < 0){
                ll add = (-a+x_add-1)/x_add * x_add;
                a += add;
                l -= add*X/D;
                r -= add*X/D;
            }else{
                ll sub = a/x_add * x_add;
                a -= sub;
                l += sub*X/D;
                r += sub*X/D;
            }
            cout << a << ":" << l << "~" << r << endl;
            ranges[a].push_back({l,r});
        }
        ll ans = 0;

        for(auto p:ranges){
            auto range = p.second;
            sort(range.begin(),range.end());
            cout << p.first << ":" << endl;
            pair<ll,ll> current = {numeric_limits<ll>::min(),numeric_limits<ll>::min()};
            for(auto r:range){
                if (current.second < r.first){
                    ans += (current.second - current.first+1)/2;
                    cout << (current.second - current.first+1)/2 << endl;
                    current = r;
                }else{
                    current.second = max(current.second,r.second);
                }
            }
            cout << (current.second - current.first+1)/2 << endl;
            ans += (current.second - current.first+1)/2;
        }
        cout << ans << endl;
    }
    return 0;
}

int main()
{
    // cout << "!" << endl;
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
