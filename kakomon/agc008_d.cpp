#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int solve()
{
    ll N;
    cin >> N;
    vector<ll> a(N * N);
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q1;
    priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q2;
    for(int i = 0;i < N;i++){
        ll x;
        cin >> x;
        x--;
        q1.push({0,x,i,i+1});
        q1.push({x,x+1,1,i+1});
        q1.push({x+1,N*N,N-1-i,i+1});
    }
    for(int i = 0;i < N*N;i++){
        while(q1.top()[0] == i){
            auto v= q1.top();
            q1.pop();
            if (v[2] != 0){
                q2.push({v[1],v[2],v[3]});
            }
        }
        // cout << i<< ":" << q2.top()[0] << endl;
        if (q2.empty() || q2.top()[0] <= i){
            cout << "No" << endl;
            return 0;
        }
        auto value = q2.top();
        q2.pop();
        a[i] = value[2];
        value[1]--;
        if (value[1] != 0){
            q2.push(value);
        }
    }
    cout << "Yes" << endl;
    for(int i = 0;i < N*N;i++){
        if (i != 0){
            cout << " ";
        }
        cout << a[i];
    }
    cout << endl;
    return 0;
}

int main()
{
    // cout << "!" << endl;
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    // cout << flush;
    return 0;
}
