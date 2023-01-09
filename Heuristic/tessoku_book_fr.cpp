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
#include <unordered_set>
using namespace std;
using ll = int;

vector<ll> direcrion_x = {1, -1, 0, 0};
vector<ll> direcrion_y = {0, 0, 1, -1};
random_device rnd;
mt19937 engine(rnd());
uniform_real_distribution<> dist(0.0, 1.0);
ll N, K, L;
ll swap_count = 0;
ll expand_count = 0;
ll tri_swap_count = 0;
ll a_total = 0;
ll b_total = 0;
double TIME_LIMIT = 0.975;
ll target = 980000;
double a_mean;
double b_mean;
double a_lower;
double a_upper;
double b_lower;
double b_upper;
unordered_set<ll> visited_towns;
double randDouble()
{
    return dist(engine);
}

template <typename G>
struct LowLink
{
    const G &g;
    vector<int> used, ord, low;
    vector<int> articulation;
    vector<pair<int, int>> bridge;

    LowLink(const G &g) : g(g) {}

    int dfs(int idx, int k, int par)
    {
        used[idx] = true;
        ord[idx] = k++;
        low[idx] = ord[idx];
        bool is_articulation = false;
        int cnt = 0;
        for (auto &to : g[idx])
        {
            if (!used[to])
            {
                ++cnt;
                k = dfs(to, k, idx);
                low[idx] = min(low[idx], low[to]);
                is_articulation |= ~par && low[to] >= ord[idx];
                if (ord[idx] < low[to])
                    bridge.emplace_back(minmax(idx, (int)to));
            }
            else if (to != par)
            {
                low[idx] = min(low[idx], ord[to]);
            }
        }
        is_articulation |= par == -1 && cnt > 1;
        if (is_articulation)
            articulation.push_back(idx);
        return k;
    }

    virtual void build()
    {
        used.assign(g.size(), 0);
        ord.assign(g.size(), 0);
        low.assign(g.size(), 0);
        int k = 0;
        for (int i = 0; i < g.size(); i++)
        {
            if (!used[i])
                k = dfs(i, k, -1);
        }
    }
};

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

bool unite(UnionFind &uf, ll town, ll neighbor_town, ll &unite_count, ll &max_unite_count, ll a_target, ll b_target, ll max_group_size)
{
    if (unite_count < max_unite_count &&
        town != 0 && neighbor_town != 0 &&
        town != neighbor_town &&
        uf.size(town) + uf.size(neighbor_town) <= max_group_size &&
        uf.unite(town, neighbor_town))
    {
        unite_count++;
    }
    return true;
}

UnionFind get_initial_uf(UnionFind &base_uf, vector<pair<ll, ll>> &AB, vector<vector<ll>> &neighbors, ll unite_count)
{
    UnionFind initial_uf(K + 1);
    for (int i = 1; i <= K; i++)
    {
        initial_uf.a_sum[i] = AB[i].first;
        initial_uf.b_sum[i] = AB[i].second;
    }
    ll max_times = 1000;
    ll a_target = (a_total + max_times - 1) / K;
    ll b_target = (b_total + max_times - 1) / K;
    ll max_group_size = 1;
    ll max_unite_count = K - L;
    shuffle(neighbors.begin(), neighbors.end(), engine);
    while (unite_count < max_unite_count)
    {
        max_group_size++;
        for (auto &v : neighbors)
        {
            unite(initial_uf, v[0], v[1], unite_count, max_unite_count, a_target, b_target, max_group_size);
        }
        a_target += (a_total + max_times - 1) / max_times;
        b_target += (b_total + max_times - 1) / max_times;
    }
    return initial_uf;
}

