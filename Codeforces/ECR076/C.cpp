#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> last_occurs_at(n,-1);

    ll value = -1;
    ll min_distance = BASE_NUM;
    for(int i = 0;i<n;i++){
        ll a;
        cin >> a;
        a--;
        if (last_occurs_at[a] != -1){
            min_distance = min(min_distance,i - last_occurs_at[a] + 1);
        }
        last_occurs_at[a] = i;
    }
    if (min_distance == BASE_NUM){
        cout << -1 << endl;
    }else{
        cout << min_distance << endl;
    }
    return;
}

int main()
{
    // 整数の入力
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        solve();
    }
    return 0;
}
