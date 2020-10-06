#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N+1,0);
    for(int x = 1;x <= 100;x++){
        for(int y = 1;y <= 100;y++){
            for (int z = 1; z <= 100; z++)
            {
                ll n = x*x + y*y + z*z + x*y + y*z+ z*x;
                if (n <= N){
                    A[n]++;
                }
            }

        }
    }
    for (size_t i = 1; i <= N; i++)
    {
        cout << A[i] << endl;
    }

   return 0;
}