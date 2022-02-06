#include <iostream>
#include <map>

using namespace std;
using ll = long long;

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll N;
    cin >> N;
    vector<ll> R(N);
    for(int i = 0;i < N;i++){
        cin >> R[i];
    }
    vector<ll> DP_ridge(N,1);
    vector<ll> DP_volley(N,1);
    ll ans = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < i;j++){
            if (R[i] > R[j]){
                DP_ridge[i] = max(DP_ridge[i],DP_volley[j] + 1);
            }
            if (R[i] < R[j]){
                DP_volley[i] = max(DP_volley[i],DP_ridge[j] + 1);
            }
        }
        ans = max(ans,DP_ridge[i]);
        ans = max(ans,DP_volley[i]);
    }
    if (ans <= 2){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
    }

    return 0;
}