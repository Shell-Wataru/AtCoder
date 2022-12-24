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

using namespace std;
using ll = long long;

int main()
{
    ll N,M;
    cin >> N >> M;
    vector<ll> w(N);
    ll maximum_weight = 0;
    ll min_v = numeric_limits<ll>::max();
    for(int i = 0;i < N;i++){
        cin >> w[i];
        maximum_weight = max(maximum_weight,w[i]);
    }
    vector<pair<ll,ll>> lv(M);
    for(int i = 0;i < M;i++){
        cin >> lv[i].second >> lv[i].first;
        min_v = min(min_v,lv[i].first);
    }
    if (maximum_weight > min_v){
        cout << -1 << endl;
        return 0;
    }
    sort(lv.begin(),lv.end());
    sort(w.begin(),w.end());
    vector<pair<ll,ll>> zipped_lv;

    zipped_lv.push_back({0,0});
    for(auto p:lv){
        if (zipped_lv.empty()){
            zipped_lv.push_back(p);
        }else if (p.second > zipped_lv.back().second){
            if (p.first == zipped_lv.back().first){
                zipped_lv.back().second = p.second;
            }else{
                zipped_lv.push_back(p);
            }
        }
    }
    zipped_lv.push_back({numeric_limits<ll>::max(),numeric_limits<ll>::max()});
    ll ans = numeric_limits<ll>::max();
    do {
        vector<vector<ll>> length(N+1,vector<ll>(N+1,numeric_limits<ll>::max()/2));
        vector<vector<ll>> weights(N+1,vector<ll>(N+1,0));
        for(int i = 0;i < N;i++){
            length[i][i+1] = 0;
            weights[i][i+1] = w[i];
        }
        for(int i = 2;i<= N;i++){
            for(int j = 0;i+j <= N;j++){
                weights[j][i+j] = weights[j][i+j-1] + weights[i+j-1][i+j];
                auto iter = lower_bound(zipped_lv.begin(),zipped_lv.end(),make_pair(weights[j][i+j],-1ll));
                iter--;
                ll base = iter->second;
                // cout << weights[j][i+j] << ":" << base << endl;
                for(int k = 2;k <= i-1;k++){
                    base = max(length[j][j+k] + length[j+k-1][i+j],base);
                }
                // cout << base << endl;
                length[j][j+i] = base;
            }
        }
        ans = min(ans,length[0][N]);
    }while(next_permutation(w.begin(),w.end()));
    cout << ans << endl;
    return 0;
}