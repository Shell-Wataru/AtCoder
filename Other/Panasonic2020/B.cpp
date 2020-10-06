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

int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    if (H == 1 || W == 1){
        cout << 1 << endl;
    }else if (H % 2 == 0 || W % 2 == 0){
        cout << H * W / 2 << endl;
    }else{
        cout << H * W / 2 + 1 << endl;
    }
    return 0;
}