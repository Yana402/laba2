#include < stdio.h >

int main()
{
	const M = 3; // число строк
	int i, j;
	int arr[3][3] = { 0 };
	int arrMax[3] = { 0 }; //массив,в котором только сумма строк
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			printf("arr[%d][%d]=", i, j);
			scanf_s("%d", &arr[i][j]); //ввели матрицу
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n"); //красиво вывели

	for (i = 0; i < M; i++) {
		arrMax[i] = 0;
		for (j = 0; j < M; j++) {
			arrMax[i] += arr[i][j]; //заполняем массив суммой элементов в строках
		}
	}

	for (i = 1; i < M; i++) {
		for (j = M - 1; j >= i; j--) {
			if (arrMax[j - 1] > arrMax[j]) {
				int temp = arrMax[j - 1];
				arrMax[j - 1] = arrMax[j];
				arrMax[j] = temp; //меняем местами строки с суммами

				for (int k = 0; k < M; k++) {
					temp = arr[j - 1][k];
					arr[j - 1][k] = arr[j][k];
					arr[j][k] = temp; //меняем местами строки введённого массива
				}
			}
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}