void set_initial_answer(UnionFind &base_uf, vector<pair<ll, ll>> &AB, vector<vector<ll>> &neighbors, ll unite_count, vector<ll> &answers, vector<vector<ll>> &inv_answers, vector<ll> &a_sum, vector<ll> &b_sum)
{
    UnionFind initial_uf = get_initial_uf(base_uf, AB, neighbors, unite_count);
    set<ll> mappingBase;
    for (int i = 1; i <= K; i++)
    {
        mappingBase.insert(initial_uf.find(base_uf.find(i)));
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
        if (base_uf.find(i) == i)
        {
            answers[i] = mapping[initial_uf.find(base_uf.find(i))];
            inv_answers[mapping[initial_uf.find(base_uf.find(i))]].push_back(i);
        }
        else
        {
            answers[i] = -1;
        }
    }
    for (int i = 1; i <= K; i++)
    {
        a_sum[mapping[initial_uf.find(base_uf.find(i))]] = initial_uf.a(base_uf.find(i));
        b_sum[mapping[initial_uf.find(base_uf.find(i))]] = initial_uf.b(base_uf.find(i));
    }
}
void print_answer(UnionFind &base_uf, vector<ll> &answers)
{
    for (int i = 1; i <= K; i++)
    {
        cout << answers[base_uf.find(i)] << "\n";
    }
    cout << flush;
}

bool collect_same_area_towns(vector<vector<ll>> &G, vector<ll> &answers, ll town, unordered_set<ll> &visited_towns, ll area_id, ll dont_use_town_id)
{
    if (visited_towns.count(town))
    {
        return true;
    }
    else if (town == dont_use_town_id)
    {
        return true;
    }
    else if (answers[town] != area_id)
    {
        return true;
    }
    visited_towns.insert(town);
    for (auto next_town : G[town])
    {
        collect_same_area_towns(G, answers, next_town, visited_towns, area_id, dont_use_town_id);
    }
    return true;
}

bool collect_towns(vector<vector<ll>> &G, ll town, set<ll> &visited_towns, ll dont_use_town_id)
{
    if (visited_towns.count(town))
    {
        return true;
    }
    else if (town == dont_use_town_id)
    {
        return true;
    }

    visited_towns.insert(town);
    for (auto next_town : G[town])
    {
        collect_towns(G, next_town, visited_towns, dont_use_town_id);
    }
    return true;
}

void clear_swap_cache(ll town, vector<map<ll, bool>> &can_swap_cache)
{
    for (auto &p : can_swap_cache[town])
    {
        can_swap_cache[p.first].erase(town);
    }
    can_swap_cache[town].clear();
}

bool can_remove(vector<vector<ll>> &G, vector<ll> &answers, vector<vector<ll>> &inv_answers, ll town, vector<ll> &can_remove_cache)
{
    if (can_remove_cache[town] == 0)
    {
        // cout << "hit:false" << endl;
        return false;
    }
    else if (can_remove_cache[town] == 1)
    {
        // cout << "hit:true" << endl;
        return true;
    }
    ll area_id = answers[town];
    ll other_town = -1;
    if (inv_answers[area_id].front() != town)
    {
        other_town = inv_answers[area_id].front();
    }
    else if (inv_answers[area_id].back() != town)
    {
        other_town = inv_answers[area_id].back();
    }

    if (other_town == -1)
    {
        can_remove_cache[town] = 0;
        return false;
    }
    else
    {
        visited_towns.clear();
        collect_same_area_towns(G, answers, other_town, visited_towns, area_id, town);
        if (inv_answers[area_id].size() - 1 == visited_towns.size())
        {
            return true;
        }
        else
        {
            can_remove_cache[town] = 0;
            return false;
        }
    }
}

bool can_swap(vector<vector<ll>> &G, vector<ll> &answers, vector<vector<ll>> &inv_answers, ll town, ll neighbor_town, vector<map<ll, bool>> &can_swap_cache)
{
    if (neighbor_town < town)
    {
        swap(town, neighbor_town);
    }
    if (can_swap_cache[town].count(neighbor_town))
    {
        return can_swap_cache[town][neighbor_town];
    }
    ll area_id = answers[town];
    ll neighbor_area_id = answers[neighbor_town];

    answers[town] = neighbor_area_id;
    answers[neighbor_town] = area_id;
    visited_towns.clear();
    collect_same_area_towns(G, answers, town, visited_towns, neighbor_area_id, -1);
    answers[town] = area_id;
    answers[neighbor_town] = neighbor_area_id;

    if (visited_towns.size() != inv_answers[neighbor_area_id].size())
    {
        can_swap_cache[town][neighbor_town] = false;
        can_swap_cache[neighbor_town][town] = false;
        return false;
    }

    answers[town] = neighbor_area_id;
    answers[neighbor_town] = area_id;
    visited_towns.clear();
    collect_same_area_towns(G, answers, neighbor_town, visited_towns, area_id, -1);
    answers[town] = area_id;
    answers[neighbor_town] = neighbor_area_id;

    if (visited_towns.size() == inv_answers[area_id].size())
    {
        return true;
    }
    else
    {
        can_swap_cache[town][neighbor_town] = false;
        can_swap_cache[neighbor_town][town] = false;
        return false;
    }
}

