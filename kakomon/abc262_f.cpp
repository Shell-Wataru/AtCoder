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

vector<ll> find_minimum(ll current, deque<ll> P, ll K)
{
    ll N= P.size();
    vector<ll> ans;
    K -= current;
    ll fixed_index = current;
    ll unknown_index = current+1;
    ans.push_back(P[current]);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    for (int i = unknown_index;i <= unknown_index+K && i < N;i++)
    {
        q.push({P[i],i});
    }
    unknown_index = min(unknown_index+K,N-1)+1;
    while(!q.empty()){
        if( q.top().second <= fixed_index){
            q.pop();
            K--;
            continue;
        }
        ans.push_back(q.top().first);
        fixed_index = q.top().second;
        q.pop();
        if (unknown_index  < N){
            q.push({P[unknown_index],unknown_index});
            unknown_index++;
        }
    }
    while(K){
        ans.pop_back();
        K--;
    }
    return ans;
}

vector<ll> find_minimum_rotate(ll current, deque<ll> P, ll K)
{
    ll initial_current = current;
    ll N = P.size();
    vector<ll> ans;
    while(current != 0){
        ll p = P.back();
        P.pop_back();
        P.push_front(p);
        current = (current+1)%N;
    }
    K -= 1;
    ll fixed_index = 0;
    ll unknown_index = 1;
    ans.push_back(P[fixed_index]);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    for (int i = unknown_index;i <=  unknown_index+K && i < N;i++)
    {
        q.push({P[i],i});
    }
    unknown_index = min(unknown_index+K,N-1)+1;
    while(!q.empty()){
        if( q.top().second <= fixed_index){
            q.pop();
            K--;
            continue;
        }
        ans.push_back(q.top().first);
        fixed_index = q.top().second;
        q.pop();
        if (fixed_index < N - initial_current){
            K--;
        }
        if (fixed_index >= N - initial_current && unknown_index  < N){
            q.push({P[unknown_index],unknown_index});
            unknown_index++;
        }
    }
    while(K){
        ans.pop_back();
        K--;
    }
    return ans;
}

int main()
{
    ll N, K;
    cin >> N >> K;
    deque<ll> P(N);
    deque<ll> revP(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
        P[i]--;
        revP[P[i]] = i;
    }
    for (int i = 0; i < N; i++)
    {
        vector<ll> ans = {999999999ll};
        if (revP[i] <= K)
        {
            // cout << "normal" << endl;
            ans = min(ans,find_minimum(revP[i],P,K));
        }
        if (N - revP[i] <= K)
        {
            // cout << "rotate" << endl;
            ans = min(ans,find_minimum_rotate(revP[i],P,K));
        }
        if (ans[0] != 999999999ll){
            for(auto a:ans){
                cout << a+1 << " ";
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}