#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;

long long find(vector<long long> &unionFindTree, long long N)
{
    if (unionFindTree[N] == N)
    {
        return N;
    }
    else
    {
        return unionFindTree[N] = find(unionFindTree, unionFindTree[N]);
    }
}

bool same(vector<long long> &unionFindTree, long long x, long long y)
{
    return find(unionFindTree, x) == find(unionFindTree, y);
}

void unionTree(vector<long long> &unionFindTree, long long x, long long y)
{
    x = find(unionFindTree, x);
    y = find(unionFindTree, y);
    if (x == y)
        return;
    unionFindTree[x] = y;
}

int main()
{
    // 整数の入力
    long long total, N, minX, minY, maxX, maxY, x, y, i;
    vector<vector<long long>> towns;
    deque<vector<long long>> edges;
    vector<long long> vectorTree;
    total = 0;
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> x >> y;
        vector<long long> a;
        a.push_back(i);
        a.push_back(x);
        a.push_back(y);
        towns.push_back(a);
        vectorTree.push_back(i);
    }

    sort(towns.begin(), towns.end(), [](vector<long long> v1, vector<long long> v2) -> long long {
        return (v1[1] < v2[1]);
    });
    for (i = 1; i < N; i++)
    {
        vector<long long> edge;
        edge.push_back(towns[i][0]);
        edge.push_back(towns[i - 1][0]);
        edge.push_back(towns[i][1] - towns[i - 1][1]);
        edges.push_back(edge);
    }
    sort(towns.begin(), towns.end(), [](vector<long long> v1, vector<long long> v2) -> long long {
        return (v1[2] < v2[2]);
    });
    for (i = 1; i < N; i++)
    {
        vector<long long> edge;
        edge.push_back(towns[i][0]);
        edge.push_back(towns[i - 1][0]);
        edge.push_back(towns[i][2] - towns[i - 1][2]);
        edges.push_back(edge);
    }
    sort(edges.begin(), edges.end(), [](vector<long long> v1, vector<long long> v2) -> long long {
        return (v1[2] < v2[2]);
    });

    while (edges.size() > 0)
    {
        vector<long long> edge = edges[0];
        edges.pop_front();
        if (!same(vectorTree, edge[0], edge[1]))
        {
            unionTree(vectorTree, edge[0], edge[1]);
            total += edge[2];
        }
    }

    cout << total << endl;
    return 0;
}