#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <climits>
using namespace std;
using ll = long long;

int solve()
{
    ll N,X;
    cin >> N >> X;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    ll over = X/A[N-1]+1;
    ll exactory = X/A[N-1];
    X %= A[N-1];
    for(int i = N-2;i >= 0;i--){
        ll next_exactory = numeric_limits<ll>::max();
        ll next_over = numeric_limits<ll>::max();
        next_exactory = min(next_exactory,exactory + X/A[i]);
        next_exactory = min(next_exactory,over + A[i+1]/A[i] - X/A[i]);
        next_over = min(next_over,exactory + X/A[i] + 1);
        next_over = min(next_over,over + A[i+1]/A[i] - X/A[i] - 1);
        over = next_over;
        exactory = next_exactory;
        X %= A[i];
    }
    // cout << X << endl;
    cout << exactory << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
