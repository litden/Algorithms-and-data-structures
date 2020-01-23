//Литвинец Д.В. Домашнее задание к третьему уроку.
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#define N 10

void solution1();
void solution2();
void solution3();
void solution4();
void menu();


int search(int c[], int elem)
{
	int m, i, j;
	m = N / 2;
	i = 0;
	j = N - 1;
	while (c[m] != elem && i <= j) {
		if (elem > c[m]) i = m + 1;
		else j = m - 1;
		m = (i + j) / 2;
	}
	if (i > j) return 0;
	else return m + 1;
}

void swapEl(int *arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}


void myShakerSort(int *arr, int size)
{
	int leftMark = 1;
	int rightMark = size - 1;
	while (leftMark <= rightMark) {
		for (int i = rightMark; i >= leftMark; i--)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		leftMark++;

		for (int i = leftMark; i <= rightMark; i++)
			if (arr[i - 1] > arr[i]) swapEl(arr, i);
		rightMark--;
	}
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "rus");

	int sel = 0;
	do
	{
		menu();
		scanf("%i", &sel);
		switch (sel)
		{
		case 1:
			solution1();
			break;
		case 2:
			solution2();
			break;
		case 3:
			solution3();
			break;
		case 4:
			solution4();
			break;
		case 0:
			printf("До свидания\n");
			break;
		default:
			printf("Неправильный выбор\n");
		}
	} while (sel != 0);
	getch();
	return 0;
}
//1. Попробовать оптимизировать пузырьковую сортировку. 
//Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. 
//Написать функции сортировки, которые возвращают количество операций.
void solution1()
{
	printf("Задача №1\n");
	srand(time(NULL));
	int arr[10] = { 0 };
	int i, j;
	int b;
	int count = 0;

	int rand_number;
	for (i = 0; i < 100; i = i + 1)
	{
		rand_number = rand() % 10;
		arr[rand_number] = arr[rand_number] + 1;
	}

	for (i = 0; i < 10; i = i + 1)
	{
		printf("%d - %d\n", i, arr[i]);
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++) 
		{
			count++;
			if (arr[j] > arr[j + 1])
			{
				b = arr[j]; 
				arr[j] = arr[j + 1]; 
				arr[j + 1] = b; 
			}
		}
	}
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d - %d\n", i, arr[i] ); 
	}


	
		/*
	b = 0;									//Оптимизированная пузырьковая сортировка
	int f; 
	for (int i = 0; i < 10 - 1; i++)
	{
		f = 0;
		for (int j = 10 - 1; j > i; j--)
		{
			count++;
			if (arr[j] < arr[j - 1])
			{
				b = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = b;

				f = 1;
			}
		} 
		if (f == 0)
			break;
		
	}
	*/
	printf("Массив в отсортированном виде: \n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d - %d\n", i, arr[i] ); 
	}
	printf("Произведено перестановок: %d \n", count);
	
}

//2. *Реализовать шейкерную сортировку.

void solution2()
{
	printf("Задача №2*\n");
	int A[N] = { 1, 20, 3, 4, 58, 32, 45, 6, 10, 11 };

	for (int i = 0; i < N; i++)
	{
		printf("%d - %d\n", i, A[i]);
	}
	printf("\n");
	myShakerSort(A, N); 
	
	printf("Массив в отсортированном виде: \n");

	for (int i = 0; i < N; i++) 
	{
		printf("%d - %d\n ", i, A[i]);
	}
	printf("\n");
	
	
}



//3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
//Функция возвращает индекс найденного элемента или -1, если элемент не найден.
void solution3()
{
	printf("Задача №3*\n");
	int l, a, e;
	int A[N] = { 1, 20, 3, 4, 58, 32, 45, 6, 10, 11 };

	myShakerSort(A, N);

	printf("Массив в отсортированном виде: \n");

	for (int i = 0; i < N; i++)
	{
		printf("%d - %d\n ", i, A[i]);
	}
	printf("\n");

	printf("\nЧисло: ");
	scanf("%d", &e);
	l = search(A, e);
	if (l == 0) printf("-1\n");
	else printf("Находится на %d месте.\n", l);
}

//4.*Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.
void solution4()
{
	printf("Задача №4*\n");
	printf("К сожалению не успел выполнить данное задание.\n");

}
void menu()
{
	printf("\n1 - Задача №1\n");
	printf("2 - Задача №2*\n");
	printf("3 - Задача №3\n");
	printf("4 - Задача №4*\n");
	printf("0 - Выход\n");
}


