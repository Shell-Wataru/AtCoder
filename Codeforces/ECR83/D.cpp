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
ll BASE_NUM = 998244353;

vector<ll> inverse_array(ll n){
    vector<ll> inverse(n,-1);
    inverse[1] = 1;
    for(int i = 2;i<n;i++){
        inverse[i] = BASE_NUM - inverse[BASE_NUM % i] * (BASE_NUM/i) % BASE_NUM;
    }
    return inverse;
}

ll combination(vector<ll> &factorial, vector<ll> &inverse_factorial, ll n,ll m){
    ll value = factorial[n];
    value = value * inverse_factorial[m] % BASE_NUM;
    value = value * inverse_factorial[n - m] % BASE_NUM;
    return value;
}

ll my_pow(ll x,ll y){
    if (y == 0){
        return 1LL;
    }else if(y == 1){
        return x;
    }else{
        ll y_2 =my_pow(x,y/2) % BASE_NUM;
        ll yy = (y_2 * y_2) % BASE_NUM;
        if (y % 2 == 0){
            return yy;
        }else{
            return (yy * x) % BASE_NUM;
        }
    }
}

int solve(){
  ll n,m;
  cin >> n >> m;
  vector<ll> inverse = inverse_array(m);
  vector<ll> factorial;
  factorial.push_back(1);
  for(int i = 1;i<= m;i++){
      factorial.push_back(factorial[i-1] * i % BASE_NUM);
  }

  vector<ll> inverse_factorial;
  inverse_factorial.push_back(1);
  for(int i = 1;i<= m;i++){
      inverse_factorial.push_back(inverse_factorial[i-1] * inverse[i] % BASE_NUM);
  }
  ll m_C_n = combination(factorial, inverse_factorial,m,n - 1);
  ll totyu = m_C_n * (n - 2) % BASE_NUM;
  // cout << m_C_n << endl;
  cout << totyu * my_pow(2,n - 3) % BASE_NUM << endl;
  return 0;
}

int main()
{
  // ll t;
  // cin >> t;
  // for (size_t i = 0; i < t; i++)
  // {
      solve();
  // }
 return 0;
}