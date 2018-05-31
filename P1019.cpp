#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

namespace Problem {
	int n;
	string ar[21];
	short used[21];
	int ans=-1;
	int dp[21][21];
	void ReadData() {
		cin>>n;
		for (int i=1;i<=n+1;i++) cin>>ar[i];
	}
	int cd(int a, int b) {
		if (dp[a][b]!=-1) return dp[a][b];
		int i=0;
		int al=ar[a].length(), bl=ar[b].length();
		int mm=min(al,bl);
		int ma=0;
		bool q;
		for (i=mm-1;i>=1;i--) {
			q=true;
			for (int j=0;j<i;j++) if (ar[a][al-i+j]!=ar[b][j]) {
				q=false;
				break;
			}
			if (q) ma=i;
		}
		if (ma==al||ma==bl) ma=0;
		dp[a][b]=ma;
		return ma;
	}
	void dfs(int t, int last) {
		int c;
		for (int i=1;i<=n;i++) {
			if (used[i]>1) continue;
			if ((c=cd(last,i))!=0) {
				used[i]++;
				dfs(t+ar[i].length()-c,i);
				used[i]--;
			}
		}
		if (t>ans) ans=t;
	}
	int Solve() {
		ReadData();
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			dp[i][j]=-1;
		for (int i=1;i<=n;i++) dp[n+1][i]=(ar[i][0]==ar[n+1][0]);
		dfs(1,n+1);
		cout<<ans<<endl;
		return 0;
	}
}

int main() {
	return Problem::Solve();
}
