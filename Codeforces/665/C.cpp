#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    scanf("%lld", &n);
    vector<ll> A(n);
    ll min_val = numeric_limits<ll>::max();
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
        min_val = min(min_val,A[i]);
    }
    vector<ll> can_move;
    for(int i = 0;i < n;i++){
        if (gcd(A[i],min_val) == min_val){
            can_move.push_back(A[i]);
            A[i] = 0;
        }
    }
    sort(can_move.begin(),can_move.end());
    for(int i = n-1;i >=0;i--){
        if (A[i] == 0){
            A[i] = can_move.back();
            can_move.pop_back();
        }
    }
    bool ans = true;
    for(int i = 0;i < n -1;i++){
        if (A[i] > A[i+1]){
            ans = false;
        }
    }
    if (ans){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
        }
    cout << flush;
    return 0;
}
