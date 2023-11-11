////This algorihtm use int so if any value over 2,147,483,647 then this algorithm has error.
////So if you want to cover more broadly and make it closer to reality then change int to long. 
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<math.h>
//#include<stdlib.h>
//#include<time.h>
//
//int prime[10] = { 0, };
//
////input x
////output true or false
////if x is prime then return true if not return fasle
//bool isPrime(int x) {
//	for (int i = 2; i <= x / 2; i++) {
//		if (x % i == 0)return false;
//	}
//	return true;
//}
//
////input none
////output none
////make prime table
//void primeTable() {
//	int i=2, j = 0;
//	for (int i = 2; i < 100; i++) {
//		if (isPrime(i)) {
//			prime[j] = i;
//			j++;
//		}
//		if (j == 10)break;
//	}
//}
//
////input a, b
////output gcd
////make gcd to recursive
//int gcd(int a, int b) {
//	if (b == 0) {
//		return a;
//	}
//	else {
//		return gcd(b, a % b);
//	}
//}
//
////input a, b
////output true or false
////checking a and b is relatively prime
//bool isRelativelyPrime(int a, int b) {
//	if (gcd(a, b) == 1)return true;
//	return false;
//}
//
////input x(EulerPi)
////output i
////Finding relatively prime for x and return
//int findRelativelyPrime(int x) {
//	for (int i = 2; i < x; i++) {
//		if (isRelativelyPrime(x, i))return i;
//	}
//}
//
////input E and EulerPi
//int computeD(int E,int EulerPi) {
//	int i = 1;
//	while (1) {
//		if ((E * i) % EulerPi == 1)return i;
//		i++;
//	}
//}
//
////save binary set for c
//int binarySet[100];
////input b(degree)
////output i(binary set's length)
////Making a binary set for the degree to using Repeated Squaring Algorithm because this algorithm is more efficient than loop.
//int makeBinary(int b) {
//	//printf("%d\n", b);
//	for (int i = 0; i < 100; i++) {
//		binarySet[i] = b % 2;
//		b = b / 2;
//		if (b == 0)return i;
//	}
//}
////input a, b, n
////output d(compute degree calculation)
////compute (a^b) mod n and return
//int RepeatedSquaringAlgorithm(int a, int b, int n) {
//	int k = makeBinary(b);
//	/*for (int i = k; i>=0; i--) {
//		printf("%d ", binarySet[i]);
//	}
//	printf("\n");*/
//	int c = 0, d = 1;
//	for (int i = k; i >=0; i--) {
//		c = 2 * c;
//		d = (d * d) % n;
//		if (binarySet[i] == 1) {
//			c = c + 1;
//			d = (d * a) % n;
//		}
//	}
//	return d;
//}
//
////input M, E, D
////output Encrypted Message
////Encrypting message and return
//int Encrypt(int M,int E, int n) {
//	return RepeatedSquaringAlgorithm(M, E, n);
//}
//
////input C, D, n
////output Decrypted Message(origin message)
////Encrypted message(C) decrypt and return
//int Decrypt(int C, int D, int n) {
//	return RepeatedSquaringAlgorithm(C, D, n);
//}
//
//int main() {
//	srand(time(NULL));
//	int i, j=0;
//	primeTable();
//	int p = prime[rand() % 10];
//	int q = prime[(rand()*rand()) % 10];
//	//p = 7, q = 17;
//	int n = p * q;
//	int EulerPi = (p-1)*(q-1);
//	int E = findRelativelyPrime(EulerPi);
//	int D = computeD(E, EulerPi);
//	int M;
//
//	scanf("%d", &M);
//	int C = Encrypt(M, E, n);
//	printf("p : %d, q : %d, n : %d, EulerPi : %d, E : %d, D : %d\n", p, q, n, EulerPi, E, D);
//	printf("%d\n", C);
//	printf("%d\n", Decrypt(C, D, n));
//	return 0;
//}