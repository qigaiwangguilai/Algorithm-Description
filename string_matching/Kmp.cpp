/*************求解Next数组**************/
void GetNext(const string &p,int next[])
{
	int j=0;
	int k=-1;
	next[0]=-1;
	while(j<p.length()-1)
	{
		//p[k]表示前缀，p[j]表示后缀
		if(k==-1||p[j]==p[k])
		{
			++j;
			++k;
			if(p[k]!=p[j])
				next[j]=k;
			else
				next[j]=next[k]; //因为不能出现p[j]=p[next[j]]，因此当出现这种情况时，需要继续递归
		}
		else
			k=next[k];
	}
}

//************Kmp算法主体，s为文本串，p为模式串*************//
int Kmp(const string &s,const string &p)
{
	int slen=s.length();
	int plen=p.length();
	int i=0,j=0;
	int *next=new int[plen];
	GetNext(p,next);
	while(i<slen&&j<plen)
	{
		if(j==-1||p[j]==s[i])
		{
			++i;
			++j;
		}
		else
			j=next[j];   //若失配，则模式串p向右移动j-next[j]位，文本串s保持不变
	}
	if(j==plen)
		return i-j;
	else
		return -1;
}
