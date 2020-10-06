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
    ll n;
    string S;
    cin >> S;
    ll ans = BASE_NUM;
    for(int i = 0;i < S.length();i++){
        ll flips = 0;
        for(int j = 0;j < S.length();j++){
            if (j <= i && S[j] == '0'){
                flips++;
            }else if(j > i && S[j] == '1'){
                flips++;
            }
        }
        ans = min(ans,flips);
    }
    for(int i = 0;i < S.length();i++){
        ll flips = 0;
        for(int j = 0;j < S.length();j++){
            if (j <= i && S[j] == '1'){
                flips++;
            }else if(j > i && S[j] == '0'){
                flips++;
            }
        }
        ans = min(ans,flips);
    }
    cout << ans << endl;
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
    return 0;
}
