//插入排序
void InsertionSort(int a[],int N)
{
	int i,j;
	int tmp;
	for(i=1;i<N;i++)
	{
		tmp=a[i];
		for(j=i;j>0&&tmp<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=tmp;
	}
}
