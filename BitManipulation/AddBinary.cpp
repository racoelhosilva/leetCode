#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    int aidx = a.size() - 1, bidx = b.size() - 1;
    int carry;
    string result = "";
    while (aidx >= 0 || bidx >= 0){
        int sum = carry;
        if (aidx >= 0){ sum += a[aidx] - '0'; aidx--;}
        if (bidx >= 0){ sum += b[bidx] - '0'; bidx--;}
        carry = sum / 2;
        result.append(to_string(sum % 2));
    } 
    if (carry == 1) {result.append(to_string(carry));}
    reverse(result.begin(), result.end());
    return result;
}