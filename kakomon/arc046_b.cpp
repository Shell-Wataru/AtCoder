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

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    if (A == B){
        if (N % (A+1) == 0){
            cout << "Aoki" << endl;
        }else{
            cout << "Takahashi" << endl;
        }
    }else if (A > B){
        cout << "Takahashi" << endl;
    }else{
        if (N <= A){
            cout << "Takahashi" << endl;
        }else{
            cout << "Aoki" << endl;
        }
    }
    return 0;

}