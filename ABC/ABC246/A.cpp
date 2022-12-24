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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll x1,x2,x3,y1,y2,y3;
    set<pair<ll,ll>> s;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    s.insert({x1,y1});
    s.insert({x2,y2});
    s.insert({x3,y3});
    ll min_x = min(x1,min(x2,x3));
    ll max_x = max(x1,max(x2,x3));
    ll min_y = min(y1,min(y2,y3));
    ll max_y = max(y1,max(y2,y3));
    if (s.find({min_x,min_y}) == s.end()){
        cout <<  min_x << " " << min_y << endl;
    }
    if (s.find({min_x,max_y}) == s.end()){
        cout <<  min_x << " " << max_y << endl;
    }
    if (s.find({max_x,min_y}) == s.end()){
        cout <<  max_x << " " << min_y << endl;
    }
    if (s.find({max_x,max_y}) == s.end()){
        cout <<  max_x << " " << max_y << endl;
    }
    return 0;
}