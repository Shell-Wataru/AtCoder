#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve()
{
    string S;
    ll N;
    cin >> N;
    cin >> S;
    bool enoughLength = N >= 7;
    bool containsUpper = false;
    bool containsLower = false;
    bool containsDigit = false;
    bool containsSpecial = false;
    for(auto c:S){
        if ( 0 <= c - 'a' && c - 'a' < 26 ){
            containsLower = true;
        }
        if ( 0 <= c - 'A' && c - 'A' < 26 ){
            containsUpper = true;
        }
        if ( 0 <= c - '0' && c - '0' < 10 ){
            containsDigit = true;
        }
        if (c == '#' || c == '@' || c == '*'  || c == '&' ){
            containsSpecial = true;
        }
    }
    if (!containsLower){
        S += 'a';
    }
    if (!containsUpper){
        S += 'A';
    }
    if (!containsDigit){
        S += '1';
    }
    if (!containsSpecial){
        S += '@';
    }
    for(int i = S.length();i < 7;i++){
        S += '0';
    }
    return S;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}