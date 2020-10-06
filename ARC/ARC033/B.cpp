#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

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

int main()
{
    // 整数の入力
    vector<string> G(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> G[i];
    }
    UnionFind uf(100);
    for (int i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            if (G[i][j] == 'o')
            {
                if (i > 0 && G[i - 1][j] == 'o')
                {
                    uf.unite(10 * i + j, 10 * (i - 1) + j);
                }

                if (j > 0 && G[i][j - 1] == 'o')
                {
                    uf.unite(10 * i + j, 10 * i + j - 1);
                }
            }
        }
    }

    set<ll> unique_islands;
    for (int i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            if (G[i][j] == 'o')
            {
                unique_islands.insert(uf.find(10*i+j));
            }
        }
    }
    // cout << unique_islands.size() << endl;
    vector<pair<ll,ll>> directions = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };
    bool can_make = false;
    for (int i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 10; j++)
        {
            set<ll> neighbors;
            for(auto d:directions){
                if(0 <= i + d.first && i + d.first < 10 && 0 <= j + d.second && j + d.second < 10){
                    if(G[i+ d.first][j+d.second] == 'o'){
                        neighbors.insert(uf.find(10*(i+ d.first) + j + d.second));
                    }
                }
            }
            if (neighbors.size() == unique_islands.size()){
                can_make =true;
            }
        }
    }
    if (can_make){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}