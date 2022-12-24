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
    // 整数の入力
    ll N,D,X,Y;
    cin >> N >> D >> X >> Y;
    vector<double> factorial(N+1,0);
    for(int i = 1;i <= N;i++){
        factorial[i] = log(i) + factorial[i-1];
    }
    double log4 = log(4);
    if (X % D != 0 || Y % D != 0){
        cout << 0 << endl;
        return 0;
    }
    X /= D;
    Y /= D;
    X = abs(X);
    Y = abs(Y);
    if (X+Y > N){
        cout << 0 << endl;
        return 0;
    }
    if ((N- (X+Y)) % 2 != 0){
        cout << 0 << endl;
        return 0;
    }
    ll remain = (N- (X+Y))/2;
    // cout << remain << endl;
    double ans = 0;
    for(int i = 0; i <= remain;i++){
        double log_ans = factorial[N] - log4 * N - factorial[X+i] - factorial[i] - factorial[Y+remain-i] - factorial[remain-i];
        ans += exp(log_ans);
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}