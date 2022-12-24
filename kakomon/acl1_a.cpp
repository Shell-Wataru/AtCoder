#include <iostream>
#include <map>

using namespace std;
using ll = long long;

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <stack>
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
    ll N;
    cin >> N;
    vector<pair<ll,ll>> points(N);
    vector<ll> x_indeces(N);
    vector<ll> y_indices(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> points[i].first >> points[i].second;
        points[i].first--;
        points[i].second--;
        x_indeces[points[i].first] = i;
        y_indices[points[i].second] = i;
    }
    UnionFind uf(N);
    ll min_y = N;
    ll min_y_index = -1;
    priority_queue<ll> q;
    for(int x = 0;x < N;x++){
        ll i = x_indeces[x];
        ll current_y = points[i].second;
        if (current_y < min_y){
            while(!q.empty() && q.top() < x){
                q.pop();
            }
            if (!q.empty()){
                // cout << "!!" << endl;
                ll j = x_indeces[q.top()];
                uf.unite(i,j);
            }
            for(int y = current_y+1;y < min_y;y++){
                ll j = y_indices[y];
                ll target_x = points[j].first;
                if (x < target_x){
                    uf.unite(i,j);
                    q.push(target_x);
                }
            }

            min_y = current_y;
            min_y_index = i;
        }
    }
    for(int i = 0;i < N;i++){
        cout << uf.size(i) << endl;
    }
    return 0;
}