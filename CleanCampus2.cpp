////ȭ���� ��� �����ϵ��� ���� �ּ� õ�� ���̸� ���ϴ� ����
////convex hull�� �������� ������ 0,0�� ���� �� convex hull�� �������� 0, 0�� �Ÿ� * 2�� ���������
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
	double crossProduct = (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);//���� ����(�׳� �ܿ�����)
	return crossProduct > 0;//Be careful!
}

// Function to find the convex hull using Jarvis's March algorithm
double JarvisMarch(struct Point P[], int n) {
	if (n < 3) {
		return 0.0; // Convex hull not possible with less than 3 points
	}

	// Find the point with the lowest y-coordinate (and leftmost if tied)
	int minX = 0;
	for (int i = 0; i < n; i++) {
		if (P[i].x < P[minX].x || (P[i].x == P[minX].y && P[i].y < P[minX].y)) {//lowest y find if y is same then select leftmost
			minX = i;
		}
	}

	// Swap the lowest point with the first point
	struct Point temp = P[0];
	P[0] = P[minX];
	P[minX] = temp;

	//// Initialize the convex hull with the lowest point
	//int hull[MAX_P];
	//int hull_i = 0;
	//int current = 0;
	Point hull[100];
	int hull_i = 0;
	int current = 0;

	do {
		hull[hull_i] = P[current];
		hull_i++;
		int next = (current + 1) % n;
		for (int i = 0; i < n; i++) {
			if (i == current || i == next) continue;
			if (!CCW(P[current], P[next], P[i])) next = i;//�� �κ��� !CCW�� CCW ��� ����
		}
		current = next;
	} while (current != 0);

	// Calculate the length of silk required
	double totalLength = 0.0;
	for (int i = 0; i < hull_i; i++) {
		/*int p1Index = hull[i];
		int p2Index = hull[(i + 1) % hull_i];
		totalLength += distance(P[p1Index], P[p2Index]);*/
		totalLength += distance(hull[i], hull[(i + 1) % hull_i]);
	}

	Point startPoint = { 0,0 };
	// Add extra meters for tying
	if (P[minX].x != 0 || P[minX].y != 0) {
		totalLength += 2 * distance(hull[0], startPoint);
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