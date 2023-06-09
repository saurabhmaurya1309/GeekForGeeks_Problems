//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void solve(int index,string S,set<string>&st){
	        if(index>=S.length()){
	           st.insert(S);
	            return;
	        }
	        for(int j=index;j<S.length();j++){
	            swap(S[j],S[index]);
	            solve(index+1,S,st);
	            swap(S[j],S[index]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    set<string>st;
		    solve(0,S,st);
		   vector<string>ans;
		   for(auto itr:st){
		       ans.push_back(itr);
		   }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends