#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int m;
	int reference_string[10],page_faults = m,n,s,pages,frames,i;
	
	printf("\nEnter Total number of pages:\n"):
	scanf("%d",&pages);
	
	printf("\nEnter values of Reference string:\n");
	for(m=0;m<pages;m++)
	{
		reference_string[m] = printRandoms(0,30,1);
	}
	for(m=0;m<pages;m++)
	{
		printf("Values No. [%d] Reference String %d:\n",m,reference_string[m]);
	}

	printf("\nEnter Total Number Of Frames:\t");
	scanf("%d",&frames);

	int temp[frames];

	for(m=0;m<frames;m++)
	{
		temp[m]=-1;
	}
	printf("ref String\t\t page frames\n");
	for(m=0;m<pages;m++)
	{
		s=0;

		for(n=0;n<frames;n++)
	{
		if(reference_string[m]==temp[n])
		{
			s++;
			page_faults--;
		}
	}
	page_faults++;
	if((page_faults<=frames)&&(s==0))
	{
		temp[m]=reference_string[m];
	}
	else if(s==0)
	{
		temp[(page_faults -1)%frames]=reference_string[m];
	}
	printf("\n");
	for(n=0;n<frames;n++)
	{
		printf("%d\t",temp[n]);
	}
	}
	printf("\n\nTotal page fault:\t%d\n",page_faults);
	return 0;
}
int printRandoms(int lower,int upper,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		int num = (rand()+lower)%(upper+1);
		return num;
	}
	return 0;
}
