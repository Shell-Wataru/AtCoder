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

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}


int solve()
{
  ll n;
  cin >> n;
  if (n % 2 == 0){
    cout << n/2 << " " << n/2 << endl;
  }else{
    ll max_divide = 1;
    for(ll i = 2;i * i <= n;i++){
      if (n % i == 0){
        max_divide = max(max_divide,i);
        max_divide = max(max_divide,n/i);
      }
    }
    cout << max_divide << " " << n - max_divide << endl;
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
