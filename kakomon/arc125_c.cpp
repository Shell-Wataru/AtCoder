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
    ll N, K;
    cin >> N >> K;
    vector<bool> used(N+1,false);
    vector<ll> A;
    vector<ll> answers;
    for (int i = 0; i < K; i++)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    }
    A[K-1] = N;
    ll unused_index = 1;
    for (int i = 0; i < K-1; i++)
    {
        answers.push_back(A[i]);
        used[A[i]] = true;
        while(used[unused_index]){
            unused_index++;
        }
        if (unused_index < A[i]){
            answers.push_back(unused_index);
            used[unused_index] = true;
        }
    }
    for(int i = N;i>= 1;i--){
        if (!used[i]){
            answers.push_back(i);
        }
    }
    for (auto a : answers)
    {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