void insert_town(vector<vector<ll>> &G, vector<vector<ll>> &diagG, vector<pair<ll, ll>> &AB, vector<ll> &answers, vector<vector<ll>> &inv_answers, vector<ll> &a_sum, vector<ll> &b_sum, ll area, ll neighbor_town, vector<ll> &can_remove_cache, vector<map<ll, bool>> &can_swap_cache)
{
    ll neighbor_area = answers[neighbor_town];
    for (int i = 0; i < inv_answers[neighbor_area].size(); i++)
    {
        if (inv_answers[neighbor_area][i] == neighbor_town)
        {
            inv_answers[neighbor_area].erase(inv_answers[neighbor_area].begin() + i);
            break;
        }
    }
    inv_answers[area].push_back(neighbor_town);
    answers[neighbor_town] = area;
    a_sum[area] += AB[neighbor_town].first;
    b_sum[area] += AB[neighbor_town].second;
    a_sum[neighbor_area] -= AB[neighbor_town].first;
    b_sum[neighbor_area] -= AB[neighbor_town].second;
    for (auto to : G[neighbor_town])
    {
        if (answers[to] == area || answers[to] == neighbor_area)
        {
            can_remove_cache[to] = -1;
        }
    }
    for (auto to : diagG[neighbor_town])
    {
        if (answers[to] == area || answers[to] == neighbor_area)
        {
            can_remove_cache[to] = -1;
        }
    }
    can_remove_cache[neighbor_town] = 1;
    for (auto to1 : G[neighbor_town])
    {
        if (answers[to1] == area || answers[to1] == neighbor_area)
        {
            clear_swap_cache(to1, can_swap_cache);
        }
    }
    for (auto to1 : diagG[neighbor_town])
    {
        if (answers[to1] == area || answers[to1] == neighbor_area)
        {
            clear_swap_cache(to1, can_swap_cache);
        }
    }
    clear_swap_cache(neighbor_town, can_swap_cache);
}

void swap_town(vector<vector<ll>> &G, vector<vector<ll>> &diagG, vector<pair<ll, ll>> &AB, vector<ll> &answers, vector<vector<ll>> &inv_answers, vector<ll> &a_sum, vector<ll> &b_sum, ll town, ll neighbor_town, vector<ll> &can_remove_cache, vector<map<ll, bool>> &can_swap_cache)
{
    if (neighbor_town < town)
    {
        swap(town, neighbor_town);
    }
    ll area = answers[town];
    ll neighbor_area = answers[neighbor_town];
    for (int i = 0; i < inv_answers[neighbor_area].size(); i++)
    {
        if (inv_answers[neighbor_area][i] == neighbor_town)
        {
            inv_answers[neighbor_area].erase(inv_answers[neighbor_area].begin() + i);
            break;
        }
    }
    for (int i = 0; i < inv_answers[area].size(); i++)
    {
        if (inv_answers[area][i] == town)
        {
            inv_answers[area].erase(inv_answers[area].begin() + i);
            break;
        }
    }
    inv_answers[area].push_back(neighbor_town);
    inv_answers[neighbor_area].push_back(town);
    answers[neighbor_town] = area;
    answers[town] = neighbor_area;
    a_sum[area] += AB[neighbor_town].first - AB[town].first;
    b_sum[area] += AB[neighbor_town].second - AB[town].second;
    a_sum[neighbor_area] -= AB[neighbor_town].first - AB[town].first;
    b_sum[neighbor_area] -= AB[neighbor_town].second - AB[town].second;
    can_remove_cache[neighbor_town] = -1;
    for (auto to : G[neighbor_town])
    {
        if (answers[to] == area || answers[to] == neighbor_area)
        {
            can_remove_cache[to] = -1;
        }
    }
    for (auto to : diagG[neighbor_town])
    {
        if (answers[to] == area || answers[to] == neighbor_area)
        {
            can_remove_cache[to] = -1;
        }
    }
    for (auto to1 : G[neighbor_town])
    {
        if (answers[to1] == area || answers[to1] == neighbor_area)
        {
            clear_swap_cache(to1, can_swap_cache);
        }
    }
    for (auto to1 : diagG[neighbor_town])
    {
        if (answers[to1] == area || answers[to1] == neighbor_area)
        {
            clear_swap_cache(to1, can_swap_cache);
        }
    }
    can_remove_cache[town] = -1;
    for (auto to : G[town])
    {
        if (answers[to] == area || answers[to] == neighbor_area)
        {
            can_remove_cache[to] = -1;
        }
    }
    for (auto to : diagG[town])
    {
        if (answers[to] == area || answers[to] == neighbor_area)
        {
            can_remove_cache[to] = -1;
        }
    }
    for (auto to1 : G[town])
    {
        if (answers[to1] == area || answers[to1] == neighbor_area)
        {
            clear_swap_cache(to1, can_swap_cache);
        }
    }
    for (auto to1 : diagG[town])
    {
        if (answers[to1] == area || answers[to1] == neighbor_area)
        {
            clear_swap_cache(to1, can_swap_cache);
        }
    }
    clear_swap_cache(town, can_swap_cache);
    clear_swap_cache(neighbor_town, can_swap_cache);
    can_swap_cache[town][neighbor_town] = true;
    can_swap_cache[neighbor_town][town] = true;
}

