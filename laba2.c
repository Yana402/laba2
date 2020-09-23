#include < stdio.h >

int main()
{
	const M = 3; // ����� �����
	int i, j;
	int arr[3][3] = { 0 };
	int arrMax[3] = { 0 }; //������,� ������� ������ ����� �����
	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			printf("arr[%d][%d]=", i, j);
			scanf_s("%d", &arr[i][j]); //����� �������
		}
	}

	for (i = 0; i < M; i++) {
		for (j = 0; j < M; j++) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n"); //������� ������

	for (i = 0; i < M; i++) {
		arrMax[i] = 0;
		for (j = 0; j < M; j++) {
			arrMax[i] += arr[i][j]; //��������� ������ ������ ��������� � �������
		}
	}

	for (i = 1; i < M; i++) {
		for (j = M - 1; j >= i; j--) {
			if (arrMax[j - 1] > arrMax[j]) {
				int temp = arrMax[j - 1];
				arrMax[j - 1] = arrMax[j];
				arrMax[j] = temp; //������ ������� ������ � �������

				for (int k = 0; k < M; k++) {
					temp = arr[j - 1][k];
					arr[j - 1][k] = arr[j][k];
					arr[j][k] = temp; //������ ������� ������ ��������� �������
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