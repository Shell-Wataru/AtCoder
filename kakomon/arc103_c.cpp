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
    string s;
    cin >> s;
    ll n = s.length();
    if (s.back() == '1' || s.front() == '0'){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0;i <= n - 2 - i;i++){
        if (s[i] != s[n-2-i]){
            cout << -1 << endl;
        }
    }
    ll last_one = -1;
    for(int i = 0;i < n-1;i++){
        if (i == 0 || s[i-1] == '1'){
            cout << i << " " << i + 1 << "\n";
        }else{
            cout << i-1 << " " << i + 1 << "\n";
        }
    }
    cout << flush;
    return 0;
}