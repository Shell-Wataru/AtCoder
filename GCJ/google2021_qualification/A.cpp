#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

string solve(){
    ll N;
    cin >> N;
    vector<ll> L(N);
    ll ans = 0;
    for(int i = 0;i < N;i++){
        cin >> L[i];
    }
    for(int i = 0;i < N-1;i++){
        ll min_index = -1;
        ll min_value = numeric_limits<ll>::max();
        for(int j = i;j < N;j++){
            if (L[j] < min_value){
                min_value = L[j];
                min_index = j;
            }
        }
        ans += min_index - i + 1;
        reverse(L.begin()+i,L.begin() + min_index + 1);
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