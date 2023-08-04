//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    vector<int>res;
        int d=256;
        void solve(string pat,string txt, int q)
        {
            int m=pat.length(),n=txt.length(),p=0,t=0,h=1,j=0;
            for(int i=0;i<m-1;i++)
            {
                h=(h*d)%q;
            }
            for(int i=0;i<m;i++)
            {
                p=(d*p+pat[i])%q;
                t=(d*t+txt[i])%q;
            }
            for(int i=0;i<=n-m;i++)
            {
                if(p==t)
                {
                    for(j=0;j<m;j++)
                    {
                        if(txt[i+j]!=pat[j])
                        {
                            break;
                        }
                    }
                    if(j==m)
                        res.push_back(i+1);
                }
                if(i<n-m)
                {
                    t=(d*(t-txt[i]*h)+txt[i+m])%q;
                    if(t<0)
                        t=t+q;
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
             int q=INT_MAX;
            solve(pat,txt,q);
            if(res.size()==0)
                res.push_back(-1);
            return res;
            
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends