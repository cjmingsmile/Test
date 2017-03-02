


void QuickSort(int *a, int low, int hight)
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


void InsertSort(int *a, int low, int hight)
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














