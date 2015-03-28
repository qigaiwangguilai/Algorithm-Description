//堆排序
inline int childIndex(int i)
{
	return 2*i+1;
}


void percolateDown(int a[],int hole,int N)
{
	int tmp;
	int child;
	for(tmp=a[hole];childIndex(hole)<N;hole=child)
	{
		child=childIndex(hole);
		if(child!=N-1&&a[child]<a[child+1])
			child++;
		if(tmp<a[child])
			a[hole]=a[child];
		else
			break;
	}
	a[hole]=tmp;
}

void HeapSort(int a[],int N)
{
	for(int i=N/2;i>=0;i--)
		percolateDown(a,i,N);
		
	for(int j=N-1;j>0;j--)
	{
		swap(a[0],a[j]);
		percolateDown(a,0,j);
	}
}
