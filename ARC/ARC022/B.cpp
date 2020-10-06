#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0;i< N;i++){
        cin >> A[i];
    }
    set<ll> using_nums;
    ll max_length = 0;
    ll from = 0;
    for(int i = 0;i< N;i++){
        while(using_nums.find(A[i])!= using_nums.end()){
            using_nums.erase(A[from]);
            from++;
        }
        using_nums.insert(A[i]);
        max_length = max(max_length,i - from + 1);
    }
    cout << max_length << endl;
    return 0;
}