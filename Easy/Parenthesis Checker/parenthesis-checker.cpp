//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool match(char top,char ch){
        if((top=='('&&ch==')')||(top=='{'&&ch=='}')||(top=='['&&ch==']')){
            return true;
        }
        return false;
    }
    bool ispar(string x)
    {
        stack<char>st;
        for(int i=0;i<x.length();i++){
            char ch=x[i];
            if(ch=='('||ch=='{'||ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    // cout<<"sf";
                    return false;
                }
                char top=st.top();
                if(match(top,ch)){
                    st.pop();
                }
                else{
                    //  cout<<"sf";
                    return false;
                }
                
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends