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
    vector<ll> maxOnes(N);
    vector<ll> minOnes(N);
    ll current = 0;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    for(int i = 0;i < N;i++){
        if (A[i] == 0){
            current--;
        }else{
            current++;
        }
        maxOnes[i] = current;
        minOnes[i] = current;
    }
    for(int i = N-2;i >= 0;i--){
        maxOnes[i] = max(maxOnes[i],maxOnes[i+1]);
        minOnes[i] = min(minOnes[i],minOnes[i+1]);
    }
    ll maxScore = max(0ll,maxOnes[0]);
    ll minScore = min(numeric_limits<ll>::max(),minOnes[0]);
    current = 0;
    for(int i = 0;i < N;i++){
        if (A[i] == 0){
            current--;
        }else{
            current++;
        }
        maxScore = max(maxScore,maxOnes[i] - current);
        minScore = min(minScore,minOnes[i] - current);
    }
    // cout << maxScore << endl;
    // cout << minScore << endl;
    cout << maxScore - minScore + 1 << endl;
    return 0;
}