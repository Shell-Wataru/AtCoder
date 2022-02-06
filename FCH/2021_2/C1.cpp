#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    ll R,C,K;
    cin >> R >> C >> K;
    K--;
    ll reverseK = R - K  - 1;
    vector<string> G(R);
    for(int i = 0;i < R;i++){
        cin >> G[i];
    }
    vector<string> reverseG(G);
    reverse(reverseG.begin(),reverseG.end());
    // cout << G[K] << endl;
    // cout << reverseG[reverseK] << endl;

    vector<vector<ll>>  upwords(R,vector<ll>(C));
    vector<vector<ll>>  downwords(R,vector<ll>(C));
    for(int i = 0;i < C;i++){
        vector<ll> ruiseki(R+1);
        for(int j = 0;j < R;j++){
            ruiseki[j+1] = ruiseki[j];
            if (G[j][i] == 'X'){
                ruiseki[j+1]++;
            }
        }
        for(int j = 0;j < R;j++){
            if ( (j+K >= R || G[j+K][i]  == '.') &&  ruiseki[min(R,j+K+1)] <= K){
                upwords[j][i] = 0;
            }else{
                upwords[j][i] = 1;
            }
        }
    }

    for(int i = 0;i < C;i++){
        vector<ll> ruiseki(R+1);
        for(int j = 0;j < R;j++){
            ruiseki[j+1] = ruiseki[j];
            if (reverseG[j][i] == 'X'){
                ruiseki[j+1]++;
            }
        }
        for(int j = 0;j < R;j++){
            if ( (j+reverseK >= R || reverseG[j+reverseK][i]  == '.') &&  ruiseki[min(R,j+reverseK+1)] <= reverseK){
                downwords[j][i] = 0;
            }else{
                downwords[j][i] = 1;
            }
        }
    }
    // for(int i = 0;i < R;i++){
    //     for(int j = 0;j < C;j++){
    //         cout <<  upwords[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    // cout << "!!" << endl;
    // for(int i = 0;i < R;i++){
    //     for(int j = 0;j < C;j++){
    //         cout <<  downwords[i][j] << ",";
    //     }
    //     cout << endl;
    // }
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i < R;i++){
        ll current = i;
        for(int j = 0;j < C;j++){
            current += upwords[i][j];
        }
        ans = min(ans,current);
    }
    for(int i = 0;i < R;i++){
        ll current = i;
        for(int j = 0;j < C;j++){
            current += downwords[i][j];
        }
        ans = min(ans,current);
    }
    return to_string(ans);
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