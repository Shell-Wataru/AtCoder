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
    char a;
    cin >> a;
    // cout << a - 'a' << endl;
    if ((a - 'a') >= 0){
        cout << 'a' << endl;
    }else{
        cout << 'A' << endl;
    }
   return 0;
}