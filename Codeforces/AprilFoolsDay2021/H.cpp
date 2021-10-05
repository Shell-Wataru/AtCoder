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
    ll input;
    cin >> input;
    ll n = input / 1000;
    ll m = input % 1000;
    ll answer = 1;
    for(int i = n; i > 0; i = i - 2){
        answer = answer * i % m;
    }
    cout << answer << endl;
    // for (int i = 1; i <= t; i++)
    // {
    //     solve();
    // }
    return 0;
}
