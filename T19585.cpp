#include <bits/stdc++.h>
using namespace std;

int m,n;
bool map[80][80];
int main() {
	cin>>m>>n;
	getchar();
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++)
			map[j][i]=getchar()=='X';
		getchar();
	}
	
	return 0;
}
