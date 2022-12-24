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
#include <set>
using namespace std;
using ll = long long;

template <typename T>
struct Compress
{
    vector<T> xs;

    Compress() = default;

    Compress(const vector<T> &vs)
    {
        add(vs);
    }

    Compress(const initializer_list<vector<T>> &vs)
    {
        for (auto &p : vs)
            add(p);
    }

    void add(const vector<T> &vs)
    {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x)
    {
        xs.emplace_back(x);
    }

    void build()
    {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector<int> get(const vector<T> &vs) const
    {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x)
                  { return lower_bound(begin(xs), end(xs), x) - begin(xs); });
        return ret;
    }

    int get(const T &x) const
    {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    size_t size() const
    {
        return xs.size();
    }
    const T &operator[](int k) const
    {
        return xs[k];
    }
};

int solve()
{
    ll H,W,N;
    cin >> H >> W >> N;
    ll sx,sy,gx,gy;
    cin >> sx >> sy >> gx >> gy;
    vector<pair<ll,ll>> points(N);
    map<pair<ll,ll>,ll> distances;
    Compress<ll> CX;
    Compress<ll> CY;
    CX.add(sx);
    CY.add(sy);
    for(int i = 0;i < N;i++){
        ll x,y;
        cin >> x >> y;
        points[i] = {x,y};
        CX.add(x+1);
        CX.add(x);
        CX.add(x-1);
        CY.add(y+1);
        CY.add(y);
        CY.add(y-1);
    }
    CX.build();
    CY.build();
    vector<vector<ll>> RowData(CX.size());
    vector<vector<ll>> ColumnData(CY.size());
    for(auto p:points){
        RowData[CX.get(p.first)].push_back(p.second);
        ColumnData[CY.get(p.second)].push_back(p.first);
    }
    for(int i = 0;i < CX.size();i++){
        sort(RowData[i].begin(),RowData[i].end());
    }
    for(int i = 0;i < CY.size();i++){
        sort(ColumnData[i].begin(),ColumnData[i].end());
    }
    queue<vector<ll>> q;
    q.push({sx,sy,0});
    distances[{sx,sy}] = 0;
    while (!q.empty())
    {
        ll x = q.front()[0];
        ll y = q.front()[1];
        ll d = q.front()[2];
        q.pop();
        auto iter_x = lower_bound(RowData[CX.get(x)].begin(),RowData[CX.get(x)].end(),y);
        if (iter_x != RowData[CX.get(x)].end()){
            ll next_y = (*iter_x) - 1;
            if (distances.find({x,next_y}) == distances.end()){
                q.push({x,next_y,d+1});
                distances[{x,next_y}] = d+1;
            }
        }
        if (iter_x != RowData[CX.get(x)].begin()){
            iter_x--;
            ll next_y = (*iter_x) + 1;
            if (distances.find({x,next_y}) == distances.end()){
                q.push({x,next_y,d+1});
                distances[{x,next_y}] = d+1;
            }
        }

        auto iter_y = lower_bound(ColumnData[CY.get(y)].begin(),ColumnData[CY.get(y)].end(),x);
        if (iter_y != ColumnData[CY.get(y)].end()){
            ll next_x = (*iter_y) - 1;
            if (distances.find({next_x,y}) == distances.end()){
                q.push({next_x,y,d+1});
                distances[{next_x,y}] = d+1;
            }
        }
        if (iter_y != ColumnData[CY.get(y)].begin()){
            iter_y--;
            ll next_x = (*iter_y) + 1;
            if (distances.find({next_x,y}) == distances.end()){
                q.push({next_x,y,d+1});
                distances[{next_x,y}] = d+1;
            }
        }
    }
    if (distances.find({gx,gy}) == distances.end()){
        cout << -1 << endl;
    }else{
        cout << distances[{gx,gy}] << endl;
    }
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // while(T--){
    solve();
    // }
    return 0;
}
