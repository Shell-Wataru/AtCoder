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

int solve()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    vector<ll>sum_a;
    sum_a.push_back(0);
    map<ll,ll> last_sum_index;
    for(int i = 0;i < n;i++){
        cin >> A[i];
        sum_a.push_back(sum_a.back() + A[i]);
    }
    last_sum_index[0] = 0;
    vector<ll> cannot_contains(n,n);
    for(int i = 1;i <= n;i++){
        if(last_sum_index.find(sum_a[i]) != last_sum_index.end()){
            // cout << i << " " << last_sum_index[sum_a[i]] << endl;
            cannot_contains[last_sum_index[sum_a[i]]] = min(cannot_contains[last_sum_index[sum_a[i]]],(ll)i-1);
        }
        last_sum_index[sum_a[i]] = i;
    }
    for(int i = n-2;i >= 0;i--){
        cannot_contains[i] = min(cannot_contains[i+1],cannot_contains[i]);
    }
    ll count = 0;
    for(int i = 0;i < n;i++){
        // cout << i << " " << cannot_contains[i] << endl;
        ll width = cannot_contains[i] - i;
        count += width;
    }
    cout << count << endl;
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}
