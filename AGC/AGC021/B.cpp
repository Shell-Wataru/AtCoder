#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;

int A[300][300] = {0};
set<int> removedSet;

int main()
{
    // 整数の入力
    long long N,x,y,i;
    vector<pair<long long,double>> data;
    cin >> N;
    double* prob = new double[N];
    for (i = 0;i< N;i++){
        cin >> x >> y;
        if (x == 0){
            data.push_back(make_pair(i,y/abs(y) * M_PI/2));
        }else{
            data.push_back(make_pair(i,atan(y*1.0/x)));
        }
    }
    sort(data.begin(),data.end(),[](pair<long long,long long> a,pair<long long,long long>  b){return a.second > b.second;});
    for (i = 0; i<N;i++){
        prob[data[i].first] = (abs(data[(i+1)% N].second - data[i].second)/2 + abs(data[(N + i - 1)% N].second - data[i].second)/2)/M_PI;
    }

    for(i = 0;i<N;i++){
        cout << prob[i] << endl;
    }
    return 0;
}