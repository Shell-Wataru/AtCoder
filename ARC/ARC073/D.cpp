#include<iostream>
#include <algorithm>
#include <vector>
#include <deque> 
using namespace std;


int main()
{
    // 整数の入力
    long long N,i,j;
    cin >> N;
    vector<long long> a;
    long long infinity = 9223372036854775807;
    long long maxTotal = -infinity;
    for (i=0;i<3*N;i++){
        long long temp;
        cin >> temp;
        a.push_back(temp);
    }

    for (i=N;i<=2*N;i++){
        vector<long long> tempA(a);
        sort(tempA.begin(),tempA.begin()+ i);
        sort(tempA.begin()+i,tempA.end());
        long long total = 0;
        for (j= 0;j<N;j++){
            total = total + tempA[i-1-j] - tempA[i+j];
        }
        if (total > maxTotal){
            maxTotal = total;
        }
    }

    cout << maxTotal<< endl;
    return 0;
}

