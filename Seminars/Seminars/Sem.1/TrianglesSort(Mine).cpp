// Задача 1 : Въвежда се цяло число N и после N тригъгълника в равнината,
//            определени от 3 точки(6 координати)
//                .Отпечатайте тригълниците сортирани по лицата им.
#include <cmath>
#include <iostream>
struct Point {
    double x;
    double y;
};
struct Triangle {
    Point point1;
    Point point2;
    Point point3;
};
void getPoint(Point &point) { std::cin >> point.x >> point.y; }
void getTriangles(Triangle &triangle) {
    getPoint(triangle.point1);
    getPoint(triangle.point2);
    getPoint(triangle.point3);
}
double getDistance(const Point &point1, const Point &point2) {
    double diffByX = point1.x - point2.x;
    double diffByY = point1.y - point2.y;

    return sqrt(diffByX * diffByX + diffByY * diffByY);
}

double getAreaOfTriangle(const Triangle &triangle) {
    double sideA = getDistance(triangle.point1, triangle.point2);
    double sideB = getDistance(triangle.point2, triangle.point3);
    double sideC = getDistance(triangle.point1, triangle.point3);

    double p = (sideA + sideB + sideC) / 2;

    return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
}
int *getAreasArr(const Triangle *triangles, int n) {
    int *areasOfTriangles = new int[n];

    for (int i = 0; i < n; ++i) {
        areasOfTriangles[i] = getAreaOfTriangle(triangles[i]);
    }

    return areasOfTriangles;
}
void swap(Triangle &triangle1, Triangle &triangle2) {
    Triangle swap = triangle1;
    triangle1 = triangle2;
    triangle2 = swap;
}
void swap(int &a, int &b) {
    int swap = a;
    a = b;
    b = swap;
}
void sortArr(Triangle *triangles, int *areasOfTriangles, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minElementIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (areasOfTriangles[j] < areasOfTriangles[minElementIndex]) {
                minElementIndex = j;
            }
        }
        if (minElementIndex != i) {
            swap(triangles[i], triangles[minElementIndex]);
            swap(areasOfTriangles[i], areasOfTriangles[minElementIndex]);
        }
    }
}
void printPoint(const Point &point) { std::cout << point.x << " " << point.y; }
void printTriangle(const Triangle &triangle) {
    printPoint(triangle.point1);
    std::cout << " ";
    printPoint(triangle.point2);
    std::cout << " ";
    printPoint(triangle.point3);
    std::cout << std::endl;
}

int main() {
    int n;
    std::cin >> n;

    Triangle *triangles = new Triangle[n];

    for (int i = 0; i < n; ++i) {
        getTriangles(triangles[i]);
    }

    int *areasOfTriangles = getAreasArr(triangles, n);

    sortArr(triangles, areasOfTriangles, n);

    for (int i = 0; i < n; i++) {
        printTriangle(triangles[i]);
    }

    delete[] triangles;
    delete[] areasOfTriangles;

    return 0;
}