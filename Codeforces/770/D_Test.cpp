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
    // vector<ll> a = {1,5,0,2,4,510};
    // vector<ll> a = {100,0,5,2,4,510};
    vector<ll> a = {0,100,5,2,4,510};
    cout << 1 << endl;
    cout << a.size() << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            ll i,j;
            cin >> i >> j;
            i--;j--;
            if (a[i] == 0 || a[j] == 0){
                cerr << "correct!!" << endl;
            }
            cerr << i << "," << j<< endl;
            break;
        }else{
            ll i,j,k;
            cin >> i >> j >> k;
            // cerr << t << " " << i <<" " << j << " " << x << endl;
            i--;j--;k--;
            cout << max(a[i],max(a[j],a[k])) - min(a[i],min(a[j],a[k])) << endl;;
        }
    }
    return 0;
}
