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
    ll n,l,r,min_s,max_s,now;
    cin >> n  >> l >> r;
    now = 1;
    min_s = 0;
    max_s = 0;
    for(int i = 0;i< l;i++){
        min_s += 1<<i;
    }
    min_s += n-l;

    for(int i = 0;i< r;i++){
        max_s += 1<<i;
    }
    max_s += (1<<(r-1))*(n-r);

    cout << min_s << " " << max_s << endl;

    return 0;
}