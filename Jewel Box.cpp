//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//
//int main() {
//	FILE* fp;
//	fp = fopen("Jewel_box.txt","r");//open file
//	int cp, c1, n1, c2, n2;
//
//	while (1) {
//		int m1 = 0, m2 = 0;
//		fscanf(fp, "%d", &cp);
//		if (cp != 0) {
//			fscanf(fp, "%d %d", &c1, &n1);
//			fscanf(fp, "%d %d", &c2, &n2);
//
//			if (n1 / c1 > n2 / c2) { //checking which box is more efficient
//				m1 = cp / n1;//Calculate how many
//				while(1){//Can change function form
//					if (((cp - (m1 * n1)) % n2) == 0) {
//						printf("%d %d\n", m1, (cp - (m1 * n1)) / n2);
//						break;
//					}
//					else {
//						if (m1 == 0) {
//							printf("failed\n");
//							break;
//						}
//						m1--;
//					}
//				}
//			}
//			else {
//				m2 = cp / n2;
//				while (1) {
//					if (((cp - (m1 * n1)) % n2) == 0) {
//						if(m2==0)
//						printf("%d %d\n", (cp - (m2 * n2)) / n1, m2);
//						break;
//					}
//					else {
//						if (m2 == 0) {
//							printf("failed\n");
//							break;
//						}
//						m2--;
//					}
//				}
//			}
//		}
//		else break;
//	}
//	return 0;
//}