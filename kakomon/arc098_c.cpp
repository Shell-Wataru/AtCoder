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

ll diff(ll K,ll Q,vector<ll> &A,ll gte){
    vector<ll> segment;
    vector<ll> removables;
    for(auto a:A){
        if (a >= gte){
            segment.push_back(a);
        }else{
            sort(segment.begin(),segment.end());
            ll n = segment.size();
            for(int i = 0; i < n - K + 1;i++){
                removables.push_back(segment[i]);
            }
            segment.clear();
        }
    }
    sort(segment.begin(),segment.end());
    ll n = segment.size();
    for(int i = 0; i < n - K + 1;i++){
        removables.push_back(segment[i]);
    }

    sort(removables.begin(),removables.end());
    if (removables.size() >= Q){
        return removables[Q-1] - removables[0];
    }else{
        return numeric_limits<ll>::max();
    }
}
int main()
{
    // 整数の入力
    ll N,K,Q;
    cin >> N >> K >> Q;
    vector<ll> a(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    priority_queue<ll,vector<ll>,greater<ll>> q;
    for(int i = 0;i < N;i++){
        q.push(a[i]);
    }

    ll min_diff =numeric_limits<ll>::max();
    while(!q.empty()){
        min_diff = min(min_diff,diff(K,Q,a,q.top()));
        q.pop();
    }
    cout << min_diff << endl;
    return 0;
}