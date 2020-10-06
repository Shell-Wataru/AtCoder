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
    vector<ll> X1(5);
    for (size_t i = 0; i < 5; i++)
    {
        cin >> X1[i];
    }

    ll ans = -1;
    for (size_t i = 0; i < 5; i++)
    {
        if(X1[i] == 0){
            ans = i;
            break;
        }
    }
    cout << ans+1 << endl;
   return 0;
}