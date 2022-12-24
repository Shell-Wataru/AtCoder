#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <numeric>

using namespace std;
using ll = long long;

string solve(){
    ll N,X,Y;
    cin >> N >> X >> Y;
    ll g = gcd(X,Y);
    X /= g;
    Y /= g;
    ll total = N*(N+1)/2;
    if (total % (X+Y) == 0){
        ll target = total * X/ (X+Y);
        string ans = "POSSIBLE";
        vector<ll> anss;
        for(int i = N;i >= 1;i--){
            if (target >= i){
                target -= i;
                anss.push_back(i);
            }
        }
        ans += "\n" + to_string(anss.size()) + "\n";
        for(int i = 0;i < anss.size();i++){
            if (i != 0){
                ans += " ";
            }
            ans += to_string(anss[i]);
        }
        return ans;

    }else{
        return "IMPOSSIBLE";
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
        cout << "Case #" << i  << ": "<< ans << endl;
    }

    return 0;
}