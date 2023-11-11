//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int pancake[30];//Save pancake's size
//int cnt = 0;
//
////input k
////output 
////Flip pancake 0~k
//void flip(int k) {
//	int buf;
//	for (int i = 0; i < k; i++) {
//		buf = pancake[k];
//		pancake[k] = pancake[i];
//		pancake[i] = buf;
//		k--;
//	}
//}
//
////input n
////output maxi(the largest pancake's index)
////Find the largest pancake
//int findMax(int n) {//When find the largest pancake, flip it to send it backward.
//	int maxi=0;//Save the largest pancake's index
//	for (int i = 0; i < n; i++) {
//		if (pancake[i]>pancake[maxi]) {
//			maxi = i;
//		}
//	}
//	return maxi;
//}
//
////input n
////output 
//////Checking from the end, send the largest one to the end, and repeat this for all but the largest ones.
//void pancakeSort(int n) {
//	for (int i = n; i > 1; i--) {
//		int mi = findMax(i);
//		if (mi != i - 1) {//If mi == i-1 don't need to flip 
//			if(mi!=0){
//				flip(mi);//If mi == 0 just need flip
//			} 
//			flip(i - 1);
//			cnt++;
//			printf("%d ", cnt);
//		}									
//	}
//	printf("0");
//}
//
//int main() {
//	int i = 0, j=0;
//	while (1) {
//		i = getchar();
//		if (i == EOF) {
//			break;
//		}
//		if (i >= '0' && i <= '9') {
//			pancake[j] = i;
//			j++;
//		}
//	}
//	for (int i = 0; i < j; i++) {
//		printf("%c ", pancake[i]);
//	}
//	printf("\n");
//	//printf("%d", j);
//	pancakeSort(j);
//
//	return 0;
//}