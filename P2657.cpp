#include <iostream>
using namespace std;

namespace Problem {
	int L,R;
	int ll[15],rl[15];
	int dp[15][11];
	void ReadData() {
		cin>>L>>R;
	}
	void loadSW(int q, int* ar) {
		int c=0;
		while (q) {
			ar[++c]=q%10;
			q/=10;
		}
		ar[0]=c;
	}
	int abs(int a, int b) {
		return (a>b?a-b:b-a);
	}
	void init() {
		loadSW(L,ll);
		loadSW(R,rl);
		for (int i=0;i<=9;i++)
			dp[1][i]=1;
		for (int i=2;i<=14;i++)
		for (int j=0;j<=9;j++)
		for (int k=0;k<=9;k++)
			if (abs(j,k)>=2) dp[i][j]+=dp[i-1][k];
	}
	int Get(int* ar) {
		int ans=0;
		for (int i=1;i<ar[0];i++)
		for (int j=1;j<10;j++)
			ans+=dp[i][j];
		for (int i=1;i<ar[ar[0]];i++)
			ans+=dp[ar[0]][i];
		for (int i=ar[0]-1;i>0;i--) {
			for (int j=0;j<ar[i];j++)
				if (abs(j,ar[i+1])>=2) ans+=dp[i][j];
			if (abs(ar[i],ar[i+1])<2) break;
		}
		return ans;
	}
	int Solve() {
		ReadData();
		R++;
		init();
		cout<<Get(rl)-Get(ll)<<endl;
		return 0;
	}
}

int main() {
	return Problem::Solve();
}
