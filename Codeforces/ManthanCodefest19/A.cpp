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
    ll T;
    cin >> T;
    for(int i = 0;i<T;i++){
        ll n,a,b;
        cin >> a >> b >> n;
        if (n % 3 == 0){
            cout << a << endl;
        }else if ( n % 3 == 1){
            cout << b << endl;
        }else{
            cout << (a ^ b) << endl;
        }
    }
    return 0;
}