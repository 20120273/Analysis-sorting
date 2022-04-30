#include"GKSort.h"
int main()
{
	int* a=new int[3000];
	GenerateData(a, 3000, 0);
	a = new int[10000];
	GenerateData(a, 10000, 0);
	a = new int[30000];
	GenerateData(a, 30000, 0);
	a = new int[100000];
	GenerateData(a, 100000, 0);
	a = new int[300000];
	GenerateData(a, 300000, 0);
	int* a = new int[3000];
	GenerateData(a, 3000, 2);
	a = new int[10000];
	GenerateData(a, 10000, 2);
	a = new int[30000];
	GenerateData(a, 30000, 2);
	a = new int[100000];
	GenerateData(a, 100000, 2);
	a = new int[300000];
	GenerateData(a, 300000, 2);
	return 0;
}