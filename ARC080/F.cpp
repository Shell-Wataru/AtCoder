#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;


int main()
{
    // 整数の入力
    long long N,a_i,i;
    vector<long long>A;
    vector<long long>primes;
    for (i= 0; i< N ; i++) {
        cin >> a_i;
        A.push_back(a_i);
    }

    for(i=2;i<10000000;i++){
        if(all_of(primes.begin(),primes.end(),[i](long long p) {return i % p != 0;})){
            primes.push_back(i);
        }
    }
    cout << primes.size() << endl;

    return 0;
}