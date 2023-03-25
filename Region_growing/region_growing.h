#pragma once
#include <vector>
#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <queue>
#include <numeric>
#include <ctime>
using namespace cv;
using namespace std;
class region_growing_sf
{
public:
	region_growing_sf();
	~region_growing_sf();
	int gray_diff(Point2i curr_point, Point2i nebor_point);
	void set_input_image(Mat *image);
	void region_growing(Point2i seed);
	void region_Auto();
	void region_peo(Point2i seed);
	void output_image(Mat &output_image_);
	Mat srcImage;
	Mat clusters_image;
	int threshold_;
	int min_number;
	vector<vector<Point2i>>cluster_final;
	int method;
private:
	vector<vector<int>>result;
	vector<vector<Point2i>>cluster_;
	static int counter1;
};









