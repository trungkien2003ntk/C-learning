#include <bits/stdc++.h>

using namespace std;
char a,b;
void nhap(){
	cin>>a>>b;
}
char viethoa(char kt){
	return kt+'A'-'a';
}
void xuli()
{
	for(int i=a;i<=b;i++)
		cout << viethoa(i) << " ";
}
int main(){
	nhap();
	xuli();
	return 0;
}