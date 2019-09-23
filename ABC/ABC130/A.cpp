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
    ll X,A;
    cin >>X>> A;

    if (X <A){
        cout << 0 <<endl;
    }else{
        cout << 10 <<endl;
    }
    return 0;
}