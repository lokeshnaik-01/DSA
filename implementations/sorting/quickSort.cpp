#include <bits/stdc++.h>
using namespace std;
int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int i=low;
    for(int j=low; j<=high; j++) {
        if(a[j] < pivot) {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
}
void quickSort(vector<int> &a, int low, int high) {
    if(low<high) {
        int ind = partition(a, low, high);
        quickSort(a, low, ind-1);
        quickSort(a, ind+1, high);
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
    cout << "Quick sort" << endl;
    quickSort(a, 0, n-1);
    print(a);
}