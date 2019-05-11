#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>

using namespace std;

int getMaxDevideTimes(int i) {
    if (i == 0){
        return 0;
    }else{
        return getMaxDevideTimes(i/2)+ 1;
    }
}


int main()
{
    // 整数の入力
    long long  N,K,i,a_i,result,temp,max_devide_times;
    max_devide_times = 0;
    cin >> N >> K;
    long long* numbers = new long long[N];
    long long* types = new long long[K];
    long long* before_types = new long long[K];

    for (i = 0;i< N;i++){
        cin >> temp;
        numbers[i] = getMaxDevideTimes(temp);
        max_devide_times = numbers[i];
    }

    for (i = 0;i<= max_devide_times;i++){
        before_types[i] = 1;
    }



    for (i = 1;i< N;i++){
        long long sum = 0;
        for (int j = 0;j <= i;j++){
            sum += numbers[j];
        }
        long long before_total = sum - numbers[i];
        cout << "sum" << sum << endl;
        for (long long j = 0;j <= numbers[i];j++){
            for(long long k = 0;j+k <= K;k++){
                cout <<  "k:"<< k << endl;
                cout << j+k << ":"<< before_types[k] << endl;
                types[j+k] += before_types[k];
            }
        }
        for (int j = 0;j<= max_devide_times;j++){
            before_types[j] = types[j];
            cout << "total:"<< j << ":" << types[j] << endl;
            types[j] = 0;
        }
    }

    cout << before_types[K] << endl;
    return 0;
}