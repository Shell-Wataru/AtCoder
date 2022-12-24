#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    scanf("%lld",&n);
    string s;
    cin >> s;
    set<ll> wants_win;
    for(int i = 0;i < n;i++){
        if (s[i] == '1'){
            continue;
        }else{
            wants_win.insert(i);
        }
    }
    if (wants_win.size() == 2 || wants_win.size() == 1){
        cout << "NO\n";
    }else{
        cout << "YES\n";
        for(int i = 0;i < n;i++){
            if (s[i] == '1'){
                for(int j = 0;j < n;j++){
                    if (i == j){
                        cout << "X";
                    }else{
                        cout << "=";
                    }
                }
                cout << "\n";
            }else{
                auto win_iter = wants_win.find(i);
                win_iter++;
                if (win_iter == wants_win.end()){
                    win_iter = wants_win.begin();
                }
                auto lose_iter = wants_win.find(i);
                if (lose_iter == wants_win.begin()){
                    lose_iter = wants_win.end();
                }
                lose_iter--;
                for(int j = 0;j < n;j++){
                    if (i == j){
                        cout << "X";
                    }else if(j == *win_iter){
                        cout << "+";
                    }else if (j == *lose_iter){
                        cout << "-";
                    }else{
                        cout << "=";
                    }
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
