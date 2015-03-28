//选择排序
void SelectSort(int a[],int N)
{
	int i,j,k;
	int tmp;
	for(i=0;i<N;i++)
	{
		k=i;
		for(j=i+1;j<N;j++)
			if(a[j]<a[k])
				k=j;
		if(k!=i)
			swap(a[k],a[i]);
	}
}
