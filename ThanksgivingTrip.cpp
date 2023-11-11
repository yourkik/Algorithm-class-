//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int main() {
//	int n, sum = 0,k=0;
//	int result[100];
//	int arr[100];
//	while (1) {
//		scanf("%d", &n);
//		if (n == 0)break;
//		for (int i = 0; i < n; i++) {
//			scanf("%d", &arr[i]);
//			sum += arr[i];//store total cost
//		}
//		int avg = (sum - sum % 10) / n;//compute avearage to sum
//		//printf("avg : %d\n", avg);
//		sum = 0;
//		for (int i = 0; i < n; i++) {
//			if (avg - arr[i] > 0) {
//				sum = sum + (avg - arr[i]);//Find the minimum amount of money to make an average.
//			}
//		}
//		result[k] = sum;//store result in array
//		k++;
//		sum = 0;
//	}
//	for (int i = 0; i < k; i++) {
//		printf("\%d\n", result[i]);
//	}
//	return 0;
//}