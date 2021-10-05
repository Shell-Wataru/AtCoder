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
    ll K;
    cin >> K;
    if (K % 2 == 0){
        cout << K/2 * K/2 << endl;
    }else{
        cout << K/2 * (K+1)/2 << endl;
    }
    return 0;
}