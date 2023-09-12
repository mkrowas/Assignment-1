#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include<array>
#include "miscfunc.h"

using namespace std;

int main()
{
    array<int, 100> ints;
    int index,num1;
    char input = 'P';
    ints = readfile();

    while (input != 'Q') {
        cout << "What do you want to do?\nF:Find index of a number\nC:Change value at index\nR:Remove Item at index\nP:Print Array\nQ:Quit";
        cin >> input;
        input = toupper(input);
        switch (input) {
            case 'C':
                ints = findint(ints);
                break;
            case 'Q':
                break;
            case 'P':
                for (int i = 0; i < 100; i++) {
                    cout << ints[i] << "|";
                }
                cout << "\n";
                break;
            case 'R':
                ints = remove(ints);
                break;
            case 'F':
                num1 = findindex(ints);
                if (num1 == -999)
                    cout << "Number not found in array.\n";
                else
                    cout << "Number located at index " << num1 << "\n";
                break;
            default:
                cout << "Incorrect input. Please try again.";
                break;
        }
    }

}