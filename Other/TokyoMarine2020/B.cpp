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
    ll A,B,V,W,T;
    cin >> A >> V >>  B >> W >> T;
    ll d = abs(A- B);
    ll vv =  V - W;
    if (vv <= 0){
        cout << "NO" << endl;
    }else{
        ll t = (d + vv - 1)/vv;
        if (t <= T){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}