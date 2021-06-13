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


int main()
{
    ll N;
    cin >> N;
    ll min_abs_value = numeric_limits<ll>::max()/2;
    ll total = 0;
    ll minus_count = 0;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        total += abs(a);
        if (a < 0){
            minus_count++;
        }
        if (abs(a) < abs(min_abs_value)){
            min_abs_value = abs(a);
        }
    }
    if (minus_count % 2 == 0){
        cout << total << endl;
    }else{
        cout << total - 2 * min_abs_value << endl;
    }
    return 0;
}