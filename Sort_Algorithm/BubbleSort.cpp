//冒泡排序
void BubbleSort(int a[],int N)
{
	int i,j;
	for(i=0;i<N;i++)
		for(j=0;j<N-i-1;j++)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
	
}
