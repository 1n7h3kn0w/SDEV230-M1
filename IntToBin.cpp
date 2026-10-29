#include <stdint.h>
#include <iostream>
using namespace std;

void PrintRevBin(uint64_t number) {
    while(number) {
        cout << (number % 2);
        number /= 2;
    }
    cout << endl;
    return;
}

void PrintBin(uint64_t number) {
    char buff[65] = {0};
    int8_t buffpoint = 0;


    while(number) {
        switch(number % 2) {
            case 0:
                buff[buffpoint++] = 0x30;
                break;
            case 1:
                buff[buffpoint++] = 0x31;
                break;
            default:
                cout << "An error occurred, exiting now." << endl;
                exit(1);
                break;
        }
        number /= 2;
    }
    while(buffpoint) {
        cout << buff[--buffpoint];
    }
    cout << endl;
}

int main() {
    uint64_t number = 0;
    cout << "Input a single positive intager: ";
    cin >> number;
    cout << endl;
    cout << "This is the binary of " << number << " from LSB to MSB." << endl;
    PrintRevBin(number);
    cout << "This is the binary of " << number << " from MSB to LSB." << endl;
    PrintBin(number);
    return 0;
}