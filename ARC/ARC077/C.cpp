#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    // 整数の入力
    long long N,i,k;
    deque<long long>data;
    string s;
    cin >> N;
    for (i= 0;i< N ;i++){
        cin >> k;
        if (N%2==0 ^ i%2!=0){
            data.push_back(k);
        }else{
            data.push_front(k);
        }
    }
    cout << data[0];
    for (i=1;i<N;i++){
        cout << " "<< data[i];
    }
    cout << endl;
    return 0;
}