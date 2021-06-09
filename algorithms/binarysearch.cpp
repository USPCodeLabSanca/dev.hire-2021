// template fera
#include <bits/stdc++.h>
using namespace std;

// [Time → O(log(n)) Space → O(log(n))]
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = (l + r) / 2;
  
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
  
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
  
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
  
    // We reach here when element is not
    // present in array
    return -1;
}

// [Time → O(log(n)) Space → O(1)]
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = (l + r) / 2;
  
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
  
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
  
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
  
    // if we reach here, then element was
    // not present
    return -1;
}


int main (){

	ios :: sync_with_stdio(false);


}