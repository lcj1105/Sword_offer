#include <iostream>

using namespace std;

int MinOrder(int *num, int index1, int index2){
	int result = num[index1];
	for (int i = index1 + 1; i <= index2; i++){
		if (num[i] < result)
			result = num[i];
	}
	return result;
}

int FindMinNum(int *num , int length){
	if( num == NULL || length <= 0)
		throw new std::exception("Invalid parameters !");
	int index1 = 0;
	int index2 = length -1;
	int indexMid = index1;    //假如整体有序，直接返回原数组
	while(num[index1] >= num[index2]){
		if((index2 - index1) == 1){
			indexMid = index2;
			break;
		}
		indexMid = (index2 + index1)/2;

		if( num[index1] == num[index2] && num[index1] == num[indexMid] )
			return MinOrder(num,index1,index2);

		if(num[indexMid] >= num[index1])
			 index1 = indexMid;
		else if( num[indexMid] <= num[index2])
			 index2 = indexMid;
	}
	return num[indexMid];
}

int main(){
	int num1[] = { 4, 5, 6, 7, 8, 2, 3 };
	int num2[] = { 1, 2, 3, 4, 5, 6, 7 };
	int num3[] = { 1, 0, 1, 1, 1, 1 ,1 };
	cout << FindMinNum(num1, 7) << endl;
	cout << FindMinNum(num2, 7) << endl;
	cout << FindMinNum(num3, 7) << endl;

}