#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
int main()
{
    // 整数の入力
    long long N,i,x_i,y_i;
    vector<pair<long long,long long> > dots;
    cin >> N;
    for (int i = 0;i< N;i++){
        cin >> x_i >> y_i;
        dots.push_back(make_pair(x_i,y_i));
    }
    double max_d = 0;

    for (int i = 0;i< N;i++){
        for (int j = i;j< N;j++){
            pair<long long,long long>a = dots[i];
            pair<long long,long long>b = dots[j];

            double d = hypot(a.first- b.first,a.second - b.second);
            if (max_d < d){
                max_d = d;
            }
        }
    }

    cout << max_d << endl;
    return 0;
}