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
    ll H,N,total;
    cin >> H >> N;
    total = 0;
    for (size_t i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        total += a;
    }
    if (total >= H){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
  return 0;
}