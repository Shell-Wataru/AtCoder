#include<iostream>
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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

struct change{
    ll p,zipped_index,i;
    double a,b;
};

int main()
{
    // 整数の入力
    ll N,M;
    double min_v,max_v;
    vector<change> changes;
    vector<pair<double,double>> projections;
    set<ll> unique_change_points;
    map<ll,ll> zipped_change_points;

    min_v = 1;
    max_v = 1;
    cin >> N >> M;
    for(int i = 0;i< M;i++){
        change c;
        cin >> c.p >> c.a >> c.b;
        unique_change_points.insert(c.p);
        c.i = i;
    }

    ll zipped_point = 0;
    for(auto p :unique_change_points){
        zipped_change_points[p] = zipped_point;
        zipped_point++;
    }

    return 0;
}