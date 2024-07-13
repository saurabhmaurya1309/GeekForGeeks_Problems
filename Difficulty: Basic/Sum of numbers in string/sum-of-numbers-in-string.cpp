//{ Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


// } Driver Code Ends

#include<bits/stdc++.h>
class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	
        int ans=0;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            string num;
            while(str[i]>='0'&&str[i]<='9'){
                num+=str[i];
                i++;
            } 
            int x=0;
            if(num.size()){
                x=stoi(num);
            }
            // cout<<num<<endl;
            // stoi(num);
            ans+=x;
            
        }
        return ans;
    	
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}

// } Driver Code Ends