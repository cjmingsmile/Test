

#include "sort.h"



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
		int m = partition(a, i, i+4);

		int mid_i = (i - low)/5 + low;
		int temp = a[mid_i];
		a[mid_i] = a[i+2];
		a[i+2] = temp;
	}

	if ((hight-low+1)%5 != 0)
	{
		int i = hight - (hight-low+1)%5 + 1;
		int m = partition(a, i, hight);

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