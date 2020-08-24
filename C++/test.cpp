#include<iostream>
#include<vector>
#include<string>
#include<unistd.h>
using namespace std;

int main(){
	double i=0;
	string m="monster ";
	while(1){
		cout<<m<<i<<endl;
		i++;
		string n=m+to_string(i);
		cout<<n<<endl;
		sleep(1);
	}
}
