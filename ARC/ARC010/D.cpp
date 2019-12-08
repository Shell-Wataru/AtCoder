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
// https://ei1333.github.io/luzhiled/snippets/graph/chu-liu-edmond.html
template <typename T>
struct edge
{
    int src, to;
    T cost;

    edge(int to, T cost) : src(-1), to(to), cost(cost) {}

    edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

    edge &operator=(const int &x)
    {
        to = x;
        return *this;
    }

    operator int() const { return to; }
};

template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnWeightedGraph = vector<vector<int>>;
template <typename T>
using Matrix = vector<vector<T>>;

struct UnionFind
{
    vector<int> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    bool same(int x, int y)
    {
        x = find(x), y = find(y);
        return x == y;
    }
    int find(int k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k)
    {
        return (-data[find(k)]);
    }
};

template <typename T, typename E = T>
struct SkewHeap
{
    using G = function<T(T, E)>;
    using H = function<E(E, E)>;

    struct Node
    {
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

    Node *propagate(Node *t)
    {
        if (t->lazy != 0)
        {
            if (t->l)
                t->l->lazy = h(t->l->lazy, t->lazy);
            if (t->r)
                t->r->lazy = h(t->r->lazy, t->lazy);
            t->key = g(t->key, t->lazy);
            t->lazy = 0;
        }
        return t;
    }

    Node *merge(Node *x, Node *y)
    {
        if (!x || !y)
            return x ? x : y;
        propagate(x), propagate(y);
        if ((x->key > y->key) ^ rev)
            swap(x, y);
        x->r = merge(y, x->r);
        swap(x->l, x->r);
        return x;
    }

    void push(Node *&root, const T &key)
    {
        root = merge(root, new Node({key, 0, nullptr, nullptr}));
    }

    T top(Node *root)
    {
        return propagate(root)->key;
    }

    T pop(Node *&root)
    {
        T top = propagate(root)->key;
        auto *temp = root;
        root = merge(root->l, root->r);
        delete temp;
        return top;
    }

    bool empty(Node *root) const
    {
        return !root;
    }

    void add(Node *root, const E &lazy)
    {
        if (root)
        {
            root->lazy = h(root->lazy, lazy);
            propagate(root);
        }
    }

    Node *makeheap()
    {
        return nullptr;
    }
};

template <typename T>
struct MinimumSpanningTreeArborescence
{
    using Pi = pair<T, int>;
    using Heap = SkewHeap<Pi, int>;
    using Node = typename Heap::Node;
    const Edges<T> &es;
    const int V;
    T INF;

    MinimumSpanningTreeArborescence(const Edges<T> &es, int V) : INF(numeric_limits<T>::max()), es(es), V(V) {}

    T build(int start)
    {
        auto g = [](const Pi &a, const T &b) { return Pi(a.first + b, a.second); };
        auto h = [](const T &a, const T &b) { return a + b; };
        Heap heap(g, h);
        vector<Node *> heaps(V, heap.makeheap());
        cout << "heap inserting..." << endl;
        for (auto &e : es)
            heap.push(heaps[e.to], {e.cost, e.src});
        cout << "heap inserted" << endl;
        UnionFind uf(V);
        vector<int> used(V, -1);
        used[start] = start;

        T ret = 0;
        for (int s = 0; s < V; s++)
        {
            stack<int> path;
            for (int u = s; used[u] < 0;)
            {
                path.push(u);
                used[u] = s;
                if (heap.empty(heaps[u]))
                    return -1;
                auto p = heap.top(heaps[u]);
                ret += p.first;
                heap.add(heaps[u], -p.first);
                heap.pop(heaps[u]);
                int v = uf.find(p.second);
                if (used[v] == s)
                {
                    int w;
                    Node *nextheap = heap.makeheap();
                    do
                    {
                        w = path.top();
                        path.pop();
                        nextheap = heap.merge(nextheap, heaps[w]);
                    } while (uf.unite(v, w));
                    heaps[uf.find(v)] = nextheap;
                    used[uf.find(v)] = -1;
                }
                u = uf.find(v);
            }
        }
        return ret;
    }
};

class Point
{
public:
    ll index = -1;
    vector<ll> position;

    ll distance(Point q)
    {
        ll dist = 0;
        for (size_t i = 0; i < position.size(); i++)
        {
            ll d = position[i] - q.position[i];
            dist += d * d;
        }
        return dist;
    }
};

//zero indexed and vector
class KDTree
{
private:
    /** @brief k-d tree node.
		*/
    struct Node
    {
        Point p;
        Node *left = nullptr;
        Node *right = nullptr;
        int depth = -1;
        int axis = -1; //!< dimension's axis
    };

