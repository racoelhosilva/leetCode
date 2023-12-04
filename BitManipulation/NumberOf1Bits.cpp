#include<bits/stdc++.h>
using namespace std;


int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0){
        if (n % 2 != 0){
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0){
        n &= n-1;
        count++;
    }
    return count;
}
