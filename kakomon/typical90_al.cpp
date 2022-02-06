#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int solve()
{
    ll A,B;
    cin >> A >> B;
    ll gcdAB = gcd(A,B);
    A /=  gcdAB;
    if (A < numeric_limits<ll>::max()/B && A*B <= 1000000000000000000ll){
        cout << A*B << endl;
    }else{
        cout << "Large" << endl;
    }
    return 0;
}

int main()
{
    // ll t;
    // cin >> t;
    // for(int i = 0;i < t;i++){
    solve();
    // }
    cout << flush;
    return 0;
}