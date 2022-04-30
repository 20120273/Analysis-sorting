#include"GKSort.h"
void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}
void SelectionSort(int* a, int n)
{
	int minI = 0;
	for (int i = 0; i < n - 1; i++)
	{
		minI = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[minI] > a[j])
				minI = j;
		}
		swap(a[i], a[minI]);
	}
}
void InsertionSort(int* a, int n)
{
	int key = 0;
	int j = 0;
	for (int i = 1; i < n; i++)
	{
		key = a[i];
		j = i;
		while (j > 0 && a[j-1] > key)
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = key;
	}
}
void BubbleSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		/*int flag = 0;*/
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				/*flag = 1;*/
			}
		}
		/*if (flag == 0)
			return;*/
	}
}
void Merge(int* a, int mid, int dau, int cuoi)
{
	int nL = mid - dau + 1;//So luong phan tu mang trai
	int nR = cuoi - mid; //So luong phan tu mang phai
	int* aL = new int[nL];// Cap phat mang trai
	int* aR = new int[nR];//Cap phat mang phai
	for (int i = 0; i < nL; i++)
	{
		aL[i] = a[dau+i]; //Truyen gia tri vao cac mang con
	}
	for (int i = 0; i < nR; i++)
	{
		aR[i] = a[mid + 1+i];
	}
	int iR = 0; //Chi so de truy cap cac phan tu mang phai
	int iL = 0;//Chi so de truy cap cac phan tu mang phai
	int iA = dau;
	while (iR < nR && iL < nL) //Neu ca hai mang van con phan tu de gop
	{
		if (aR[iR] < aL[iL])//Cai nao be hon thi dua vao mang chinh truoc va tang chi so len
		{
			a[iA++] = aR[iR++];
		}
		else
		{
			a[iA++] = aL[iL++];
		}
	}
	while (iR < nR)//neu mang phai van con phan  tu thi dua not vao mang chinh
	{
		a[iA++] = aR[iR++];
	}
	while (iL < nL)//neu mang trai van con phan  tu thi dua not vao mang chinh
	{
		a[iA++] = aL[iL++];
	}
}
void MergeSort(int* a, int dau,int cuoi)
{
	if (dau < cuoi)
	{
		int mid = dau + (cuoi - dau) / 2;
		MergeSort(a, dau, mid);
		MergeSort(a, mid + 1, cuoi);
		Merge(a, mid, dau, cuoi);
	}
}
int Partition(int* a, int dau, int cuoi)
{
	int mid = (cuoi + dau) / 2;
	int pivot = a[mid];//day la phan tu ta se dua ve dung vi tri
	int j = dau; //Day la chi so dung de chuyen cac phan tu nho hon pivot len dau mang va de dua pivot ve dung vi tri
	for (int i = dau; i < mid; i++)
	{
		if (a[i] < pivot)
		{
			swap(a[i], a[j]);
			j++;
		}
	}
	for (int i = mid+1; i <=cuoi; i++)
	{
		if (a[i] < pivot)
		{
			swap(a[i], a[j]);
			j++;
		}
	}
	swap(a[j], a[mid]);
	return j;
}
void QuickSort(int* a, int dau, int cuoi)
{
	if (dau < cuoi)
	{
		int pi = Partition(a, dau, cuoi);//pi la chi so cua phan tu da o dung vi tri
		QuickSort(a, dau, pi - 1);//ta sap xep lai phan mang o phia truoc pi va sau pi
		QuickSort(a, pi + 1, cuoi);
	}
}
void heapify(int* a, int n, int i)
{
	int max = i; //chi so cua phan tu lon nhat
	int l = 2 * i + 1; //con trai
	int r = 2 * i + 2;// con phai
	if (l<n && a[l]>a[max]) //neu con trai > cha thi chi so cua phan tu lon nhat la con trai
		max = l;
	if (r<n && a[r]>a[max])
		max = r;
	if (max != i)//neu co phan tu lon hon cha thi minh doi vi tri
	{
		swap(a[i], a[max]);
		heapify(a, n, max);// kiem tra tiep coi co phan tu nao lon hon o cay con duoi ko
	}
}
void HeapSort(int* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) //phan tu co chi n/2-1 la phan tu dau tien co con xet tu duoi len
	{
		heapify(a, n, i); //xay dung max heap
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(a[0], a[i]);//a[0] la phan tu lon nhat trong max heap nen chuyen no ve cuoi
		heapify(a, i, 0);//vi da co san max heap(chi vi tri dau sai vi tri) nen ta xet tu vi tri dau xuong se duoc 1 max heap nua
	}
}


