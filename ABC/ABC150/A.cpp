
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
    ll N,K;
    cin >> N >> K;
    if (500 * N >= K){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}