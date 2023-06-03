//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
            string temp="";
            int i=0;
            stack<string> st;
            while(i<s.size()){
                string no="";
                while(i<s.size()&& s[i]>='0'&&s[i]<='9'){
                    no+=s[i++];
                }
                if(no!=""){
                    st.push(no);
                    no="";
                }
                if(i<s.size()){
                    string ans="";
                    ans+=s[i];
                    st.push(ans);
                }
                i++;
            }
            while(!st.empty()){
               temp+=st.top();
               st.pop();
            }
            return temp;
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends