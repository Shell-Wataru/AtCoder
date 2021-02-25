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
    cin >> N;
    ll grundy = 0;
    map<ll,ll> color_counts;
    for (size_t i = 0; i < N; i++)
    {
      ll a;
      cin >> a;
      color_counts[a]++;
    }
    ll remain = N;
    ll last = 0;
    for(auto &p:color_counts){
      ll width = (p.first - last) % 2;
      ll height = remain;
      grundy = grundy ^ (width * height);
      remain = remain - p.second;
      last = p.first;
    }
    if (grundy == 0){
      cout << "second" << endl;
    }else{
      cout << "first" << endl;
    }

    return 0;
}