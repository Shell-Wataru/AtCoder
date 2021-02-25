#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll N,K;
    cin >> N >> K;
    vector<ll> counts(N+1,0);
    for(int i = 0;i<N;i++){
        ll a;
        cin >> a;
        counts[a]++;
    }
    ll ans = 0;
    ll base = min(counts[0],K);
    for(int i = 1;i <= N;i++){
        ans += i * (base - min(base,counts[i]));
        base = min(base,counts[i]);
    }
    cout << ans << endl;
    return 0;
}