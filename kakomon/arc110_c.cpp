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
    vector<ll> A(N);
    vector<ll> index(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i]--;
        index[A[i]] = i;
    }
    vector<bool> used(N-1,false);
    vector<ll> answer;
    for(int i = 0;i < N-1;i++){
        for(int j = index[i]-1;j >= i;j--){
            if (used[j]){
                cout << -1 << endl;
                return 0;
            }
            used[j] = true;
            answer.push_back(j);
            swap(A[j],A[j+1]);
            index[A[j]] = j;
            index[A[j+1]] = j+1;
        }
        // cout << A[i] << endl;
    }
    if (answer.size() == N -1){
        for(auto p:answer){
            cout << p + 1<< "\n";
        }
        cout << flush;
    }else{
        cout << -1 << endl;
    }
    return 0;
}