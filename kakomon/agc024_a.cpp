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
    ll A,B,C,K;
    cin >> A >> B >> C >> K;
    if (K % 2 == 0){
        cout << A - B << endl;
    }else{
        cout << B - A << endl;
    }
    return 0;
}