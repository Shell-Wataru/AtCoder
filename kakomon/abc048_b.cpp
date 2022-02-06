#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll a,b,x;
    cin >> a >> b >> x;
    if (a > 0){
        cout << b/x - (a-1)/x << endl;
    }else{
        cout << b/x + 1 << endl;
    }

    return 0;
}