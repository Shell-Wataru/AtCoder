#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    ll x,y;
    cin >> x >> y;
    string S;
    cin >> S;
    ll turn = 0;
    ll clear_turn = -1;
    for(auto c:S){
        turn++;
        if (c == 'N'){
            y++;
        }else if (c == 'S'){
            y--;
        }else if (c == 'E'){
            x++;
        }else if (c == 'W'){
            x--;
        }
        if (abs(x) + abs(y) <= turn){
            clear_turn = turn;
            break;
        }
    }
    if (clear_turn == -1){
        return "IMPOSSIBLE";
    }else{
        return to_string(clear_turn);
    }
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