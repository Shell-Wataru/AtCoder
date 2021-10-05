#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
using namespace std;
using ll = long long;
string ALPHABETS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for(int i = 1; i<= T;i++){
        ll N,L;
        vector<long long> primes;
        set<long long> used_primes;
        map<long long,char> dictionary;
        set<ll> hints;

        cin >> N;
        cin >> L;
        ll *secret_text = new ll[L];

        for(int j=2;j<= N;j++){
            if(all_of(primes.begin(),primes.end(),[j](long long p) {return j % p != 0;})){
                primes.push_back(j);
            }
        }

        for(int j=0;j< L;j++){
            cin >> secret_text[j];
            hints.insert(secret_text[j]);
        }

        for(auto f : hints) {
        // use f here
            bool breaked = false;
            for (int k = 0; k< primes.size() ;k++){
                if (f % primes[k] == 0){
                    breaked = true;
                    used_primes.insert(primes[k]);
                    used_primes.insert(f/primes[k]);
                    break;
                }
            }
        }

        int iterator = 0;
        for(ll p : used_primes){
            dictionary[p] = ALPHABETS[iterator];
            iterator++;
        }

        vector<ll> first_char_alternatives;
        for (ll p : used_primes){
            if (secret_text[0] % p == 0){
                first_char_alternatives.push_back(p);
            }
        }


        ll correct_first_char;
        for(ll first_char: first_char_alternatives){
            ll last_char = first_char;
            bool decipher = true;
            for (int j =0; j< L;j++ ){
                if (secret_text[j] % last_char != 0){
                    decipher = false;
                    break;
                }

                last_char = secret_text[j]/ last_char;
            }

            if (decipher){
                correct_first_char = first_char;
            }
        }

        ll last_char = correct_first_char;
        cout << "Case #" << i << ": ";
        cout << dictionary[correct_first_char];
        for (int j =0; j< L;j++ ){
            last_char = secret_text[j]/ last_char;
            cout << dictionary[last_char];
        }

        cout << endl;
    }

    return 0;
}