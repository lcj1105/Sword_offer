#include <iostream>

using namespace std;

int NumberOf1_(int n){
	size_t flag = 1;
	int count = 0;
	while (flag){
		if (n & flag)
			++count;
		flag = flag << 1;  //���ֻ�ܸ�������λ��ѭ��32�Σ���
	}
	return n;
}

int NumberOf1(int n){
	int count = 0;
	while (n){
		++count;
		n = (n - 1) & n;
	}
	return count;
}

int main(){
	int num = 31,count = 0;
	count = NumberOf1(num);
	cout << count << endl;
	
}