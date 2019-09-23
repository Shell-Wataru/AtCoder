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
    long long N;
    ll total = 0;
    cin >> N;
    for(int i = 0;i< N; i++){
        ll a,b;
        cin >> a >> b;
        total += a*b;
    }

    cout << (int)(total * 1.05)<<endl;
    return 0;
}