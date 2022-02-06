#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll L,R;
    cin >> L >> R;
    vector<ll> DP(R+1,0);
    for(int i = R;i >= 1;i--){

        ll count = R/i - (L-1)/i;
        ll total = count*count;
        for(int j = 2;i *j <= R;j++){
            total -= DP[i*j];
        }
        DP[i] = total;
    }
    ll ans = 0;
    for(int i = 2;i <= R;i++){
        if (i < L){
            ans +=  DP[i];
        }else{
            ll total = R/i - (L - 1)/i;
            ans +=  DP[i] - 2*total + 1;
        }
        // cout << i << ":" << DP[i] << endl;
    }
    cout << ans << endl;
    return 0;
}