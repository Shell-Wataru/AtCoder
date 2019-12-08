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

using namespace std;
using ll = long long;

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

template <typename T>
struct MinimumSpanningTreeArborescence
{
  T INF;
  vector<vector<T>> G;
  const int V;
  MinimumSpanningTreeArborescence(int V) : INF(numeric_limits<T>::max()), V(V), G(V,vector<T>(V,INF)){}

  T build(int start)
  {
    UnionFind uf(V);
    vector<int> used(V, -1);
    used[start] = start;

    T ret = 0;
    for (int s = 0; s < V; s++)
    {
      stack<int> path;
      for (int u = s; used[u] < 0;)
      {
        auto itr = min_element(G[u].begin(), G[u].end());
        T cost = *itr;
        ret += cost;
        if (cost != 0)
        {
          for (int i = 0; i < V; i++)
          {
            if (G[u][i] != INF)
            {
              G[u][i] -= cost;
            }
          }
        }
        *itr = INF;
        path.push(u);
        used[u] = s;
        int v = uf.find(itr - G[u].begin());
        if (used[v] == s)
        {
          int w;
          vector<T> nextEdges(V, INF);
          do
          {
            w = path.top();
            path.pop();
            for (int i = 0; i < V; i++)
            {
              nextEdges[i] = min(nextEdges[i], G[w][i]);
            }
          } while (uf.unite(v, w));
          int root = uf.find(v);
          for (int i = 0; i < V; i++)
          {
            if (uf.same(root,i))
            {
              G[root][i] = INF;
            }else{
              G[root][i] = nextEdges[i];
            }
          }

          used[root] = -1;
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
    int index = -1;
    vector<int> position;

    ll distance(Point &q)
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
    void nnSearchRecursive(Point &query, Node *node, Node *&nearestNode, ll *minDistance)
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
    int N, M;
    vector<Point> friends;
    vector<Point> spies;
    vector<edge<int>> edges;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        Point p;
        p.index = i;
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
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
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        // cin >> x >> y;
        p.position.push_back(x);
        p.position.push_back(y);
        spies.push_back(p);
    }

    KDTree kdt(spies);
    MinimumSpanningTreeArborescence<int> msta(N+1);
    for (int i = 0; i < N; i++)
    {
        msta.G[i][N] = 1;
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

        for (int j = 0; j < N; j++)
        {
            if (i == j){
                continue;
            }
            ll distance = friends[i].distance(friends[j]);
            if (distance < min_distance)
            {
                msta.G[j][i] = 0;
            }
        }
    }


    // cout << "sss" << endl;
    std::cout << msta.build(N) << endl;
    return 0;
}
