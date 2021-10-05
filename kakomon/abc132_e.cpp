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
    ll N,M;
    scanf("%lld", &N);
    scanf("%lld", &M);
    vector<vector<ll>> G(3*N);
    for(int i = 0;i < M;i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        G[3*u ].push_back(3*v+1);
        G[3*u +1].push_back(3*v+2);
        G[3*u +2].push_back(3*v);
    }
    ll S,T;
    cin >> S;
    cin >> T;
    S--;
    T--;
    S = 3*S;
    T = 3*T;
    vector<ll> visited(3*N,false);
    vector<ll> D(3*N,numeric_limits<ll>::max());
    queue<pair<ll,ll>> q;
    q.push({0,S});
    while(!q.empty()){
        auto data = q.front();
        q.pop();
        ll d = data.first;
        ll current = data.second;
        D[current] = d;
        for(auto to:G[current]){
            if (!visited[to]){
                visited[to] = true;
                q.push({d+1,to});
            }
        }
    }
    if (D[T] == numeric_limits<ll>::max()){
        cout << -1 << endl;
    }else{
        cout << D[T]/3 << endl;
    }

    return 0;
}