#include<bits/stdc++.h>
#define LL long long
using namespace std;
void Merge(LL arr[], LL low, LL mid, LL high)
{
    LL i = low, j = mid + 1; //Stores the starting position of both parts in temporary variables.
    LL k = low;
    LL temp[1000];

    while(i <= mid and j <= high)
    {
        if(arr[i] < arr[j]) //checks if first part comes to an end or not .
            temp[k++] = arr[i++];
        else temp[k++] =  arr[j++]; //checks if second part comes to an end or not
    }
    while(i <= mid) // Puts the rest elements which are not entered in temp array upto mid
        temp[k++] = arr[i++];
    while(j <= high) // Puts the rest elements which are not entered in temp array upto mid
        temp[k++] = arr[j++];

    for(int i = low; i <= high; i++) // Puts temp elements into main array.
        arr[i] = temp[i];
}

void Merge_Sort(LL arr[], LL low, LL high)
{
    if(low == high) // Test the base case
        return;

    LL mid = (low + high) >> 1; // Divide the unsorted N list into  sublists, until each containing 1 element.
    Merge_Sort(arr, low, mid);  // Merge the left sub-tree
    Merge_Sort(arr, mid + 1, high); // Merge the right sub-tree
    Merge(arr, low, mid, high); // Merge the both parts by comparing elements of both the parts.
}
int main()
{
    LL N, Arr[100];
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> Arr[i]; // Enter the N amount of numbers.

    Merge_Sort(Arr, 0, N); // Calling the Merge_Sort() function.

    for(int i = 0; i < N; i++)
        cout << Arr[i] << ' ';
    cout << endl;
}

