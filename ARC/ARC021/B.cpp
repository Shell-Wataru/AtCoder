#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll total_xor = 0;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        total_xor = total_xor ^ A[i];
    }

    if (total_xor == 0){
        ll b = 0;
        for(int i = 0;i < N;i++){
            cout << b << endl;
            b = b ^ A[i];
        }
    }else{
        cout << -1 << endl;
    }
    return 0;
}