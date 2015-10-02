#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long int lld;
bool factor(lld n) {
	int size = 0;
	if (n == 1) return true;
	lld t = 1, s, sqrtn = int(sqrt(n));
	for (lld i = 2; i <= sqrtn; i++) {
		for (s = n / t; s%i == 0; s /= i) {
			size++;
			t *= i;
		}
	}
	if (t != n) size++;
	return (size-1 ? false : true );
}
int main() {
	
	for(int i = 4 ; i < 10; i++)
	{
		if(factor(i))
		cout<< "prime"<<endl;
	}

	return 0;
}