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
    ll N,K;
    cin >> N >> K;
    if (K % 2 == 0){
        ll odds = N/K;
        ll evens = N/K + (N%K)/(K/2);
        ll ans = odds * odds * odds + evens * evens * evens;
        cout << ans << endl;
    }else{
        ll count = N/K;
        cout << count * count * count << endl;
    }
   return 0;
}