    Node *buildRecursive(typename vector<Point>::iterator start_itr, typename vector<Point>::iterator end_itr, ll depth)
    {
        ll npoints = end_itr - start_itr;
        if (npoints <= 0)
            return nullptr;

        const int axis = depth % (*start_itr).position.size();
        const int mid = (npoints - 1) / 2;

        std::nth_element(start_itr, start_itr + mid, end_itr, [&](Point &lhs, Point &rhs) {
            return lhs.position[axis] < rhs.position[axis];
        });

        Node *node = new Node();
        node->axis = axis;
        node->depth = depth;
        node->p = *(start_itr + mid);
        node->left = buildRecursive(start_itr, start_itr + mid, depth + 1);
        node->right = buildRecursive(start_itr + mid + 1, end_itr, depth + 1);
        return node;
    }

public:
    vector<Point> data;
    Node *root = nullptr;
    KDTree(vector<Point> &_data) : data(_data)
    {
        // cout << data[0][1] << endl;
        root = buildRecursive(data.begin(), data.end(), 0);
    }

    Point *nnSearch(Point &query)
    {
        Node *nearestNode = nullptr;

        ll minDistance = (1LL << 62) - 1;
        nnSearchRecursive(query, root, nearestNode, &minDistance);
        if (!nearestNode)
        {
            return nullptr;
        }
        else
        {
            return &nearestNode->p;
        }
    }
    void nnSearchRecursive(Point &query, Node *node, Node* &nearestNode, ll *minDistance)
    {
        if (node == nullptr)
        {
            return;
        }

        ll current_node_distance = query.distance(node->p);

        if (current_node_distance < *minDistance)
        {
            *minDistance = current_node_distance;
            nearestNode = node;
        }

        const int axis = node->axis;
        const int containsInLeft = query.position[axis] < node->p.position[axis];

        if (containsInLeft)
        {
            nnSearchRecursive(query, node->left, nearestNode, minDistance);
        }
        else
        {
            nnSearchRecursive(query, node->right, nearestNode, minDistance);
        }

        const double other_side_minimum = fabs(query.position[axis] - node->p.position[axis]);
        if (other_side_minimum < *minDistance)
        {
            if (containsInLeft)
            {
                nnSearchRecursive(query, node->right, nearestNode, minDistance);
            }
            else
            {
                nnSearchRecursive(query, node->left, nearestNode, minDistance);
            }
        }
    }

    void show()
    {
        if (root != nullptr)
        {
            show(root);
        }
    }
    void show(Node *node)
    {
        cout << "depth:" << node->depth << " position:" << node->p.position[0] << " " << node->p.position[1] << endl;
        if (node->left != nullptr)
        {
            show(node->left);
        }
        if (node->right != nullptr)
        {
            show(node->right);
        }
    }
};

int main()
{
    // 整数の入力
    ll N, M;
    vector<Point> friends;
    vector<Point> spies;
    vector<edge<int>> edges;
    vector<ll> min_distances;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        Point p;
        p.index = i;
        ll x, y;
        scanf("%lld",&x);
        scanf("%lld",&y);
        // cin >> x >> y;
        p.position.push_back(x);
        p.position.push_back(y);
        friends.push_back(p);
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        Point p;
        p.index = i;
        ll x, y;
        scanf("%lld",&x);
        scanf("%lld",&y);
        // cin >> x >> y;
        p.position.push_back(x);
        p.position.push_back(y);
        spies.push_back(p);
    }

    KDTree kdt(spies);

    for (int i = 0; i < N; i++)
    {
        edges.push_back(edge<int>(N, i, 1));
        Point *nearest_spy = kdt.nnSearch(friends[i]);
        ll min_distance;
        if (nearest_spy)
        {
            min_distance = friends[i].distance(*nearest_spy);
        }
        else
        {
            min_distance = (1LL << 62) - 1;
        }
        min_distances.push_back(min_distance);
    }

    for (int i = 0; i < N; i++)
    {
        // cout << min_distance << endl;
        for (int j = i + 1; j < N; j++)
        {
            ll distance = friends[i].distance(friends[j]);
            if (distance < min_distances[i])
            {
                edges.push_back(edge<int>(i, j, 0));
            }

            if (distance < min_distances[j])
            {
                edges.push_back(edge<int>(j, i, 0));
            }

        }
    }
    cout << "sssss" << endl;
    MinimumSpanningTreeArborescence<int> msta(edges, N + 1);
    std::cout << msta.build(N) << endl;
    return 0;
}
