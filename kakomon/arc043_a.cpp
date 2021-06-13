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
    // 整数の入力
    ll N , A , B;
    cin >> N >> A >> B;
    vector<double> S(N);
    double total = 0;
    for(int i = 0;i < N;i++){
        cin >> S[i];
        total += S[i];
    }
    double mean = total/N;
    sort(S.begin(),S.end());
    if( S.back() ==  S.front()){
        if (B == 0){
            cout << 0 << " " << A;
        }else{
            cout << -1 << endl;
        }
    }else{
        double p = B/(S.back() - S.front());
        double q = A - mean*p;
        cout << fixed << setprecision(12) << p << " " << q << endl;
    }
    return 0;
}