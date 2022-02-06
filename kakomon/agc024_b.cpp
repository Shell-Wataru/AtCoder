#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 2;

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
    UnionFind uf(N);
    vector<bool> visited(N,false);
    for(int i = 0;i < N;i++){
        cin >> A[i];
        A[i]--;
    }
    for(int i = 0;i < N;i++){
        if (A[i] + 1 < N && !visited[A[i]+1]){
            uf.unite(A[i],A[i]+1);
        }
        visited[A[i]] = true;
    }
    int max_size = 0;
    for(int i = 0;i < N;i++){
        max_size = max(max_size,uf.size(A[i]));
    }
    cout << N- max_size << endl;
    return 0;
}