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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

const long long BASE_NUM = 1000000007;

int main()
{
    ll N;
    scanf("%lld", &N);
    if ( (N* (N-1)/2 ) % 6 != 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for(int i = 3;i <= 50;i++){
        if ((i* (i-1)/2 ) % 6 == 0){
            cout << i << endl;
        }
    }
    return 0;
}