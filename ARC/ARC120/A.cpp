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
    ll N;
    cin >> N;
    ll total = 0;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        total+= a;
        A[i] = a;
    }
    ll max_value = numeric_limits<ll>::min();
    ll current_total = 0;
    ll base = 0;
    for(int i = 0;i < N;i++){
        if (A[i] > max_value){
            max_value = A[i];
        }
        base += current_total;
        current_total += A[i];
        cout << current_total + base + max_value  * (i+1) << endl;
    }

    return 0;
}