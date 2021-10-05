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
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

int main()
{
    ll N,M,X,Y;
    scanf("%lld", &N);
    scanf("%lld", &M);
    scanf("%lld", &X);
    scanf("%lld", &Y);
    X--;
    Y--;
    vector<vector<vector<ll>>> G(N);
    for(int i = 0;i < M;i++){
        ll a,b,t,k;
        cin >> a >> b >> t >> k;
        a--;
        b--;
        G[a].push_back({b,t,k});
        G[b].push_back({a,t,k});
    }
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>> > q;
    q.push({0,X});
    vector<ll> D(N,numeric_limits<ll>::max());
    while(!q.empty()){
        auto data = q.top();
        q.pop();
        ll d = data.first;
        ll current = data.second;
        if (d >= D[current]){
            continue;
        }
        D[current] = d;
        for(auto e:G[current]){
            q.push({ (d+ e[2]-1)/e[2] * e[2] + e[1],e[0]});
        }
    }
    if (D[Y] == numeric_limits<ll>::max()){
        cout << -1 << endl;
    }else{
        cout << D[Y] << endl;
    }
    return 0;
}