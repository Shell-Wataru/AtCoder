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
#include <set>
using namespace std;
using ll = long long;

int main()
{
    ll N;
    double M,S;
    cin >> N >> M >> S;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    reverse(A.begin(), A.end());
    ll last = 0;
    double ans = 0;
    while (last < N){
        double maximum_mean = 0;
        int maximum_mean_index = -1;
        double total = 0;
        for(int i = last;i < N;i++){
            total += A[i];
            if (total/(i-last+1) > maximum_mean){
                maximum_mean = total/(i-last+1);
                maximum_mean_index = i;
            }
        }
        double count = (maximum_mean_index - last + 1);
        ans +=  count * maximum_mean * min(M,S/count);
        S -= min(M,S/count)* count;
        last = maximum_mean_index + 1;
    }
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}
