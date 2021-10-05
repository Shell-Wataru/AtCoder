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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N,C;
    cin >> N >> C;
    vector<ll> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i]--;
    }
    vector<vector<ll>> indexes(N);
    for (size_t i = 0; i < N; i++)
    {
        indexes[A[i]].push_back(i);
    }
    for(int i = 0;i < C;i++){
        ll ans = N*(N+1)/2;
        ll current = -1;
        for(auto index:indexes[i]){
            ans -= (index-current-1)*(index-current)/2;
            current = index;
        }
        ans -= (N-current-1)*(N-current)/2;
        cout << ans << "\n";
    }
    cout << flush;
    return 0;
}
