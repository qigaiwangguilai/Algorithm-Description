//桶排序
void BucketSort(int a[],int N,int Max)
{
	int *radix=new int[Max]();
	for(int i=0;i<N;i++)
	{
		radix[a[i]]=1;
	}
	for(int i=0,j=0;i<Max;i++)
	{
		if(radix[i]==1)
			a[j++]=i;
	}
}


//基数排序
int getKthNumber(int num ,int k)
{
	
	for(int i=1;i<k;i++)
		num/=10;
	return num%10;
}

//(LSD)
void lsdradix_sort(int a[],int N,int d)
{
	const int radix=10;
	int count[radix];
	int i,j;
	int *bucket=new int[N];
	
	for(int k=1;k<=d;k++)
	{
		for(i=0;i<radix;i++)
			count[i]=0;
			
		for(i=0;i<N;i++)
			count[getKthNumber(a[i],k)]++;
		
		for(i=1;i<radix;i++)
			count[i]=count[i]+count[i-1];
			
		for(i=N-1;i>=0;i--)
		{
			j=getKthNumber(a[i],k);
			bucket[count[j]-1]=a[i];
			count[j]--;
		}
				
		
		for(i=0;i<N;i++)
			a[i]=bucket[i];
	}
	delete [] bucket;
}


//(MSD)
void msdradixSort(int a[],int tmp[],int left,int right,int d)
{
	const int radix=10;
	int count[radix];
	int i,j;
	
	for(i=0;i<radix;i++)
		count[i]=0;
			
	for(i=left;i<=right;i++)
		count[getKthNumber(a[i],d)]++;
		
	for(i=1;i<radix;i++)
		count[i]=count[i]+count[i-1];
		
	for(i=right;i>=left;i--) //保证基排序的稳定性
	{
		j=getKthNumber(a[i],d);
		tmp[count[j]-1]=a[i];
		count[j]--;
	}
	
	for(i=left,j=0;i<=right;i++,j++)
		a[i]=tmp[j];
		
	for(i=0;i<radix;i++)
	{
		int p1=left+count[i];
		int p2=left+count[i+1]-1;
		if(p1<p2&&d>1)
		{
			msdradixSort(a,tmp,p1,p2,d-1);
		}
	}
}

void msdradixSort(int a[],int N,int d)
{
	int *tmp=new int[N];
	msdradixSort(a,tmp,0,N-1,d);
	delete [] tmp;
}
