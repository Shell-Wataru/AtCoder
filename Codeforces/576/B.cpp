#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM =  1000000007;

int main()
{
    ll H,L;
    cin >> H  >> L;
    cout << fixed << setprecision(12) << (H*H + L*L)*1.0/(2 * H) - H<< endl;

    return 0;
}