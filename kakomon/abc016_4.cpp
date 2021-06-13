#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve_linear_equation(double a11, double a12, double a21, double a22, double b1, double b2, double &x1, double &x2)
{
    double det = a11 * a22 - a12 * a21;
    if (abs(det) < 1e-8 )
    {
        // cout << a11 << a12 << a21 << a22 << endl;
        return 0;
    }
    else
    {
        x1 = 1.0 * (a22 * b1 - a12 * b2) / det;
        x2 = 1.0 * (-a21 * b1 + a11 * b2) / det;
        return 1;
    }
}

int main()
{
    double a_x,a_y,b_x,b_y;
    cin >> a_x >> a_y >> b_x >> b_y;
    ll N;
    cin >> N;
    double cross = 0;
    vector<pair<double,double>> P(N);
    for(int i =0;i < N;i++){
        cin >> P[i].first >> P[i].second;
    }
    // cout << "==" << endl;
    for(int i =0;i < N;i++){
        double a11 = b_y - a_y;
        double a12 = -b_x + a_x;
        double a21 = P[(i+1)% N].second - P[i].second;
        double a22 = -P[(i+1)% N].first + P[i].first;
        double b1 = a_x*b_y - b_x*a_y;
        double b2 = P[i].first*P[(i+1)% N].second - P[(i+1)% N].first*P[i].second;
        double x,y;
        ll solved = solve_linear_equation(a11,a12,a21,a22,b1,b2,x,y);
        // if (solved){
        //     cout << x << "," << y << endl;
        // }
        if (solved == 1 &&
            min(a_x,b_x) <= x && x <= max(a_x,b_x) &&
            min(a_y,b_y) <= y && y <= max(a_y,b_y) &&
            min(P[(i+1)% N].first,P[i].first) <= x && x <= max(P[(i+1)% N].first,P[i].first) &&
            min(P[(i+1)% N].second,P[i].second) <= y && y <= max(P[(i+1)% N].second,P[i].second)){
            cross++;
        }
    }
    cout << cross /2 + 1<< endl;
  return 0;
}
