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
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         vector<int>left;
         vector<int>right;
         for(int i=l;i<=m;i++){
             left.push_back(arr[i]);
         }
         for(int i=m+1;i<=r;i++){
             right.push_back(arr[i]);
         }
        
         int i=0;
         int j=0;
         int k=l;
         while(i<left.size()&&j<right.size()){
             if(left[i]<=right[j]){
                 arr[k]=left[i];
                 k++;
                 i++;
             }
             else{
                 arr[k]=right[j];
                 k++;
                 j++;
             }
         }
         while(i<left.size()){
             arr[k]=left[i];
             i++;
             k++;
         }
         while(j<right.size()){
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
            
            int mid=l+(r-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
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