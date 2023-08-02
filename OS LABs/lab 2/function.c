#include"header.h"

void sort(int array[],int order,int size)
{
//int size = sizeof(array) / sizeof(array[0]);
int temp;
if(order)
{
int i;
  for(i=0;i<size;i++)
  {
  int j;
 	for( j=0;j<size-1;j++)
  	{
  		if(array[j]>array[j+1])
  		{
  			temp=array[j];
 			array[j]=array[j+1];
  			array[j+1]=temp;
		}
  	}
 }
 }
 else
 {
 int i;
  	for( i=0;i<size;i++)
  	{
  	int j;
  		for( j=0;j<size-1;j++)
  		{
  			if(array[j]<array[j+1])
  			{
  			temp=array[j];
  			array[j]=array[j+1];
  			array[j+1]=temp;
			}
  		}
 	}
 }
 }
 
 void findHighest(int array[],int nth,int size)
 {
 		//int size = sizeof(array) / sizeof(array[0]);
 		//nth highest value from array
		sort(array,0,size);
		printf("\nNth Highest Number : %d\n",array[nth-1]);
 }
 void print(int array[],int size)
 {
 		//int size = sizeof(array) / sizeof(array[0]);
 		printf("\nArray : ");
		//print all ele of array
		int i;
		for(i = 0; i < size; i++)
      	printf("%d ", array[i]);
      	
}
