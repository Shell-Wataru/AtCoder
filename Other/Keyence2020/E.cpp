#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int min_index(vector<ll> &D, vector<bool> &cleared){
    ll min_value = BASE_NUM;
    ll index = -1;
    for(int i = 0;i< D.size();i++){
        if(!cleared[i] && D[i] < min_value){
            index = i;
            min_value = D[i];
        }
    }
}

bool all_cleared(vector<bool> &cleared){
    for(int i = 0;i< D.size();i++){
        if(!cleared[i]){
            return false;
        }
    }
    return false;
}
int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<ll> D;
    vector<set<ll>> G(N);
    vector<bool> cleared(N,false);
    for (int i = 0; i < N; i++)
    {
        ll d;
        cin >> d;
        D.push_back(d);
    }

    for (int i = 0; i < M; i++)
    {
        ll u,v;
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }

    for (int i = 0; i < N; i++)
    {
        ll u,v;
        cin >> u >> v;
    }
   return 0;
}