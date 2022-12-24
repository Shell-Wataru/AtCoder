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
#include <unordered_map>
using namespace std;
using ll = long long;

vector<ll> direcrion_x = {1, -1, 0, 0};
vector<ll> direcrion_y = {0, 0, 1, -1};
ll N, K, L;
ll swap_count = 0;
double randDouble()
{
    return 1.0 * rand() / RAND_MAX;
}
struct UnionFind
{
    vector<int> data;
    vector<int> a_sum;
    vector<int> b_sum;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
        a_sum.assign(sz, -1);
        b_sum.assign(sz, -1);
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
        a_sum[x] += a_sum[y];
        b_sum[x] += b_sum[y];
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

    int a(int k)
    {
        return a_sum[find(k)];
    }

    int b(int k)
    {
        return b_sum[find(k)];
    }
};

bool unite(vector<vector<ll>> &Town, UnionFind &uf, ll x1, ll y1, ll x2, ll y2, ll &unite_count, ll &max_unite_count, ll a_target, ll b_target)
{
    ll town = uf.find(Town[x1][y1]);
    ll neighbor_town = uf.find(Town[x2][y2]);
    if (unite_count < max_unite_count &&
        town != 0 && neighbor_town != 0 &&
        town != neighbor_town &&
        uf.a(town) + uf.a(neighbor_town) <= a_target &&
        uf.b(town) + uf.b(neighbor_town) <= a_target &&
        uf.unite(town, neighbor_town))
    {
        unite_count++;
    }
    return true;
}

void set_initial_answer(UnionFind &uf, vector<ll> &answers, vector<ll> &a_sum, vector<ll> &b_sum)
{
    set<ll> mappingBase;
    for (int i = 1; i <= K; i++)
    {
        mappingBase.insert(uf.find(i));
    }
    ll town_id = 1;
    unordered_map<ll, ll> mapping;
    for (auto m : mappingBase)
    {
        mapping[m] = town_id;
        town_id++;
    }
    for (int i = 1; i <= K; i++)
    {
        answers[i] = mapping[uf.find(i)];
    }
    for (int i = 1; i <= K; i++)
    {
        a_sum[mapping[uf.find(i)]] = uf.a(i);
        b_sum[mapping[uf.find(i)]] = uf.b(i);
    }
}
void print_answer(vector<ll> &answers)
{
    for (int i = 1; i <= K; i++)
    {
        cout << answers[i] << "\n";
    }
    cout << flush;
}

bool dfs(vector<vector<ll>> &Town, vector<ll> &answers, ll x, ll y, set<pair<ll, ll>> &visited_positions, ll area_id, ll dont_use_town_id)
{
    if (visited_positions.count({x, y}))
    {
        return true;
    }
    else if (Town[x][y] == dont_use_town_id)
    {
        return true;
    }
    else if (answers[Town[x][y]] != area_id)
    {
        return true;
    }
    visited_positions.insert({x, y});
    for (int i = 0; i < 4; i++)
    {
        ll next_x = x + direcrion_x[i];
        ll next_y = y + direcrion_y[i];
        if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N)
        {
            dfs(Town, answers, next_x, next_y, visited_positions, area_id, dont_use_town_id);
        }
    }
    return true;
}

bool can_remove(vector<vector<ll>> &Town, vector<ll> &answers, ll x, ll y, vector<ll> &can_remove_cache)
{
    if (can_remove_cache[Town[x][y]] == 0)
    {
        // cout << "hit:false" << endl;
        return false;
    }
    else if (can_remove_cache[Town[x][y]] == 1)
    {
        // cout << "hit:true" << endl;
        return true;
    }
    set<pair<ll, ll>> visited_positions;
    ll area_id = answers[Town[x][y]];
    dfs(Town, answers, x, y, visited_positions, area_id, -1);
    pair<ll, ll> other_town = {-1, -1};
    ll other_town_count = 0;
    for (auto p : visited_positions)
    {
        if (Town[p.first][p.second] != Town[x][y])
        {
            other_town = p;
            other_town_count++;
        }
    }
    if (other_town.first == -1)
    {
        if (can_remove_cache[Town[x][y]] == 1)
        {
            cout << "!!A" << endl;
        }
        can_remove_cache[Town[x][y]] = 0;
        return false;
    }
    set<pair<ll, ll>> other_visited_positions;
    dfs(Town, answers, other_town.first, other_town.second, other_visited_positions, area_id, Town[x][y]);
    if (other_town_count == other_visited_positions.size())
    {
        can_remove_cache[Town[x][y]] = 1;
        return true;
    }
    else
    {
        can_remove_cache[Town[x][y]] = 0;
        return false;
    }
}

