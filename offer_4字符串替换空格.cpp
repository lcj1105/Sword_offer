
void ReplaceBlack(char string[],int length){
	if(string == NULL || length<= 0)
		return;
	//求字符串长度以及得到新字符串长度
	int originLength = 0;
	int newLength = 0;
	int numofblack = 0;
	while(string[originLength] != '\0'){
		originLength++;
		if(string[originLength] == ' '){
			numofblack ++ ;
		}
	}
	newLength = originLength + numofblack*2;
	if(newLength > length)
		return;

	int indexOfOriginal = originLength;
	int indexOfNew = newLength;
	while(indexOfOriginal >=0 && indexOfNew>indexOfOriginal){	
		if(string[indexOfOriginal] == ' '){
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else{
			string[indexOfNew -- ] = string[indexOfOriginal];
		}
		indexOfOriginal --;
	}
}

/* 举一反三：两个排序数组A1，A2，实现一个函数，把A2中的所有数字插入到A1中并且所有的数字是排序的 */

template <class T>
int getArrayLen(const T& array){
	return (sizeof(array) / sizeof(array[0]));
}

void ArrayAppend(int A1[], int A2[]){
	if(A1 == NULL || A2 = NULL)
		return;
	int length_A1 = getArrayLen(A1);
	int length_A2 = getArrayLen(A2);

	int indexOfA1 = length_A1 - 1;
	int indexOfA2 = length_A2 -1;
	int indexOfNew = length_A1 + length_A2 - 1;

	while(indexOfA1 > 0 && indexOfA2 > 0 && indexOfA1 < indexOfNew ){
		if(A1[indexOfA1] >= A2[indexOfA2]){
			A1[indexOfNew --] = A1[indexOfA1--];
			A1[indexOfNew --] = A1[indexOfA2--];
		}
		else{
			A1[indexOfNew--] = A2[indexOfA2--];
			A1[indexOfNew--] = A1[indexOfA1--];
		}
	}
}