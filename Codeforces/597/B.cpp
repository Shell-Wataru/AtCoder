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
    ll n,r,p,s;
    map<char,ll> rps_count;
    cin >> n;
    cin >> r >> p >> s;
    string S;
    cin >> S;
    for(int i = 0;i<n;i++){
        rps_count[S[i]]++;
    }
    ll wins = 0;
    ll r_wins = min(r,rps_count['S']);
    ll p_wins = min(p,rps_count['R']);
    ll s_wins = min(s,rps_count['P']);
    ll r_not_wins = r - r_wins;
    ll p_not_wins = p - p_wins;
    ll s_not_wins = s - s_wins;
    wins+= min(r,rps_count['S']);
    wins+= min(p,rps_count['R']);
    wins+= min(s,rps_count['P']);
    if (wins >= (n+1)/2){
        cout << "YES" << endl;
        for(int i = 0;i< n;i++){
            if (S[i] ==  'S'){
                if (r_wins > 0){
                    r_wins--;
                    cout << 'R';
                }else{
                    if (p_not_wins > 0){
                        p_not_wins--;
                        cout << 'P';
                    }else{
                        s_not_wins--;
                        cout << 'S';
                    }
                }
            }else if (S[i] ==  'R'){
                if (p_wins > 0){
                    p_wins--;
                    cout << 'P';
                }else{
                    if (s_not_wins > 0){
                        s_not_wins--;
                        cout << 'S';
                    }else{
                        r_not_wins--;
                        cout << 'R';
                    }
                }
            }else{
                if (s_wins > 0){
                    s_wins--;
                    cout << 'S';
                }else{
                    if (r_not_wins > 0){
                        r_not_wins--;
                        cout << 'R';
                    }else{
                        p_not_wins--;
                        cout << 'P';
                    }
                }
            }
        }
        cout << endl;
    }else{
        cout << "NO" << endl;
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
