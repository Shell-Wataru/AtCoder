#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
#include <stack>
using namespace std;
using ll = long long;
// https://ei1333.github.io/luzhiled/snippets/graph/chu-liu-edmond.html
template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};


template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

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

template< typename T, typename E = T >
struct SkewHeap {
  using G = function< T(T, E) >;
  using H = function< E(E, E) >;

  struct Node {
    T key;
    E lazy;
    Node *l, *r;
  };

  const bool rev;
  const G g;
  const H h;

  SkewHeap(bool rev = false) : g([](const T &a, const E &b) { return a + b; }),
                               h([](const E &a, const E &b) { return a + b; }), rev(rev) {}

  SkewHeap(const G &g, const H &h, bool rev = false) : g(g), h(h), rev(rev) {}

  Node *propagate(Node *t) {
    if(t->lazy != 0) {
      if(t->l) t->l->lazy = h(t->l->lazy, t->lazy);
      if(t->r) t->r->lazy = h(t->r->lazy, t->lazy);
      t->key = g(t->key, t->lazy);
      t->lazy = 0;
    }
    return t;
  }

  Node *merge(Node *x, Node *y) {
    if(!x || !y) return x ? x : y;
    propagate(x), propagate(y);
    if((x->key > y->key) ^ rev) swap(x, y);
    x->r = merge(y, x->r);
    swap(x->l, x->r);
    return x;
  }

  void push(Node *&root, const T &key) {
    root = merge(root, new Node({key, 0, nullptr, nullptr}));
  }

  T top(Node *root) {
    return propagate(root)->key;
  }

  T pop(Node *&root) {
    T top = propagate(root)->key;
    auto *temp = root;
    root = merge(root->l, root->r);
    delete temp;
    return top;
  }

  bool empty(Node *root) const {
    return !root;
  }

  void add(Node *root, const E &lazy) {
    if(root) {
      root->lazy = h(root->lazy, lazy);
      propagate(root);
    }
  }

  Node *makeheap() {
    return nullptr;
  }
};

template< typename T >
struct MinimumSpanningTreeArborescence
{
  using Pi = pair< T, int >;
  using Heap = SkewHeap< Pi, int >;
  using Node = typename Heap::Node;
  const Edges< T > &es;
  const int V;
  T INF;

  MinimumSpanningTreeArborescence(const Edges< T > &es, int V) :
      INF(numeric_limits< T >::max()), es(es), V(V) {}

  T build(int start)
  {
    auto g = [](const Pi &a, const T &b) { return Pi(a.first + b, a.second); };
    auto h = [](const T &a, const T &b) { return a + b; };
    Heap heap(g, h);
    vector< Node * > heaps(V, heap.makeheap());
    for(auto &e : es) heap.push(heaps[e.to], {e.cost, e.src});
    UnionFind uf(V);
    vector< int > used(V, -1);
    used[start] = start;

    T ret = 0;
    for(int s = 0; s < V; s++) {
      stack< int > path;
      for(int u = s; used[u] < 0;) {
        path.push(u);
        used[u] = s;
        if(heap.empty(heaps[u])) return -1;
        auto p = heap.top(heaps[u]);
        ret += p.first;
        heap.add(heaps[u], -p.first);
        heap.pop(heaps[u]);
        int v = uf.find(p.second);
        if(used[v] == s) {
          int w;
          Node *nextheap = heap.makeheap();
          do {
            w = path.top();
            path.pop();
            nextheap = heap.merge(nextheap, heaps[w]);
          } while(uf.unite(v, w));
          heaps[uf.find(v)] = nextheap;
          used[uf.find(v)] = -1;
        }
        u = uf.find(v);
      }
    }
    return ret;
  }
};

int main()
{
    vector<edge<int>> edges{
        {0, 1, 1},
        {0, 2, 1},
        {0, 3, 0},
        {1, 2, 1},
        {1, 3, 0},
        {2, 3, 0},
    };
    MinimumSpanningTreeArborescence<int> msta(edges, 4);
    cout << msta.build(0) << endl;
    return 0;
}
