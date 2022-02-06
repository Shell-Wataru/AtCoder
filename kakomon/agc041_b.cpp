#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll N,M,V,P;
    cin >> N >> M >> V >> P;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    sort(A.rbegin(),A.rend());
    ll total_add = M*V;
    vector<ll> accumulate_sum(N+1,0);
    for(int i = 0;i < N;i++){
        accumulate_sum[i+1] = accumulate_sum[i] + A[i];
    }
    P--;
    ll ans = 0;
    for(ll i = 0;i < N;i++){
        ll max_add = (N -i) * M  + min(P,i)*M;
        // cout << max_add << endl;
        if (i > P){
            ll diff = (A[i]+M)*(i-P) - (accumulate_sum[i] - accumulate_sum[P]);
            max_add += diff;
        }
        // cout << A[i] << ":";
        // cout << max_add << endl;
        if (A[i]+M >= A[P] &&  max_add >= total_add){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}