double value(double area_a, double neighbor_a, double area_b, double neighbor_b)
{
    return min(min(min(area_a, neighbor_a), a_lower) / max(max(area_a, neighbor_a), a_upper),
               min(min(area_b, neighbor_b), b_lower) / max(max(area_b, neighbor_b), b_upper));
}

bool expand_if_you_can(vector<vector<ll>> &G, vector<vector<ll>> &diagG, vector<pair<ll, ll>> &AB, vector<ll> &answers, vector<vector<ll>> &inv_answers, vector<ll> &a_sum, vector<ll> &b_sum, ll area, ll neighbor_town, vector<ll> &can_remove_cache, vector<map<ll, bool>> &can_swap_cache, double T)
{
    ll neighbor_area = answers[neighbor_town];
    if (area != neighbor_area)
    {
        double current_value = value(a_sum[area], a_sum[neighbor_area], b_sum[area], b_sum[neighbor_area]);
        double area_a = a_sum[area] + AB[neighbor_town].first;
        double neighbor_area_a = a_sum[neighbor_area] - AB[neighbor_town].first;
        double area_b = b_sum[area] + AB[neighbor_town].second;
        double neighbor_area_b = b_sum[neighbor_area] - AB[neighbor_town].second;
        double next_value = value(area_a, neighbor_area_a, area_b, neighbor_area_b);
        double p = exp(min(0.0, next_value - current_value) / T);
        if (randDouble() < p)
        {
            if (can_remove(G, answers, inv_answers, neighbor_town, can_remove_cache))
            {
                expand_count++;
                insert_town(G, diagG, AB, answers, inv_answers, a_sum, b_sum, area, neighbor_town, can_remove_cache, can_swap_cache);
            }
        }
    }
    return false;
}

bool swap_if_you_can(vector<vector<ll>> &G, vector<vector<ll>> &diagG, vector<pair<ll, ll>> &AB, vector<ll> &answers, vector<vector<ll>> &inv_answers, vector<ll> &a_sum, vector<ll> &b_sum, ll town, ll neighbor_town, vector<ll> &can_remove_cache, vector<map<ll, bool>> &can_swap_cache, double T)
{
    if (neighbor_town < town)
    {
        swap(town, neighbor_town);
    }
    ll area = answers[town];
    ll neighbor_area = answers[neighbor_town];
    if (area != neighbor_area)
    {
        double current_value = value(a_sum[area], a_sum[neighbor_area], b_sum[area], b_sum[neighbor_area]);
        double area_a = a_sum[area] + AB[neighbor_town].first - AB[town].first;
        double neighbor_area_a = a_sum[neighbor_area] - AB[neighbor_town].first + AB[town].first;
        double area_b = b_sum[area] + AB[neighbor_town].second - AB[town].second;
        double neighbor_area_b = b_sum[neighbor_area] - AB[neighbor_town].second + AB[town].second;
        double next_value = value(area_a, neighbor_area_a, area_b, neighbor_area_b);
        double p = exp(min(0.0, next_value - current_value) / T);
        if (randDouble() < p)
        {
            if (can_swap(G, answers, inv_answers, town, neighbor_town, can_swap_cache))
            {
                swap_count++;
                swap_town(G, diagG, AB, answers, inv_answers, a_sum, b_sum, town, neighbor_town, can_remove_cache, can_swap_cache);
                return true;
            }
        }
    }
    return false;
}

