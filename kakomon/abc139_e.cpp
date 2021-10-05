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
    ll N;
    cin >> N;
    vector<queue<ll>> A(N);
    vector<set<ll>> applications(N);
    vector<ll> days(N,0);
    for(int i =0;i < N;i++){
        for(int j = 0; j < N-1;j++){
            ll a;
            cin >> a;
            a--;
            A[i].push(a);
        }
    }
    // cout << "!" << endl;
    queue<ll> q;
    for(int i = 0;i< N;i++){
        q.push(i);
    }
    while(!q.empty()){
        ll i = q.front();
        // cout << i << endl;
        q.pop();
        if (A[i].empty()){
            continue;
        }else if (applications[i].find(A[i].front()) != applications[i].end()){
            applications[i].erase(A[i].front());
            ll current_day = max(days[i], days[A[i].front()]) + 1;
            days[i] = current_day;
            days[A[i].front()] = current_day;
            q.push(i);
            q.push(A[i].front());
            A[A[i].front()].pop();
            A[i].pop();
        }else{
            applications[A[i].front()].insert(i);
        }
    }
    ll ans = 0;
    for(int i = 0; i < N;i++){
        if (!A[i].empty()){
            ans = max(ans,numeric_limits<ll>::max());
        }else{
            ans = max(ans,days[i]);
        }
    }
    if (ans == numeric_limits<ll>::max()){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}