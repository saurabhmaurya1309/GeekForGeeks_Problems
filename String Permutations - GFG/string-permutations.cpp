//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(int index,string S,vector<string>&st){
	        if(index>=S.length()){
	           st.push_back(S);
	            return;
	        }
	        for(int j=index;j<S.length();j++){
	            swap(S[j],S[index]);
	            solve(index+1,S,st);
	            swap(S[j],S[index]);
	        }
	    }
		vector<string>permutation(string S)
		{
		    // Code here there
		    vector<string>ans;
		    solve(0,S,ans);
		   sort(ans.begin(),ans.end());
		    return ans;
		}
   
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends