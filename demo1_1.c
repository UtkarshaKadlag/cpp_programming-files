// accept and print array  
// selection sort asc w
#include<stdio.h>
#define SIZE 6
void accept_array(int a[], int size);
void display_array(const int *a, int size);
void selection_sort_asc(int a[], int size);
int main(void)
{
    int arr[SIZE];
    printf("\n enter array elements :\n");
    accept_array(arr,SIZE);

    printf("\n  array elements :\n");
    display_array(arr,SIZE);

    selection_sort_asc(arr, SIZE);
    printf("\n  after asc sort  of array elements :\n");
    display_array(arr,SIZE);

    
    return 0;
}
void selection_sort_asc(int a[], int size)
{
    int i, j, temp;
    for(i=0; i<size; i++ ) // outer loop for selection of index
    {
        for(j=i+1; j<size; j++) //inner loop for compare with index of array
        {
            printf("\n a[%d] %d a[%d] %d", i, a[i], j, a[j]);
            if( a[i]>a[j])  
            {
                // way 1 swap using temp variable
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        if( i< (size-1))
            printf("\n itration =%d", i+1);
    }
    return;

}
void accept_array(int a[], int size)
{
    int index;
    for(index=0; index<size; ++index)
    {
        printf("\n a[%d]", index);
        scanf("%d", &a[index]);
    }
    return;
}
void display_array(const int *a, int size)
{
    int index;
    for(index=0; index<size; index++)
    {        
		printf("\n a[%d]  %5d   [%u] ", index, a[index], &a[index]);
    }
	return;
} // a[index] == *(a+index)
  // index[a] == *(index+a)