void insert_town(vector<pair<ll, ll>> &AB, vector<ll> &answers, vector<ll> &a_sum, vector<ll> &b_sum, ll neighbor_town, ll area, ll neighbor_area, vector<ll> &can_remove_cache)
{
    answers[neighbor_town] = area;
    a_sum[area] += AB[neighbor_town].first;
    b_sum[area] += AB[neighbor_town].second;
    a_sum[neighbor_area] -= AB[neighbor_town].first;
    b_sum[neighbor_area] -= AB[neighbor_town].second;
    for (int i = 1; i <= K; i++)
    {
        if (answers[i] == area)
        {
            if (i == neighbor_town)
            {
                can_remove_cache[i] = 1;
            }
            else
            {
                can_remove_cache[i] = -1;
            }
        }
        else if (answers[i] == neighbor_area)
        {
            can_remove_cache[i] = -1;
        }
    }
}
bool swap_if_you_can(vector<vector<ll>> &Town, vector<pair<ll, ll>> &AB, vector<ll> &answers, vector<ll> &a_sum, vector<ll> &b_sum, ll x1, ll y1, ll x2, ll y2, vector<ll> &can_remove_cache, double T)
{
    ll town = Town[x1][y1];
    ll neighbor_town = Town[x2][y2];
    ll area = answers[town];
    ll neighbor_area = answers[neighbor_town];
    if (town != 0 && neighbor_town != 0 &&
        town != neighbor_town &&
        area != neighbor_area)
    {
        double current = min(min(1.0 * a_sum[area] / a_sum[neighbor_area], 1.0 * a_sum[neighbor_area] / a_sum[area]),
                             min(1.0 * b_sum[area] / b_sum[neighbor_area], 1.0 * b_sum[neighbor_area] / b_sum[area]));
        double area_change_in_a = a_sum[area] + AB[neighbor_town].first;
        double neighbor_area_change_in_a = a_sum[neighbor_area] - AB[neighbor_town].first;
        double area_change_in_b = b_sum[area] + AB[neighbor_town].second;
        double neighbor_area_change_in_b = b_sum[neighbor_area] - AB[neighbor_town].second;
        double change_in = min(min(area_change_in_a, neighbor_area_change_in_a) / max(neighbor_area_change_in_a, area_change_in_a),
                               min(area_change_in_b, neighbor_area_change_in_b) / max(neighbor_area_change_in_b, area_change_in_b));
        double p = exp(min(0.0, change_in - current) / T);
        if (randDouble() < p)
        {
            if (can_remove(Town, answers, x2, y2, can_remove_cache))
            {
                swap_count++;
                insert_town(AB, answers, a_sum, b_sum, neighbor_town, area, neighbor_area, can_remove_cache);
            }
        }
    }
    return false;
}
void print_current_status(ll L, ll a_total, ll b_total, vector<ll> &answers, vector<ll> &a_sum, vector<ll> &b_sum)
{
    ll a_max = numeric_limits<ll>::min();
    ll b_max = numeric_limits<ll>::min();
    ll a_min = numeric_limits<ll>::max();
    ll b_min = numeric_limits<ll>::max();
    for (int i = 1; i <= L; i++)
    {
        cout << a_sum[i] << "," << b_sum[i] << endl;
        a_max = max(a_max, a_sum[i]);
        b_max = max(b_max, b_sum[i]);
        a_min = min(a_min, a_sum[i]);
        b_min = min(b_min, b_sum[i]);
    }
    cout << a_total / L << ":" << a_max << "~" << a_min << endl;
    cout << b_total / L << ":" << b_max << "~" << b_min << endl;
    cout << min(1000000 * a_min / a_max, 1000000 * b_min / b_max) << endl;
}

