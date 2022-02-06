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
    vector<ll> ans(N);
    ll index = 0;
    vector<ll> A_Sum(N+1,0);
    vector<ll> B_Sum(N+1,0);
    vector<ll> C_Sum(N+1,0);
    for(int i = 0;i < N;i++){
        A_Sum[i+1] += A_Sum[i];
        B_Sum[i+1] += B_Sum[i];
        C_Sum[i+1] += C_Sum[i];
        if (S[i] == 'A'){
            A_Sum[i+1]++;
        }
        if (S[i] == 'B'){
            B_Sum[i+1]++;
        }
        if (S[i] == 'C'){
            C_Sum[i+1]++;
        }
    }
    for()
    return 0;
}