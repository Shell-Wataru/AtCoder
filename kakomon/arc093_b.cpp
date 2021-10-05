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
    ll A,B;
    cin >> A >> B;
    vector<string> ans(100);
    for(int i =0;i < 50;i++){
        ans[i] = string(100,'#');
    }

    for(int i =50;i < 100;i++){
        ans[i] = string(100,'.');
    }
    A--;
    B--;
    for(int i = 0;i < A;i++){
        ans[2*(i/50)][2*(i%50)] = '.';
    }
    for(int i = 0;i < B;i++){
        ans[2*(i/50)+51][2*(i%50)] = '#';
    }
    cout << 100 << " " << 100 << endl;
    for(int i = 0;i < 100;i++){
        cout << ans[i] << endl;
    }
    return 0;

}