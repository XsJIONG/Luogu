#include <iostream>
using namespace std;

long long a[105];
int n;
int z;
int x,mmax,c;
void multiply(int k) {
	mmax=-1;
	for (int i=a[0];i>=1;i--) {
		z=a[i]*k;
		a[i]=0;
		c=i;
		while (z!=0) {
			a[c++]+=z%10;
			z/=10;
			z+=a[c-1]/10;
			a[c-1]=a[c-1]%10;
		}
		if (c-1>mmax) mmax=c-1;
	}
	if (mmax!=-1) a[0]=mmax;
}
int main() {
	cin>>n;
	if (n==0) {
		cout<<"0!=0"<<endl;
		return 0;
	}
	a[0]=1;
	a[1]=1;
	for (int i=2;i<=n;i++) multiply(i);
	cout<<n<<"!=";
	for (int i=a[0];i>=1;i--) cout<<a[i];
	cout<<endl;
	return 0; 
}
