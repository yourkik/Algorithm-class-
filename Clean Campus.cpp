#define _CRT_SECURE_NO_WARNINGS
//화단을 모두 포함하도록 묶는 최소 천의 길이를 구하는 문제
//최종 결과에 2를 더해야함
//시작점은 (0, 0)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Point {
	double x;
	double y;
}P[100];

//Input p1, p2
//Output none
//Swapping value type of Point 
void swap(Point *p1,Point *p2) {
	Point temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int compareDegree(const void* a, const void* b) {
	Point* p1 = (Point *) a;//Pointer format change error in 'Point * a',
	Point* p2 = (Point *) b;
	double angle1 = atan2(p1->y, p1->x);
	double angle2 = atan2(p2->y, p2->x);
	if (angle1 > angle2)return 1;
	else if (angle1 < angle2)return -1;
	return 0;
}

double distance(Point p1, Point p2) {
	double dx = p1.x - p2.x;
	double dy = p1.y - p2.y;
	printf("%lf %lf\n", dx, dy);
	return sqrt(dx * dx + dy * dy);
}

//Input p1, p2, p3
//Output true or false
//If three point's relation is CCW then return true if not return false.
//If the calculation is not performed all at once, errors may occur due to missing values.
bool CCW(Point* p1, Point* p2, Point* p3) {
	double crossProduct = (p2->x - p1->x) * (p3->y - p1->y) - (p2->y - p1->y) * (p3->x - p1->x);//Vector의 외적을 통해 CCW를 검출하는 방법
	return crossProduct > 0;
}

//Input Point array, n(number of points)
//Output Length of silk that used by cleaning the campus
//Computing length of silk using to Graham Scan Algorithm
double GrahamScan(Point P[],int n) {
	//Finding point have minimum y noordinate and if y coordinate is same then leftmost
	int minY = 0;
	for (int i = 0; i < n; i++) {
		if (P[i].y < P[minY].y || (P[i].y==P[minY].y && P[i].x<P[minY].x)) {
			minY = i;
		}
	}

	//Swapping P[0] and point that have lowest y
	swap(&P[0], &P[minY]);

	//Sorting by angle relative to starting point
	qsort(&P[1], n - 1, sizeof(Point), compareDegree);

	Point hull[100];//Saving the connection order
	int hull_i=0;
	for (int i = 0; i < n; i++) {
		//0~1까지는 그냥 넣고 이후부터 CW인지를 검출 CW라면 backtracking해서 아닌 값을 찾아 연결
		while (hull_i >= 2 && CCW(&hull[hull_i-1],&P[hull_i],&P[i])==true){
			hull_i--;
		}
		hull[hull_i] = P[i];
		hull_i++;
	}
	printf("%d\n", hull_i);
	double total_length = 0;
	for (int i = 0; i < hull_i; i++) {
		total_length += distance(hull[i], hull[(i + 1) % hull_i]);
	}

	return total_length;
}


int main() {
	FILE* fp;
	fp = fopen("CleanCampus.txt","r");
	int t,n;
	fscanf(fp, "%d", &t);
	while (t)
	{
		fscanf(fp, "%d", &n);
		n++;
		P[0].x = 0;
		P[0].y = 0;
		for (int i = 1; i < n; i++) {
			fscanf(fp, "%lf %lf", &P[i].x, &P[i].y);
			//printf("%lf %lf\n", P[i].x, P[i].y);
		}
		printf("%lf\n",GrahamScan(P, n)+2);
		t--;
	}
	return 0;
}