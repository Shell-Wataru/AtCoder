#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <cmath>
using namespace std;
using ll = long long;

string solve()
{
    ll R;
    cin >> R;
    vector<vector<ll>> CorrectCircle(2*R+1,vector<ll>(2*R+1,0));
    vector<vector<ll>> WrongCircle(2*R+1,vector<ll>(2*R+1,0));
    for(int i = 0;i < 2*R+1;i++){
        for(int j = 0;j < 2*R+1;j++){
            ll x = i-R;
            ll y = j-R;
            if (4*(x*x + y*y) <= (2*R + 1)*(2*R + 1)){
                CorrectCircle[i][j] = 1;
            }
        }
    }
    for(int i = 0;i <= R;i++){
        for(int j = 0;j < 2*R+1;j++){
            ll x = j-R;
            ll y = round(sqrt(i*i-x*x));
            WrongCircle[x+R][y+R] = 1;
            WrongCircle[x+R][-y+R] = 1;
            WrongCircle[y+R][x+R] = 1;
            WrongCircle[-y+R][x+R] = 1;
        }
    }
    ll ans = 0;
    for(int i = 0;i < 2*R+1;i++){
        for(int j = 0;j < 2*R+1;j++){
            if (CorrectCircle[i][j] != WrongCircle[i][j]){
                ans++;
            }
        }
    }
    // for(int i = 0;i < 2*R+1;i++){
    //     for(int j = 0;j < 2*R+1;j++){
    //         cout << CorrectCircle[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i = 0;i < 2*R+1;i++){
    //     for(int j = 0;j < 2*R+1;j++){
    //         cout << WrongCircle[i][j];
    //     }
    //     cout << endl;
    // }
    return to_string(ans);
}
int main()
{
    ll T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}