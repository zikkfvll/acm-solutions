#include <iostream>
using namespace std;
#define N 1000
struct student{
	char   name[8]; 
	int    chinese;
	int    math;
	int    english;
}s[N];

void input(int n)
{
	for(int i=0;i<n;i++)
	{

		scanf("%s",s[i].name);

		scanf("%d",&s[i].chinese);

		scanf("%d",&s[i].math);
		
		scanf("%d",&s[i].english);
				
		printf("\n");

	}

}

int sortl(int n)
{
	int max=s[0].chinese+s[0].math+s[0].english;
	int max_inx = 0;
	for(int i=1;i<n;i++)
	{
		if(s[i].chinese+s[i].math+s[i].english>max)
		{
			max=s[i].chinese+s[i].math+s[i].english;
			max_inx=i;
		}
	}
	
	
	return max_inx;
}

int main()
{
	int n;
	cin >> n;
	input(n);
	
	int max_inx=sortl(n);
	printf("%s\t%d\t%d\t%d\n",s[max_inx].name,s[max_inx].chinese,s[max_inx].math,s[max_inx].english); 
	
	return 0;
}
