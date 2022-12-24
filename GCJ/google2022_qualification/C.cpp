#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;

ll maximum(ll N)
{
    return (N - 1) * (N + 2) / 2;
}
string solve()
{
    ll N;
    cin >> N;
    vector<ll> S(N);
    for(int i = 0;i < N;i++){
        cin >> S[i];
    }
    sort(S.begin(),S.end());
    ll l = 0;
    ll r = 0;
    ll ans = 0;
    for(int i = 0;i < N;i++){
        if (S[i] > ans){
            ans++;
        }
    }
    return to_string(ans);
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