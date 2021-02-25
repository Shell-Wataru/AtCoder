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
    map<ll,ll,greater<ll>> bigger_number_count;
    map<ll,ll,greater<ll>> smaller_number_count;
    for (size_t i = 0; i < n; i++)
    {
        scanf("%lld",&A[i]);
    }
    sort(A.begin(),A.end(),greater<ll>());
    for(int i = 0;i< (n+1)/2;i++){
        bigger_number_count[A[i]]++;
    }
    for(int i = (n+1)/2;i< n;i++){
        smaller_number_count[A[i]]++;
    }
    vector<ll> Ans;
    for(int i = 0;i < n;i++){
        if (i % 2 == 0){
            ll number = bigger_number_count.begin()->first;
            // cout << number << endl;
            Ans.push_back(number);
            bigger_number_count[number]--;
            if (bigger_number_count[number] == 0){
                bigger_number_count.erase(number);
            }
        }else{
            ll before = Ans.back();
            ll number = smaller_number_count.lower_bound(before-1)->first;
            if (number == 0){
                number = smaller_number_count.begin()->first;
            }
            // cout << number << endl;
            Ans.push_back(number);
            smaller_number_count[number]--;
            if (smaller_number_count[number] == 0){
                smaller_number_count.erase(number);
            }
        }
    }
    ll cheap_count = 0;
    for(int i = 1;i < n-1;i++){
        if (Ans[i] < Ans[i-1] && Ans[i] < Ans[i+1]){
            cheap_count++;
        }
    }
    cout << cheap_count << endl;
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
