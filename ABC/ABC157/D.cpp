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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<set<ll>> blocks(N);
    vector<set<ll>> friends(N);
    map<ll,set<ll>> groups;
    UnionFind uf(N);
    for(int i = 0;i< M;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        uf.unite(a,b);
        friends[a].insert(b);
        friends[b].insert(a);
    }

    for(int i = 0;i< K;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        blocks[a].insert(b);
        blocks[b].insert(a);
    }

    for(int i = 0;i < N;i++){
        groups[uf.find(i)].insert(i);
    }

    for(int i = 0;i < N;i++){
        ll count = groups[uf.find(i)].size();
        count--;//じぶん
        for(auto f:friends[i]){
            if(groups[uf.find(i)].find(f) != groups[uf.find(i)].end()){
                count--;
            }
        }

        for(auto b:blocks[i]){
            if(groups[uf.find(i)].find(b) != groups[uf.find(i)].end()){
                count--;
            }
        }
        if (i != 0){
            cout << " ";
        }
        cout << count;
    }
    cout << endl;
    return 0;
}