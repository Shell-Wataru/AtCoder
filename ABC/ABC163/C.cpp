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

long long gcd(long long a, long long b){
    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int main()
{
    // 整数の入力

    ll K;
    cin >>  K;
    map<ll,ll> counts;
    for(int i = 0;i < K-1;i++){
        ll a;
        cin >> a;
        counts[a]++;
    }
    for(int i = 1;i <= K ;i++){
        if (i != 1){
            cout << " ";
        }
        cout << counts[i];
    }
    cout << endl;
   return 0;
}