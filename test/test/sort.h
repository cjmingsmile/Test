
#ifndef SORT_H
#define SORT_H

void CloneArray(int *a, int *b, int num);
void PrintArray(int *a, int num);
class Sort
{
public:
	static Sort Instance() {
		static Sort instance;
		return instance;
	}

	void PrintSort();

	// øÏ≈≈
	void QuickSort(int *a, int low, int hight);
	// ≤Â»Î
	void InsertSort(int *a, int low, int hight);
	// ∂—≈≈–Ú
	void HeapAdjust(int *a, int low, int hight);
	void HeapSort(int *a, int len);

	//∫œ≤¢≈≈–Ú
	void MergeArray(int *a, int *temp, int begin, int mid, int end);
	void MergeMySort(int *a, int *temp, int begin, int end);;
	void MergeSort(int *a, int len);

	// √∞≈›
	void BubbleSort(int *a, int len);
};


#endif 


