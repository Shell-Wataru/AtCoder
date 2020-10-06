#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    vector<bool> locked(n);
    for(int i = 0;i < n;i++){
        cin >> A[i];
    }
    for(int i = 0;i < n;i++){
        ll a;
        cin >> a;
        locked[i] = a != 0;
    }
    vector<ll>locked_values;
    vector<ll>unlocked_values;
    for(int i = 0;i < n;i++){
        if (locked[i]){
            locked_values.push_back(A[i]);
        }else{
            unlocked_values.push_back(A[i]);
        }
    }
    sort(unlocked_values.begin(),unlocked_values.end(),greater<ll>());
    vector<ll> ans(n);
    ll locked_index = 0;
    ll unlocked_index = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (locked[i]){
            ans[i] = locked_values[locked_index];
            locked_index++;
        }else{
            ans[i] = unlocked_values[unlocked_index];
            unlocked_index++;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        if(i != 0){
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
