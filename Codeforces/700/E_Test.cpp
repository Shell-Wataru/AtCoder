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
    ll n = 4;
    vector<ll> A = {1,2,3,4};
    cout << n << endl;
    while(true){
        string t;
        cin >> t;
        // cerr << "!!!" << endl;
        if (t == "!"){
            break;
        }else{
            ll l,r;
            cin >> l >> r;
            l--;
            r--;
            if (t == "OR"){
                cout << (A[l] | A[r]) << endl;
            }else if(t == "XOR"){
                cout << (A[l] ^ A[r]) << endl;
            }else if(t == "AND"){
                cout << (A[l] & A[r]) << endl;
            }
        }
    }
    return 0;
}
