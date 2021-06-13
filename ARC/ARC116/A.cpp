#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int solve(){
    ll N;
    cin >> N;
    ll two_count = 0;
    while(N % 2 == 0){
        two_count++;
        N/= 2;
    }
    if (two_count == 0){
        cout << "Odd" << endl;
    }else if(two_count == 1){
        cout << "Same" << endl;
    }else{
        cout << "Even" << endl;
    }
    return 0;
}
int main()
{
    ll T;
    cin >> T;
    for(int i = 0;i < T;i++){
        solve();
    }

    return 0;
}