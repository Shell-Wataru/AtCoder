#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    ll N,D;
    cin >> N >> D;
    vector<ll> X(N);
    for(int i = 0;i< N;i++){
        cin >> X[i];
    }
    ll ans = D;
    for(int i = N-1;i>=0;i--){
        ans = ans - ans % X[i];
    }
    return to_string(ans);;
}
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i  << ":"<< ans << endl;
    }

    return 0;
}