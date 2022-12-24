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
    ll R,C;
    cin >> R >> C;
    vector<string> G(R);
    for(int i = 0;i < R;i++){
        cin >> G[i];
    }

    if (R > 1 && C > 1){
        string ans;
        ans += "Possible\n";
        for(int i = 0;i < R;i++){
            ans += string(C,'^') + "\n";
        }
        return ans;
    }else{
        bool containsTree = false;
        for(auto row:G) {
            for(auto cell:row){
                if (cell == '^'){
                    containsTree = true;
                    break;
                }
            }
        }
        string ans;
        if (containsTree){
            ans += "Impossible\n";
        }else{
            ans += "Possible\n";
            for(int i = 0;i < R;i++){
                ans += string(C,'.') + "\n";
            }
        }
        return ans;
    }
}
int main()
{
    ll T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans;
    }
    cout << flush;
    return 0;
}