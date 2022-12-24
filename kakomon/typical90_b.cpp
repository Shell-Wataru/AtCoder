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
    ll N;
    cin >> N;
    if (N % 2 == 0){
        vector<ll> numbers(N,0);
        for(int i = N/2;i < N;i++){
            numbers[i] = 1;
        }
        do{
            string ans = "";
            ll depth = 0;
            bool valid = true;
            for(int i = 0;i < N;i++){

                if (numbers[i] == 0){
                    depth++;
                    ans+= '(';
                }else{
                    depth--;
                    ans+= ')';
                }
                if (depth < 0){
                    valid = false;
                    break;
                }
            }
            if (valid){
                cout << ans << "\n";
            }
        }while(next_permutation(numbers.begin(),numbers.end()));
        cout << flush;
    }
    return 0;
}