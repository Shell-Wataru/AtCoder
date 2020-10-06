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
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n;
    cin >> n;
    vector<ll> A(n);
    ll ones = 0;
    vector<ll> B(n);
    bool sorted = true;
    for(int i = 0;i < n;i++){
      scanf("%lld",&A[i]);
      if (i > 0 && A[i-1] > A[i]){
        sorted = false;
      }
    }

    for(int i = 0;i < n;i++){
      scanf("%lld",&B[i]);
      if (B[i] == 0){
        ones++;
      }
    }

    if (!sorted && (ones == n || ones == 0)){
      cout << "No" << endl;
    }else{
      cout << "Yes" << endl;
    }
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
