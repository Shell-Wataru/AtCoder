#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int solve(){
    string s,t;
    cin >> s >> t;
    vector<vector<ll>> next_indexes(26,vector<ll>(s.size(),-1));
    for(int i = s.size() - 1;i >=0;i--){
        // cout << "i" << i << endl;
        for(int j = 0;j < 26;j++){
            if(j == s[i] - 'a'){
                next_indexes[j][i] = i;
            }else if (i < s.size() - 1){
                // cout << "j" << j << endl;
                next_indexes[j][i] = next_indexes[j][i+1];
            }
        }
    }
    // for(int i = 0;i < s.size();i++){
    //     for(int j = 0;j < 26;j++){
    //         cout << next_indexes[j][i];
    //     }
    //     cout << endl;
    // }
    // cout << "a" << endl;
    ll t_current = 0;
    ll count = 0;
    while(t_current < t.size()){
        count++;
        ll s_current = 0;
        // cout << t_current << t[t_current] << t[t_current] - 'a' << endl;
        // cout << next_indexes[t[t_current] - 'a'][s_current] << endl;
        while(t_current < t.size() && s_current < s.size() && next_indexes[t[t_current] - 'a'][s_current] != -1){
            // cout << t_current << "," << next_indexes[t[t_current] - 'a'][s_current] << endl;
            s_current = next_indexes[t[t_current] - 'a'][s_current] + 1;
            t_current++;
        }
        if (s_current == 0){
            break;
        }
    }
    if (t_current == t.size()){
        cout << count << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    long long T;
    cin >> T;
    for(int i = 0;i< T;i++){
        solve();
    }

    return 0;
}