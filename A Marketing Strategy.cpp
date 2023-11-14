//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <float.h>
//#include <stdio.h>
//#include <time.h>
//
//
//struct Point {
//    double x;
//    double y;
//}P[30];
//
//// 비교 함수를 작성하여 x 좌표를 기준으로 정렬
//int compareX(const void* a, const void* b) {
//    struct Point* p1 = (struct Point*)a;
//    struct Point* p2 = (struct Point*)b;
//    return (p1->x > p2->x) - (p1->x < p2->x);
//}
//
//// 비교 함수를 작성하여 y 좌표를 기준으로 정렬
//int compareY(const void* a, const void* b) {
//    struct Point* p1 = (struct Point*)a;
//    struct Point* p2 = (struct Point*)b;
//    //return (p1->y > p2->y) - (p1->y < p2->y);//이 코드와 아래 코드는 동일(내림차순으로 할라면 반대로 하면 됨)
//    if (p1->y > p2->y)return -1;
//    else if (p1->y == p2->y)return 0;
//    else if (p1->y < p1->y)return 1;
//}
//
//// 두 점 사이의 거리를 계산
//double distance(struct Point p1, struct Point p2) {
//    double dx = p1.x - p2.x;
//    double dy = p1.y - p2.y;
//    return sqrt(dx * dx + dy * dy);
//}
//
//// 가장 가까운 두 점을 찾는 함수
//double findClosestPair(struct Point P[], int n) {
//    if (n <= 3) {
//        double minDist = DBL_MAX;
//        for (int i = 0; i < n; i++) {
//            for (int j = i + 1; j < n; j++) {
//                double dist = distance(P[i], P[j]);
//                if (dist < minDist) {
//                    minDist = dist;
//                }
//            }
//        }
//        return minDist;
//    }
//
//    int mid = n / 2;
//    struct Point midPoint = P[mid];
//
//    // 중간 라인을 기준으로 왼쪽과 오른쪽을 나눔
//    double leftDist = findClosestPair(P, mid);
//    double rightDist = findClosestPair(P + mid, n - mid);
//
//    double minDist = fmin(leftDist, rightDist);//Save minimum value for leftDist or rightDist.
//
//    // 중간 라인에서 걸치는 부분을 계산
//    struct Point strip[30];
//    int stripSize = 0;
//    for (int i = 0; i < n; i++) {
//        if (fabs(P[i].x - midPoint.x) < minDist) {//x와 y를 동시에 계싼하는 것 보다 정렬하는 것이 시간이 더 짧아짐 -> 따로 분할 단 합쳐도 정답은 나옴
//            strip[stripSize] = P[i];
//            stripSize++;
//        }
//    }
//
//    // strip 내에서 가장 가까운 두 점을 찾음
//    qsort(strip, stripSize, sizeof(struct Point), compareY);
//    for (int i = 0; i < stripSize; i++) {
//        for (int j = i + 1; j < stripSize&& (fabs(strip[j].y - strip[i].y) < minDist); j++) {
//            double dist = distance(strip[i], strip[j]);
//            if (dist < minDist) {
//                minDist = dist;
//            }
//        }
//    }
//
//    return minDist;
//}
//
//int main() {
//    time_t start = time(NULL);
//
//    int n;
//    while (1) {
//        scanf("%d", &n);
//        if (n == 0) break;
//
//        for (int i = 0; i < n; i++) {
//            scanf("%lf %lf", &P[i].x, &P[i].y);
//        }
//
//        // x 좌표를 기준으로 정렬
//        qsort(P, n, sizeof(struct Point), compareX);
//
//        // 가장 가까운 두 점을 찾고 출력
//        double closestDist = findClosestPair(P, n);
//        if (closestDist < 10000.0) {
//            printf("%.2lf\n", closestDist);
//        }
//        else {
//            printf("Infinity\n");
//        }
//    }
//
//    time_t end = time(NULL);
//    printf("소요시간: %lf\n", (double)(end - start));
//
//    return 0;
//}