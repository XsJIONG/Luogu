#include <iostream>
using namespace std;

char c;
bool af;
int main() {
	af=0;
	while ((c=getchar())!=EOF) {
		if (c=='\"') {
			if (af) cout<<"''"; else cout<<"``";
			af=!af;
		} else cout<<c;
	}
	return 0;
}
