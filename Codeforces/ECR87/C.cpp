#define _USE_MATH_DEFINES
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    // cout << "==" << endl;
    ll n;
    cin >> n;
    if (n % 2 == 0){
        double theta = M_PI/(2*n);
        // cout << sin(theta ) << endl;
        cout << fixed << setprecision(12) <<1.0/(tan(theta)) << endl;
    }else{
        double theta = M_PI/(2*n);
        double x = 1.0/sin(theta);
        double max_height = 0;
        // cout << x << endl;
        for(int i = 1;i < n;i++){
            double alpha = M_PI - M_PI/4 - M_PI*i/n;
            double heigt = x * sin(alpha);
            // cout << alpha/M_PI << endl;
            max_height = max(max_height,heigt);
            // cout << heigt << endl;
        }
        // cout << x << endl;
        cout << fixed << setprecision(12) << max_height << endl;
    }
    return 0;
}
int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    // cout << flush;
    return 0;
}
