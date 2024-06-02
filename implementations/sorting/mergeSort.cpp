#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &a, int left, int mid, int right) {
    int n1 = mid-left+1;
    int n2 = right-mid;
    vector<int> leftSubArr(n1);
    vector<int> rightSubArr(n2);
    
    for(int i=0; i<n1; i++) {
        leftSubArr[i] = a[left+i];
    }
    for(int i=0; i<n2; i++) {
        rightSubArr[i] = a[mid+1+i];
    }
    int i=0, j=0, k=left;
    while(i<n1 && j<n2) {
        if(leftSubArr[i] < rightSubArr[j]) {
            a[k++] = leftSubArr[i++];
        }
        else {
            a[k++] = rightSubArr[j++];
        }
    }
    while(i<n1) {
        a[k++] = leftSubArr[i++];
    }
    while(j<n2) {
        a[k++] = rightSubArr[j++];
    }
}
void mergeSort(vector<int> &a, int low, int high) {
    if(low<high) {
        int mid = (low+high)/2;
        mergeSort(a, low, mid);
        mergeSort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}
void print(vector<int> a) {
    for(int x: a) {
        cout << x <<  " ";
    }
}
int main()
{
    vector<int> a={4,2,6,2,5,1,56,23,-89, 0};
    int n = a.size();
    cout << "Merge sort" << endl;
    mergeSort(a, 0, n-1);
    print(a);
}