#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include "miscfunc.h"

using namespace std;

array<int, 100> readfile(){
    using namespace std;
    string temp = "1";
    int num;
    vector<int> nums;
    int passes = 0;
    array<int, 100> ints;
    ifstream file("file.txt");
    while (getline(file, temp))
    {
        nums.clear();
        stringstream nums1(temp);
        while (nums1 >> num)
            nums.push_back(num);

        for (int i = 0; i < 10; ++i)
        {
            ints[i + (passes * 10)] = nums[i];
        }
        passes++;
    }
    return ints;

}

int findindex(array<int, 100> ints) {

    int num;
    cout << "What number are you looking for?";
    cin >> num;

    for (int i = 0; i < 100; i++) {
        if (ints[i] == num) {
            return i;
        }
    }
    return -999;
}

array<int, 100> findint(array<int, 100> ints) {
    vector<int> nums;
    int temp, num, num2;

    cout << "What index do you want to change?";
    cin >> num;
    cout << "What value do you want to change it to?";
    cin >> num2;

    temp = ints[num];
    ints[num] = num2;
    cout << "Old Value: " << ints[temp] << "  |   New Value: " << ints[num] << "\n";
    return ints;

}

array<int, 100> remove(array<int, 100> ints) {
    int index;
    cout << "What index do you want to zero out?";
    cin >> index;
    ints[index] = 0;
    return ints;
}