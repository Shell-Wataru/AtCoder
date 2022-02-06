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
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> requirements(M);
    for(int i = 0;i < M;i++){
        cin >> requirements[i].second >> requirements[i].first;
    }
    sort(requirements.begin(),requirements.end());
    ll ans = 0;
    ll last_cut = 0;
    for(int i = 0;i < M;i++){
        if (requirements[i].second >= last_cut){
            last_cut = requirements[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}