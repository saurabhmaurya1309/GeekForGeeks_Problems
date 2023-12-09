//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
     vector<int>pf;
    
    void findPrime(int n){
        if(n==1)return;
        
        for(int i=2;i<=n;i++){
            if(n%i==0){
                pf.push_back(i);
                findPrime(n/i);
                break;
            }
        }
    }
    
    int sum_digits(int n){
        
        int sum=0;
        
        while(n!=0){
            int digit=n%10;
            n=n/10;
            sum+=digit;
        }
        return sum;
    }
    
    bool ifPrime(int n){
        if(pf.size()==1)return true;
        return false;
    }
    
  public:
    int smithNum(int n) {
           
       findPrime(n);
       if(ifPrime(n)){
           return 0;
       }
       int sumofDigits=sum_digits(n);
       
       int sumofFactors=0;
       for(auto it:pf){
           
           sumofFactors+=sum_digits(it);
       }
       
       
       //cout<<endl<<sumofFactors<<" "<<sumofDigits<<endl;
       
       if(sumofFactors==sumofDigits)return 1;
       return 0;
       
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends