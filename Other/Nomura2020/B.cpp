#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

long long extGCD(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

ll reverse(ll n,ll modulo){
    ll x,y;
    extGCD(n, modulo, x, y);
    return (x + ((abs(x / modulo) + 1) * modulo)) % modulo;
}

int main()
{
    // 整数の入力
    string S;
    cin >> S;
    for(int i = 0;i < S.length();i++){
        if (S[i] == '?'){
            S[i] = 'D';
        }
    }
    cout << S << endl;
    return 0;
}