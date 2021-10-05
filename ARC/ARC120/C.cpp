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

class BIT
{
public:
  vector<ll> data;
  BIT(long long n) : data(n) {}
  void add(int index, long long v)
  {
    int N = data.size();
    for (int i = index; i < N; i |= i + 1)
    {
      data[i] += v;
    }
  }

  long long sum(int index)
  {
    long long retValue = 0;
    int i;
    for (i = index; i >= 0; i = (i & (i + 1)) - 1)
    {
      retValue += data[i];
    }
    return retValue;
  }

  void show()
  {
    for (auto v : data)
    {
      cout << v << endl;
    }
  }
};

int main()
{
  ll N;
  cin >> N;
  map<ll, vector<ll>> a_indexes;
  map<ll, vector<ll>> b_indexes;
  for (int i = 0; i < N; i++)
  {
    ll a;
    cin >> a;
    a_indexes[a + i].push_back(i);
  }
  for (int i = 0; i < N; i++)
  {
    ll b;
    cin >> b;
    b_indexes[b + i].push_back(i);
  }
  vector<ll> ans_a_indexes(N);
  for (auto p : a_indexes)
  {
    if (p.second.size() != b_indexes[p.first].size())
    {
      cout << -1 << endl;
      return 0;
    }
    for (int i = 0; i < p.second.size(); i++)
    {
      ans_a_indexes[p.second[i]] = b_indexes[p.first][i];
    }
  }
  BIT bit(N);
  ll ans = 0;
  for (int i = 0; i < N; i++)
  {
    ans += i - bit.sum(ans_a_indexes[i]);
    bit.add(ans_a_indexes[i], 1);
  }
  cout << ans << endl;
  return 0;
}