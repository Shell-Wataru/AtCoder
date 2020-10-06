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
    ll total = 0;
    for(int a = 1; a <= K;a++){
        for(int b=1 ; b<= K;b++){
            for(int c = 1; c<=K;c++){
                total += gcd(gcd(a,b),c);
            }
        }
    }
    cout << total << endl;
   return 0;
}