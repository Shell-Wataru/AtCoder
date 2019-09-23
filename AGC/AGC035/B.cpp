#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int dfs(ll parent,ll node,map<ll,set<ll>> &G){
    // cout << parent << "-" << node << endl;
    vector<ll> children;

    while(!G[node].empty()){
        ll p = *G[node].begin();
        G[node].erase(p);
        G[p].erase(node);
        ll count = dfs(node,p,G);
        if (count != 0){
            children.push_back(p);
        }
        if (children.size() == 2){
            cout << node << " " << children[0] << endl;
            cout << node << " " << children[1] << endl;
            children.clear();
        }
    }

    if (children.size()  == 0){
        return 1;
    }else{
        cout << node << " " << children[0] << endl;
        cout << node << " " << parent << endl;
        return 0;
    }
}
int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    map<ll,set<ll>> G;

    for (int i = 0;i<M;i++){
        ll a,b;
        cin >> a >> b;
        G[a].insert(b);
        G[b].insert(a);
    }

    // cout << "-" << endl;
    if (M % 2 != 0){
        cout << -1 << endl;
    }else{
        dfs(0,1,G);
    }
    return 0;
}