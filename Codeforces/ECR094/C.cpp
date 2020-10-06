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
    string S;
    cin >> S;
    ll x;
    cin >> x;
    string ans;
    string reverse_ans;
    for(int i = 0;i < S.length();i++){
        if (i - x >= 0 && i + x < S.length()){
            if (S[i-x] == '1' && S[i+x] == '1'){
                ans+= '1';
            }else{
                ans+= '0';
            }
        }else if (i - x >= 0){
            if (S[i-x] == '1'){
                ans+= '1';
            }else{
                ans+= '0';
            }
        }else if (i+ x < S.length()){
            if (S[i+x] == '1'){
                ans+= '1';
            }else{
                ans+= '0';
            }
        }else{
            ans += '0';
        }
    }

    for(int i = 0;i < S.length();i++){
        if (i - x >= 0 && i + x < S.length()){
            if (ans[i-x] == '1' || ans[i+x] == '1'){
                reverse_ans+= '1';
            }else{
                reverse_ans+= '0';
            }
        }else if (i - x >= 0){
            if (ans[i-x] == '1'){
                reverse_ans+= '1';
            }else{
                reverse_ans+= '0';
            }
        }else if (i+ x < S.length()){
            if (ans[i+x] == '1'){
                reverse_ans+= '1';
            }else{
                reverse_ans+= '0';
            }
        }else{
            reverse_ans += '0';
        }
    }
    if (reverse_ans == S){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
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
