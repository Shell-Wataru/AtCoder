#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 2;

vector<ll> two_powers(int n)
{
    vector<ll> ret(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        ll p = 0;
        while ((i >> p) % 2 == 0)
        {
            p++;
        }
        // cout << i << ":" << p << endl;
        ret[i] = p;
    }
    return ret;
}
ll combination(vector<ll> &factorial, ll n, ll m)
{
    if (factorial[n] - factorial[m] - factorial[n - m] > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> DP(N+1,numeric_limits<ll>::max());
    DP[0] = numeric_limits<ll>::min();
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    for(int i = 0;i < N;i++){
        auto itr = lower_bound(DP.begin(),DP.end(),A[i]);
        *itr = A[i];
    }
    cout << N - (lower_bound(DP.begin(),DP.end(),numeric_limits<ll>::max()) - DP.begin()) << endl;
    return 0;
}