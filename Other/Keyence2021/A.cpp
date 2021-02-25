
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
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> Amax(N);
    vector<ll> B(N);
    ll a_max = numeric_limits<ll>::min();
    ll b_max = numeric_limits<ll>::min();
    for(int i = 0;i< N;i++){
        cin >> A[i];
        if (a_max < A[i]){
            a_max = A[i];
        }
        Amax[i] = a_max;
    }

    for(int i = 0;i< N;i++){
        cin >> B[i];
    }

    ll c_max = numeric_limits<ll>::min();
    for(int i = 0;i< N;i++){
        if (c_max < B[i] * Amax[i]){
            c_max = B[i] * Amax[i];
        }
        cout << c_max << endl;
    }

    return 0;
}