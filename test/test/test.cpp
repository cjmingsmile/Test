// test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <cassert>

#include "select.h"
#include <time.h>    

#include "prime.h"

int _tmain(int argc, _TCHAR* argv[])
{
	static const int num = 10000000;
	int *a = new int[num];
	int *b = new int[num];

	for (int i = 0; i < num; ++i)
	{
		b[i] = num-i;
	}

	time_t start = clock();
	time_t end = clock();

	MakePrime();
	printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);
	PrintPrime();
/*
 while(true)
 {
	//for (int i = 0; i < num; ++i)
	//{
	//	a[i] = b[i];
	//}
	//start = clock();
	//QuickSort(a, 0, num-1);
	//end = clock();
	//printf("\nQuickSort = \n");
	//printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);

	//for (int i = 0; i < num; ++i)
	//{
	//	a[i] = b[i];
	//}
	//start = clock();
	//InsertSort(a, 0, num-1);
	//end = clock();
	//printf("\nInsertSort = \n");
	//printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);


	 int find_num = rand()%1000+1;

	 printf("\nthe find_num is :%d\n", find_num);
	for (int i = 0; i < num; ++i)
	{
		a[i] = b[i];
	}
	start = clock();
	int key = QuickSelect(a, 0, num-1, find_num);
	end = clock();
	printf("\nQuickSelect = %d\n", key);
	printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);

	for (int i = 0; i < num; ++i)
	{
		a[i] = b[i];
	}
	start = clock();
	key = BFPRTSelect(a, 0, num-1, find_num);
	end = clock();
	printf("\nBFPRTSelect = %d\n", key);
	printf("the running time is :%f\n", double(end -start)/CLOCKS_PER_SEC);



	Sleep(1000);
 }
*/

	delete[] a;
	delete[] b;

	system("pause");

	return 0;
}

