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
#include <set>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

long long extGCD(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll reverse(ll n,ll modulo){
    ll x,y;
    extGCD(n, modulo, x, y);
    return (x + ((abs(x / modulo) + 1) * modulo)) % modulo;
}

//https://scrapbox.io/pocala-kyopro/%E6%8B%A1%E5%BC%B5%E3%83%A6%E3%83%BC%E3%82%AF%E3%83%AA%E3%83%83%E3%83%89%E3%81%AE%E4%BA%92%E9%99%A4%E6%B3%95
vector<ll> inverse_array(ll n)
{
    vector<ll> inverse(n, -1);
    inverse[1] = 1;
    for (int i = 2; i < n; i++)
    {
        inverse[i] = BASE_NUM - inverse[BASE_NUM % i] * (BASE_NUM / i) % BASE_NUM;
    }
    return inverse;
}

pair<ll, ll> patterns(vector<vector<ll>> &G, ll from, ll parent, vector<ll> &factorial,vector<ll> &inverse_factorial, vector<map<ll,pair<ll,ll>>> &memo)
{
    if(memo[from].find(parent) != memo[from].end()){
        // cout << "hit!!" << endl;
        return memo[from][parent];
    }else if(memo[from].find(-1) != memo[from].end()){
        pair<ll,ll> reverse_child = patterns(G,parent,from,factorial,inverse_factorial, memo);
        pair<ll,ll> all = memo[from][-1];
        ll ret_patterns = all.first * factorial[reverse_child.second] % BASE_NUM;
        ret_patterns = ret_patterns * reverse(reverse_child.first,BASE_NUM) % BASE_NUM;
        ret_patterns = ret_patterns * inverse_factorial[all.second - 1] % BASE_NUM;
        ret_patterns = ret_patterns * factorial[all.second - 1 - reverse_child.second] % BASE_NUM;
        memo[from][parent] = {ret_patterns, all.second - reverse_child.second };
        return memo[from][parent];
    }else{
        ll ret_patterns = 1;
        ll children_nodes_total = 0;
        for (auto &to : G[from])
        {
            if (to == parent)
            {
                continue;
            }
            pair<ll,ll> child = patterns(G,to,from,factorial,inverse_factorial, memo);
            ret_patterns = ret_patterns * inverse_factorial[child.second] % BASE_NUM;
            children_nodes_total += child.second;
            ret_patterns = ret_patterns * child.first % BASE_NUM;
        }
        ret_patterns = ret_patterns * factorial[children_nodes_total] % BASE_NUM;
        memo[from][parent] = {ret_patterns, children_nodes_total + 1};
        return {ret_patterns, children_nodes_total + 1};
    }
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<vector<ll>> G(N);
    for (int i = 0; i < N-1; i++)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<pair<ll,ll>> node_degrees;
    for(int i = 0;i<N;i++){
        node_degrees.push_back({G[i].size(),i});
    }
    sort(node_degrees.begin(),node_degrees.end(),greater<pair<ll,ll>>());
    vector<ll> inverse = inverse_array(N);
    vector<ll> factorial;
    factorial.push_back(1);
    for (int i = 1; i <= N; i++)
    {
        factorial.push_back(factorial[i - 1] * i % BASE_NUM);
    }

    vector<ll> inverse_factorial;
    inverse_factorial.push_back(1);
    for (int i = 1; i <= N; i++)
    {
        inverse_factorial.push_back(inverse_factorial[i - 1] * inverse[i] % BASE_NUM);
    }
    vector<map<ll,pair<ll,ll>>> memo(N);
    for(int i = 0;i< N;i++){
        patterns(G,node_degrees[i].second,-1,factorial,inverse_factorial,memo);
    }

    for(int i = 0;i< N;i++){
        cout << patterns(G,i,-1,factorial,inverse_factorial,memo).first << "\n";
    }
    cout << flush;
    return 0;
}