#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    string ans = "";
    ll N;
    cin >> N;
    set<ll> rows;
    ll max_row = -1;
    for(ll i = 30;i >=0;i--){
        ll remain = N - (max(max_row,i)+ 1);
        if(remain >= (1<<i) - 1){
            // cout << i << endl;
            rows.insert(i);
            N -= (1<<i) - 1;
            max_row = max(max_row,i);
        }
    }
    // cout << "remain" << N - (max_row+ 1) << endl;
    bool from_left = true;
    for(int i = 0;i<= max_row;i++){
        if(rows.find(i) != rows.end()){
            for(int j = 0;j< i+ 1;j++){
                if (from_left){
                    ans += to_string(i+1) +  " " + to_string(j+1) + "\n";
                }else{
                    ans += to_string(i+1) +  " " + to_string(i - j+1) + "\n";
                }
            }
            from_left = !from_left;
        }else{
            if(from_left){
                ans+= to_string(i+1) + " 1\n";
            }else{
                ans+= to_string(i+1) + " " + to_string(i+1) + "\n";
            }
        }
    }

    for(int i = 1;i <= N - (max_row+ 1);i++){
        if(from_left){
            ans+= to_string(max_row+1+ i) + " 1\n";
        }else{
            ans+= to_string(max_row+1+ i) + " " + to_string(max_row+1+ i) + "\n";
        }
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i  << ":"<< endl;
        cout << ans << flush;
    }

    return 0;
}