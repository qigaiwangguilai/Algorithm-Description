//快速排序1
int position1(int a[],int left ,int right)
{
	int privot=a[left];
	int i=left,j=right;
	
	while(i<j)
	{
		while(i<j&&a[j]>=privot)
		{
			j--;
		}
			
		while(i<j&&a[i]<=privot)
		{
			i++;
		}
		
		if(i<j)
			swap(a[i],a[j]);
		else
			break;
	}
	a[left]=a[i];
	a[i]=privot;
	return i;
}


void QuickSort1(int a[],int left,int right)
{
	if(left<right)
	{
		int p=position1(a,left,right);
		QuickSort1(a,left,p-1);
		QuickSort1(a,p+1,right);
	}
}


void QuickSort1(int a[],int N)
{
	QuickSort1(a,0,N-1);
}

//快速排序2(优化枢纽元，小数组排序)
void insertsort(int a[],int left,int right)
{
	int tmp;
	int j;
	for(int i=left+1;i<=right;i++)
	{
		tmp=a[i];
		for(j=i;j>left&&tmp<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=tmp;
	}
}

int median3(int a[],int left,int right)
{
	int center=(left+right)/2;
	if(a[left]>a[center])
		swap(a[left],a[center]);
	if(a[left]>a[right])
		swap(a[left],a[right]);
	if(a[center]>a[right])
		swap(a[center],a[right]);
	
	swap(a[center],a[right-1]);
	return a[right-1];
}


int position2(int a[],int left,int right)
{
	int i,j;
	int privot=median3(a,left,right);
	i=left;
	j=right-1;
	while(1)
	{
		while(a[--j]>privot){}
		while(a[++i]<privot){}
		if(i<j)
			swap(a[i],a[j]);
		else
			break;
	}
	swap(a[i],a[right-1]);
	return i;
}

void QuickSort2(int a[],int left,int right)
{
	if(left+10<=right)
	{
		int p=position2(a,left,right);
		QuickSort2(a,left,p-1);
		QuickSort2(a,p+1,right);
	}
	else
		insertsort(a,left,right);
}

void QuickSort2(int a[],int N)
{
	QuickSort2(a,0,N-1);
}


//快速选择--利用快排
void QuickSelect(int a[],int left,int right,int K)
{
	if(left<right)
	{
		int p=position1(a,left,right);
		if(K<p+1)
			QuickSelect(a,left,p-1,K);
		else if(K>p+1)
			QuickSelect(a,p+1,right,K);
	}
}

void QuickSelect(int a[],int N,int K)
{
	QuickSelect(a,0,N-1,K);
}
