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
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }
    sort(A.begin(),A.end());
    vector<ll> Ans;
    ll i = 0;
    ll j = n -1;
    while(i < j){
        Ans.push_back(A[j]);
        Ans.push_back(A[i]);
        i++;
        j--;
    }
    if (i == j){
        Ans.push_back(A[i]);
    }
    cout << (n-1)/2 << endl;
    for(int i = 0;i < n;i++){
        if (i!= 0){
            cout << " ";
        }
        cout << Ans[i];
    }
    cout << endl;
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
    // cout << flush;
    return 0;
}
