#include <bits/stdc++.h>
using namespace std;

int n,k;
int a[105];
bool used[105];
int ans;
void dp(int used,int total,int st) {
	if (st>n) return;
	if (total>ans) return;
	if (used==k) {
		if (total<ans) ans=total;
		return;
	}
	dp(used+1,total+a[st],st+2);
	dp(used,total,st+1);
}
int main() {
	cin>>n>>k;
	k+=3;
	if (n<k*2) {
		cout<<"-1"<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<n;i++) a[i]=(a[i+1]-a[i])*(a[i+1]-a[i]);
	ans=2147483647;
	dp(0,0,1);
    cout<<ans<<endl;
	return 0;
}
