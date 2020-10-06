
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
    ll S,L,R;
    cin >> S >> L >> R;
    if (S < L){
        cout << L << endl;
    }else if(S < R){
        cout << S << endl;
    }else{
        cout << R << endl;
    }
    return 0;
}