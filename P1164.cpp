#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[101];
int f[10001];
int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	f[0]=1;
	for (int i=1;i<=n;i++)
	for (int j=m;j>=a[i];j--)
		a[j]+=a[j-a[i]];
	cout<<f[m]<<endl;
	return 0;
}
