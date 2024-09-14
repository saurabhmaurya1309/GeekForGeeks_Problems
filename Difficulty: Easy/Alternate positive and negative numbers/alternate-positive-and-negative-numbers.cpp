//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int>pos,neg;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>=0){
                pos.push_back(arr[i]);
            }
            else{
                neg.push_back(arr[i]);
            }
        }
        int j=0,k=0;
        
        for(int i=0;i<arr.size();i++){
            if(j<pos.size()){
                arr[i]=pos[j];
                j++;
                if(k<neg.size())
                    i++;
            }
            if(k<neg.size()){
                arr[i]=neg[k];
                k++;
            }
        }
        // for(int i=0;i<arr.size();i++){
        //     cout<<arr[i]<<" ";
        // }cout<<endl;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends