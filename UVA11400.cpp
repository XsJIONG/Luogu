//Xs.JIONG 2018.5.31
//Chino±£ÓÓ£¬´úÂëÎŞBug 

#include <iostream>
#include <algorithm>
#include <memory.h>
#define M 1002
using namespace std;

struct Light {
	int v,k,c,l;
	void Read() {
		cin>>v>>k>>c>>l;
	}
};
bool cmp(Light a, Light b) {
	return a.v<b.v;
}
Light a[M];
int f[M];
int n;
int main() {
	cin>>n;
	for (int i=1;i<=n;i++)
		a[i].Read();
	sort(a+1,a+n+1,cmp);
	for (int i=2;i<=n;i++)
		a[i].l+=a[i-1].l;
	memset(f,127,sizeof(int)*(n+1));
	f[0]=0;
	for (int i=1;i<=n;i++)
	for (int j=0;j<i;j++)
		f[i]=min(f[i],f[j]+a[i].k+a[i].c*(a[i].l-a[j].l));
	cout<<f[n]<<endl;
	return 0;
}
