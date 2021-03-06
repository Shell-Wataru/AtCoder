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
    ll N;
    cin >>  N;
    set<ll> unique_x;
    for (size_t i = 0; i < N; i++)
    {

        ll x;
        cin >> x;
        while( x % 2 == 0){
            x /= 2;
        }
        unique_x.insert(x);
    }
    cout << unique_x.size() << endl;
    return 0;
}