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
    ll P,Q,R;
    cin >> P >> Q >> R;

    cout << min(min(P+Q,Q+R),R+P)<<endl;
    return 0;
}