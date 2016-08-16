
void PrintMatrixInCircle(int **num,int columns,int rows,int start){
	int endX = columns - start - 1;
	int endY = rows - start - 1;
	for(int i = start ; i <= endX ; i++){
		int number = num[start][i];
		printf("%d\t", number);
	}
	if(endY > start){
		for (int i = start+1; i <= endY; ++i){
			int number = num[i][endX];
			printf("%d\t", number);
		}
	}
	if(endY >start && endX > start){
		for(int i = endX -1; i >= start ; --i ){
			int number = num[endY][i];
			printf("%d\t", number);
		}
	}
	if(endX > start && endY > start + 1){
		for (int i = endY -1 ; i >= start ; --i ){
			int number = num[i][start];
			printf("%d\t", number);
		}
	}

}
void PrintMatrixClockwisely(int **num ,int columns ,int rows){
	if( num == NULL || columns <= 0 || rows <= 0)
		return;
	int start = 0;
	while(columns > start*2 && rows > start*2){
		PrintMatrixInCircle(num,columns,rows,start);
		++start;
	}
}