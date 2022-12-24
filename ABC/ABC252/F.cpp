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

int solve()
{
    ll N, L;
    cin >> N >> L;
    priority_queue<ll,vector<ll>,greater<ll>> q;
    vector<ll> A(N);
    ll total = 0;
    for(int i = 0;i < N;i++){
      cin >> A[i];
      total += A[i];
      q.push(A[i]);
    }
    if (total != L){
      q.push(L -total);
    }
    ll ans = 0;
    while(q.size() > 1){
      ll a = q.top();
      q.pop();
      ll b= q.top();
      q.pop();
      ans += a+b;
      q.push(a+b);
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
