#include <bits/stdc++.h>
using namespace std;

int a[1005],f1[1005],f2[1005];
bool Read(int &total) {
	char c;
	total=0;
	c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) {
		total=(total<<3)+(total<<1)+(c-'0');
		c=getchar();
	}
	return c!='\n'&&c!=EOF;
}
int main() {
	int n=0;
	int r;
	while (Read(r)) a[++n]=r;
	a[++n]=r;
	int max1,max2;
	f1[1]=1;
	f2[1]=1;
	int ans1=-1,ans2=-1;
	for (int i=2;i<=n;i++) {
		max1=0;
		max2=0;
		for (int j=1;j<i;j++) {
			if (f1[j]>max1&&a[j]>a[i]) max1=f1[j];
			if (f2[j]>max2&&a[j]<a[i]) max2=f2[j];
		}
		f1[i]=max1+1;
		f2[i]=max2+1;
		if (f1[i]>ans1) ans1=f1[i];
		if (f2[i]>ans2) ans2=f2[i];
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}
