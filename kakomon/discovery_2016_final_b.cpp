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

ll time(ll l,ll r,vector<pair<ll,ll>> &P,ll X){
    if (l+1 == r){
        return r;
    }
    ll center = (l+r)/2;
    priority_queue<ll> q;
    ll p_index = P.size() -1;
    ll x = 0;
    for(int i = 100001;i >= 0;i--){
        if (!q.empty() && i <= center){
            x += q.top();
            q.pop();
        }
        while(p_index >= 0 && P[p_index].first == i){
            q.push(P[p_index].second);
            p_index--;
        }
    }
    if (x >= X){
        return time(l,center,P,X);
    }else{
        return time(center,r,P,X);
    }
}

int main()
{
    // 整数の入力
    ll N,X;
    cin >> N >> X;
    vector<pair<ll,ll>> P(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> P[i].first;
    }
    for (size_t i = 0; i < N; i++)
    {
        cin >> P[i].second;
    }
    sort(P.begin(),P.end());
    ll t =  time(-1,100001,P,X);
    if (t == 100001){
        cout << -1 << endl;
    }else{
        cout << t + 1 << endl;
    }
    return 0;
}