//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}
// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}
void GenerateData(int* a,int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
	{
		GenerateRandomData(a, n);
		clock_t start = clock();
		SelectionSort(a, n);
		clock_t finish = clock();
		cout << "Thoi gian chay cua selection sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateRandomData(a, n);
		start = clock();
		InsertionSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Insertion Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateRandomData(a, n);
		start = clock();
		BubbleSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Bubble Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateRandomData(a, n);
		start = clock();
		MergeSort(a, 0, n - 1);
		finish = clock();
		cout << "Thoi gian chay cua Merge sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateRandomData(a, n);
		start = clock();
		QuickSort(a, 0, n - 1);
		finish = clock();
		cout << "Thoi gian chay cua Quick Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateRandomData(a, n);
		start = clock();
		HeapSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Heap Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		delete[] a;
		break;
	}
	case 1:	// có thứ tự
	{
		GenerateSortedData(a, n);
		clock_t start = clock();
		SelectionSort(a, n);
		clock_t finish = clock();
		cout << "Thoi gian chay cua selection sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateSortedData(a, n);
		start = clock();
		InsertionSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Insertion Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateSortedData(a, n);
		start = clock();
		BubbleSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Bubble Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateSortedData(a, n);
		start = clock();
		MergeSort(a, 0, n - 1);
		finish = clock();
		cout << "Thoi gian chay cua Merge sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateSortedData(a, n);
		start = clock();
		QuickSort(a, 0, n - 1);
		finish = clock();
		cout << "Thoi gian chay cua Quick Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateSortedData(a, n);
		start = clock();
		HeapSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Heap Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		delete[] a;
		break;
	}
	case 2:	// có thứ tự ngược
	{
		GenerateReverseData(a, n);
		clock_t start = clock();
		SelectionSort(a, n);
		clock_t finish = clock();
		cout << "Thoi gian chay cua selection sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateReverseData(a, n);
		start = clock();
		InsertionSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Insertion Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateReverseData(a, n);
		start = clock();
		BubbleSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Bubble Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateReverseData(a, n);
		start = clock();
		MergeSort(a, 0, n - 1);
		finish = clock();
		cout << "Thoi gian chay cua Merge sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateReverseData(a, n);
		start = clock();
		QuickSort(a, 0, n - 1);
		finish = clock();
		cout << "Thoi gian chay cua Quick Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateReverseData(a, n);
		start = clock();
		HeapSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Heap Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		delete[] a;
		break;
	}
	case 3:	// gần như có thứ tự
	{
		GenerateNearlySortedData(a, n);
		clock_t start = clock();
		SelectionSort(a, n);
		clock_t finish = clock();
		cout << "Thoi gian chay cua selection sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateNearlySortedData(a, n);
		start = clock();
		InsertionSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Insertion Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateNearlySortedData(a, n);
		start = clock();
		BubbleSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Bubble Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateNearlySortedData(a, n);
		start = clock();
		MergeSort(a, 0, n - 1);
		finish = clock();
		cout << "Thoi gian chay cua Merge sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateNearlySortedData(a, n);
		start = clock();
		QuickSort(a, 0, n - 1);
		finish = clock();
		cout << "Thoi gian chay cua Quick Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		GenerateNearlySortedData(a, n);
		start = clock();
		HeapSort(a, n);
		finish = clock();
		cout << "Thoi gian chay cua Heap Sort la: " << (double)(finish - start) / CLOCKS_PER_SEC << endl;
		delete[] a;
		break;
	}
	default:
		printf("Error: unknown data type!\n");
	}
}