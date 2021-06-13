#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int main()
{
    ll K;
    cin >> K;
    ll a = 1;
    ll b = 1;
    for(int i = 0; i< K -1;i++){
        a = a+b;
        swap(a,b);
    }
    cout << a << " " << b << endl;
    return 0;
}