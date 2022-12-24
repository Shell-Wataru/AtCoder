#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
using ll = long long;

string solve()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<string> ans;
    for(int i = 0;i < 1ll<<10;i++){
        string c = string(10,'*');
        for(int j = 0;j < 10;j++){
            if (i & 1ll<<j){
                c[j] = '-';
            }else{
                c[j] = '.';
            }
        }
        if (S.substr(0,min((int)S.size(),10)) != c.substr(0,min((int)S.size(),10))){
            ans.push_back(c);
            if (ans.size() == N -1){
                break;
            }
        }
    }
    string ans_string;
    for(auto c:ans){
        ans_string += c + "\n";
    }
    return ans_string;
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": \n" << ans;
    }
    cout << flush;
    return 0;
}
