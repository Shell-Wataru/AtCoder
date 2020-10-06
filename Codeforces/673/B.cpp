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
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
  ll n,T;
  cin >> n >> T;
  vector<ll> A(n);
  ll half_count = 0;
  for (size_t i = 0; i < n; i++)
  {
    cin >> A[i];
    if (A[i] * 2 == T){
      half_count++;
    }
  }
  ll initial_half_count = half_count;
  for(int i = 0;i < n;i++){
    if (i !=0){
      cout << " ";
    }
    if (2 * A[i] < T){
      cout << 0;
    }else if(2 * A[i] == T){
      if (2 * half_count <= initial_half_count){
        cout << 0;
      }else{
        cout << 1;
      }
      half_count--;
    }else{
      cout << 1;
    }
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
