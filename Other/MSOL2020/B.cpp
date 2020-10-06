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
    ll A,B,C;
    cin >> A >> B >> C;
    ll K;
    cin >> K;
    for(int i = 0;i < K;i++){
        if (B <= A){
            B = B * 2;
        }else if(C <= B){
            C = C * 2;
        }
    }
    if (A < B && B < C){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}