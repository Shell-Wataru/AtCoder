#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    // cout << "==" << endl;
    ll n,m;
    string S;
    cin >> S;
    ll cur = 0;
    ll min_cur = 0;
    ll ans = 0;
    for(int i = 0;i < S.length();i++){
        if (S[i] == '+'){
            cur++;
        }else{
            cur--;
        }
        if (cur < min_cur){
            min_cur = cur;
            ans += i + 1;
        }
    }
    ans += S.length();
    cout << ans << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
