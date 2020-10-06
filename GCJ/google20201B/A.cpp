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
    bool x_reversed = false;
    bool y_reversed = false;
    char north = 'N';
    char south = 'S';
    char west = 'W';
    char east = 'E';
    if (x < 0){
        x_reversed = true;
        x = - x;
    }
    if (y < 0){
        y_reversed = true;
        y = - y;
    }
    string ans = "";
    while(x > 0 || y > 0){
        cout << x << y << endl;
        if (y & 1 && x & 1){
            return "IMPOSSBLE";
        }else if( !(y & 1) && !(x & 1) ){
            return "IMPOSSBLE";
        }else if(x == 0){
            if(y & 2){
                y = y - 1;
                ans += north;
            }else{
                y = y + 1;
                ans += south;
            }
        }else if (y & 1){
            if(x & 2){
                if(y & 2){
                    y = y + 1;
                    ans += north;
                }else{
                    y = y - 1;
                    ans += south;
                }
            }else{
                if(y & 2){
                    y = y - 1;
                    ans += south;
                }else{
                    y = y + 1;
                    ans += north;
                }
            }
        }else if (x & 1){
            if(y & 2){
                if(x & 2){
                    x = x + 1;
                    ans += east;
                }else{
                    x = x - 1;
                    ans += west;
                }
            }else{
                if(x & 2){
                    x = x - 1;
                    ans += west;
                }else{
                    x = x + 1;
                    ans += east;
                }
            }
        }
        x >>= 1;
        y >>= 1;
    }
    return ans;
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