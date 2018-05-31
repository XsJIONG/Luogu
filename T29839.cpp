#include <iostream>
#include <algorithm>
using namespace std;

namespace Problem {
	struct Hill {
		int size,h,l;
	};
	const int Mx[4]={-1,0,1,0},My[4]={0,1,0,-1};
	Hill all[500005];
	int n,m;
	int a[1005][1005];
	int top;
	int Read() {
		int t=0;
		char c=getchar();
		while (!isdigit(c)) c=getchar();
		while (isdigit(c)) {
			t=(t<<3)+(t<<1)+(c-'0');
			c=getchar();
		}
		return t;
	}
	void ReadData() {
		top=0;
		n=Read(), m=Read();
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			a[i][j]=Read();
	}
	int ss,hh,ll;
	void find(int x, int y) {
		a[x][y]=0;
		for (int i=0;i<4;i++)
			if (a[x+Mx[i]][y+My[i]]!=0) hh=max(hh,a[x+Mx[i]][y+My[i]]),ll=min(ll,a[x+Mx[i]][y+My[i]]),ss++,find(x+Mx[i],y+My[i]);
	}
	bool ComparationForStructHill(Hill a, Hill b) {
		if (a.size==b.size) {
			if (a.h==b.h) return a.l<b.l;
			return a.h>b.h;
		}
		return a.size>b.size;
	}
	void Solve() {
		for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (a[i][j]!=0) ss=1,hh=a[i][j],ll=a[i][j],find(i,j),all[++top].size=ss,all[top].h=hh,all[top].l=ll;
		sort(all+1,all+top,ComparationForStructHill);
		cout<<top<<endl;
		for (int i=1;i<=top;i++) cout<<all[i].size<<' '<<all[i].h<<' '<<all[i].l<<endl;
	}
}

int main() {
	Problem::ReadData();
	Problem::Solve();
	return 0;
}
