//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<algorithm>
//
//#ifndef min
//#define min(a,b)  (((a) < (b)) ? (a) : (b))
//#endif
//
//int a[10][100] = { 0, };
//int dp[10][100];
//
//int find_min(int row, int col,int height) {
//	int k = a[row][col];
//	int j = col - 1;
//	if (col == 0)return k;//맨 처음을 채움
//	if (row == 0) {//맨 위일 경우 가장 아랫 줄을 고려
//		return min(min(dp[height - 1][j], dp[row][j]), dp[row + 1][j]) + k;
//	}
//	else if (row >= height-1) {//맨 아래일 경우 맨 윗 줄을 고려
//		return min(min(dp[row - 1][j], dp[row][j]), dp[0][j]) + k;
//	}
//	return min(min(dp[row - 1][j], dp[row][j]),dp[row+1][j])+k;
//
//	//dp[row - 1][col - 1];//왼쪽 아래 대각선
//	//dp[row][col - 1];//왼쪽
//	//dp[row + 1][col - 1];//왼쪽 위 대각선
//}
////int find_path() {
////
////}
//
//int main() {
//	FILE* fp;
//	fp = fopen("CheapestWay.txt", "r");
//	int m, n;
//	while (1) {
//		if (fscanf(fp, "%d %d", &m, &n) != EOF) {
//			for (int i = 0; i < m; i++) {
//				for (int j = 0; j < n; j++) {
//					fscanf(fp, "%d ", &a[i][j]);
//					//printf("%d ", a[i][j]);
//				}
//				//printf("\n");
//			}
//		}
//		else break;
//		//printf("\n");
//		for (int j = 0; j < n; j++) {
//			for (int i = 0; i < m; i++) {
//				dp[i][j] = find_min(i, j,m);
//			}
//		}
//		/*for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n; j++) {
//				printf("%d ", dp[i][j]);
//			}
//			printf("\n");
//		}*/
//
//		//find total min in dp[0~m-1][n-1]
//		int min = 100000,min_num=0;
//		for (int i = 0; i < m; i++) {
//			if (min > dp[i][n - 1]) {
//				min = dp[i][n - 1];
//				min_num = i;
//			}
//		}
//
//
//		int path[100];//save path
//		path[n - 1] = a[min_num][n-1];
//		int temp = min;
//		for (int j = n - 2; j >= 0; j--) {
//			for (int i = 0; i < m; i++) {
//				if ((temp - path[j + 1]) == dp[i][j]) {
//					temp = temp - path[j+1];
//					path[j] = a[i][j];
//				}
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			printf("%d ", path[i]);
//		}
//		printf("\n%d\n", min);
//	}
//	return 0;
//}