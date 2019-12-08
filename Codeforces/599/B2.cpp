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
    map<char,ll> counts;
    for(int i = 0; i< n;i++){
        counts[s[i]]++;
        counts[t[i]]++;
    }

    bool can_clear = true;
    for(auto p:counts){
        if (p.second % 2 == 1){
            can_clear = false;
        }
    }

    if (!can_clear){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        vector<pair<ll,ll>> changes;
        for(int i = 0; i< n;i++){
            if (s[i] == t[i]){
                continue;
            }
            bool changed = false;
            for(int j = i+1;j<n;j++){
                if (s[i] == s[j]){
                    changes.push_back(make_pair(j,i));
                    s[j] = t[i];
                    t[i] = s[i];
                    changed = true;
                    break;
                }
            }
            if (changed){
                continue;
            }

            for(int j = i+1;j<n;j++){
                if (s[i] == t[j]){
                    changes.push_back(make_pair(i+1,j));
                    changes.push_back(make_pair(i+1,i));
                    t[j] = s[i+1];
                    s[i+1] = t[i];
                    t[i] = s[i];
                    changed = true;
                    break;
                }
            }
        }
        cout << changes.size() << endl;
        for(auto p:changes){
            cout << p.first + 1 << " " << p.second + 1<< endl;
        }

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
