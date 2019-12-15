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
#include <set>
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
    ll N,X,D;
    cin >> N >> X >> D;
    ll greatest_common = gcd(X,D);
    ll smallest = X * D/gcd(X,D);
    ll x_count = smallest/ X;
    ll d_count  = smallest/D;
    ll counts = 0;

    for(int i = 0;i <= N;i++){
        ll min_d = i * (i - 1)/2;
        ll max_d = i * (2 * N - i + 1)/2;

    }
    return 0;
}