ll current_score(vector<ll> &a_sum, vector<ll> &b_sum)
{
    ll a_max = numeric_limits<ll>::min();
    ll b_max = numeric_limits<ll>::min();
    ll a_min = numeric_limits<ll>::max();
    ll b_min = numeric_limits<ll>::max();
    for (int i = 1; i <= L; i++)
    {
        a_max = max(a_max, a_sum[i]);
        b_max = max(b_max, b_sum[i]);
        a_min = min(a_min, a_sum[i]);
        b_min = min(b_min, b_sum[i]);
    }
    return llround(min(1000000.0 * a_min / a_max, 1000000.0 * b_min / b_max));
}

void current_status(UnionFind &base_uf, vector<ll> &answers, vector<pair<ll, ll>> &AB)
{
    vector<ll> a_sum(K + 1);
    vector<ll> b_sum(K + 1);
    for (int i = 1; i <= K; i++)
    {
        a_sum[answers[base_uf.find(i)]] += AB[i].first;
        b_sum[answers[base_uf.find(i)]] += AB[i].second;
    }
    for (int i = 1; i <= L; i++)
    {
        cerr << (a_sum[i] - a_mean) / 50 << "," << b_sum[i] - b_mean << endl;
    }
}

vector<vector<ll>> town_neighbors(vector<vector<ll>> &Town)
{
    set<pair<ll, ll>> neighbors;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i + 1 < N)
            {
                if (Town[i][j] < Town[i + 1][j])
                {
                    neighbors.insert({Town[i][j], Town[i + 1][j]});
                }
                else if (Town[i][j] > Town[i + 1][j])
                {
                    neighbors.insert({Town[i + 1][j], Town[i][j]});
                }
            }
            if (j + 1 < N)
            {
                if (Town[i][j] < Town[i][j + 1])
                {
                    neighbors.insert({Town[i][j], Town[i][j + 1]});
                }
                else if (Town[i][j] > Town[i][j + 1])
                {
                    neighbors.insert({Town[i][j + 1], Town[i][j]});
                }
            }
        }
    }
    vector<vector<ll>> ret;
    for (auto p : neighbors)
    {
        if (p.first != 0 && p.second != 0)
        {
            ret.push_back({p.first, p.second});
        }
    }
    return ret;
}

