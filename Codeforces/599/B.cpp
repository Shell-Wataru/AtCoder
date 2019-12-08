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
ll BASE_NUM = 1000000007;
int solve(){
    ll n;
    string s,t;
    cin >> n;
    cin >> s >> t;
    map<pair<char,char>,ll> counts;
    for(int i = 0; i< n;i++){
        if (s[i] != t[i]){
            counts[make_pair(s[i],t[i])]++;
        }
    }
    if (counts.size() > 1){
        cout <<  "NO" << endl;
    }else if ((*counts.begin()).second != 2){
        cout <<  "NO" << endl;
    }else{
        cout <<  "YES" << endl;
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for(int i=0;i<t;i++){
        solve();
    }
   return 0;
}
