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

string solve()
{
    ll N;
    cin >> N;
    vector<ll> V(N+1,0);
    for(int i = 1;i <= N;i++){
        cin >> V[i];
    }
    vector<map<ll,modint>> DP(1<<N);
    DP[0][0] = 1;
    for(int i = 0;i < (1<<N)-1;i++){
        // i:used;
        for(auto p:DP[i]){
            // j:visible;
            ll n = popcount(i);
            ll j = p.first;

            for(int k = 0;k < N;k++){
                if (!(i & 1<<k) && V[n+1] == v_new(j,k)){
                    ll new_plates = ((j >> k) << k) | (1<<k);
                    DP[i|1<<k][new_plates] += p.second;
                }
            }
        }
    }
    modint ans = 0;
    for(auto p:DP[(1<<N) -1]){
        ans += p.second;
    }
    return to_string(ans.x);
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}