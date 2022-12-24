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

namespace mp = boost::multiprecision;
using namespace std;

using ll = long long;

int main()
{
    ll N,H;
    cin >> N >> H;
    if (H == 1){
        cout << 1;
        for(int i = 2;i*i <= N;i++){
            if (N % i == 0){
                for(int j = 0;j < i;j++){
                    cout << " " << i;
                }
                for(int j = 0;j < N/i;j++){
                    cout << " " << N/i;
                }
            }
        }
        cout << endl;
    }else{
        vector<ll> numbers = {1};
        for(int i = 2;i*i <= N;i++){
            if (N % i == 0){
                numbers.push_back(i);
                numbers.push_back(N/i);
            }
        }
        sort(numbers.rbegin(),numbers.rend());
        ll realH = H;
        if (H > N/H){
            H = N/H;
        }
        vector<vector<ll>> Answer;
        ll W = N/H;
        for(auto n:numbers){
            for(int i = 0;i < n;i++){
                if (Answer.empty() || Answer.back().size() == W){
                    Answer.push_back({n});
                }else{
                    Answer.back().push_back(n);
                }
            }
        }
        if (realH != H){
            for(int i = 0;i < W;i++){
                for(int j = 0;j < H;j++){
                    if (j != 0){
                        cout << " ";
                    }
                    cout << Answer[j][i];
                }
                cout << endl;
            }
        }else{
            for(int i = 0;i < H;i++){
                for(int j = 0;j < W;j++){
                    if (j != 0){
                        cout << " ";
                    }
                    cout << Answer[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}