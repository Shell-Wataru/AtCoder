#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    vector<vector<ll>> colors(3,vector<ll>(4));
    vector<ll> ans_color(4);
    ll total_color = 1000000;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 4;j++){
            cin >> colors[i][j];
        }
    }
    for(int i = 0;i < 4;i++){
        ll c = total_color;
        for(int j = 0;j < 3;j++){
            c = min(c,colors[j][i]);
        }
        total_color -= c;
        ans_color[i] = c;
    }
    if (total_color > 0){
        return "IMPOSSIBLE";
    }else{
        string ans = "";
        for(int i = 0;i < 4;i++){
            if (i!= 0){
                ans += " ";
            }
            ans += to_string(ans_color[i]);
        }
        return ans;
    }

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