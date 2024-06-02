/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
void selection(vector<int> &a, int n) {
    
    for(int i=0; i<n-1; i++) {
        int minInd = i;
        for(int j=i+1; j<n; j++) {
            if(a[j] < a[minInd]) {
                minInd = j;
            }
        }
        swap(a[i], a[minInd]);
    }
}
void insertion(vector<int> &a, int n) {
    for(int i=1; i<n; i++) {
        int j=i-1;
        int key = a[i];
        while(j>=0 && a[j]>key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1]=key;
    }
}
void bubble(vector<int> &a, int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
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
    cout << "Selection sort" << endl;
    selection(a, n);
    print(a);
    cout << "\n \n";
    
    
    a={4,2,6,2,5,1,56,23,-89, 0};
    cout << "Insertion sort" << endl;
    insertion(a, n);
    print(a);
    cout << "\n \n";
    
    a={4,2,6,2,5,1,56,23,-89, 0};
    cout << "Bubble sort" << endl;
    bubble(a, n);
    print(a);
    cout << "\n \n";
}