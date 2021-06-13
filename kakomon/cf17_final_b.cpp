#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    string S;
    cin >> S;
    ll a = 0;
    ll b = 0;
    ll c = 0;
    for(auto s:S){
        if (s == 'a'){
            a++;
        }else if(s == 'b'){
            b++;
        }else{
            c++;
        }
    }
    vector<ll> counts = {a,b,c};
    sort(counts.begin(),counts.end());
    // cout << a << b << c << endl;
    if(counts[1] == 0){
        if (counts[2] == 1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else if (counts[0] == 0){
        if (counts[1] == 1 && counts[2] == 1 ){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }else{
        if (counts[2] - counts[0] > 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}