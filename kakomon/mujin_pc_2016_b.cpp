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

int main()
{
    ll A,B,C;
    cin >> A >> B >> C;
    vector<ll> L = {
        A,B,C
    };
    sort(L.begin(),L.end());
    if (L[2] > L[0] + L[1]){
        cout << fixed << setprecision(12) << M_PI * ((A+B+C)*(A+B+C) -  (L[2] - L[0] - L[1])* (L[2] - L[0] - L[1])) << endl;
    }else{
        cout << fixed << setprecision(12) << M_PI * ((A+B+C)*(A+B+C)) << endl;
    }
    return 0;
}