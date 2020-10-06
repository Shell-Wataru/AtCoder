#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1e+9 + 7;

long long gcd(long long a, long long b){

    if (a== 0){
        return b;
    }else if (b == 0){
        return a;
    }

    if (a%b == 0){
        return b;
    }else{
        return gcd(b,a%b);
    }
}

int main()
{
    ll x;
    cin >> x;
    ll g = gcd(x,360);
    ll lcm = x*360/g;
    cout << lcm/x << endl;
    return 0;
}