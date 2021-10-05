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
    vector<ll> A(N+1);
    for(int i = 0;i <= N;i++){
        cin >> A[i];
    }
    ll min_diff = numeric_limits<ll>::max();
    for(int i = 0;i < N;i++){
        min_diff = min(min_diff,abs(A[i] - A[i+1]));
    }
    cout << min_diff << "\n";
    for(int i = 0;i < min_diff;i++){
        for(int j = 0;j <=N;j++){
            if (j != 0){
                cout << " ";
            }
            if (i < A[j] % min_diff){
                cout << A[j]/min_diff + 1;
            }else{
                cout << A[j]/min_diff;
            }

        }
        cout << "\n";
    }
    cout << flush;
    return 0;
}