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

struct Road
{
    double a, b, c;
    bool operator<(const Road &another) const
    {
        if (a != another.a)
        {
            return a < another.a;
        }
        else if (b != another.b)
        {
            return b < another.b;
        }
        else
        {
            return c < another.c;
        }
    };
};

int solve_linear_equation(double a11, double a12, double a21, double a22, double b1, double b2, double &x1, double &x2)
{
    double det = a11 * a22 - a12 * a21;
    if (det == 0)
    {
        // cout << a11 << a12 << a21 << a22 << endl;
        return 0;
    }
    else
    {
        x1 = 1.0 * (a22 * b1 - a12 * b2) / det;
        x2 = 1.0 * (-a21 * b1 + a11 * b2) / det;
        return 1;
    }
}

struct Home
{
    double x, y;
    bool operator<(const Home &another) const
    {
        if (x != another.x)
        {
            return x < another.x;
        }
        else
        {
            return y < another.y;
        }
    };
};

void insert_candidates(set<pair<double, double>> &candidates, double a11, double a12, double a21, double a22, double b1, double b2)
{
    double x1, x2;
    if (solve_linear_equation(a11, a12, a21, a22, b1, b2, x1, x2))
    {
        candidates.insert({x1, x2});
    }
}

int main()
{
    // 整数の入力
    ll N, M;
    double R;
    set<Road> distinct_roads;
    set<Home> distinct_homes;
    vector<Road> roads;
    vector<Home> homes;
    set<pair<double, double>> candidates;
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++)
    {
        Road r;
        cin >> r.a >> r.b >> r.c;
        distinct_roads.insert(r);
    }
    for (int i = 0; i < M; i++)
    {
        Home h;
        cin >> h.x >> h.y;
        distinct_homes.insert(h);
    }
    for (auto r : distinct_roads)
    {
        roads.push_back(r);
    }
    for (auto h : distinct_homes)
    {
        homes.push_back(h);
    }
    // cout << "===" << endl;
    candidates.insert({R, R});
    candidates.insert({R, -R});
    candidates.insert({-R, R});
    candidates.insert({-R, -R});
    double x1, x2;
    for (int j = 0; j < homes.size(); j++)
    {
        Home h1 = homes[j];
        for (int k = j + 1; k < homes.size(); k++)
        {
            Home h2 = homes[k];
            double c12 = (h1.x * h1.x - h2.x * h2.x + h1.y * h1.y - h2.y * h2.y) * 1.0 / 2;
            insert_candidates(candidates, 1, 0, h1.x - h2.x, h1.y - h2.y, R, c12);
            insert_candidates(candidates, 1, 0, h1.x - h2.x, h1.y - h2.y, -R, c12);
            insert_candidates(candidates, 0, 1, h1.x - h2.x, h1.y - h2.y, R, c12);
            insert_candidates(candidates, 0, 1, h1.x - h2.x, h1.y - h2.y, -R, c12);
            for (int l = k + 1; l < homes.size(); l++)
            {
                Home h3 = homes[l];
                double c13 = (h1.x * h1.x - h3.x * h3.x + h1.y * h1.y - h3.y * h3.y) * 1.0 / 2;
                double x1, x2;
                insert_candidates(candidates,
                                  h1.x - h2.x, h1.y - h2.y,
                                  h1.x - h3.x, h1.y - h3.y,
                                  c12, c13);
            }
        }
    }

    for (int i = 0; i < roads.size(); i++)
    {
        Road &road1 = roads[i];
        double r1 = hypot(road1.a, road1.b);
        // cout <<  "r1:" <<r1 << endl;
        for (int j = i + 1; j < roads.size(); j++)
        {
            Road &road2 = roads[j];
            double r2 = hypot(road2.a, road2.b);
            insert_candidates(candidates,
                              1, 0,
                              r2 * road1.a - r1 * road2.a, r2 * road1.b - r1 * road2.b,
                              R, -r2 * road1.c + r1 * road2.c);
            insert_candidates(candidates,
                              1, 0,
                              r2 * road1.a - r1 * road2.a, r2 * road1.b - r1 * road2.b,
                              -R, -r2 * road1.c + r1 * road2.c);
            insert_candidates(candidates,
                              0, 1,
                              r2 * road1.a - r1 * road2.a, r2 * road1.b - r1 * road2.b,
                              R, -r2 * road1.c + r1 * road2.c);
            insert_candidates(candidates,
                              0, 1,
                              r2 * road1.a - r1 * road2.a, r2 * road1.b - r1 * road2.b,
                              -R, -r2 * road1.c + r1 * road2.c);
            insert_candidates(candidates,
                              1, 0,
                              r2 * road1.a + r1 * road2.a, r2 * road1.b + r1 * road2.b,
                              R, -r2 * road1.c - r1 * road2.c);
            insert_candidates(candidates,
                              1, 0,
                              r2 * road1.a + r1 * road2.a, r2 * road1.b + r1 * road2.b,
                              -R, -r2 * road1.c - r1 * road2.c);
            insert_candidates(candidates,
                              0, 1,
                              r2 * road1.a + r1 * road2.a, r2 * road1.b + r1 * road2.b,
                              R, -r2 * road1.c - r1 * road2.c);
            insert_candidates(candidates,
                              0, 1,
                              r2 * road1.a + r1 * road2.a, r2 * road1.b + r1 * road2.b,
                              -R, -r2 * road1.c - r1 * road2.c);
            for (int k = j + 1; k < roads.size(); k++)
            {
                Road &road3 = roads[k];
                double r3 = hypot(road3.a, road3.b);
                insert_candidates(candidates,
                                  r2 * road1.a - r1 * road2.a, r2 * road1.b - r1 * road2.b,
                                  r3 * road1.a - r1 * road3.a, r3 * road1.b - r1 * road3.b,
                                  -r2 * road1.c + r1 * road2.c,
                                  -r3 * road1.c + r1 * road3.c);
                insert_candidates(candidates,
                                  r2 * road1.a + r1 * road2.a, r2 * road1.b + r1 * road2.b,
                                  r3 * road1.a - r1 * road3.a, r3 * road1.b - r1 * road3.b,
                                  -r2 * road1.c - r1 * road2.c,
                                  -r3 * road1.c + r1 * road3.c);
                insert_candidates(candidates,
                                  r2 * road1.a - r1 * road2.a, r2 * road1.b - r1 * road2.b,
                                  r3 * road1.a + r1 * road3.a, r3 * road1.b + r1 * road3.b,
                                  -r2 * road1.c + r1 * road2.c,
                                  -r3 * road1.c - r1 * road3.c);
                insert_candidates(candidates,
                                  r2 * road1.a + r1 * road2.a, r2 * road1.b + r1 * road2.b,
                                  r3 * road1.a + r1 * road3.a, r3 * road1.b + r1 * road3.b,
                                  -r2 * road1.c - r1 * road2.c,
                                  -r3 * road1.c - r1 * road3.c);
            }
        }
    }

    for (int i = 0; i < roads.size(); i++)
    {
        Road &road1 = roads[i];
        double r1 = hypot(road1.a, road1.b);
        // cout <<  "r1:" <<r1 << endl;
        for (int j = i + 1; j < roads.size(); j++)
        {
            Road &road2 = roads[j];
            double r2 = hypot(road2.a, road2.b);
            for (int k = 0; k < homes.size(); k++)
            {
                Home &h1 = homes[k];
                for (int l = k + 1; l < homes.size(); l++)
                {
                    Home &h2 = homes[l];
                    double c12 = (h1.x * h1.x - h2.x * h2.x + h1.y * h1.y - h2.y * h2.y) * 1.0 / 2;
                    insert_candidates(candidates,
                                      h1.x - h2.x, h1.y - h2.y,
                                      r2 * road1.a - r1 * road2.a, r2 * road1.b - r1 * road2.b,
                                      c12, -r2 * road1.c + r1 * road2.c);
                    insert_candidates(candidates,
                                      h1.x - h2.x, h1.y - h2.y,
                                      r2 * road1.a + r1 * road2.a, r2 * road1.b + r1 * road2.b,
                                      c12, -r2 * road1.c - r1 * road2.c);
                }
            }
        }
    }

    double best = 0;
    for (auto p : candidates)
    {
        if (abs(p.first) <= R && abs(p.second) <= R)
        {
            // cout << p.first << " " << p.second << endl;
            double nearest_road_distance = numeric_limits<double>::max();
            double nearest_home_distance = numeric_limits<double>::max();
            for (auto h : homes)
            {
                double d = (p.first - h.x) * (p.first - h.x) + (p.second - h.y) * (p.second - h.y);
                nearest_home_distance = min(d, nearest_home_distance);
            }
            for (auto r : roads)
            {
                double d = abs(r.a * p.first + r.b * p.second + r.c) / hypot(r.a, r.b);
                nearest_road_distance = min(d, nearest_road_distance);
            }
            best = max(best, nearest_home_distance + nearest_road_distance);
        }
    }
    cout << fixed << setprecision(14) << best << endl;
    return 0;
}
