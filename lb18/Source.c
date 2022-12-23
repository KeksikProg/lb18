#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

//#define _CRT_SECURE_NO_WARNINGS

struct point {
	float x;
	float y;
	char name;
};

struct car {
	char brand[60];
	char proizvod[60];
	char type[60];
	int year_vipusk;
	int date_register;
};
typedef struct car Car;

typedef struct point Point;

void put_point(Point z) {

	printf("point %c (%.1f, %.1f)", z.name, z.x, z.y);
}

float dist(Point z, Point w) {
	float d;
	d = sqrt(pow(w.x - z.x, 2) + pow(w.y - z.y, 2));
	printf("Расстояние между точками: %f\n", d);
}

float mid(Point z, Point w) {
	Point m;
	m = (Point){ (z.x + w.x) / 2.f, (z.y + w.y) / 2.f, 'M' };
	printf("Середина отрезка между точками:");
	put_point(m);
}


void task1() {
	Point a, b;

	a = (Point){ 1.f, 2.f, 'A' };
	b.name = 'B'; b.x = 5; b.y = -3;

	put_point(a);
	printf("point %c (%.1f %.1f)\n", b.name, b.x, b.y);
	dist(a, b);
	mid(a, b);
	printf("\n\n");

}


void task2() {

	struct tm* my_time;
	time_t t, tn;
	t = time(NULL);
	my_time = localtime(&t);
	printf("Московское время %02d:%02d:%02d \n", my_time->tm_hour, my_time->tm_min, my_time->tm_sec);
	printf("\n");
	printf("%80s", "");
	if (my_time->tm_mon == 11 || my_time->tm_mon == 0 || my_time->tm_mon == 1) {
		printf("Зима");
	}
	if (my_time->tm_mon == 2 || my_time->tm_mon == 3 || my_time->tm_mon == 4) {
		printf("весна");
	}
	if (my_time->tm_mon == 5 || my_time->tm_mon == 6 || my_time->tm_mon == 7) {
		printf("лето");
	}
	if (my_time->tm_mon == 8 || my_time->tm_mon == 9 || my_time->tm_mon == 10) {
		printf("осень");
	}
	printf(" %d", my_time->tm_year-100);
}

void task3() {
	Car cari[3];
	cari[0] = (Car){ "focus", "Ford", "buty", 1956, 1990};
	cari[1] = (Car){ "cocus", "Ford", "cuty", 1965, 1991 };
	cari[2] = (Car){ "pocus", "Ford", "nuty", 1945, 1998 };

	for (int i = 0; i < 3; i++) {
		printf("%s ", cari[i].brand);
		printf("%s ", cari[i].proizvod);
		printf("%s ", cari[i].type);
		printf("%d ", cari[i].year_vipusk);
		printf("%d\n",cari[i].date_register);
	}
}

int main() {
	setlocale(LC_ALL, "RUS");


	task3();

}

