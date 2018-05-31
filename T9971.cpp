#include <bits/stdc++.h>
using namespace std;

int n,m;
int w[105];
bool used[105];
void dfs(int qw) {
	if (qw==m) {
		cout<<"yes"<<endl;
		exit(0);
	}
	for (int i=1;i<=n;i++) {
		if (used[i]) continue;
		used[i]=true;
		dfs(qw+w[i]);
		used[i]=false;
	}
}
int main() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>w[i];
	dfs(0);
	cout<<"not found"<<endl;
	return 0;
}
