
void ReorderOddEven(int *pData, size_t length){
	if(pData == NULL || length ==NULL )
		return;
	int *p1 = pData;
	int *p2 = pData + length - 1;
	while(p1 < p2){
/*		while( (*p1) / 2 != 0 )  //限制不够
			++p1;
		while( (*p2) / 2 == 0 )
			--p2;
		if( p1 >= p2 )
			break;
		else{
			int temp = *p1;
			*p2++ = *p1;
			*p1++ = temp;
		}
*/
		while( p1 < p2 && (*p1 & 0x1) != 0) //用位运算装逼
			++p1;
		while( p1 < p2 && (*p2 & 0x1) == 0)
			--p2;
		if(p1 < p2){
			int temp = *p1;
			*p2++ = *p1;
			*p1++ = temp;
		}

	}
}

// 拆分成三部分，随时可切换模式

bool isEven(int n){
	return (n & 1) == 0;
}
void Reorder(int *pData, size_t length , bool (*func)(int) ){
	if(pData == NULL || length ==NULL )
		return;
	int *p1 = pData;
	int *p2 = pData + length - 1;
	while(p1 < p2){
		while( p1 < p2 && !func(*p1) ) //用位运算装逼
			++p1;
		while( p1 < p2 && func(*p2) )
			--p2;
		if(p1 < p2){
			int temp = *p1;
			*p2++ = *p1;
			*p1++ = temp;
		}
	}
}
void ReorderOddEven(int *pData, size_t length){
	Reorder(pData, length, isEven);
}
