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
//// �� �Լ��� �ۼ��Ͽ� x ��ǥ�� �������� ����
//int compareX(const void* a, const void* b) {
//    struct Point* p1 = (struct Point*)a;
//    struct Point* p2 = (struct Point*)b;
//    return (p1->x > p2->x) - (p1->x < p2->x);
//}
//
//// �� �Լ��� �ۼ��Ͽ� y ��ǥ�� �������� ����
//int compareY(const void* a, const void* b) {
//    struct Point* p1 = (struct Point*)a;
//    struct Point* p2 = (struct Point*)b;
//    //return (p1->y > p2->y) - (p1->y < p2->y);//�� �ڵ�� �Ʒ� �ڵ�� ����(������������ �Ҷ�� �ݴ�� �ϸ� ��)
//    if (p1->y > p2->y)return -1;
//    else if (p1->y == p2->y)return 0;
//    else if (p1->y < p1->y)return 1;
//}
//
//// �� �� ������ �Ÿ��� ���
//double distance(struct Point p1, struct Point p2) {
//    double dx = p1.x - p2.x;
//    double dy = p1.y - p2.y;
//    return sqrt(dx * dx + dy * dy);
//}
//
//// ���� ����� �� ���� ã�� �Լ�
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
//    // �߰� ������ �������� ���ʰ� �������� ����
//    double leftDist = findClosestPair(P, mid);
//    double rightDist = findClosestPair(P + mid, n - mid);
//
//    double minDist = fmin(leftDist, rightDist);//Save minimum value for leftDist or rightDist.
//
//    // �߰� ���ο��� ��ġ�� �κ��� ���
//    struct Point strip[30];
//    int stripSize = 0;
//    for (int i = 0; i < n; i++) {
//        if (fabs(P[i].x - midPoint.x) < minDist) {//x�� y�� ���ÿ� ����ϴ� �� ���� �����ϴ� ���� �ð��� �� ª���� -> ���� ���� �� ���ĵ� ������ ����
//            strip[stripSize] = P[i];
//            stripSize++;
//        }
//    }
//
//    // strip ������ ���� ����� �� ���� ã��
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
//        // x ��ǥ�� �������� ����
//        qsort(P, n, sizeof(struct Point), compareX);
//
//        // ���� ����� �� ���� ã�� ���
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
//    printf("�ҿ�ð�: %lf\n", (double)(end - start));
//
//    return 0;
//}