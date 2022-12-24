#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

bool is_bigger(string &a,string &b){
    if (a.size() > b.size()){
        return true;
    }else if (a.size() < b.size()){
        return false;
    }else{
        for(int i = 0;i < a.size();i++){
            if (a[i] - b[i] > 0){
                return true;
            }else if (a[i] - b[i] < 0){
                return false;
            }
        }
        return false;
    }
}
string solve(){
    string S;
    cin >> S;
    string ans;
    vector<pair<char,ll>> runlength;
    for(auto c:S){
        if (runlength.empty() || runlength.back().first != c){
            runlength.push_back({c,1});
        }else{
            runlength[runlength.size()-1].second++;
        }
    }
    for(int i = 0;i < runlength.size()-1;i++){
        // cout << runlength[i].first << " " << runlength[i].second << endl;
        if(runlength[i].first < runlength[i+1].first){
            for(int j = 0;j < 2*runlength[i].second;j++){
                ans += runlength[i].first;
            }
        }else{
            for(int j = 0;j < runlength[i].second;j++){
                ans += runlength[i].first;
            }
        }
    }
    for(int j = 0;j < runlength.back().second;j++){
        ans += runlength.back().first;
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
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}