#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
using namespace std;
using ll = long long;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  for(int i = 0;i < N;i++){
      cin >> A[i] >> B[i];
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  ll x = A[N/2];
  ll y = B[N/2];
  ll ans = 0;
  for(int i = 0;i < N;i++){
      ans += abs(A[i]-x);
      ans += abs(B[i]-y);
  }
  cout << ans << endl;
  return 0;
}
