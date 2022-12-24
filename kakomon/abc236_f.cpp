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

bool is_independent(vector<ll> vs){
    sort(vs.rbegin(),vs.rend());
    for(int i = 16;i >= 0;i--){
        for(int j = 0;j < vs.size();j++){
            if ((vs[j] & 1ll<<i) && (vs[j] < 1ll<<(i+1))){
                for(int k = 0;k < vs.size();k++){
                    if (k != j && (vs[k] & 1ll<<i)){
                        vs[k] ^= vs[j];
                    }
                }
                break;
            }
        }
    }
    for(auto v:vs){
        if (v == 0){
            return false;
        }
    }
    return true;
}

int solve()
{
    ll N;
    cin >> N;
    vector<pair<ll,ll>> C((1ll<<N) -1);
    for(int i = 1;i < 1ll<<N;i++){
        ll c;
        cin >> c;
        C[i-1] = {c,i};
    }
    sort(C.begin(),C.end());

     ll ans = 0;
    vector<ll> vs;
    for(auto c:C){
        vs.push_back(c.second);
        // cout << c.second << endl;
        if (is_independent(vs)){
            ans+= c.first;
        }else{
            vs.pop_back();
        }
        // if (vs.size() == N){
        //     break;
        // }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
