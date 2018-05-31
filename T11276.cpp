#include <bits/stdc++.h>
using namespace std;

int n;
int a[1002][1002];
int main() {
	cin>>n;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=i;j++)
		cin>>a[i][j];
	for (int i=n-1;i>=1;i--)
	for (int j=1;j<n;j++)
		a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
	printf("max=%d\n",a[1][1]);
	return 0;
}
