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
#include <unordered_map>

using namespace std;
using ll = long long;

int main()
{
  ll N;
  cin >> N;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  ll g = 0;
  for(int i = 1;i < N;i++){
    g = gcd(g,abs((A[i]-A[0])-(A[N-1]-A[i])));
  }
  cout << (A[N-1]-A[0]) + A[0] % g << endl;
  return 0;
}
