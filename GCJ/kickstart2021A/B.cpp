#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    ll R,C;
    cin >> R >> C;
    vector<vector<ll>> G(R,vector<ll>(C));
    vector<vector<ll>> UC(R,vector<ll>(C,0));
    vector<vector<ll>> DC(R,vector<ll>(C,0));
    vector<vector<ll>> LC(R,vector<ll>(C,0));
    vector<vector<ll>> RC(R,vector<ll>(C,0));
    for(ll i = 0;i < R;i++){
        for (ll j = 0; j < C; j++)
        {
            cin >> G[i][j];
        }
    }

    for(ll i = 0;i < R;i++){
        for (ll j = 0; j < C; j++)
        {
            if (G[i][j] == 0){
                UC[i][j] = 0;
            }else{
                if (i == 0){
                    UC[i][j] = 1;
                }else{
                    UC[i][j] = UC[i-1][j] +1;
                }
            }
        }
    }

    for(ll i = 0;i < R;i++){
        for (ll j = 0; j < C; j++)
        {
            if (G[i][j] == 0){
                LC[i][j] = 0;
            }else{
                if (j == 0){
                    LC[i][j] = 1;
                }else{
                    LC[i][j] = LC[i][j-1] +1;
                }
            }
        }
    }

    for(ll i = R-1;i >= 0;i--){
        for (ll j = 0; j < C; j++)
        {
            if (G[i][j] == 0){
                DC[i][j] = 0;
            }else{
                if (i == R-1){
                    DC[i][j] = 1;
                }else{
                    DC[i][j] = DC[i+1][j] +1;
                }
            }
        }
    }

    for(ll i = 0;i < R;i++){
        for (ll j = C-1; j >= 0; j--)
        {
            if (G[i][j] == 0){
                RC[i][j] = 0;
            }else{
                if (j == C-1){
                    RC[i][j] = 1;
                }else{
                    RC[i][j] = RC[i][j+1] + 1;
                }
            }
        }
    }
    ll ans = 0;

    for(ll i = 0;i < R;i++){
        for (ll j = 0; j < C; j++)
        {
            ans += max(min(UC[i][j]/2,LC[i][j]) -1,0ll);
            ans += max(min(UC[i][j],LC[i][j]/2) -1,0ll);
            ans += max(min(UC[i][j]/2,RC[i][j]) -1,0ll);
            ans += max(min(UC[i][j],RC[i][j]/2) -1,0ll);
            ans += max(min(DC[i][j]/2,LC[i][j]) -1,0ll);
            ans += max(min(DC[i][j],LC[i][j]/2) -1,0ll);
            ans += max(min(DC[i][j]/2,RC[i][j]) -1,0ll);
            ans += max(min(DC[i][j],RC[i][j]/2) -1,0ll);
        }
    }

    return to_string(ans);;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i  << ": "<< ans << endl;
    }

    return 0;
}