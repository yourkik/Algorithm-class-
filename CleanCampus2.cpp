//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//
//struct Point {
//    double x;
//    double y;
//};
//
//// Function to compute the distance between two points
//double distance(struct Point p1, struct Point p2) {
//    double dx = p1.x - p2.x;
//    double dy = p1.y - p2.y;
//    return sqrt(dx * dx + dy * dy);
//}
//
//bool CCW(Point* p1, Point* p2, Point* p3) {
//    double crossProduct = (p2->x - p1->x) * (p3->y - p1->y) - (p2->y - p1->y) * (p3->x - p1->x);
//    return crossProduct > 0;
//}
//
//// Function to find the convex hull using Jarvis's March algorithm
//double JarvisMarch(struct Point P[], int n) {
//    if (n < 3) {
//        return 0.0; // Convex hull not possible with less than 3 points
//    }
//
//    // Find the point with the lowest x-coordinate
//    int minX = 0;
//    for (int i = 1; i < n; i++) {
//        if (P[i].x < P[minX].x) {
//            minX = i;
//        }
//    }
//
//    // Initialize the convex hull with the leftmost point
//    int hull[100]; // Assuming a maximum of 100 points in the hull
//    int hull_i = 0;
//    int current = minX;
//
//    do {
//        hull[hull_i] = current;
//        hull_i++;
//        int next = (current + 1) % n;
//        for (int i = 0; i < n; i++) {
//            if (i != current && (hull_i == 1 || (P[i].x != P[current].x || P[i].y != P[current].y)) &&
//                (next == current || (P[next].x - P[current].x) * (P[i].y - P[current].y) - (P[next].y - P[current].y) * (P[i].x - P[current].x) > 0)) {
//                next = i;
//            }
//        }
//        current = next;
//    } while (current != minX);
//
//    // Calculate the length of silk required
//    double totalLength = 0.0;
//    for (int i = 0; i < hull_i; i++) {
//        int p1Index = hull[i];
//        int p2Index = hull[(i + 1) % hull_i];
//        totalLength += distance(P[p1Index], P[p2Index]);
//    }
//    totalLength += 2.0; // Add extra meters for tying
//
//    return totalLength;
//}
//
//int main() {
//    int t, n;
//    scanf("%d", &t);
//
//    while (t--) {
//        scanf("%d", &n);
//        struct Point P[100]; // Assuming a maximum of 100 points
//        P[0].x = 0;
//        P[0].y = 0;
//        n++;
//        for (int i = 0; i < n; i++) {
//            scanf("%lf %lf", &P[i].x, &P[i].y);
//        }
//
//        double silkLength = JarvisMarch(P, n);
//        printf("%.3lf\n", silkLength+2); // Display up to 3 decimal places
//    }
//
//    return 0;
//}