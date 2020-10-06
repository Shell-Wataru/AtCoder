#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll a,b,c;
    cin >> a >> b >> c;
    ll diff = c- a -b;
    if (diff <= 0){
        cout << "No" << endl;
    }else if(4 * a * b < diff * diff){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
   return 0;
}