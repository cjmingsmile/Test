
#include "stdafx.h"

#include "sort.h"

#include <time.h>  
#include <windows.h>
#include <cassert>


void CloneArray(int *a, int *b, int num)
{
	for (int i = 0; i < num; ++i)
	{
		a[i] = b[i];
	}
}

void PrintArray(int *a, int num)
{
	for (int i = 0; i < num; ++i)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}



void Sort::PrintSort()
{
	printf("PrintSort Start\n");
	static const int num = 100000;
	int *a = new int[num];
	int *b = new int[num];

	for (int i = 0; i < num; ++i)
	{
		b[i] = rand()%num; //num-i;
	}

	time_t start = clock();
	time_t end = clock();

	CloneArray(a, b, num);
	printf("QuickSort = \n");
	start = clock();
	QuickSort(a, 0, num-1);
	end = clock();
	printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);

	CloneArray(a, b, num);
	printf("InsertSort = \n");
	start = clock();
	InsertSort(a, 0, num-1);
	end = clock();
	printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);

	CloneArray(a, b, num);
	printf("HeapSort = \n");
	start = clock();
	HeapSort(a,num-1);
	end = clock();
	printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);

	CloneArray(a, b, num);
	printf("MergeSort = \n");
	start = clock();
	MergeSort(a,num);
	end = clock();
	printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);

	CloneArray(a, b, num);
	printf("BubbleSort = \n");
	start = clock();
	BubbleSort(a,num);
	end = clock();
	printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);



	delete[] a;
	delete[] b;

	printf("PrintSort End\n");
	system("pause");
}


void Sort::QuickSort(int *a, int low, int hight)
{
	if (low >= hight)
	{
		return;
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
	QuickSort(a, low, first - 1);
	QuickSort(a, first + 1, hight);
}


void Sort::InsertSort(int *a, int low, int hight)
{
	if (low >= hight)
	{
		return;
	}

	for (int i = low + 1; i <= hight; ++i)
	{
		if (a[i-1] > a[i])
		{
			int temp = a[i];
			int j = i;
			while (j <= hight && a[j-1] > temp)
			{
				a[j] = a[j-1];
				--j;
			}
			a[j] = temp;
		}
	}
}

// ∂—≈≈–Ú
void Sort::HeapAdjust(int *a, int low, int hight)
{
	int left_c = 2*low;
	int right_c = 2*low + 1;

	int k = low;
	if (left_c <= hight  && a[left_c] > a[k] )
	{
		k = left_c;
	}
	if (right_c <= hight && a[right_c] > a[k])
	{
		k = right_c;
	}

	if (k != low)
	{	
		int temp = a[low];
		a[low] = a[k];
		a[k] = temp;

		HeapAdjust(a, k, hight);
	}
}

void Sort::HeapSort(int *a, int len)
{
	for (int i = len/2; i >= 1; --i)
	{
		HeapAdjust(a, i, len);
	}

	int temp = 0;
	for (int i = len; i >= 1; --i)
	{
		temp = a[i];
		a[i] = a[1];
		a[1] = temp;

		HeapAdjust(a, 1, i-1);
	}
}

//∫œ≤¢≈≈–Ú
void Sort::MergeArray(int *a, int *temp, int begin, int mid, int end)
{
	int i = begin;
	int j = mid + 1;
	int k = begin;

	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}

	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= end)
	{
		temp[k++] = a[j++];
	}

	for (i = begin; i <= end; ++i)
	{
		a[i] = temp[i];
	}
}

void Sort::MergeMySort(int *a, int *temp, int begin, int end)
{
	if (begin < end)
	{
		int mid = (end - begin)/2 +begin;
		MergeMySort(a, temp, begin, mid);
		MergeMySort(a, temp, mid + 1, end);
		MergeArray(a, temp, begin, mid, end);
	}
}

void Sort::MergeSort(int *a, int len)
{
	if (len <= 1)
	{
		return;
	}

	int *q = new int[len];
	MergeMySort(a, q, 0, len - 1);
	delete[] q;
}


void Sort::BubbleSort(int *a, int len)
{
	int i, j, temp;
	for (i = 0; i < len; ++i)
	{
		for (j = 0; j < len - 1 - i; ++j)
		{
			if (a[j+1] > a[j])
			{
				temp = a[j+1];
				a[j+1] = a[j];
				a[j] = temp;
			}
		}
	}
}






