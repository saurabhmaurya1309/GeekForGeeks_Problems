//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}

// } Driver Code Ends




//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
     //Your code here
      int b=x.length();

     

    for(int i=0;i<s.length()-b+1;i++){

        if(x==string(s.begin()+i, s.begin() +b+i))

           return i;

    }

return -1;
     
     
}