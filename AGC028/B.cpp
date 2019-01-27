#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;


int main()
{
    // 整数の入力
    long long N,result,base,a,multi,i,nkaijou,multiTotal;
    vector<long long>A;
    vector<long long> multiRuiseki;
    nkaijou = 1;
    base = 1000000007;
    result = 0;
    multi = 1;
    cin >> N;
    multiRuiseki.push_back(0);
    A.push_back(0);
    for (i = 1;i<=N;i++){
        nkaijou = (nkaijou * i)% base;
        multi = (nkaijou + ((i-1)* multi) % base) %base;
        multiRuiseki.push_back(multi + multiRuiseki.back());
        cin >> a;
        A.push_back(a);
    }

    multiTotal = multiRuiseki.back();
    for (i = 1;i<=N;i++){
        
    }

    cout << result % base << endl;
    return 0;
}