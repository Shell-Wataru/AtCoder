
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
    ll A,B,C;
    cin >> A >> B >> C;
    if (A+B+C <=21 ){
        cout << "win" << endl;
    }else{
        cout << "bust" << endl;
    }
    return 0;
}