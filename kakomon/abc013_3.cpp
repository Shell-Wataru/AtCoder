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
    ll N,H,A,B,C,D,E;
    cin >> N >> H >> A >> B >> C >> D >> E;
    ll answer = numeric_limits<ll>::max();
    for(int i = 0;i <= N;i++){
        ll remain = N - i;
        ll hunger = -(H - i*E);
        // cout << "i:" << i << endl;
        // cout << "hunger:" << hunger << endl;
        ll y =  min((hunger- B*remain + 1)/(D - B),remain);
        // cout << "y:" << y << endl;
        // cout << "cost:" << A*(remain-y) + C*y << endl;
        // cout << "eat:" << B*(remain-y) + D*y << endl;
        if (0 <= y &&  hunger- B*remain + 1 <= 0){
            // cout << B*(remain-y) + D*y << endl;
            answer = min(answer,A*(remain-y) + C*y);
        }
    }
    cout << answer << endl;
    return 0;
}