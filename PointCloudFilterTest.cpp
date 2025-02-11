/**
* @file PointCloudFilterTest.cpp
* @author Ol�an Sat�r (152120171109)
* @date 15.01.2022
* @brief Test file of PointCloudFilter class.
*
* This file is for testing purposes.
*/


#include "PointCloud.h"
#include "RadiusOutlierFilter.h"
#include "PassThroughFilter.h"
#include "PointCloudFilter.h"
using namespace std;

int main()
{
	PointCloud pointCloud;
	Point p(1, 1, 1);
	pointCloud.addElementToEnd(p);

	Point p1(4, 1, 10);
	pointCloud.addElementToEnd(p1); 

	Point p2(100, 100, 100);
	pointCloud.addElementToEnd(p2); // it must be deleted by pass through filter

	Point p3(2, 3, 0);
	pointCloud.addElementToEnd(p3);

	Point p4(56, 91, 2);
	pointCloud.addElementToEnd(p4); // it must be deleted by radius outlier filter

	Point p5(95, 97, 102);
	pointCloud.addElementToEnd(p5); // it must be deleted by pass through filter

	Point p6(2, 5, 1);
	pointCloud.addElementToEnd(p6);

	Point p7(3, 4, 1);
	pointCloud.addElementToEnd(p7);

	Point p8(3, 16, -47);
	pointCloud.addElementToEnd(p8); // it must be deleted by pass through filter

	Point p9(5, 8, 1);
	pointCloud.addElementToEnd(p9);

	Point p10(401, 8, 1);
	pointCloud.addElementToEnd(p10); // it must be deleted by pass through filter


	PointCloudFilter *radiusOutlierFilter = new RadiusOutlierFilter(25); //ikisinide PointCloudFilter da yapt�k. RadiusOutlierFilter�n filter�n� �a��rd���m�zda bu karar veriyor bunu yaratt�m ve bunun filter�n� �a��rd�m.
	PointCloudFilter* passThroughFilter = new PassThroughFilter(400, 0, 400, 0, 45, -45); //new leyip veriyoruz al bu senin bunu i�le.
	radiusOutlierFilter->filter(pointCloud); //Bu filter pointcloudun radiusOutlier filter�
	passThroughFilter->filter(pointCloud);  //Bu filter pointcloudun passThroughun filter�. karar verici filtre geldi bunu kimin yapaca��na karar verecek bir aray�z.

	pointCloud.printPoints();
}