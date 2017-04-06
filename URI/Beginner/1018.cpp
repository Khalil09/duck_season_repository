#include <iostream>

using namespace std;

int main() {

    long int number;
    int notes[7] = {100, 50, 20, 10, 5, 2, 1};

    cin >> number;
    cout << number << "\n";

    for(int i=0;i<7;i++){
        if(number >= notes[i]){
            cout << (number/notes[i]) << " nota(s) de R$ " << notes[i] << ",00\n";
            number = number % notes[i];
        } else{
            cout << "0 nota(s) de R$ " << notes[i] << ",00\n";
        }
    }

    return 0;
}
