//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    int counter=2;
    bool isLucky(int n) {
        // code here
        if (counter > n) 
            return true;
    
        // If n is divisible by the current counter, then n isn't a lucky number
        if (n % counter == 0)
            return false;
    
        // If n isn't divisible, then reduce the position of n. 
        n = n - n / counter;
    
        // Move on to the next number (which essentially means, delete every "counter-th" number)
        counter++;
    
        return isLucky(n);
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends