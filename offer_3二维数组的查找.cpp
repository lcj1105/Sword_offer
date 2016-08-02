
bool Find(int* matrix,int rows,int cols, int number){
	bool found = false;
	if(matrix == NULL || rows<= 0 || cols <= 0 ){
		return found;
	}
	int row = 0;
	int col = cols -1;

	while(row < rows && cols> 0 ){
		if( number == matrix[row*cols+ col]){
			found = true;
			break;
		}
		else if( matrix[row*cols + col] > number){
			--col;
		}
		else{
			--row;
		}
	}
	return found;
}