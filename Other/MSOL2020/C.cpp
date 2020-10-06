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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for(int i = K;i < N;i++){
        if (A[i-K] < A[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
   return 0;
}