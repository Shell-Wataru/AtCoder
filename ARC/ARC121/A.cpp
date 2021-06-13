#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll N;
    cin >> N;
    vector<pair<ll,ll>> xs;
    vector<pair<ll,ll>> ys;
    vector<pair<ll,ll>> points;
    for(int i = 0;i < N;i++){
        ll x,y;
        cin >> x >> y;
        xs.emplace_back(x,i);
        ys.emplace_back(y,i);
        points.push_back({x,y});
    }
    sort(xs.begin(),xs.end());
    sort(ys.begin(),ys.end());
    pair<ll,ll> x_max_pair = {xs.front().second,xs.back().second};
    pair<ll,ll> x_second_pair;
    if (xs[N-1].first - xs[1].first > xs[N-2].first - xs[0].first){
        x_second_pair = {xs[1].second,xs[N-1].second};
    }else{
        x_second_pair = {xs[0].second,xs[N-2].second};
    }
    pair<ll,ll> y_max_pair = {ys.front().second,ys.back().second};
    pair<ll,ll> y_second_pair;
    if (ys[N-1].first - ys[1].first > ys[N-2].first - ys[0].first){
        y_second_pair = {ys[1].second,ys[N-1].second};
    }else{
        y_second_pair = {ys[0].second,ys[N-2].second};
    }

    set<pair<ll,ll>> unique_pairs;
    unique_pairs.insert(x_max_pair);
    unique_pairs.insert(x_second_pair);
    unique_pairs.insert(y_max_pair);
    unique_pairs.insert(y_second_pair);
    vector<ll> answers;
    for(auto p:unique_pairs){
        // cout << p.first << "," << p.second << endl;
        answers.push_back(
            max(abs(points[p.first].first - points[p.second].first ),
                abs(points[p.first].second - points[p.second].second)
            )
        );
    }
    sort(answers.rbegin(),answers.rend());
    // for(auto a:answers){
    //     cout << a << endl;
    // }
    cout << answers[1] << endl;
    return 0;
}