#include<iostream>
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
mp::cpp_int BASE_NUM = 1777777777L;

mp::cpp_int extGCD(mp::cpp_int a, mp::cpp_int b, mp::cpp_int &x, mp::cpp_int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    mp::cpp_int d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

mp::cpp_int combination(mp::cpp_int n,mp::cpp_int m){
    mp::cpp_int value = 1;
    if (m > n-m){
        m = n-m;
    }
    for (mp::cpp_int i = 0;i < m;i++){
        value = (value * (n - i)) % BASE_NUM;
    }

    for (mp::cpp_int i = 1;i <= m;i++){
        mp::cpp_int x,y,reverse;
        extGCD(i,BASE_NUM,x,y);
        reverse = (x + ((abs(x/BASE_NUM) + 1)* BASE_NUM) )% BASE_NUM;
        value = (value * reverse) % BASE_NUM;
    }
    return value;
}
int main()
{
    // 整数の入力
    mp::cpp_int N,K;
    cin >> N >> K;
    mp::cpp_int a = combination(N,K);
    vector<mp::cpp_int> Kcombinations;
    Kcombinations.push_back(1);
    Kcombinations.push_back(0);
    for(int i = 2;i<=K;i++){
        Kcombinations.push_back((i-1)*( (Kcombinations[i-1] + Kcombinations[i-2]) % BASE_NUM )% BASE_NUM);
    }
    cout << a * Kcombinations[(int)K] % BASE_NUM << endl;
    return 0;
}