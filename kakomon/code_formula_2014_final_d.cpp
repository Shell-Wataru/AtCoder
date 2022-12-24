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
    ll N;
    cin >> N;
    vector<ll> H(N);
    vector<ll> continueH(N);
    for(int i = 0;i < N;i++){
        cin >> H[i];
    }
    ll h = 0;
    for(int i = 0;i < N;i++){
        h += H[i];
        continueH[i] = h;
    }
    vector<vector<pair<ll,ll>>> ranges(N);
    for(int i = 0;i < N;i++){
        ll m,s,e;
        cin >> m >> s >> e;
        m--;
        ranges[m].emplace_back(e,s);
    }
    vector<vector<ll>> all_ranges;
    for(int i = 0;i < N;i++){
        for(auto p:ranges[i]){
            priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
            for(auto r:ranges[i]){
                q.push(r);
            }
            ll e = p.first;
            ll s = p.second;
            ll count = 0;
            all_ranges.push_back({s,e,continueH[count]});
            while(!q.empty()){
                if (q.top().second < e ){
                    q.pop();
                }else{
                    e = q.top().first;
                    count++;
                    all_ranges.push_back({s,e,continueH[count]});
                    q.pop();
                }
            }
        }
    }
    sort(all_ranges.begin(),all_ranges.end());
    // for(auto r:all_ranges){
    //     cout << r[0] << "~" << r[1] << ":" << r[2] << endl;
    // }
    ll i = 0;
    vector<ll> DP(100001,0);
    for(int j = 0;j < 100001;j++){
        if (j != 0){
            DP[j] = max(DP[j],DP[j-1]);
        }
        while(i < all_ranges.size() && all_ranges[i][0] == j ){
            DP[all_ranges[i][1]] = max(DP[all_ranges[i][1]],DP[all_ranges[i][0]] + all_ranges[i][2]);
            i++;
        }
    }
    cout << DP[100000] << endl;
    return 0;
}
