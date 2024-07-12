#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.second>b.second||(a.second==b.second&&a.first<b.first);
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int>arr(n);
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    unordered_map<int,int>ump;
	    for(int i=0;i<n;i++){
	        ump[arr[i]]++;
	    }
	    vector<pair<int,int>>ans(ump.begin(),ump.end());
	    sort(ans.begin(),ans.end(),cmp);
	    vector<int> result;
	    for(int i=0;i<ans.size();i++){
	        int value=ans[i].first;
	        int freq=ans[i].second;
	        for(int j=0;j<freq;j++){
	           cout<<value<<" ";
	        }
	    }
	    cout<<endl;
	   // return result;
	    
	}
	return 0;

}