#include <iostream>
using namespace std;

long long Fibonacci1(unsigned int n){
	if(n <= 0)
		return 0;
	if(n == 1)
		return 1;
	return Fibonacci1( n - 1 ) + Fibonacci1( n - 2 );
}

long long Fibonacci2(unsigned int n){
	int result[2] = {0,1};
	if(n < 2) 
		return result[n];
	long long Fib1 = 1;
	long long Fib2 = 0;
	long long FibN = 0;
	for(int i = 0; i < n; i++){
		FibN = Fib1 + Fib2;
		Fib2 = Fib1;
		Fib1 = FibN;	
	}
	return FibN;
}

int main(){
	int num;
	num = Fibonacci1(10);
	cout<< num <<endl;
}