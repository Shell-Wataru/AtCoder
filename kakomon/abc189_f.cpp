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
    ll N, M,K;
    cin >> N >> M >> K;
    vector<double> DP(N+M+1,0);
    vector<bool> A(N,false);
    ll max_continue = 0;
    ll current_continue = 0;
    ll last_a = -1;
    for(int i = 0;i < K;i++){
        ll a;
        cin >> a;
        A[a] = true;
        if (last_a + 1 == a){
            current_continue++;
            last_a = a;
        }else{
            current_continue = 1;
            last_a = a;
        }
        max_continue = max(max_continue,current_continue);
    }
    // cout << max_continue << endl;
    if (max_continue >= M){
        cout << -1 << endl;
        return 0;
    }
    DP[0] = 2.0*N/M;
    double l = 0;
    double r = numeric_limits<ll>::max();
    while(abs(r-l) >= 1e-4){
        double center = (l+r)/2;
        // cout << center << endl;
        double total = 0;
        for(int i = N-1;i>=0;i--){
            if (A[i]){
                DP[i] = center;
            }else{
                DP[i] = total/M + 1;
            }
            total += DP[i];
            total -= DP[i+M];
        }
        if (center < DP[0]){
            l = center;
        }else{
            r = center;
        }
    }
    cout << fixed << setprecision(12) << DP[0] << endl;
    return 0;
}

int main()
{
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
