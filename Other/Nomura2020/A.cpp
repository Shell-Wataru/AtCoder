
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <map>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll H1,M1,H2,M2,K;
    cin >> H1 >> M1 >> H2 >> M2 >> K;
    cout << max((H2 * 60 + M2) - (H1 * 60 + M1) - K,0LL) <<endl;

    return 0;
}