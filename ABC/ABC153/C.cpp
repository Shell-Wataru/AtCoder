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
    ll N,K;
    cin >> N >> K;
    vector<ll> H;
    for(int i = 0;i< N;i++){
        ll h;
        cin >> h;
        H.push_back(h);
    }
    sort(H.begin(),H.end());
    ll count = 0;
    for(int i = 0; i< N - K;i++){
        count+= H[i];
    }
    cout << count << endl;
    return 0;
}