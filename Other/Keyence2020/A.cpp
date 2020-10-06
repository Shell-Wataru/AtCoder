
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
    ll H,W,N;
    cin >> H >>W >> N;
    ll max_counts = max(H,W);
    cout << (N + max_counts - 1)/max_counts << endl;

    return 0;
}