#include "binary_search.hpp"

int binary_search(int arr[], int beg, int end, int target) {
    if(beg > end) {
        return -1;
    }
    int mid = beg + (end - beg) / 2;
    if(arr[mid] == target) {
        return mid;
    }
    else if (arr[mid] > target) {
        return binary_search(arr, beg, mid - 1, target);
    }
    return binary_search(arr, mid + 1, end, target);
}
