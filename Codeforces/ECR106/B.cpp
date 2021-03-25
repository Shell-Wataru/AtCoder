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

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    string S;
    cin >> S;
    bool one_exists = false;
    bool can_make = true;
    for(int i = 1;i < S.length();i++){
        if (!one_exists){
            if (S[i-1] == '0' && S[i] == '0'){
                continue;
            }else if (S[i-1] == '0' && S[i] == '1'){
                continue;
            }else if (S[i-1] == '1' && S[i] == '0'){
                continue;
            }else if (S[i-1] == '1' && S[i] == '1'){
                one_exists = true;
            }
        }else{
            if (S[i-1] == '0' && S[i] == '0'){
                can_make = false;
                break;
            }else if (S[i-1] == '0' && S[i] == '1'){
                continue;
            }else if (S[i-1] == '1' && S[i] == '0'){
                continue;
            }else if (S[i-1] == '1' && S[i] == '1'){
                continue;
            }
        }
    }
    if (can_make){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
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
