#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    ll U;
    cin >> U;
    map<char,ll> counts;
    set<char> using_chars;
    for(int i = 0;i < 10000;i++){
        string m;
        string r;
        cin >> m >> r;
        for(auto rc:r){
            using_chars.insert(rc);
        }
        counts[r[0]]++;
    }
    vector<pair<ll,char>> descending_order;
    for(auto uc:using_chars){
        descending_order.push_back({counts[uc],uc});
    }
    sort(descending_order.begin(),descending_order.end());
    string ans = "";
    ans += descending_order[0].second;
    ans += descending_order[9].second;
    ans += descending_order[8].second;
    ans += descending_order[7].second;
    ans += descending_order[6].second;
    ans += descending_order[5].second;
    ans += descending_order[4].second;
    ans += descending_order[3].second;
    ans += descending_order[2].second;
    ans += descending_order[1].second;
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
        cout << "Case #" << i  << ": "<< ans << endl;
    }

    return 0;
}