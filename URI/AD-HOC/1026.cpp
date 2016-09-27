#include <bits/stdc++.h>

using namespace std;

int xor_func (char a, char b) {
    return (a != b);
}

int main(){
    unsigned long long decimal1, decimal2;
    string res_binary = bitset<32>(0).to_string();

    unsigned long long res_decimal = bitset<32>(0).to_ulong();

    while(scanf("%lld%lld", &decimal1, &decimal2) == 2) {
        string binary1 = bitset<32>(decimal1).to_string();
        string binary2 = bitset<32>(decimal2).to_string();

        for(int j = 0; j < 32; j++){
            if (xor_func(binary1[j], binary2[j])) {
                res_binary[j] = '1';
            }
        }
        res_decimal = bitset<32>(res_binary).to_ulong();
        cout << res_decimal << endl;

        res_binary = bitset<32>(0).to_string();
    }

    return 0;
}
