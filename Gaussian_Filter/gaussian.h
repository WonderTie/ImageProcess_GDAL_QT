#pragma once
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;

class guassian{
public:
	double** matrix_weight(int weight_size, float sigma, vector<vector<pair<int, int>>>&weight_direction);
	void myGaussianFilter(cv::Mat *src, cv::Mat *dst, double **array, int weight_size, vector<vector<pair<int, int>>>weight_direction);
	Mat Gaussian_read(Mat *src, int weight_size, double sigma, double **array, vector<vector<pair<int, int>>>weight_direction);

};