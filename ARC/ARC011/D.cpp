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
    ll a, b, c;
    bool operator<(const Road &another) const
    {
        if (a != another.a){
            return a < another.a;
        }else if(b != another.b ){
            return b < another.b;
        }else{
            return c < another.c;
        }
    };
};

struct Home
{
    ll x, y;
    bool operator<(const Home &another) const
    {
        if (x != another.x){
            return x < another.x;
        }else{
            return y < another.y;
        }
    };
};

int main()
{
    // 整数の入力
    ll N, M, R;
    set<Road> distinct_roads;
    set<Home> distinct_homes;
    vector<Road> roads;
    vector<Home> homes;
    set<pair<double,double>> candidates;
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
    for(auto r: distinct_roads){
        roads.push_back(r);
    }
    for(auto h: distinct_homes){
        homes.push_back(h);
    }
    candidates.insert({R,R});
    candidates.insert({R,-R});
    candidates.insert({-R,R});
    candidates.insert({-R,-R});
    for (int j = 0; j < homes.size(); j++)
    {
        Home h1 = homes[j];
        for (int k = j + 1; k < homes.size(); k++)
        {
            Home h2 = homes[k];
            double c = (h1.x * h1.x - h2.x * h2.x + h1.y * h1.y - h2.y * h2.y)*1.0/2;
            if(h1.x == h2.x){
                candidates.insert({R,(c - (h1.x - h2.x) * R)*1.0/(h1.y - h2.y)});
                candidates.insert({- R,(c + (h1.x - h2.x) * R)*1.0/(h1.y - h2.y)});
            }else if (h1.y == h2.y){
                candidates.insert({(c - (h1.y - h2.y) * R)*1.0/(h1.x - h2.x),R});
                candidates.insert({(c + (h1.y - h2.y) * R)*1.0/(h1.x - h2.x),-R});

            }else{
                candidates.insert({R,(c - (h1.x - h2.x) * R)*1.0/(h1.y - h2.y)});
                candidates.insert({- R,(c + (h1.x - h2.x) * R)*1.0/(h1.y - h2.y)});
                candidates.insert({(c - (h1.y - h2.y) * R)*1.0/(h1.x - h2.x),R});
                candidates.insert({(c + (h1.y - h2.y) * R)*1.0/(h1.x - h2.x),-R});
            }
            for (int l = k + 1; l < homes.size(); l++)
            {
                Home h3 = homes[l];
                double cc = (h1.x * h1.x - h3.x * h3.x + h1.y * h1.y - h3.y * h3.y)*1.0/2;
                double det = (h1.x - h2.x) * (h1.y - h3.y) - (h1.y - h2.y) * (h1.x - h3.x);
                if (det != 0){
                    double x =   (h1.y - h3.y) * c - (h1.y - h2.y) * cc;
                    double y = - (h1.x - h3.x) * c + (h1.x - h2.x) * cc;
                    candidates.insert({x*1.0/det,y*1.0/det});
                }
            }
        }
    }
    // cout << "======" << endl;
    double best = 0;
    for(auto p:candidates){
        if (abs(p.first) <= R && abs(p.second) <= R){
            // cout << p.first << " " << p.second << endl;
            double nearest_road_distance = numeric_limits<double>::max();
            double nearest_home_distance = numeric_limits<double>::max();
            for(auto h:homes){
                double d = (p.first - h.x)* (p.first - h.x) + (p.second - h.y)* (p.second - h.y);
                nearest_home_distance = min(d,nearest_home_distance);
            }
            for(auto r:roads){
                double d = abs(r.a * p.first  + r.b * p.second + r.c)/sqrt(r.a*r.a+r.b*r.b);
                nearest_road_distance = min(d,nearest_road_distance);
            }
            best = max(best,nearest_home_distance + nearest_road_distance);
        }
    }
    cout << fixed << setprecision(14) <<best << endl;
    return 0;
}
