//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
          int ans;
        for(int i=0;i<str.length();i++){
            if(str[i]=='I'){
                if((i+1<str.length()&&str[i+1]=='V')||(i+1<str.length()&&str[i+1]=='X')){
                    ans=ans-1;
                }
                else{
                    ans=ans+1;
                }
            }
            if(str[i]=='V'){
                ans=ans+5;
            }
            if(str[i]=='X'){
                if((i+1<str.length()&&str[i+1]=='C')||(i+1<str.length()&&str[i+1]=='L')){
                    ans=ans-10;
                }
                else{
                    ans=ans+10;
                }
            }
            if(str[i]=='L'){
                ans=ans+50;
            }
             if(str[i]=='C'){
                if((i+1<str.length()&&str[i+1]=='D')||(i+1<str.length()&&str[i+1]=='M')){
                    ans=ans-100;
                }
                else{
                    ans=ans+100;
                }
            }
            if(str[i]=='D'){
                ans=ans+500;
            }
            if(str[i]=='M'){
                ans=ans+1000;
            }
            
        }
        return ans;
        
        
    //  int value(char roman)
    // {
    //     switch(roman)
    //     {
    //         case 'I':return 1;
    //         case 'V':return 5;
    //         case 'X':return 10;
    //         case 'L':return 50;
    //         case 'C':return 100;
    //         case 'D':return 500;
    //         case 'M':return 1000;
    //     }
    // }
    // int romanToDecimal(string &str) {
    //     int i, n, ans=0, p=0;
    //     n=str.length()-1;
    //     for( i=n; i>=0; i--)
    //     {
    //         if( value(str[i]) >= p)
    //             ans = ans + value(str[i]);
    //         else
    //             ans = ans - value(str[i]);
    //         p = value(str[i]);

    //     }
    //     return ans;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends