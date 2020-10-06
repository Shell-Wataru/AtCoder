#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;

int solve(){
    string s,h;
    cin >> s >> h;
    map<char,int> counts;
    for(auto c:s){
        counts[c] = counts[c] + 1;
    }
    bool can_create = false;
    // cout << h.size() - s.size() << endl;
    for(int i = 0;i + s.size() <= h.size();i++){
        map<char,int> current_counts;
        for(int j = 0;j< s.size();j++){
            // cout << i + j << endl;
            current_counts[h[i+j]] = current_counts[h[i+j]] + 1;
        }
        if (counts == current_counts){
            can_create = true;
            break;
        }
    }
    if (can_create){
        cout << "YES"<<endl;
    }else{
        cout << "NO"<<endl;
    }
    return 0;
};

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for(int i = 0;i<t;i++){
        solve();
    }
   return 0;
}