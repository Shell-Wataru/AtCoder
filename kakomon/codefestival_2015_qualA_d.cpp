#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

ll answer(ll l,ll r,ll N,vector<ll> &X){
    if (l+1 == r){
        return r;
    }
    ll center = (l+r)/2;
    ll last_cleaned = -1;
    for(auto x:X){
        if (last_cleaned + 1 < x - center){
            return answer(center,r,N,X);
        }else{
            ll back = max(x - (last_cleaned+1),0ll);
            last_cleaned = max(max(x, x + center - 2 * back),x + (center - back)/2);
        }
    }
    if (last_cleaned >= N-1){
        return answer(l,center,N,X);
    }else{
        return answer(center,r,N,X);
    }
}
int solve()
{
    ll N,M;
    cin >> N >> M;
    vector<ll> X(M);
    for(int i = 0;i < M;i++){
        cin >> X[i];
        X[i]--;
    }
    cout << answer(-1,numeric_limits<ll>::max()/2,N,X) << endl;
    return 0;
}
int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
