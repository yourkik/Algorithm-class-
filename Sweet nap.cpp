////순서 상관 없는 버전
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//char s[255];
//int times[100][2]; // 순서 상관없이 입력된 시간을 저장하기 위한 2차원 배열
//
////input how many schedule input
////output 
////sorting schedule so this algorithm can solve if input is not order
//void sort(int a) {
//    for (int i = 0; i < a; i++) {
//        for (int j = i + 1; j < a; j++) {
//            if (times[i][0] > times[j][0]) {
//                int temp_start = times[i][0];
//                int temp_end = times[i][1];
//                times[i][0] = times[j][0];
//                times[i][1] = times[j][1];
//                times[j][0] = temp_start;
//                times[j][1] = temp_end;
//            }
//        }
//    }
//}
//
//int main() {
//    int a, max = 0, st, day;
//
//    printf("Please enter how many days of nap time you would like to calculate. : ");
//    scanf("%d", &day);
//    for (int d = 0; d < day; d++) {
//        scanf("%d", &a);
//        getchar();
//        for (int i = 0; i < a; i++) {
//            scanf("%[^\n]s", &s);
//            getchar();
//            int k = 0;
//            for (int j = 0; j < 20; j++) {
//                if (s[j] >= '0' && s[j] <= '9') {
//                    times[i][k] = (s[j] - '0') * 600 + (s[j + 1] - '0') * 60 + (s[j + 3] - '0') * 10 + (s[j + 4] - '0');
//                    j = j + 4;
//                    k++;
//                }
//            }
//        }
//        sort(a); // 시간을 오름차순으로 정렬
//
//        int bf[2] = { 600, 600 }; // 초기값을 10:00 (600)으로 설정
//        for (int i = 0; i < a; i++) {
//            if (times[i][0] - bf[1] > max) {
//                max = times[i][0] - bf[1];
//                st = bf[1];
//            }
//            bf[0] = times[i][0];
//            bf[1] = times[i][1];
//        }
//
//        if (1080 - bf[1] > max) { // 남은 시간 계산
//            max = 1080 - bf[1];
//            st = bf[1];
//        }
//
//        if (max / 60 > 0)
//            printf("Day %d : the longest nap starts at %d:%02d and will last for %d hours %d minutes\n", d + 1, st / 60, st % 60, max / 60, max % 60);
//        else
//            printf("Day %d : the longest nap starts at %d:%02d and will last for %d minutes\n", d + 1, st / 60, st % 60, max % 60);
//
//        max = 0; // 초기화
//    }
//    return 0;
//}