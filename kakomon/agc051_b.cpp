#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{

    vector<pair<ll,ll>> points;
    points.push_back({0,0});
    ll width = 1;
    for(int i = 0;i < 10;i++){
        vector<pair<ll,ll>> additions;
        for(auto p:points){
            additions.push_back({p.first+width,p.second});
            additions.push_back({p.first+width,p.second+width});
        }
        for(auto p:additions){
            points.push_back(p);
        }
        width = 3* width;
    }
    cout << points.size() << endl;
    for(auto p:points){
        cout << p.first << " " << p.second << endl;
    }
    set<ll> a,b,c,d;
    for(auto p:points){
        a.insert(p.first);
        b.insert(p.second);
        c.insert(p.second+p.first);
        d.insert(p.second-p.first);
    }
    // cout << a.size() << endl;
    // cout << b.size() << endl;
    // cout << c.size() << endl;
    // cout << d.size() << endl;
    return 0;
}
int main()
{
    //   int t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}