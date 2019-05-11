#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>

using namespace std;

int times(int number){
    if (number <= 5){
        return 0;
    }else if(number == 6 || number == 7){
        return 1;
    }else if(number == 8){
        return 2;
    }else if(number == 9){
        return 3;
    }else {
        return 0;
    }
}

int main()
{

    long long N,M,temp;

    cin >> N >> M;

    if (N == 1){
        vector<long long> data;
        for (int j = 0; j< M;j++){
            cin >> temp;
            data.push_back(temp);
        }

        int max_number = *max_element(data.begin(),data.end());
        if (max_number == 0){
            cout << "Yes 0" << endl;
        }else{
            int min_value = 1000000;
            for (int i = 0; i < data.size();i++){
                if (data[i] == 5){
                    int max_before = *max_element(data.begin(),data.begin() + i);
                    int max_after = *max_element(data.begin() + i,data.end());
                    min_value = min(min_value, times(max_before) + times(max_after) + 1);
                }
            }

            if (min_value != 1000000){
                cout << "Yes " << min_value << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }else if (M == 1) {
        vector<long long> data;
        for (int j = 0; j< N;j++){
            cin >> temp;
            data.push_back(temp);
        }

        int max_number = *max_element(data.begin(),data.end());
        if (max_number == 0){
            cout << "Yes 0" << endl;
        }else{
            int min_value = 1000000;
            for (int i = 0; i < data.size();i++){
                if (data[i] == 5){
                    int max_before = *max_element(data.begin(),data.begin() + i);
                    int max_after = *max_element(data.begin() + i,data.end());
                    min_value = min(min_value, times(max_before) + times(max_after) + 1);
                }
            }

            if (min_value != 1000000){
                cout << "Yes " << min_value << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }else{
        set<long long> contains;

        for (int i = 0;i< N;i++){
            for (int j = 0; j< M;j++){
            cin >> temp;
                contains.insert(temp);
            }
        }

        int max_number = *max_element(contains.begin(),contains.end());
        if (max_number == 0){
            cout << "Yes 0" << endl;
        }else if(contains.find(5) != contains.end()){
            cout << "Yes " << times(max_number) + 1 << endl;
        }else {
            cout << "No" << endl;
        }

    }

    return 0;
}