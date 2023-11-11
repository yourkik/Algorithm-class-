//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//
//float g[30][2];
//
//struct EDGE {//save one edge's information
//	int v, s;
//	float l;
//}edge[1000];
//
////input n
////output k
////After calculating the length of the line connecting all nodes and storing it in w,
////the number k of lines that can be connected is returned.
//int calculate(int n) {
//	int k = 0;
//	for (int i = 0; i < n-1; i++) {
//		for (int j = i+1; j < n; j++) {
//			edge[k].v = i;//Save the two end points of one edge to distinguish them using numbers.
//			edge[k].s = j;
//			edge[k].l = sqrt((pow(g[i][0] - g[j][0], 2) + pow(g[i][1] - g[j][1],2)));
//			k++;
//		}
//	}
//	return k;
//}
//
////input two EDGE pointer
////output 
////swapping two edge array
//void swap(EDGE* p1, EDGE* p2) {
//	EDGE temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//
////input k
////output 
////sorting edge array for length
//void sort(int k) {
//	for (int i = 0; i < k; i++) {
//		for (int j = i; j < k; j++) {
//			if (edge[i].l > edge[j].l) swap(&edge[i], &edge[j]);
//		}
//	}
//}
//
////input k
////output sum
////finding minimum total length of link lines and return that value
//float find_minimum_length(int k) {
//	int set[30] = { 0, };
//	float sum = 0.0;
//	for (int i = 0; i < k; i++) {
//		if (set[edge[i].s] != 1 || set[edge[i].v] != 1) {
//			sum += edge[i].l;
//			set[edge[i].s] = 1;
//			set[edge[i].v] = 1;
//		}
//	}
//	return sum;
//}
//
//int main() {
//	FILE* fp;
//	fp = fopen("Saving_ink.txt", "r");
//	int n=0, k=0;
//	fscanf(fp, "%d", &n);
//	for (int i = 0; i < n; i++) {
//		fscanf(fp, "%f %f", &g[i][0], &g[i][1]);
//	}
//
//	k=calculate(n);
//
//	sort(k);
//
//	printf("%.2f", find_minimum_length(k));
//	return 0;
//}