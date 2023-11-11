////예시에서 나올 수 있는 경우의 수가 2개임 이 코드도 정답 가능
////weight 순으로 정렬 후 IQ가 작아지는 부분 집합 탐색
////시작 지점을 처음부터 끝까지 탐색하면 모든 경우의 수를 확인 가능
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//#define MAX 1000
//
////Store weight, IQ and order
//struct Elephant {
//	int order;
//	int weight;
//	int IQ;
//}arr[MAX];
//
////Input 
////output n
////Read number in file and return how many elephant in there
//int File_Open() {
//	FILE* fp;
//	fp = fopen("SmartElephantInput.txt", "r");
//	int i = 0;
//	for (i = 0; i < 1000; i++) {
//		if (fscanf(fp, "%d %d", &arr[i].weight, &arr[i].IQ) == EOF)break;
//		arr[i].order = i+1;
//	}
//	/*for (int j = 0; j < i; j++) {
//		printf("%d %d\n", arr[j][0], arr[j][1]);
//	}*/
//	fclose(fp);
//	return i;
//}
//
////Input two address to swap
////ouput 
////swap them
//void swap(Elephant* p1, Elephant* p2) {
//	Elephant temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}
//
////Input n
////output 
////sort elephant imformation about weight
//void sort(int n) {
//	for (int i = 0; i < n; i++) {
//		for (int j = i; j < n; j++) {
//			if (arr[i].weight > arr[j].weight) {
//				swap(&arr[i], &arr[j]);
//			}
//		}
//	}
//}
//
//int main() {
//	int n = File_Open();
//	int bfIQ;
//	int k=0,maxk=0;//k mean how long subsequence
//	int result[MAX] = { 0, };
//	int buf[MAX] = { 0, };
//	sort(n);
//
//	for (int i = 0; i < n; i++) {
//		printf("%d %d\n", arr[i].weight, arr[i].IQ);
//	}
//	
//	for (int i = 0; i < n; i++) {
//		bfIQ = 10000;//initialize bfIQ to max value
//		k = 0;//initialize k to 0
//		for (int j = i; j < n; j++) {
//			if (bfIQ > arr[j].IQ) {
//				bfIQ = arr[j].IQ;
//				//printf("%d\n", bfIQ);
//				buf[k] = arr[j].order;
//				k++;
//			}
//		}
//		//printf("k: %d\n", k);
//		if (k > maxk) {//change buf and result array if subsequence longer than before
//			maxk = k;
//			for (int l = 0; l < k; l++) {
//				result[l] = buf[l];
//			}
//		}
//		if (k > (n - i))break;//if left number less than longest subsequence then break this loop
//	}
//	printf("%d\n", maxk);
//	for (int i = 0; i < maxk; i++) {
//		printf("%d\n", result[i]);
//	}
//	return 0;
//}