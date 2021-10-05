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
    ll N,A,B;
    cin >> N >> A >> B;
    vector<ll> X(N);
    for(int i = 0;i < N;i++){
        cin >> X[i];
    }
    ll ans = 0;
    for(int i = 1;i < N;i++){
        ans += min((X[i] - X[i-1]) * A,B);
    }
    cout << ans << endl;
    return 0;
}