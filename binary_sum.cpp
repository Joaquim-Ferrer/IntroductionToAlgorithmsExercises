using namespace std;
#include <iostream>

int main() {

	//As there's nothing in the problem saying that there should be an input the array will be initialized in the code
	int size = 5;
	bool A[size] = {0,0,0,0,0};
	bool B[size] = {0,0,0,0,0};
	
	bool ans[size+1];

	//adder with carry out
	bool carry_out = 0;
	for(int i=size-1; i>=0; i--) {
		bool temp = A[i] xor B[i];
		ans[i+1] = temp xor carry_out;
		carry_out = (A[i] and B[i]) or (carry_out and (temp));
	}
	ans[0] = carry_out;

	//output
	for(int i=0; i<=size; i++) {
		cout << ans[i];
	}
	
	cout << endl;

}