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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

int solve(){
    ll N;
    string S1,S2,S3;
    cin >> N;
    cin >> S1;
    cin >> S2;
    cin >> S3;
    if ((S1.back() == '0' || S1.front() == '0') &&
        (S2.back() == '0' || S2.front() == '0') &&
        (S3.back() == '0' || S3.front() == '0')){
        cout << string(N,'1') << '0' << string(N,'1') << endl;
    }else{
        cout << string(N,'0') << '1' << string(N,'0') << endl;
    }
    return 0;
}
int main()
{
    ll T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}