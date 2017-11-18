#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;

map<long long,long long> XFactorial
map <long long,long long> XFactorialInverse

long long Combination(long long n,long long m ,long long p){

}

int main()
{
    // 整数の入力
    long long N,i,K,temp,all,all_1,out,out_1,all_2,K1,K2;
    for (i= 0;i<= ;i++){
        cin >> temp;
        if (mp.find(temp) != mp.end()){
            K1 = mp[temp];
            K2 = i;
        }else{
            mp[temp] = i;
        };
    }

    map<int,int> mp;
    cin >> N;
    all = 1;
    all_1 = 1;
    out = 1;
    out_1 = 1;
    all_2 = 0;

    for (i= 0;i<=N ;i++){
        cin >> temp;
        if (mp.find(temp) != mp.end()){
            K1 = mp[temp];
            K2 = i;
        }else{
            mp[temp] = i;
        };
    }

    for (i= 0;i<=N ;i++){
        all = (all*(N-1-i)/(i+1))% 1000000007;
        out = (out*(K1 + N - K2-i)/(i+1))% 1000000007;
        //cout <<all << ","<<out << endl;
        cout << (all + (all_1 - out_1)*2 + out_1 + all_2) % 1000000007 << endl;
        all_2 = all_1;
        all_1 = all;
        out_1 = out;
    }
    return 0;
}