#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

vector<vector<ll>> warshall_floyd(int n, vector<vector<ll>> &G)
{
    vector<vector<ll>> d = G;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return d;
}

ll solve(){
    string S;
    cin >> S;
    vector<vector<ll>> G(26,vector<ll>(26,numeric_limits<ll>::max()/2));
    ll K;
    cin >> K;

    for(int i = 0;i < K;i++){
        string change;
        cin >> change;
        G[change[0]-'A'][change[1]-'A'] = 1;
    }
    for(int i = 0;i < 26;i++){
        G[i][i] = 0;
    }
    auto D = warshall_floyd(26,G);
    ll ans = numeric_limits<ll>::max();
    for (size_t i = 0; i < 26; i++)
    {
        ll changes = 0;
        for(auto c:S){
            if (D[c-'A'][i] >= numeric_limits<ll>::max()/2){
                changes = numeric_limits<ll>::max();
                break;
            }else{
                changes += D[c-'A'][i];
            }

        }
        ans = min(ans,changes);
    }
    if (ans == numeric_limits<ll>::max()){
        return -1;
    }else{
        return ans;
    }
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;
    // cerr << T << endl;
    for (int i = 1; i <= T; i++)
    {
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}