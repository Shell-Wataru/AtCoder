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
    long long N,M,A,B;
    cin >> N >> M >> A >> B;
    for(int i = 1;i<= M; i++){
        if (N <= A){
            N += B;
        }
        ll c;
        cin >> c;
        N -= c;
        if (N < 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << "complete" <<endl;
    return 0;
}