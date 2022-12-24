#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
#include <unordered_set>

using namespace std;
using ll = long long;

int main()
{
    string s = "g";
    ll n = s.size();
    cout << n << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            string ans;
            cin >> ans;
            cerr << ans << endl;
            break;
        }else{
            ll t;
            cin >> t;
            if (t == 1){
                ll i;
                cin >> i;
                i--;
                cout << s[i] << endl;
            }else{
                ll l,r;
                cin >> l >> r;
                l--;
                unordered_set<char> ss;
                for(int i = l;i < r;i++){
                    ss.insert(s[i]);
                }
                cout << ss.size() << endl;
            }
        }
    }
    return 0;
}
