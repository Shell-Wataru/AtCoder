#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    string S;
    string SS = "";
    cin >> S;
    ll depth = 0;
    for(int i = 0;i < S.size();i++){
        ll new_d = S[i] - '0';
        if (new_d > depth){
            for(int j = 0;j < new_d - depth;j++){
                SS += '(';
            }
        }else if (new_d < depth){
            for(int j = 0;j < depth - new_d;j++){
                SS += ')';
            }
        }
        SS += S[i];
        depth = new_d;
    }
    for(int j = 0;j < depth;j++){
        SS += ')';
    }
    return SS;
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