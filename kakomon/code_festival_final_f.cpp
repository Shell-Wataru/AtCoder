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
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

ll solve(ll N, vector<ll> B,ll first)
{
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        ll g = gcd(B[(first+i)%N], B[(first+i + 2) % N]);
        if (B[(first+i + 1) % N] % g != 0)
        {
            B[(first+i + 2) % N] = gcd(B[(first+i + 1) % N], B[(first+i + 3) % N]);
            ans++;
        }
    }
    return ans;
}
int main()
{
    ll N;
    cin >> N;
    vector<ll> B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> B[i];
    }
    ll ans = numeric_limits<ll>::max();
    for(int i = 0;i < 4;i++){
        ans = min(ans,solve(N,B,i));
    }
    cout << ans << endl;
    return 0;
}
