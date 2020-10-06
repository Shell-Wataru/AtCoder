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
    cin >> N;
    ll min_v = BASE_NUM;
    ll count = 0;
    for(int i = 0;i< N;i++){
        ll p;
        cin >> p;
        if (p < min_v){
            count++;
        }
        min_v = min(p,min_v);
    }

    cout << count << endl;
    return 0;
}