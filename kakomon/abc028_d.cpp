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
    // 整数の入力
    ll N,K;
    cin >> N >> K;
    double ans = 0;
    //全部異なる
    ans += (1.0/N)*((K-1.0)/N)*((N-K+0.0)/N)*6;
    //2つ同じ
    ans += (1.0/N)*(1.0/N)*((N-1.0)/N)*3;
    //3つ同じ
    ans += (1.0/N)*(1.0/N)*(1.0/N);
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}