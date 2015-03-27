#include<iostream>
#include <iomanip>
#include<vector>
#include<cstdlib>
using std::vector;
using std::cout;
using std::endl;


template<typename Comparable>
void swap1(Comparable & lhs,Comparable & rhs)
{
	Comparable Tmp;
	Tmp=lhs;
	lhs=rhs;
	rhs=Tmp;
}


//冒泡排序1
template<typename Comparable>
void bubbleSort(Comparable a[],int N)
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap1(a[j],a[j+1]);				
			}
		}		
	}
}

//冒泡排序2
void BubbleSort2(int a[], int n)
{
       int j, k;
       bool flag;

       k = n;
       flag = true;
       while (flag)
       {
              flag = false;
              for (j = 1; j < k; j++)
                     if (a[j - 1] > a[j])
                     {
                            swap1(a[j - 1], a[j]);
                            flag = true;
                     }
              k--;
			  for(int ii=0;ii<n;ii++)
				cout<<a[ii]<<" ";
			cout<<endl;
	}
}


//选择排序
template<typename Comparable>
void SelectionSort(Comparable a[],int N)
{
	int i,j,k;
	Comparable Min;
	for(i=0;i<N-1;i++)
	{
		k=i;
		for(j=i+1;j<N;j++)
			if(a[k]>a[j])
				k=j;
		if(k!=i)
			swap1(a[k],a[i]);
	}
}

//插入排序
template<typename Comparable>
void insertionSort(Comparable a[],int N)
{
	int j;
	for(int p=1;p<N;p++)
	{
		Comparable Tmp=a[p];
		for(j=p;j>0&&Tmp<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=Tmp;
	}
}


//希尔排序
template<typename Comparable>
void shellSort(Comparable a[],int N)
{
	for(int gap=N/2;gap>0;gap/=2)
	{
		for(int i=gap;i<N;i++)//从数组第gap个元素开始
		{
			Comparable tmp=a[i];
			int j=i;
			for(;j>=gap&&tmp<a[j-gap];j-=gap)//每个元素与自己组内的数据进行直接插入排序
				a[j]=a[j-gap];
			a[j]=tmp;
		}
	}
}



//堆排序
inline int leftChild(int i)
{
	return 2*i+1;
}

template<typename Comparable>
void percolateDown(Comparable a[],int i ,int N)
{
	int child;
	Comparable tmp;

	for(tmp=a[i];leftChild(i)<N;i=child)
	{
		child=leftChild(i);
		if(child!=N-1&&a[child]<a[child+1])
			child++;
		if(tmp<a[child])
			a[i]=a[child];
		else
			break;
	}
	a[i]=tmp;
}

template<typename Comparable>
void heapSort(Comparable a[],int N)
{
	for(int i=N/2;i>=0;i--)
		percolateDown(a,i,N);
	for(int j=N-1;j>0;j--)
	{
		swap1(a[0],a[j]);
		percolateDown(a,0,j);
	}
}


//归并排序
template<typename Comparable>
void merge(Comparable a[],Comparable tmpArray[],int leftPos,int rightPos,int rightEnd)
{
	int leftEnd=rightPos-1;
	int tmpPos=leftPos;
	int numElements=rightEnd-leftPos+1;

	while(leftPos<=leftEnd&&rightPos<=rightEnd)
		if(a[leftPos]<=a[rightPos])
			tmpArray[tmpPos++]=a[leftPos++];
		else
			tmpArray[tmpPos++]=a[rightPos++];
	while(leftPos<=leftEnd)
		tmpArray[tmpPos++]=a[leftPos++];
	while(rightPos<=rightEnd)
		tmpArray[tmpPos++]=a[rightPos++];

	for(int i=0;i<numElements;i++,rightEnd--)
		a[rightEnd]=tmpArray[rightEnd];
}

template<typename Comparable>
void mergeSort(Comparable a[],Comparable tmpArray[],int left,int right)
{
	if(left<right)
	{
		int center=(left+right)/2;
		mergeSort(a,tmpArray,left,center);
		mergeSort(a,tmpArray,center+1,right);
		merge(a,tmpArray,left,center+1,right);
	}
}

template<typename Comparable>
bool merge(Comparable a[],int N)
{
	Comparable *tmpArray=new Comparable[N];
	if(tmpArray==NULL)
		return false;
	mergeSort(a,tmpArray,0,N-1);
	delete [] tmpArray;
	return true;
}


//快速排序
template<typename Comparable>
void insertsort(Comparable a[],int left,int right)
{
	for(int p=left+1;p<=right;p++)
	{
		Comparable tmp=a[p];
		int j=p;
		for(;j>left&&tmp<a[j-1];j--)
			a[j]=a[j-1];
		a[j]=tmp;
	}
}


template<typename Comparable>
const Comparable& median3(Comparable a[],int left,int right)
{
	int center=(left+right)/2;
	if(a[center]<a[left])
		std::swap(a[center],a[left]);
	if(a[left]>a[right])
		std::swap(a[right],a[left]);
	if(a[center]>a[right])
		std::swap(a[center],a[right]);

	std::swap(a[center],a[right-1]);
	return a[right-1];
}

template<typename Comparable>
void quicksort(Comparable a[],int left,int right)
{
	if(left+10<=right)
	{
		Comparable privot=median3(a,left,right);
		int i=left,j=right-1;
		for(;;)
		{
			while(a[++i]<privot){}
			while(a[--j]>privot){}
			if(i<j)
				std::swap(a[i],a[j]);
			else
				break;
		}
		std::swap(a[i],a[right-1]);
		quicksort(a,left,i-1);
		quicksort(a,i+1,right);
	}
	else
		insertsort(a,left,right);
}


template<typename Comparable>
int position(Comparable a[],int left,int right)
{
	
	int i,j,tmp;
	i=left;
	j=right;
	tmp=a[left];
	while(i<j)
	{
		while(a[j]>=tmp&&i<j)
			j--;
		while(a[i]<=tmp&&i<j)
			i++;
		if(i<j)
			swap1(a[i],a[j]);
	}
	
	a[left]=a[i];
	a[i]=tmp;
	return i;
}

template<typename Comparable>
void quicksort2(Comparable a[],int left,int right)
{
	if(left<right)
	{
		int p=position(a,left,right);
		quicksort(a,left,p-1);
		quicksort(a,p+1,right);
	}
}


template<typename Comparable>
void quicksort(Comparable a[],int N)
{
	quicksort(a,0,N-1);
	
}


//快速选择
template<typename Comparable>
void quickSelect(Comparable a[],int left,int right,int K)
{
	if(left+10<=right)
	{
		Comparable privot=median3(a,left,right);
		int i=left,j=right-1;
		for(;;)
		{
			while(a[--j]>privot){}
			while(a[++i]<privot){}
			if(i<j)
				std::swap(a[i],a[j]);
			else
				break;
		}
		std::swap(a[i],a[right-1]);

		if(K<=i)
			quickSelect(a,left,i-1,K);
		else if(K>i+1)
			quickSelect(a,i+1,right,K);
	}
	else
		insertsort(a,left,right);
}


template<typename Comparable>
void quickSelect(Comparable a[],int N,int K)
{
	quickSelect(a,0,N-1,K);
}

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
