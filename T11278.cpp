#include <bits/stdc++.h>
using namespace std;

int f[10005],a[10005],l[10005];
int main() {
	int n=0;
	int r;
	while (cin>>a[++n]);
	int ans,po,nn,maxx=-1;
	f[1]=1;
	l[1]=-1;
	for (int i=2;i<=n;i++) {
		ans=0;
		po=-1;
		for (int j=1;j<i;j++)
			if (a[j]<=a[i]&&f[j]>ans) {
				ans=f[j];
				po=j;
			}
		f[i]=ans+1;
		if (f[i]>maxx) {
			maxx=f[i];
			nn=i;
		}
		l[i]=po;
	}
	printf("max=%d\n",maxx);
	int q=nn;
	po=1;
	while (q!=-1) {
		a[po++]=a[q];
		q=l[q];
	}
	for (int i=po-1;i>=1;i--)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
