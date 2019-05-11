#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
int main()
{
    // 整数の入力
    double Xa,Ya,Xb,Yb,Xc,Yc,a,b,c,d;
    string DegOut;
    cin >> Xa >> Ya;
    cin >> Xb >> Yb;
    cin >> Xc >> Yc;
    a = Xb - Xa;
    b = Yb - Ya;
    c = Xc - Xa;
    d = Yc - Ya;
    cout << fixed << setprecision(14) << abs(a * d - b * c)/2 << endl;
    return 0;
}