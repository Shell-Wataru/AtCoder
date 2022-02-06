#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 1000000007;

int main()
{
    ll N;
    string S;
    cin >> N;
    cin >> S;
    if (S.front() != S.back()){
        cout << 1 << endl;
    }else{
        for(int i = 1;i < N-2;i++){
            if (S[0] != S[i] && S[i+1] != S[N-1]){
                cout << 2 << endl;
                return 0;
            }
        }
        cout << -1 << endl;
    }
    return 0;
}