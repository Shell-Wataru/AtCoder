#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000000;

pair<ll,ll> position(string &S,ll &current){
    ll x = 0;
    ll y = 0;
    while(current < S.size()){
        // cout << S[current] << S[current] - '0' << endl;
        if(S[current] == 'N'){
            y = (BASE_NUM + y - 1) % BASE_NUM;
        }else if(S[current] == 'S'){
            y = (BASE_NUM + y + 1) % BASE_NUM;
        }else if(S[current] == 'W'){
            x = (BASE_NUM + x - 1) % BASE_NUM;
        }else if(S[current] == 'E'){
            x = (BASE_NUM + x + 1) % BASE_NUM;
        }else if(S[current] - '0' < 10 && S[current] - '0' >= 0){
            ll times = S[current] - '0';
            current += 2;
            pair<ll,ll> p = position(S,current);
            // cout << times << ":" <<p.first << " " << p.second << endl;
            x = (BASE_NUM + x + times * p.first) % BASE_NUM;
            y = (BASE_NUM + y + times * p.second) % BASE_NUM;
        }else if (S[current] == ')'){
            return {x,y};
        }
        current++;
    }
    return {x,y};
}

string solve()
{
    string S;
    cin >> S;
    ll current = 0;
    pair<ll,ll> ans = position(S,current);
    // cout << ans.first << " " << ans.second << endl;
    return to_string(ans.first + 1) + " " + to_string(ans.second + 1);
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