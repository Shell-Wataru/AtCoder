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
    // vector<ll> a = {5,1,4,2,3,6};
    // vector<ll> a = {5,4,3,2,1,6};
    vector<ll> a = {1,6,4,2,3,5,4};
    // vector<ll> a = {5,6,3,2,1,4};
    ll n = a.size();
    ll k = 6;
    cout << n << " "  << k << endl;
    while(true){
        string type;
        cin >> type;
        if (type == "and"){
            ll i,j;
            cin >> i >> j;
            i--;j--;
            cout << (a[i] & a[j]) << endl;
        }else if (type == "or"){
            ll i,j;
            cin >> i >> j;
            i--;j--;
            cout << (a[i] | a[j]) << endl;
        }else{
            ll result;
            cin >> result;
            cerr << result << endl;
            break;
        }
    }
    return 0;
}
