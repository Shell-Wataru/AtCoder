#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int solve()
{

    ll N;
    cin >>  N;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    ll ans = 0;
    for(int i = 0; i < N;i++){
        for (size_t j = 0; j < N; j++)
        {
            for (size_t k = 0; k < N; k++)
            {
                ans = max(ans,A[i] | A[j] | A[k]);
            }
        }

    }
    cout << ans << endl;
    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}