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
    // 整数の入力
    ll N, K;
    cin >> N >> K;
    vector<priority_queue<ll>> neta(N);
    priority_queue<pair<ll,ll>> delicious_new_neta;
    priority_queue<ll> delicious_old_neta;
    for (int i = 0; i < N; i++)
    {
        ll t,d;
        cin >> t >> d;
        t--;
        neta[t].push(d);
    }
    for (int i = 0; i < N; i++)
    {
        if(!neta[i].empty()){
            delicious_new_neta.push({neta[i].top(),i});
            neta[i].pop();
        }
    }
    ll ans = K*K;
    ll penalty = 2 * K - 1;
    for(int i = 0;i < K;i++){
        if (delicious_new_neta.empty()){
            ans += delicious_old_neta.top();
            ans -= penalty;
            penalty -= 2;
            delicious_old_neta.pop();
        }else if(delicious_old_neta.empty()){
            auto n = delicious_new_neta.top();
            ans += n.first;
            delicious_new_neta.pop();
            while(!neta[n.second].empty()){
                delicious_old_neta.push(neta[n.second].top());
                neta[n.second].pop();
            }
        }else{
            if (delicious_old_neta.top() - penalty > delicious_new_neta.top().first){
                ans += delicious_old_neta.top();
                ans -= penalty;
                penalty -= 2;
                delicious_old_neta.pop();
            }else{
                auto n = delicious_new_neta.top();
                ans += n.first;
                delicious_new_neta.pop();
                while(!neta[n.second].empty()){
                    delicious_old_neta.push(neta[n.second].top());
                    neta[n.second].pop();
                }
            }
        }
    }
    cout << ans << endl;
   return 0;
}