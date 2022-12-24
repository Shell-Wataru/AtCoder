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

void dfs1(vector<set<ll>> &G, vector<ll> &data, vector<ll> &parents, string &S, int idx, int par)
{
    parents[idx] = par;
    if (S[idx] == 'W'){
        data[idx]++;
    }
    for (ll to : G[idx])
    {
        if (to == par)
            continue;
        dfs1(G, data, parents, S, to, idx);
        data[idx] += data[to];
    }
}

int main()
{
    ll N;
    scanf("%lld", &N);
    vector<set<ll>> G(N);
    for (int i = 0; i < N; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    string S;
    cin >> S;
    ll white_count = 0;
    for(auto c:S){
        if (c == 'W'){
            white_count++;
        }
    }
    vector<ll> data(N, 0);
    vector<ll> parents(N, 0);
    dfs1(G, data,parents, S, 0, -1);
    priority_queue<ll> q;
    for(int i = 0;i < N;i++){
        if (S[i] != 'W'){
            continue;
        }
        bool is_ok = true;
        for(auto to:G[i]){
            ll whites;
            if (to == parents[i]){
                whites = white_count - data[i];
            }else{
                whites = data[to];
            }
            if (whites % 2 == 1){
                is_ok = false;
                break;
            }
        }
        if (is_ok){
            q.push(i);
        }
    }
    vector<ll> answer;
    while(!q.empty()){
        ll current = q.top();
        answer.push_back(current);
        for(auto to:G[current]){
            if (S[to] == 'W'){
                S[to] = 'B';
            }else{
                S[to] = 'W';
                G[to].erase(current);
                bool is_ok = true;
                for(auto toto:G[to]){
                    ll whites;
                    if (toto == parents[to]){
                        whites = white_count - data[to];
                    }else{
                        whites = data[toto];
                    }
                    if (whites % 2 == 1){
                        is_ok = false;
                        break;
                    }
                }
            }
        }
    }
    return 0;
}