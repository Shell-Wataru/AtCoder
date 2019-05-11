#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    long long N;
    cin >> N;
    cout <<  min((N/10) * 100 + (N % 10) * 15,(N/10) * 100 + 100) << endl;
   return 0;
}