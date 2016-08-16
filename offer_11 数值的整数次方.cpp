#include <iostream>
using namespace std;

bool equal(double num1,double num2){
	if( (num1 - num2 < 0.0000001) && (num1 - num2 > -0.0000001) )
		return true;
	else
		return false;
}

double PowerWithUnsignedExp(double base, unsigned int exp){
	if(exp == 0)
		return 1;
	if(exp == 1)
		return base;
	double result = PowerWithUnsignedExp( base , exp >> 1 );
	result *= result;
	if( exp & 0x1 == 1)
		result *= base;
	return result;
}

double Power(double base , int exp){
	if( equal(base,0.0) && exp < 0 )
		throw new std::exception("Invalid Input!");
	unsigned int absExp = (unsigned int)exp;
	if(exp < 0)
		absExp = (unsigned int)(-exp);
	double result = PowerWithUnsignedExp(base,absExp);
	if(exp < 0)
		result = 1.0 / result;
	return result; 
}

int main(){
	double bases[] = {2.4,3.0,-1.2,222.0,0.0};
	double exps[] = {3,0,2,-3,-2};
	for(size_t i = 0; i < 5 ; i++){
		double result;
		result = Power(bases[i],exps[i]);
		cout << bases[i] << "的" << exps[i] << " 次方的result: " << result << endl;
	}
}