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
#include <set>
#include <unordered_map>
using namespace std;
using ll = long long;

ll solve()
{
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);
    for(int i = 0;i < N;i++){
        cin >> a[i];
    }
    for(int i = 0;i < N;i++){
        cin >> b[i];
    }
    vector<bool> decieded(N,false);
    ll ans = 0;
    for(int l = 0;l < N;l++){
        vector<vector<ll>> DP(51,vector<ll>(51,numeric_limits<ll>::max()));
        for(int i = 0;i <= 50;i++){
            for(int j = i;j <= 50;j++){
                if (i == j){
                    DP[j][i] = ans;
                }else{
                    ll minimum = numeric_limits<ll>::max();
                    for(int k = 1;k <= j;k++){
                        minimum = min(minimum,1ll<<k | DP[j%k][i] | ans);
                        if (j % k == i){
                            minimum = min(minimum,1ll<<k | ans);
                        }
                    }
                    DP[j][i] = minimum;
                }
            }
        }
        ll maximum = -1;;
        ll maximum_index = -1;
        for(int i = 0 ;i < N;i++){
            if (!decieded[i] && DP[a[i]][b[i]] > maximum){
                maximum = DP[a[i]][b[i]];
                maximum_index = i;
            }
        }
        decieded[maximum_index] = true;
        ans = maximum;
    }
    if (ans != numeric_limits<ll>::max()){
        cout << ans << endl;
    }else{
        cout << -1 << endl;

    }
    return 0;
}

int main()
{
    // ll N;
    // cin >> N;
    // for(int i = 1; i <= N;i++){
    solve();
    // }
    cout << flush;
    return 0;
}
