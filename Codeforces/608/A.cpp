#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator>  // std::rbegin, std::rend


using namespace std;
using ll = long long;


int main()
{
    // 整数の入力
    ll a,b,c,d,e,f;
    cin >> a >> b>> c>> d>> e>> f;
    ll first = min(a,d);
    ll second = min(min(d- first,b),c);
    ll best = first * e + second * f;
    second = min(min(d,b),c);
    first = min(a,d -second);
    best = max(best,first * e + second * f);
    cout << best << endl;
    return 0;
}