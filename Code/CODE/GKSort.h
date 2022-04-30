#pragma once
#include<iostream>
#include <fstream>
#include <cmath>
#include <time.h>
using namespace std;
template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
void swap(int& a, int& b);
void SelectionSort(int* a, int n);
void InsertionSort(int* a, int n);
void BubbleSort(int* a, int n);
void Merge(int* a, int mid, int dau, int cuoi);
void MergeSort(int* a, int dau, int cuoi);
int Partition(int* a, int dau, int cuoi);
void QuickSort(int* a, int dau, int cuoi);
void heapify(int* a, int n, int i);
void HeapSort(int* a, int n);

