#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
#include <regex>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    ll N;
    cin >> N;
    ll total = 0;
    for(ll i = 1;i*i <= N;i++){
        if (N % i == 0){
            if (i != N){
                total += i;
            }
            if (N/i != i && N/i != N){
                total += N/i;
            }
        }
    }
    if (total == N){
        cout << "Perfect" << endl;
    }else if (total > N){
        cout << "Abundant" << endl;
    }else{
        cout << "Deficient" << endl;
    }
    return 0;
}