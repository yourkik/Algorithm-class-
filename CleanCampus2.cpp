#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_P 100

struct Point {
	double x;
	double y;
};

double distance(struct Point p1, struct Point p2) {
	printf("%lf %lf : %lf %lf\n", p1.x, p1.y, p2.x, p2.y);
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy);
}

// Function to check if three points are in counterclockwise order
bool CCW(struct Point p1, struct Point p2, struct Point p3) {
	double crossProduct = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
	return crossProduct > 0;
}

// Function to find the convex hull using Jarvis's March algorithm
double JarvisMarch(struct Point P[], int n) {
	if (n < 3) {
		return 0.0; // Convex hull not possible with less than 3 points
	}

	// Find the point with the lowest y-coordinate (and leftmost if tied)
	int minY = 0;
	for (int i = 0; i < n; i++) {
		if (P[i].y < P[minY].y || (P[i].y == P[minY].y && P[i].x < P[minY].x)) {
			minY = i;
		}
	}

	// Swap the lowest point with the first point (0,0)
	struct Point temp = P[0];
	P[0] = P[minY];
	P[minY] = temp;

	// Initialize the convex hull with the lowest point
	int hull[MAX_P];
	int hull_i = 0;
	int current = 0;

	do {
		hull[hull_i] = current;
		hull_i++;
		int next = (current + 1) % n;
		for (int i = 0; i < n; i++) {
			if (i == current || i == next) continue;
			if (CCW(P[current], P[next], P[i])) next = i;
		}
		current = next;
	} while (current != 0);

	// Calculate the length of silk required
	double totalLength = 0.0;
	for (int i = 0; i < hull_i; i++) {
		int p1Index = hull[i];
		int p2Index = hull[(i + 1) % hull_i];
		totalLength += distance(P[p1Index], P[p2Index]);
	}

	Point startPoint = { 0,0 };
	// Add extra meters for tying
	if (P[minY].x != 0 || P[minY].y != 0) {
		totalLength += 2 * distance(P[hull[0]], startPoint);
	}

	return totalLength;
}

int main() {
	int numTestCases;
	scanf("%d", &numTestCases);

	for (int testCase = 0; testCase < numTestCases; testCase++) {
		int n;
		scanf("%d", &n);

		struct Point P[MAX_P];

		for (int i = 0; i < n; i++) {
			scanf("%lf %lf", &P[i].x, &P[i].y);
		}

		double silkLength = JarvisMarch(P, n);
		printf("%.2lf\n", silkLength);

	}

	return 0;
}