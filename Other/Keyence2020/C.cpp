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
    ll N,K,S;
    cin >> N >> K >> S;
    ll dummy;
    if (S == 1000000000){
        dummy = 1;
    }else{
        dummy = 1000000000;
    }

    for(int i = 0;i < N;i++){
        if (i != 0){
            cout << " ";
        }
        if(i < K){
            cout << S;
        }else{
            cout << dummy;
        }
    }
    cout << endl;

   return 0;
}