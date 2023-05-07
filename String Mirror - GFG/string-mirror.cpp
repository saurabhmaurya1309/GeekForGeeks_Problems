//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    
    string stringMirror(string s){
        // Code here
        string ans="";
        int i;
        if(s.length()>1&&s[0]==s[1]){
            ans=s[0];
            ans+=ans;
            return ans;
        }
        for(i=0;i<s.length()-1;i++){
            if(s[i]>=s[i+1]){
                ans+=s[i];
            }
            else{
                break;
            }
        }
        ans+=s[i];
        
        string temp="";
        for(int j=ans.size()-1;j>=0;j--){
            temp+=ans[j];
        }
        ans=ans+temp;
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends