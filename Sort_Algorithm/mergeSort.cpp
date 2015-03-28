//归并排序
void merge(int a[],int leftPos,int rightPos,int rightEnd,int tmp[])
{
	int leftEnd=rightPos-1;
	int number=rightEnd-leftPos+1;
	int tmpPos=leftPos;
	
	while(leftPos<=leftEnd&&rightPos<=rightEnd)
		if(a[leftPos]<=a[rightPos])
		{
			tmp[tmpPos++]=a[leftPos++];
		}
		else
		{
			tmp[tmpPos++]=a[rightPos++];
		}
		
	while(leftPos<=leftEnd)
		tmp[tmpPos++]=a[leftPos++];
		
	while(rightPos<=rightEnd)
		tmp[tmpPos++]=a[rightPos++];
		
	for(int i=0;i<number;i++,rightEnd--)
		a[rightEnd]=tmp[rightEnd];
}

void mergeSort(int a[],int left,int right,int tmp[])
{
	if(left<right)
	{
		int center=(left+right)/2;
		mergeSort(a,left,center,tmp);
		mergeSort(a,center+1,right,tmp);
		merge(a,left,center+1,right,tmp);
	}
}

void mergeSort(int a[],int N)
{
	int *tmp=new int[N];
	if(tmp==NULL)
		return ;
	mergeSort(a,0,N-1,tmp);
	delete [] tmp;
	
}
