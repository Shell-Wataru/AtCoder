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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;


int main()
{
    // 整数の入力
    ll N;
    map<pair<ll,ll>,ll> counts;
    cin >> N;
    for(int i = 1;i<=N;i++){
        string i_s = to_string(i);
        ll first = i_s.front() - '0';
        ll last = i_s.back() - '0';
        counts[{first,last}]++;
    }

    ll ans = 0;

    for(auto p:counts){
        ans+= p.second * counts[{p.first.second,p.first.first}];
    }
    cout << ans << endl;
    return 0;
}