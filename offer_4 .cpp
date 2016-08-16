#include <iostream>

using namespace std;

//template <class T>

//int getArrayLen(const T& array){
//	return (sizeof(array) / sizeof(array[0]));
//}
//
//void ArrayAppend(int *A1, int *A2,int len_A1,int len_A2){
//	if (A1 == NULL || A2 == NULL)
//		return;
//
//	int indexOfA1 = len_A1 - 1;
//	int indexOfA2 = len_A2 - 1;
//	int indexOfNew = len_A1 + len_A2 - 1;
//
//	while (indexOfA1 > 0 && indexOfA2 > 0 && indexOfA1 < indexOfNew){
//		if (A1[indexOfA1] >= A2[indexOfA2]){
//			A1[indexOfNew--] = A1[indexOfA1--];
//			A1[indexOfNew--] = A2[indexOfA2--];
//		}
//		else{
//			A1[indexOfNew--] = A2[indexOfA2--];
//			A1[indexOfNew--] = A1[indexOfA1--];
//		}
//	}
//
//}
//
//int main(){
//	int a1[] = { 1, 2, 5, 6, 8, 9, 10, 20 };
//	int a2[] = { 3, 4, 7, 11, 19, 22 };
//	int length_A1 = getArrayLen(a1);
//	int length_A2 = getArrayLen(a2);
//	cout << length_A1 << " " << length_A2 << endl;
//	ArrayAppend(a1, a2, length_A1, length_A2);
//
//	for (auto p = begin(a1); p != end(a1); ++p){
//		cout << *p << " ";
//	}
//
//}


void ReplaceBlack(char string[], int length){
	if (string == NULL || length <= 0)
		return;
	//求字符串长度以及得到新字符串长度
	int originLength = 0;
	int newLength = 0;
	int numofblack = 0;
	while (string[originLength] != '\0'){
		originLength++;
		if (string[originLength] == ' '){
			numofblack++;
		}
	}
	newLength = originLength + numofblack * 2;
	if (newLength > length)
		return;

	int indexOfOriginal = originLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal){
		if (string[indexOfOriginal] == ' '){
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else{
			string[indexOfNew--] = string[indexOfOriginal];
		}
		indexOfOriginal--;
	}
}

int main(void)
{
	const size_t array_size = 1000;
	char strs[array_size];
	//gets_s(strs, array_size - 1);
	int i = 0;
	char tmp;
	tmp = cin.get();
	while (tmp != '\n')
	{
		strs[i] = tmp;
		tmp = cin.get();
		i++;
	}
	strs[i] = '\0';
	ReplaceBlack(strs, array_size);

	for (auto p = begin(strs); p != end(strs); ++p){
		cout << *p ;
	}

	system("pause");
	return 0;
}