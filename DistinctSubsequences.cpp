//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//char x[10000];
//char z[100];
//int **dp;
//int count;
//
////input index of row and column
////output none
////Check subsequence exist and count them
//void loop(int r,int c) {
//	if (r >= strlen(z)) {
//		count++;
//		return;
//	}
//	for (int j = c; j < strlen(x); j++) {
//		if (dp[r][j] != -1) {
//			loop(r + 1,j+1);
//		}
//	}
//}
//
//int main() {
//	FILE* fp;
//	fp = fopen("DistinctSubsequences.txt", "r");
//
//	int n;
//	fscanf(fp, "%d", &n);
//	for (int k = 0; k < n; k++) {
//		fscanf(fp, "%s %s", &x, &z);
//		//printf("%s %s\n", x, z);
//		//printf("%d\n", strlen(z));
//
//		//make two-dimensional array use malloc
//		dp = (int**)malloc(sizeof(int) * strlen(z));
//		for (int i = 0; i < strlen(z); i++) {
//			dp[i] = (int*)malloc(sizeof(int) * strlen(x));
//		}
//
//		for (int i = 0; i < strlen(z); i++) {
//			for (int j = 0; j < strlen(x); j++) {
//				if (z[i] == x[j]) {
//					dp[i][j] = j;//if z[i] == x[j] save index in dp else save -1
//				}
//				else {
//					dp[i][j] = -1;
//				}
//			}
//		}
//		/*for (int i = 0; i < strlen(z); i++) {
//			for (int j = 0; j < strlen(x); j++) {
//				printf("%d ", dp[i][j]);
//			}
//			printf("\n");
//		}*/
//
//		count = 0;//reset count to 0
//
//		loop(0,0);//start loop 
//
//		printf("%d\n", count);
//
//		free(dp);//reset dp
//	}
//	fclose(fp);
//	return 0;
//}