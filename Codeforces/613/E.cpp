#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve(){
    ll N;
    cin >> N;
    vector<pair<ll,ll>> LRs;
    set<ll> usedlr;
    for(int i = 0;i<N;i++){
        ll l,r;
        cin >> l >> r;
        usedlr.insert(l);
        usedlr.insert(r);
        LRs.push_back({l,r});
    }
    map<ll,ll> asshuku;
    ll last = 0;
    for(auto i: usedlr){
        if (last != 0 && last + 1 != i){
            last += 2;
            asshuku[i] = last;
        }else{
            last++;
            asshuku[i] = last;
        }
    }
    vector<pair<ll,ll>> zippedLRs;
}

int main()
{
    ll N;
    cin >> N;
    for(int i=0;i<N;i++){
        solve()
    }
    return 0;
}