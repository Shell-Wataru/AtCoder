#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

int solve(){
    ll R,C;
    cin >> R >> C;
    vector<string> ans(2*R+1,string(2*C+1,'.'));
    for(int i = 0;i < 2*R+1;i++){
        for(int j = 0;j < 2*C+1;j++){
            if (i % 2 == 0 && j % 2 == 0){
                ans[i][j] = '+';
            }else if (i % 2 == 0){
                ans[i][j] = '-';
            }else if (j % 2 == 0){
                ans[i][j] = '|';
            }
        }
    }
    ans[0][0] = '.';
    ans[0][1] = '.';
    ans[1][0] = '.';
    for(auto a:ans){
        cout << a << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {

        cout << "Case #" << i << ":"  << endl;
        solve();
    }

    return 0;
}