vector<ll> find_answer(UnionFind &base_uf, vector<pair<ll, ll>> &AB, vector<vector<ll>> &G, vector<vector<ll>> &diagG, vector<vector<ll>> &neighbors, vector<ll> &maximum_answers, ll &maximum_score, double ti, double time_limit, ll unite_count)
{
    vector<ll> answers(K + 1);
    vector<vector<ll>> inv_answers(K + 1);
    vector<ll> can_remove_cache(K + 1, -1); // 0 :false, 1: true, -1:unknown
    vector<map<ll, bool>> can_swap_cache(K + 1);
    vector<ll> a_sum(L + 1);
    vector<ll> b_sum(L + 1);
    set_initial_answer(base_uf, AB, neighbors, unite_count, answers, inv_answers, a_sum, b_sum);
    ll loops = 0;
    map<pair<ll, ll>, vector<vector<ll>>> swap_candidates;
    while (double(clock() - ti) / CLOCKS_PER_SEC < time_limit || (maximum_score > target && double(clock() - ti) / CLOCKS_PER_SEC < TIME_LIMIT))
    {
        loops++;
        double t1 = 1.0 / (40 + loops);
        double t2 = 1.0 / (400 + loops);
        if (loops < 100)
        {
            shuffle(neighbors.begin(), neighbors.end(), engine);
            for (auto &v : neighbors)
            {
                if (randDouble() < 0.5)
                {
                    expand_if_you_can(G, diagG, AB, answers, inv_answers, a_sum, b_sum, answers[v[0]], v[1], can_remove_cache, can_swap_cache, t1);
                }
                else
                {
                    expand_if_you_can(G, diagG, AB, answers, inv_answers, a_sum, b_sum, answers[v[1]], v[0], can_remove_cache, can_swap_cache, t1);
                }
            }
        }

        swap_candidates.clear();
        for (auto &v : neighbors)
        {
            ll area_a = answers[v[0]];
            ll area_b = answers[v[1]];
            if (area_a > area_b)
            {
                swap_candidates[{
                                    area_b,
                                    area_a,
                                }]
                    .push_back({v[1], v[0]});
            }
            else if (area_a < area_b)
            {
                swap_candidates[{area_a, area_b}].push_back(v);
            }
        }

        for (auto &p : swap_candidates)
        {
            auto &v = p.second;
            for (int i = 0; i < v.size(); i++)
            {
                ll a = v[i][0];
                ll b = v[i][1];
                for (int j = i + 1; j < v.size(); j++)
                {
                    ll c = v[j][0];
                    ll d = v[j][1];
                    if (a != c && b != d &&
                        answers[a] == p.first.first &&
                        answers[c] == p.first.first &&
                        answers[b] == p.first.second &&
                        answers[d] == p.first.second)
                    {
                        if (randDouble() < 0.5)
                        {
                            swap_if_you_can(G, diagG, AB, answers, inv_answers, a_sum, b_sum, b, c, can_remove_cache, can_swap_cache, t2);
                        }
                        else
                        {
                            swap_if_you_can(G, diagG, AB, answers, inv_answers, a_sum, b_sum, a, d, can_remove_cache, can_swap_cache, t2);
                        }
                    }
                }
            }
        }

        ll score = current_score(a_sum, b_sum);
        if (score > maximum_score)
        {
            maximum_score = score;
            maximum_answers.assign(answers.begin(), answers.end());
        }
    }
    // cout << "!" << endl;
    cerr << "loop:" << loops << endl;
    // cerr << "expand:" << expand_count << endl;
    // cerr << "swap:" << swap_count << endl;
    // cerr << "score:" << maximum_score << endl;
    // cerr << a_mean << endl;
    // cerr << b_mean << endl;
    // for(int i = 1;i <= L;i++){
    //     cerr << inv_answers[i].size() << ":" << (a_sum[i] - a_total/L)/50 << "," << b_sum[i] - b_total/L << endl;
    // }
    return maximum_answers;
}

vector<vector<ll>> getDiagonals(UnionFind &base_uf, vector<vector<ll>> &Town)
{
    map<pair<ll, ll>, vector<ll>> data;
    set<pair<ll, ll>> edges;
    set<pair<ll, ll>> diagonals;
    for (int i = 0; i + 1 < N; i++)
    {
        for (int j = 0; j + 1 < N; j++)
        {
            set<ll> counts;
            if (base_uf.find(Town[i][j]) != 0)
            {
                counts.insert(base_uf.find(Town[i][j]));
            }
            if (base_uf.find(Town[i + 1][j]) != 0)
            {
                counts.insert(base_uf.find(Town[i + 1][j]));
            }
            if (base_uf.find(Town[i][j + 1]) != 0)
            {
                counts.insert(base_uf.find(Town[i][j + 1]));
            }
            if (base_uf.find(Town[i + 1][j + 1]) != 0)
            {
                counts.insert(base_uf.find(Town[i + 1][j + 1]));
            }
            if (counts.size() == 4)
            {
                diagonals.insert({Town[i][j], Town[i + 1][j + 1]});
                diagonals.insert({Town[i + 1][j + 1], Town[i][j]});
                diagonals.insert({Town[i][j + 1], Town[i + 1][j]});
                diagonals.insert({Town[i + 1][j], Town[i][j + 1]});
            }
        }
    }
    vector<vector<ll>> ret(K + 1);
    for (auto e : diagonals)
    {
        ret[e.first].push_back(e.second);
    }
    return ret;
}
void setNormalizedData(vector<vector<ll>> &neighbors, vector<pair<ll, ll>> &AB, UnionFind &base_uf, vector<vector<ll>> &G, ll &unite_count)
{
    for (auto &v : neighbors)
    {
        G[v[0]].push_back(v[1]);
        G[v[1]].push_back(v[0]);
    }
    LowLink<vector<vector<ll>>> lowlink(G);
    lowlink.build();
    for (auto a : lowlink.articulation)
    {
        for (auto to : G[a])
        {
            set<ll> edge_towns;
            collect_towns(G, to, edge_towns, a);
            ll a_sum = 0;
            ll b_sum = 0;
            for (auto t : edge_towns)
            {
                a_sum += AB[t].first;
                b_sum += AB[t].second;
            }
            if (a_sum < a_mean * 0.7 || b_sum < b_mean * 0.7)
            {
                for (auto t : edge_towns)
                {
                    if (base_uf.unite(a, t))
                    {
                        unite_count++;
                    }
                }
            }
        }
    }
    neighbors.clear();
    for (int i = 1; i <= K; i++)
    {
        for (auto to : G[i])
        {
            ll a = base_uf.find(i);
            ll b = base_uf.find(to);
            if (a > b)
            {
                swap(a, b);
            }
            neighbors.push_back({a, b});
        }
    }
    sort(neighbors.begin(), neighbors.end());
    auto iter = unique(neighbors.begin(), neighbors.end());
    neighbors.erase(iter, neighbors.end());
    for (int i = 1; i <= K; i++)
    {
        G[i].clear();
    }
    for (auto &v : neighbors)
    {
        G[v[0]].push_back(v[1]);
        G[v[1]].push_back(v[0]);
    }
    for (int i = 1; i <= K; i++)
    {
        if (base_uf.find(i) != i)
        {
            AB[base_uf.find(i)].first += AB[i].first;
            AB[base_uf.find(i)].second += AB[i].second;
            AB[i].first = 0;
            AB[i].second = 0;
        }
    }
}

