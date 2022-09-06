#include <bits/stdc++.h>
using namespace std;

//This sorting algorithm works for list of positive integers and the integers should be less than MAX
// Time complexity = O(n+MAX)

const int MAX = 100000;
void countingSort(vector<int> &arr, int n, vector<int> &out){

    // declaring and initializing array to store count of elements
    int c[MAX];
    for(int i = 0; i < MAX; i++){
        c[i] = 0;
    }
    for(int i = n; i >= 1; i--){
        c[arr[i]]++;
    }

    // storing the count of all elements less than equal to a particular element
    for(int i = 1; i < MAX; i++){
        c[i] += c[i-1];
    }

    // placing each element to it's position in output array
    for(int i = n; i >= 1; i--){
        out[c[arr[i]]] = arr[i];
        c[arr[i]]--;
    }
}

int main(){
    // driver code 
    int n;
    cin >> n;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<int> out(n+1);
    countingSort(arr,n,out);
    for(int i = 1; i <= n; i++){
        cout << out[i] << " ";
    }
}