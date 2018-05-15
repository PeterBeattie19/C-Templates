#include <bits/stdc++.h>
using namespace std; 

typedef long long ll;

#define endl "\n"
#define rep(i,a,b) for(int i = a; i<b; i++)

const vector<string> explode(const string& s, const char& c){
	string buff{""};
	vector<string> v;
	
	for(auto n:s)
	{
		if(n != c) buff+=n; else
		if(n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if(buff != "") v.push_back(buff);
	
	return v;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);


	return 0; 
}
