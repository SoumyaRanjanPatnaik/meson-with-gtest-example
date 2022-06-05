#include "binary_search.hpp"
#include <functional>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int t;
    cin>>t;
    cout<<"Found at: "<<binary_search(arr, 0, n-1, t);
}
