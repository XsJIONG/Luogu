#include <iostream>
using namespace std;

namespace Problem {
	int n,m,x,y,k;
	int a[2005][2005];
	void ReadData() {
		cin>>n>>m>>x>>y>>k;
		for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	void Solve() {
		
	}
}

int main() {
	Problem::ReadData();
	Problem::Solve();
	return 0;
}
