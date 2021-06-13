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
    ll i = 0;
    ll j = S.size() - 1;
    ll ans = 0;
    while(i < j){
        if (S[i] == 'x' && S[j] == 'x'){
            i++;
            j--;
        }else if (S[i] == 'x'){
            i++;
            ans++;
        }else if (S[j] == 'x'){
            j--;
            ans++;
        }else if (S[i] == S[j]){
            i++;
            j--;
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}