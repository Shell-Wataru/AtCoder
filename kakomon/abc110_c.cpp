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
    string S,T;
    cin >> S >> T;
    vector<ll> s_counts(26,0);
    vector<ll> t_counts(26,0);
    for(auto c:S){
        s_counts[c - 'a']++;
    }
    for(auto c:T){
        t_counts[c - 'a']++;
    }
    sort(s_counts.begin(),s_counts.end());
    sort(t_counts.begin(),t_counts.end());
    if (s_counts == t_counts){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}