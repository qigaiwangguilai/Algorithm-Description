//希尔排序----使用希尔增量
void ShellSort(int a[],int N)
{
	int gap;
	int i,j;
	int tmp;
	for(gap=N/2;gap>0;gap/=2)
		for(i=gap;i<N;i++)
		{
			tmp=a[i];
			for(j=i;j>=gap&&tmp<a[j-gap];j-=gap)
				a[j]=a[j-gap];
			a[j]=tmp;
		}
}
