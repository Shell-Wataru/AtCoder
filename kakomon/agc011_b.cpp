#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (size_t i = 0; i < N; i++)
  {
      cin >> A[i];
  }

  sort(A.begin(),A.end());
  vector<ll> Sum(N);
  Sum[0] = A[0];
  for(int i = 1;i < N;i++){
      Sum[i] += Sum[i-1] + A[i];
  }
  ll ans = 1;
  for(int i = N-2;i >=0;i--){
    if (A[i+1] > 2 *Sum[i]){
        break;
    }
    ans++;
  }
  cout << ans << endl;
 return 0;
}