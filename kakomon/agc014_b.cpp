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
    ll N,M;
    cin >> N >> M;
    vector<ll> counts(N,0);

    for(int i = 0;i < M;i++){
        // cout << i << endl;
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        counts[a]++;
        counts[b]++;
    }

    ll odds = count_if(counts.begin(),counts.end(),[](ll i){
        return i % 2 == 0;
    });
    if (odds == N){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}