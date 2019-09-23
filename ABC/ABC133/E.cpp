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
#include <set>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;


int main()
{
    // 整数の入力
    ll N,K;
    queue<ll> next_nodes;
    map<ll,set<ll>> G,G2;
    set<ll> searched;

    cin >> N >> K;
    for (int i = 1;i<=N;i++){
        set<ll> s,s2;
        G[i] = s;
        G2[i] = s2;
    }

    for (int i = 0; i < N-1; i++)
    {
        ll a,b;
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }
    next_nodes.push(1);
    searched.insert(1);

    ll total = K;
    while(!next_nodes.empty()){
        ll node = next_nodes.front();
        next_nodes.pop();
        for(auto n:G[node]){
            if(searched.find(n) == searched.end()){
                next_nodes.push(n);
                searched.insert(n);

                G2[node].insert(n);
                G2[n].insert(node);
                total = total * (K - G2[node].size()) % BASE_NUM;
            }

        }
    }

    cout << total << endl;
    return 0;
}