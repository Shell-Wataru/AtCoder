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
#include <stack>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

template< typename T >
struct Compress {
  vector< T > xs;

  Compress() = default;

  Compress(const vector< T > &vs) {
    add(vs);
  }

  Compress(const initializer_list< vector< T > > &vs) {
    for(auto &p : vs) add(p);
  }

  void add(const vector< T > &vs) {
    copy(begin(vs), end(vs), back_inserter(xs));
  }

  void add(const T &x) {
    xs.emplace_back(x);
  }

  void build() {
    sort(begin(xs), end(xs));
    xs.erase(unique(begin(xs), end(xs)), end(xs));
  }

  vector< int > get(const vector< T > &vs) const {
    vector< int > ret;
    transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
      return lower_bound(begin(xs), end(xs), x) - begin(xs);
    });
    return ret;
  }

  int get(const T &x) const {
    return lower_bound(begin(xs), end(xs), x) - begin(xs);
  }

  const T &operator[](int k) const {
    return xs[k];
  }
};

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    Compress<ll> comp(A);
    comp.build();
    vector<ll> same_next_index(N);
    vector<ll> greater_next_index(N);
    vector<ll> last_occured(N,-1);
    for(int i = N-1;i >= 0;i--){
        last_occured[comp.get(A[i])] = i;
    }
    for(int i = N-1;i >= 0;i--){
        same_next_index[i] = last_occured[comp.get(A[i])];
        greater_next_index[i] = last_occured[comp.get(A[i])+1];
        last_occured[comp.get(A[i])] = i;
    }
    ll move_count = 1;
    ll round_count = 0;
    vector<bool> visited(N,false);
    ll current = last_occured[0];
    visited[current] = true;
    while(move_count < N){
        ll next = -1;;
        if (!visited[same_next_index[current]]){
            next = same_next_index[current];
        }else{
            next = greater_next_index[current];
        }
        if (next < current){
            round_count++;
        }
        move_count++;
        current = next;
        visited[current] = true;
    }
    if (current == 0){
        cout << round_count << endl;
    }else{
        cout << round_count + 1<< endl;
    }

    return 0;
}