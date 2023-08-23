//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int q, int r)
    {
         // Your code here
         int n=q-l+1;
         int m=r-q;
         int left[n];
         int right[m];
         for(int i=0;i<n;i++){
             left[i]=arr[l+i];
         }
         for(int j=0;j<m;j++){
             right[j]=arr[j+q+1];
         }
         int i=0,j=0,k=l;
         while(i<n&&j<m){
             if(left[i]<=right[j]){
                 arr[k]=left[i];
                 i++;
                 k++;
             }
             else{
                 arr[k]=right[j];
                 j++;
                 k++;
             }
         }
         while(i<n){
             arr[k]=left[i];
                 i++;
                 k++;
         }
         while(j<m){
             arr[k]=right[j];
                 j++;
                 k++;
         }
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l<r){
            int q=l+(r-l)/2;
            mergeSort(arr,l,q);
            mergeSort(arr,q+1,r);
            merge(arr,l,q,r);
        }
    }
};


//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends