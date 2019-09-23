#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long T;
    map<ll,ll> piles;
    cin >> T;
    for(int i = 0;i < T;i++){
        ll n,k;
        cin >> n >> k;
        if (k % 3 != 0){
            if ( n % 3 == 0){
                cout << "Bob" << endl;
            }else{
                cout << "Alice" << endl;
            }
        }else{
            ll a = n % (k+1);
            if (a != k && (a % 3)  == 0){
                cout << "Bob" << endl;
            }else{
                cout << "Alice" << endl;
            }
        }
    }
   return 0;
}