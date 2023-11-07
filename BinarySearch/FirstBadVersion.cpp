#include<bits/stdc++.h>
using namespace std;

// Checks if the version is bad or not (73 is an unknown number)
bool isBadVersion(int version){
    return version <= 73;
}

int firstBadVersion(int n) {
    int lowerBound = 0;
    int upperBound = n;
    while (!isBadVersion(lowerBound)){
        int midValue = lowerBound + (upperBound - lowerBound) / 2; // This avoids overflow!!
        if (isBadVersion(midValue)){
            upperBound = midValue; // If midValue is the fbv, then upperBound = midValue - 1; might skip the fbv
        }
        else {
            lowerBound = midValue + 1;
        }
    }
    return lowerBound;
}