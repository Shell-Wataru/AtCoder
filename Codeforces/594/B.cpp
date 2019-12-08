#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<ll> lines;
    ll total = 0;
    for(int i =0;i<N;i++){
        ll a;
        cin >> a;
        lines.push_back(a);
        total += a;
    }
    sort(lines.begin(),lines.end());
    ll small_side = 0;
    for(int i = 0;i<N/2;i++){
        small_side += lines[i];
    }
    ll large_side = total - small_side;
    cout << small_side*small_side + large_side * large_side << endl;
   return 0;
}
