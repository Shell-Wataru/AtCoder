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
namespace mp = boost::multiprecision;

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    map<ll,ll> counts;
    for(int i = 0; i<N;i++){
      cin >> A[i];
      counts[A[i]]++;
    }
    ll su = 0;
    for(auto p:counts){
      su += p.second * (p.second -1)/2;
    }
    for(int i = 0;i < N;i++){
      ll m = counts[A[i]];
      cout << su - m * (m -1) /2 + (m -1) * (m - 2)/2 << endl;
    }
    return 0;
}