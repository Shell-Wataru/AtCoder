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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
  ll N;
  cin >> N;
  vector<pair<ll,ll>> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i].first;
    A[i].second = i;
  }
  ll total = 0;
  sort(A.rbegin(),A.rend());
  vector<bool> takes(N,false);
  for (int i = 0; i < N/2; i++)
  {
    total += A[i].first;
    takes[A[i].second] = true;
  }
  ll current  = 0;
  ll maximum = -1;
  ll maximum_index = -1;
  for (int i = 0; i < N; i++)
  {
    if (takes[i]){
      current += 1;
    }else{
      current -= 1;
    }
    if (current > maximum){
      maximum = current;
      maximum_index = i;
    }
  }
  cout << (maximum_index + 1) % N << endl;
  cout << total << endl;
  return 0;
}
