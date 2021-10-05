#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    ll X,Y;
    cin >> X >> Y;
    string S;
    cin >> S;
    char last_char = '-';
    ll ans = 0;
    for(auto c:S){
        if (c == '?'){
            continue;
        }
        if (last_char == 'C' && c == 'J'){
            ans += X;
        }
        if (last_char == 'J' && c == 'C'){
            ans += Y;
        }
        last_char = c;
    }
    return to_string(ans);
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