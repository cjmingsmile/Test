
#include "sort.h"
#include <windows.h>
#include <time.h>  



int partition(int *a, int low, int hight, int p = 0)
{
	if (low == hight)
	{
		return low;
	}
	if (low > p || hight < p)
	{
		p = low;
	}

	if (p != low)
	{
		int temp = a[p];
		a[p] = a[low];
		a[low] = temp;
	}

	int first = low; 
	int last = hight;
	int pivot = a[first];
	while (first < last)
	{
		while (first < last && a[last] >= pivot)
		{
			--last;
		}
		a[first] = a[last];
		while (first < last && a[first] <= pivot)
		{
			++first;
		}
		a[last] = a[first];
	}

	a[first] = pivot;
	return first;
}



int QuickSelect(int *a, int low, int hight, int k)
{
	assert(low <= hight);
	assert(hight - low + 1 >= k);

	if (low == hight)
	{
		return a[low];
	}

	int m = partition(a, low, hight);

	int i = m - low +1;
	if (i == k)
	{
		return a[m];
	}
	else if (i > k)
	{
		return QuickSelect(a, low, m - 1, k);
	}
	else
	{
		return QuickSelect(a, m + 1, hight, k - i);
	}
}



int FindMid(int *a, int low, int hight)
{
	for (int i = low; i < hight - 5; i += 5)
	{
		Sort::Instance().InsertSort(a, i, i+4);

		int mid_i = (i - low)/5 + low;
		int temp = a[mid_i];
		a[mid_i] = a[i+2];
		a[i+2] = temp;
	}

	if ((hight-low+1)%5 != 0)
	{
		int i = hight - (hight-low+1)%5 + 1;
		Sort::Instance().InsertSort(a, i, hight);

		int mid_me = (hight - i)/2 + i;
		int mid_i = (i - low)/5 + low;
		int temp = a[mid_i];
		a[mid_i] = a[mid_me];
		a[mid_me] = temp;
	}

	if ((hight-low+1)/5 == 0)
	{
		return 0;
	}

	return FindMid(a, low,low + ((hight-low+1)%5 == 0 ? 0:1) + (hight-low+1)/5 );
}

int BFPRTSelect(int *a, int low, int hight, int k)
{
	assert(low <= hight);
	assert(hight - low + 1 >= k);

	int mid = FindMid(a, low, hight);
	int m = partition(a, low, hight, mid);

	int i = m - low + 1;
	if (i == k)
	{
		return a[m];
	}
	else if (i > k)
	{
		return BFPRTSelect(a, low, m - 1, k);
	}
	else
	{
		return BFPRTSelect(a, m + 1, hight, k - i);
	}
}













void PrintSelect()
{
	printf("PrintSelect Start\n");
	static const int num = 100000;
	int *a = new int[num];
	int *b = new int[num];

	for (int i = 0; i < num; ++i)
	{
		b[i] = rand()%num; //num-i;
	}

	time_t start = clock();
	time_t end = clock();


	int find_num = rand()%num+1;
	printf("the find_num is :%d\n", find_num);

	CloneArray(a, b, num);
	start = clock();
	int key = QuickSelect(a, 0, num-1, find_num);
	end = clock();
	printf("QuickSelect = %d\n", key);
	printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);

	CloneArray(a, b, num);
	start = clock();
	key = BFPRTSelect(a, 0, num-1, find_num);
	end = clock();
	printf("BFPRTSelect = %d\n", key);
	printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);

	delete[] a;
	delete[] b;

	printf("PrintSelect End\n");
	system("pause");
}
