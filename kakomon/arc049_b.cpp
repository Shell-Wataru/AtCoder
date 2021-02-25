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

struct takahashi {
    ll x,y,c;
};
int main()
{
    // 整数の入力
    ll N, K;
    cin >> N;
    vector<takahashi> T(N);
    for (int i = 0; i < N; i++)
    {
        ll x,y,c;
        cin >> x >> y >> c;
        T[i] = {x,y,c};
    }
    double max_dx = 0;
    double max_dy = 0;
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            double dx =  1.0 * abs(T[i].x - T[j].x) *  T[i].c * T[j].c /(T[i].c + T[j].c);
            max_dx= max(max_dx,dx);
            double dy =  1.0 * abs(T[i].y - T[j].y) *  T[i].c * T[j].c /(T[i].c + T[j].c);
            max_dy= max(max_dy,dy);
        }
    }
    cout << fixed << setprecision(12) << max(max_dx,max_dy) << endl;
    return 0;
}