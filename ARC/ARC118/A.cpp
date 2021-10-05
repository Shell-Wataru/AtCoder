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
    ll N;
    ll t;
    cin >> t;
    cin >> N;
    ll A = (100 * N + t - 1)/t;
    cout << (100 + t)*A/100 - 1 << endl;
    return 0;
}