
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

	// ����
	void QuickSort(int *a, int low, int hight);
	// ����
	void InsertSort(int *a, int low, int hight);
	// ������
	void HeapAdjust(int *a, int low, int hight);
	void HeapSort(int *a, int len);

	//�ϲ�����
	void MergeArray(int *a, int *temp, int begin, int mid, int end);
	void MergeMySort(int *a, int *temp, int begin, int end);;
	void MergeSort(int *a, int len);

	// ð��
	void BubbleSort(int *a, int len);
};


#endif 


