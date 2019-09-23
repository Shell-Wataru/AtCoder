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

int main()
{
    // 整数の入力
    long long T;
    cin >> T;
    for(int i = 0;i< T;i++){
        ll n,s,t,a,b,c;
        cin >> n >> s >> t;
        a = n - t;
        b = s + t - n;
        c = n -s ;
        cout << max({a+1,c+1}) << endl;
    }
    return 0;
}