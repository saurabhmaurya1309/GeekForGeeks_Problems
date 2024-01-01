//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if((nums.size())%2==1)
            return false;
        unordered_map<int,int>ump;
        for(int i=0;i<nums.size();i++){
            ump[nums[i]%k]++;
        }
        for(auto i:ump){
            int x=abs(k-i.first);
           
            if(i.first==0&&i.second%2==0)
                continue;
            if(ump[x]==i.second)
                continue;
                
            else
            {
                return false;
            }
        }
        return true;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends