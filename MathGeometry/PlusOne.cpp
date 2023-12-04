#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int lastPosition = digits.size()-1;
    while (digits[lastPosition] == 9){
        digits[lastPosition] = 0;
        if (lastPosition == 0){
            digits.push_back(0);
            break;
        }
        else {
            lastPosition--;
        }
    }
    digits[lastPosition]++;
    return digits;  
}
