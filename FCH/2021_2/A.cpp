#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    ll n,m;
    cin >> n >> m;
    map<ll,ll> defaultS;
    map<ll,ll> changedS;
    for(int i = 0;i < m;i++){
        ll s;
        cin >> s;
        defaultS[s]++;
    }
    ll ans = 0;
    ll default_total = m;
    for(int i = 0;i < n;i++){
        map<ll,ll> nextDefaultS;
        map<ll,ll> nextChangedS;
        ll changed_count = 0;
        ll next_default_total = 0;
        for(int j = 0;j < m;j++){
            ll s;
            cin >> s;
            if (changedS.find(s) != changedS.end()){
                nextChangedS[s]++;
                changedS[s]--;
                if (changedS[s] == 0){
                    changedS.erase(s);
                }
            }else if (defaultS.find(s) != defaultS.end()){
                nextDefaultS[s]++;
                defaultS[s]--;
                next_default_total++;
                if (defaultS[s] == 0){
                    defaultS.erase(s);
                }

            }else{
                changed_count++;
                nextChangedS[s]++;
            }

        }
        ans += changed_count - default_total + next_default_total;
        default_total = next_default_total;
        swap(defaultS,nextDefaultS);
        swap(changedS,nextChangedS);
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