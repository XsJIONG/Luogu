#include <bits/stdc++.h>
using namespace std;

struct Field {
	int x,y,hs;
	void set(int a, int b, int c) {
		x=a; y=b; hs=c;
	}
	int abs(int a) {
		return a<0?-a:a;
	}
	int dis(int &a, int &b) {
		int q=abs(a-x)+abs(b-y);
		a=x; b=y;
		return q;
	}
};
Field a[405]; //Base On 1
int m,n,k,top=0,tmp,ans=0,x,y,tim=0;
bool compare(Field a, Field b) {
	return a.hs>b.hs;
}
int main() {
	cin>>m>>n>>k;
	for (int i=1;i<=m;i++)
	for (int j=1;j<=n;j++) {
		cin>>tmp;
		if (tmp==0) continue;
		a[++top].set(i,j,tmp);
	}
	if (top==0) {
		cout<<"0"<<endl;
		return 0;
	}
	sort(a+1,a+top+1,compare);
	tim++;
	if (tim>k) {
		cout<<"0"<<endl;
		return 0;
	}
	x=1; y=a[1].y;
	top=0;
	while (true) {
		tim+=a[++top].dis(x,y);
		tim++;
		if (tim+a[top].x>k) {
			cout<<ans<<endl;
			return 0;
		}
		ans+=a[top].hs;
	}
	cout<<ans<<endl;
	return 0;
}
