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
    ll N;
    cin >> N;
    string S,X;
    cin >> S;
    cin >> X;
    vector<bool> win_numbers(7,false);
    win_numbers[0] = true;
    for(int i = N-1;i >= 0;i--){
        ll a = (S[i] - '0') % 7;
        vector<bool> next_win_numbers(7);
        if (X[i] == 'T'){
            for(int j = 0;j < 7;j++){
                if (win_numbers[(10 * j + a) % 7]){
                    next_win_numbers[j] = true;
                }
                if (win_numbers[(10 * j) % 7]){
                    next_win_numbers[j] = true;
                }
            }
        }else{
            for(int j = 0;j < 7;j++){
                bool all_win = true;
                if (!win_numbers[(10 * j + a) % 7]){
                    all_win = false;
                }
                if (!win_numbers[(10 * j) % 7]){
                    all_win = false;
                }
                next_win_numbers[j] = all_win;
            }
        }
        win_numbers = next_win_numbers;
    }
    if (win_numbers[0]){
        cout << "Takahashi" << endl;
    }else{
        cout << "Aoki" << endl;
    }
    return 0;
}