vector<vector<ll>> town_neighbors(vector<vector<ll>> &Town)
{
    map<pair<ll, ll>, vector<ll>> neighbors;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (i + 1 < N)
            {
                if (Town[i][j] < Town[i + 1][j])
                {
                    neighbors[{Town[i][j], Town[i + 1][j]}] = {{i, j, i + 1, j}};
                }
                else if (Town[i][j] > Town[i + 1][j])
                {
                    neighbors[{Town[i + 1][j], Town[i][j]}] = {{i + 1, j, i, j}};
                }
            }
            if (j + 1 < N)
            {
                if (Town[i][j] < Town[i][j + 1])
                {
                    neighbors[{Town[i][j], Town[i][j + 1]}] = {{i, j, i, j + 1}};
                }
                else if (Town[i][j] > Town[i][j + 1])
                {
                    neighbors[{Town[i][j + 1], Town[i][j]}] = {{i, j + 1, i, j}};
                }
            }
        }
    }
    vector<vector<ll>> ret;
    for (auto p : neighbors)
    {
        ret.push_back({p.first.first, p.first.second, p.second[0], p.second[1], p.second[2], p.second[3]});
    }
    return ret;
}

int main()
{
    double TIME_LIMIT = 0.95;
    int ti = clock();
    cin >> N >> K >> L;
    vector<pair<ll, ll>> AB(K + 1);
    UnionFind uf(K + 1);
    ll a_total = 0;
    ll b_total = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> AB[i + 1].first >> AB[i + 1].second;
        a_total += AB[i + 1].first;
        b_total += AB[i + 1].second;
        uf.a_sum[i + 1] = AB[i + 1].first;
        uf.b_sum[i + 1] = AB[i + 1].second;
    }
    vector<vector<ll>> Town(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Town[i][j];
        }
    }

    auto neighbors = town_neighbors(Town);
    ll unite_count = 0;
    ll max_unite_count = K - L;
    ll max_times = 1000;
    ll a_target = (a_total + max_times - 1) / K;
    ll b_target = (b_total + max_times - 1) / K;

    while (unite_count < max_unite_count)
    {
        for (auto &v : neighbors)
        {
            unite(Town, uf, v[2], v[3], v[4], v[5], unite_count, max_unite_count, a_target, b_target);
        }
        a_target += (a_total + max_times - 1) / max_times;
        b_target += (b_total + max_times - 1) / max_times;
    }
    vector<ll> answers(K + 1);
    vector<ll> can_remove_cache(K + 1, -1); // 0 :false, 1: true, -1:unknown
    vector<ll> a_sum(L + 1);
    vector<ll> b_sum(L + 1);
    set_initial_answer(uf, answers, a_sum, b_sum);

    // print_current_status(L, a_total, b_total, answers, a_sum, b_sum);
    ll k = 0;
    while (double(clock() - ti) / CLOCKS_PER_SEC < TIME_LIMIT)
    {
        k++;
        double t = 1.0 / (20 + k);
        for (auto &v : neighbors)
        {
            swap_if_you_can(Town, AB, answers, a_sum, b_sum, v[2], v[3], v[4], v[5], can_remove_cache, t);
        }
        for (auto &v : neighbors)
        {
            swap_if_you_can(Town, AB, answers, a_sum, b_sum, v[4], v[5], v[2], v[3], can_remove_cache, t);
        }
    }
    cout << neighbors.size() << endl;
    cout << k << endl;
    cout << swap_count << endl;
    print_current_status(L, a_total, b_total, answers, a_sum, b_sum);
    // print_answer(answers);
    return 0;
}