bool is_valid_answer(vector<vector<ll>> neighbors, vector<ll> &answers, ll unite_count)
{
    UnionFind uf(K + 1);
    for (auto &p : neighbors)
    {
        if (answers[p[0]] == answers[p[1]] && uf.unite(p[0], p[1]))
        {
            unite_count++;
        }
    }
    return unite_count == K - L;
}
int main()
{
    int ti = clock();
    cin >> N >> K >> L;
    vector<pair<ll, ll>> AB(K + 1);
    UnionFind base_uf(K + 1);

    for (int i = 0; i < K; i++)
    {
        cin >> AB[i + 1].first >> AB[i + 1].second;
        a_total += AB[i + 1].first;
        b_total += AB[i + 1].second;
        base_uf.a_sum[i + 1] = AB[i + 1].first;
        base_uf.b_sum[i + 1] = AB[i + 1].second;
    }
    a_mean = 1.0 * a_total / L;
    b_mean = 1.0 * b_total / L;
    a_lower = a_mean * 0.999;
    a_upper = a_mean * 1.001;
    b_lower = b_mean * 0.999;
    b_upper = b_mean * 1.001;
    vector<vector<ll>> Town(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> Town[i][j];
        }
    }

    ll unite_count = 0;
    auto neighbors = town_neighbors(Town);
    vector<vector<ll>> G(K + 1);
    setNormalizedData(neighbors, AB, base_uf, G, unite_count);
    vector<vector<ll>> diagG = getDiagonals(base_uf, Town);
    vector<ll> maximum_answers(K + 1);
    ll maximum_score = 0;
    // vector<ll> initial_answers(K + 1);
    // vector<ll> initial_a_sum(K + 1);
    // vector<ll> initial_b_sum(K + 1);
    // vector<vector<ll>> initial_inv_answers(K + 1);
    // set_initial_answer(base_uf, initial_uf, initial_answers, initial_inv_answers, initial_a_sum, initial_b_sum);
    // print_answer(base_uf, initial_answers);
    // current_status(base_uf, initial_answers, AB);
    ll max_try = 5;
    for (int i = 1; i <= max_try; i++)
    {
        // cout << i << endl;
        find_answer(base_uf, AB, G, diagG, neighbors, maximum_answers, maximum_score, ti, i * TIME_LIMIT / max_try, unite_count);
        // cerr << maximum_score << endl;
    }
    // current_status(base_uf, maximum_answers, AB);
    cerr << maximum_score << endl;
    cerr << swap_count << endl;
    cout << maximum_score << endl;
    if (!is_valid_answer(neighbors, maximum_answers, unite_count))
    {
        cerr << "!bad_answer" << endl;
    }
    // print_answer(base_uf, maximum_answers);
    return 0;
}