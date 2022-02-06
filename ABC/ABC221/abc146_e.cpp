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
#include <climits>
using namespace std;
using ll = long long;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    if (K == 1){
        cout << 0 << endl;
        return 0;
    }
    map<ll,ll> count;
    vector<ll> totals(N+1,0);
    count[0]++;
    ll total = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        total = (total + A[i] - 1 + K) % K;
        totals[i+1] = total;
        ans += count[total];
        // cout << total << ":"<< count[total] << endl;
        count[total]++;
        if (i >= K-2){
            // cout << "remove" << endl;
            count[totals[i-(K-2)]]--;
        }
    }
    cout << ans << endl;
    return 0;
}