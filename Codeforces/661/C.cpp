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
    scanf("%lld", &n);
    vector<ll> A(n);
    for (size_t i = 0; i < n; i++)
    {
      cin >> A[i];
    }
    sort(A.begin(),A.end());
    vector<ll> candidates;
    for(int i = 0;i < n;i++){
      for (size_t j = i+1; j < n; j++)
      {
        candidates.push_back(A[i] + A[j]);
      }
    }
    ll max_total =0 ;
    for(auto s:candidates){
      ll i = 0;
      ll j = n-1;
      ll total = 0;
      while(i < j){
        if (A[i] + A[j] == s){
          total++;
          i++;
          j--;
        }else if(A[i] + A[j] > s){
          j--;
        }else if (A[i] + A[j] < s){
          i++;
        }
      }
      max_total = max(max_total,total);
    }
    cout << max_total << endl;
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
    // cout << flush;
    return 0;
}
