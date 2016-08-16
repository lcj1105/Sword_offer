#include <iostream>
#include <stdio.h>
using namespace std;
#include <iostream>

using namespace std;

//方法1：最简单方式，不过n大了就不行了
void Print1ToMaxDigits_1(int n){
	int number = 1;
	int i = 0;
	while (++i < n){
		number *= 10;
	}
	for (int i = 0; i < number; i++){
		printf("%d \t", i);
	}
}

//方法二：利用字符串普通循环
bool Increment(char *number){
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength - 1; i >= 0; i--){
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1){
			nSum += 1;
		}
		if (nSum >= 10){
			if (i == 0)
				isOverflow = true;
			else{
				nSum -= 10;
				nTakeOver++;
				number[i] = '0' + nSum;
			}
		}
		else{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}
void Print(char *number){
	bool isBegin0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; i++){
		if (isBegin0 && number[i] != '0'){
			isBegin0 = false;
		}
		if (!isBegin0){
			printf("%c", number[i]);
		}
	}
	printf("\n");
}
void Print1ToMaxDigits_2(int n){
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0',n);
	number[n] = '\0';
	while (!Increment(number)){
		Print(number);
	}
	delete[]number;
}


// 方法3：利用递归

void Print_3(char *number){
	bool isBegin0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; i++){
		if (isBegin0 && number[i] != '0'){
			isBegin0 = false;
		}
		if (!isBegin0){
			printf("%c", number[i]);
		}
	}
	printf("\n");
}
void Print1ToMaxDigitsRecursively(char *number, int nLength, int index){
	if (index == nLength - 1){
		Print_3(number);
		return;
	}
	for (int i = 0; i < 10; i++){
		number[index+1] = i + '0';
		Print1ToMaxDigitsRecursively(number, nLength, index + 1);
	}

}

void Print1ToMaxDigits_3(int n){
	if (n <= 0)
		return;
	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';
	for (int i = 0; i < 10; i++){
		number[0] = i + '0';
		Print1ToMaxDigitsRecursively(number, n, 0);
	}
}

int main(){
	int n = 3;
	Print1ToMaxDigits_3(n);
}