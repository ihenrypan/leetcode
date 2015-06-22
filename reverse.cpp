#include <iostream>

using namespace std;

int reverse(int x)
{
	int ret = 1;
	int arr[32] = {0};

	if (x < 0) {
		ret = -1;
		x = -x;
	}
	// converte x to array. 12340=> 0, 4, 3, 2, 1
	int i;
	for(i=0; x!=0; i++) {
		arr[i] =  x%10;
		x = x/10;
	}
	int p = 0, q=i-1;

	// skip last digit is 0, such as, 100, 1200000
	while (p<q) {
		if (arr[p] == 0)
			p++;
		else
			break;
	}
	int t=0, s=0;
	while (p<=q) {
		t = s;
		s *= 10;
		s += arr[p];
		// check overflow
		if (s/10 != t)
		{
			ret = 0;
			break;
		}
		p++;
	}
	
	ret *= s;

	return ret;
}

int main()
{
	int x = -2147483648;
	cout << "reverse: " << endl;
	cout << reverse(x) << endl;
	
	return 0;
}
