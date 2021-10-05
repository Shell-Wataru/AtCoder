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
    ll N;
    ll T,A;
    cin >> N >> T >> A;
    ll min_index = -1;
    double min_diff = numeric_limits<double>::max();
    for(int i = 0;i < N;i++){
        ll h;
        cin >> h;
        double diff = abs(A - (T - 0.006 * h));
        if (diff < min_diff){
            min_diff = diff;
            min_index = i;
        }
    }
    cout << min_index + 1 << endl;
    return 0;
}