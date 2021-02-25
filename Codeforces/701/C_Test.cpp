#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;


int main()
{
    ll n = 5;
    vector<ll> A = {3,2,1,4,5};
    cout << n << endl;
    while(true){
        char t;
        cin >> t;
        ll k;
        cin >> k;
        cerr << t << " " << k << endl;
        if (t == '!'){
            cout << k << endl;
            break;
        }else{
            k--;
            cout << A[k] << endl;
        }
    }
    return 0;
}
