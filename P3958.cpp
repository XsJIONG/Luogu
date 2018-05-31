//XsJIONG Code 2018.5.26
//Chino±£ÓÓ£¬´úÂëÎŞBug

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

struct Ball {
	long long x,y,z;
}a[1002];
int f[1002];
int n,h,r,T;
long long temp;
bool fs;
long long ReadLL() {
	temp=0;
	fs=0;
	char c=getchar();
	while (!(c>='0'&&c<='9')&&c!='-') c=getchar();
	if (c=='-') {
		fs=1;
		c=getchar();
	}
	while (c>='0'&&c<='9') {
		temp=(temp<<3)+(temp<<1)+c-'0';
		c=getchar();
	}
	return fs?-temp:temp;
}
int tmp;
int Read() {
	tmp=0;
	char c=getchar();
	while (!(c>='0'&&c<='9')&&c!='-') c=getchar();
	while (c>='0'&&c<='9') {
		tmp=(tmp<<3)+(tmp<<1)+c-'0';
		c=getchar();
	}
	return tmp;
}
inline bool calcCollide(Ball a, Ball b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z))<=r*2;
}
int findParent(int i) {
	if (f[i]==i) return i;
	return f[i]=findParent(f[i]);
}
bool sky[1002],ground[1002];
void joinParent(int a, int b) {
	int aa=findParent(a), bb=findParent(b);
	if (aa!=bb) {
		if (sky[aa]) sky[bb]=1;
		if (ground[aa]) ground[bb]=1;
		f[aa]=bb;
	}
}
inline void Solve() {
	n=Read(), h=Read(), r=Read();
	for (int i=1;i<=n;i++) {
		f[i]=i;
		sky[i]=ground[i]=0;
	}
	int fa;
	for (int i=1;i<=n;i++) {
		a[i].x=ReadLL(), a[i].y=ReadLL(), a[i].z=ReadLL();
		fa=f[i];
		if (a[i].z+r>=h) sky[fa]=1;
		if (a[i].z<=r) ground[fa]=1;
		for (int j=1;j<i;j++)
			if (calcCollide(a[i],a[j])) joinParent(i,j);
	}
	for (int i=1;i<=n;i++) {
		if (sky[f[i]]&&ground[f[i]]) {
			cout<<"Yes\n";
			return;
		}
	}
	cout<<"No\n";
}
int main() {
	T=Read();
	while (T--) Solve();
	return 0;
}
