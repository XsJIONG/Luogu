#include <iostream>
using namespace std;

int a[11];
int k;
int f[1000005];
int main() {
	for (int i=1;i<=10;i++) cin>>a[i];
	cin>>k;
	for (int i=1;i<=k;i++) f[i]=2147483647;
	f[0]=0;
	for (int i=1;i<=k;i++)
	for (int j=1;j<=min(10,i);j++)
		f[i]=min(f[i],f[i-j]+a[j]);
	cout<<f[k]<<endl;
	return 0;
}
