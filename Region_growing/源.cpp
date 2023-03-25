#pragma once
#include "region_growing.h"
using namespace cv;
using namespace std;


int main()
{
	//??????
	Mat srcImage = imread("C:\\Users\\Administrator\\Desktop\\test1.tiff");
	if (!srcImage.data)
	{
		cout << "??????????" << endl;
		return -1;
	}
	int min_number = 30;
	int threshold_ = 30;
	vector<vector<Point2i>>cluster_;
	int rows = srcImage.rows;
	int cols = srcImage.cols;

	Mat clusters_image;
	RNG rng;
	Point2i seed;
	seed.x = rng() % rows;
	seed.y = rng() % cols;
	//region_Auto(srcImage, threshold_, min_number, cluster_, clusters_image, 1);
	//imshow("???1", clusters_image);
/*
	region_Auto(srcImage, threshold_, min_number, cluster_, clusters_image,3);
	imshow("???2", clusters_image);*/
	/*region_Auto(srcImage, threshold_, min_number, cluster_, clusters_image);
	imshow("???", clusters_image);*/
	/*region_peo(srcImage, seed, threshold_, cluster_, clusters_image);
	imshow("???", clusters_image);*/
	waitKey();

	return 0;
}