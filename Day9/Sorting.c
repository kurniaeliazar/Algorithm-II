#include <stdio.h>

void printArray(int arr[]){
	int arrSize = (int) sizeof(arr) - 1;
	//printf("%d\n", arrSize );
	for(int i = 0; i < arrSize; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void insertion_sort (int arr[], int length){

	printf("Insertion Sort \n");

	int j, temp;
		
	for (int i = 0; i < length; i++){
		j = i;
		while (j > 0 && arr[j] < arr[j-1]){
		  temp = arr[j];
		  arr[j] = arr[j-1];
		  arr[j-1] = temp;
		  j--;
		}
	}

	printArray(arr);
}

void selectSort(int arr[], int n)
{
	printf("Selection Sort \n");
	//pos_min is short for position of min
	int pos_min,temp;
	for (int i=0; i < n-1; i++){
	    pos_min = i;//set pos_min to the current index of array
		for (int j=i+1; j < n; j++){
			//pos_min will keep track of the index that min is in, this is needed when a swap happens
			if (arr[j] < arr[pos_min]) pos_min=j;
		}
		
		//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
	    if (pos_min != i)
	    {
	         temp = arr[i];
	         arr[i] = arr[pos_min];
	         arr[pos_min] = temp;
	    }
	}
	printArray(arr);
}

int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

void quickSort( int a[], int l, int r)
{
   int j;
   int arrSize = (int) sizeof(a) - 2;

   if( l < r ) 
   {
   	// divide and conquer
       j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }else if(l == arrSize && r == arrSize){
   	   printf("Quick Sort \n");
   	   printArray(a);
   }
}

int main() {

	int arrData[] = {5,4,7,2,6,1,3};
	int arrData2[] = {5,4,7,2,6,1,3};
	int arrData3[] = {5,4,7,2,6,1,3};

	printf("Before sorting \n");
	printArray(arrData);
	insertion_sort(arrData, 7);
	selectSort(arrData2, 7);
	quickSort(arrData3, 0, 6);
}