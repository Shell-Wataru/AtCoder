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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N, Q;
    cin >> N >> Q;
    vector<double> base(20001);
    vector<double> ruisekiwa(20002, 0);
    for (int i = 0; i < N; i++)
    {
        ll x, r, h;
        cin >> x >> r >> h;
        for (int j = 0; j < h; j++)
        {
            double h1 = j+1;
            double r1 = r * h1/h;
            double h2 = j;
            double r2 = r * h2/h;
            base[x + h - 1 - j] += r1*r1*h1 - r2*r2*h2;
        }
    }
    for (int i = 0; i < 20002; i++)
    {
        ruisekiwa[i + 1] = ruisekiwa[i] + base[i];
    }
    // for(int i = 0;i < 10;i++){
    //     cout << ruisekiwa[i] << endl;
    // }
    for (int i = 0; i < Q; i++)
    {
        ll A, B;
        cin >> A >> B;
        // cout << fixed << setprecision(12) << (ruisekiwa[B] - ruisekiwa[A]) << endl;
        cout << fixed << setprecision(12) << M_PI * (ruisekiwa[B] - ruisekiwa[A]) / 3 << endl;
    }
    return 0;
}
