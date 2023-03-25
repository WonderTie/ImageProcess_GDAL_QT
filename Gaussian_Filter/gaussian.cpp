#include "gaussian.h"

double** guassian::matrix_weight(int weight_size, float sigma, vector<vector<pair<int, int>>>&weight_direction){
	vector<pair<int, int>>tem_row_ave;
	tem_row_ave.resize(weight_size);
	weight_direction.resize(weight_size, tem_row_ave);//权重方向
	double **array = new double *[weight_size];//初始化动态矩阵
	for (int i = 0; i < weight_size;i++)
	{
		array[i] = new double[weight_size];
	}
	int center_i, center_j;
	center_i = center_j = weight_size / 2;
	double pi = 3.141592653589793;
	double sum = 0.0f;
	int x, y;
	for (int i = 0; i < weight_size;i++)
	{
		for (int j = 0; j < weight_size;j++){
			x = i - center_i;
			y = j - center_j;
			weight_direction[i][j].first = x;
			weight_direction[i][j].second = y;
			array[i][j] = (1 / (2 * 3.1415926*sigma*sigma))*exp(-(x*x + y*y) / (2 * sigma*sigma));
			sum += array[i][j];
		}
	}
	//归一化
	for (int i = 0; i < weight_size; i++)
	{
		for (int j = 0; j < weight_size; j++)
		{
			array[i][j] /= sum;
		}
	}
	return array;
}
void guassian::myGaussianFilter(cv::Mat *src, cv::Mat *dst, double **array, int weight_size, vector<vector<pair<int, int>>>weight_direction){
	(*dst) = (*src).clone();
	int rows = src->rows;
	int cols = src->cols;
	int x_(0), y_(0);
	double sum = 0;
	Mat_<uchar> image = *dst;
	Mat_<Vec3b> image_rgb = *dst;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols;j++)
		{
			sum = 0;
			double sum_rgb[3] = { 0 };
			for (int w_row = 0; w_row < weight_size; w_row++)//处理邻域
			{
				for (int w_col = 0; w_col < weight_size; w_col++)
				{
					x_ = weight_direction[w_row][w_col].first;
					y_ = weight_direction[w_row][w_col].second;
					if (i + x_<0 || i + x_>rows - 1 || j + y_<0 || j + y_>cols - 1)
					{
						continue;
					}
					if ((*src).type() == CV_8UC1){ sum += (*src).at<uchar>(i + x_, j + y_)*array[w_row][w_col]; }
					if ((*src).type() == CV_8UC3)
					{ 
						sum_rgb[0] += (*src).at<Vec3b>(i + x_, j + y_)[0] * array[w_row][w_col];
					    sum_rgb[1] += (*src).at<Vec3b>(i + x_, j + y_)[1] * array[w_row][w_col];
						sum_rgb[2] += (*src).at<Vec3b>(i + x_, j + y_)[2] * array[w_row][w_col];
					};
				}
			}
			if ((*src).type() == CV_8UC1){ image(i, j) = saturate_cast<uchar>(sum);}
			if ((*src).type() == CV_8UC3)
			{
				image_rgb(i, j)[0] = saturate_cast<uchar>(sum_rgb[0]);
				image_rgb(i, j)[1] = saturate_cast<uchar>(sum_rgb[1]);
				image_rgb(i, j)[2] = saturate_cast<uchar>(sum_rgb[2]);
			};
		}
	}
}
Mat guassian::Gaussian_read(Mat *src, int weight_size, double sigma, double **array, vector<vector<pair<int, int>>>weight_direction){
	Mat dst;
	myGaussianFilter(src, &dst, array, weight_size, weight_direction);
	return dst;
	/*if (src->type()==CV_8UC1)
	{
		myGaussianFilter(src, &dst, array, weight_size, weight_direction);
		return dst;
	}
	else
	{
		vector<Mat> dst_rgb;
		dst_rgb.resize(3);
		vector<Mat>channel;
		split(*src, channel);
		myGaussianFilter(&channel[0], &dst_rgb[0], array, weight_size, weight_direction);
		myGaussianFilter(&channel[1], &dst_rgb[1], array, weight_size, weight_direction);
		myGaussianFilter(&channel[2], &dst_rgb[2], array, weight_size, weight_direction);
		merge(dst_rgb, dst);
		return dst;
	}*/
}














/*

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;
double** matrix_weight(int weight_size, float sigma, vector<vector<pair<int, int>>>&weight_direction){
	vector<pair<int, int>>tem_row_ave;
	tem_row_ave.resize(weight_size);
	weight_direction.resize(weight_size, tem_row_ave);//权重方向
	double **array = new double *[weight_size];//初始化动态矩阵
	for (int i = 0; i < weight_size; i++)
	{
		array[i] = new double[weight_size];
	}
	int center_i, center_j;
	center_i = center_j = weight_size / 2;
	double pi = 3.141592653589793;
	double sum = 0.0f;
	int x, y;
	for (int i = 0; i < weight_size; i++)
	{
		for (int j = 0; j < weight_size; j++){
			x = i - center_i;
			y = j - center_j;
			weight_direction[i][j].first = x;
			weight_direction[i][j].second = y;
			array[i][j] = (1 / (2 * 3.1415926*sigma*sigma))*exp(-(x*x + y*y) / (2 * sigma*sigma));
			sum += array[i][j];
		}
	}
	//归一化
	for (int i = 0; i < weight_size; i++)
	{
		for (int j = 0; j < weight_size; j++)
		{
			array[i][j] /= sum;
		}
	}
	return array;
}
void myGaussianFilter(cv::Mat *src, cv::Mat *dst, double **array, int weight_size, vector<vector<pair<int, int>>>weight_direction){
	(*dst) = (*src).clone();
	int rows = src->rows;
	int cols = src->cols;
	int x_(0), y_(0);
	double sum = 0;
	Mat_<uchar> image = *dst;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			sum = 0;
			for (int w_row = 0; w_row < weight_size; w_row++)//处理邻域
			{
				for (int w_col = 0; w_col < weight_size; w_col++)
				{
					x_ = weight_direction[w_row][w_col].first;
					y_ = weight_direction[w_row][w_col].second;
					if (i + x_<0 || i + x_>rows - 1 || j + y_<0 || j + y_>cols - 1)
					{
						continue;
					}

					sum += (*src).at<uchar>(i + x_, j + y_)*array[w_row][w_col];
				}
			}
			image(i, j) = saturate_cast<uchar>(sum);
		}

	}

}
Mat Gaussian_read(Mat *src, int weight_size, double sigma){
	vector<vector<pair<int, int>>>weight_direction;
	double **array = matrix_weight(weight_size, sigma, weight_direction);
	Mat dst;
	if (src->type() == CV_8UC1)
	{

		myGaussianFilter(src, &dst, array, weight_size, weight_direction);
		return dst;
	}
	else
	{
		vector<Mat> dst_rgb;
		dst_rgb.resize(3);
		vector<Mat>channel;
		split(*src, channel);
		myGaussianFilter(&channel[0], &dst_rgb[0], array, weight_size, weight_direction);
		myGaussianFilter(&channel[1], &dst_rgb[1], array, weight_size, weight_direction);
		myGaussianFilter(&channel[2], &dst_rgb[2], array, weight_size, weight_direction);
		merge(dst_rgb, dst);
		return dst;
	}
}
int main(){
	Mat src = imread("C:\\Users\\Administrator\\Desktop\\软件测试\\test1.jpg");

	Mat dis = Gaussian_read(&src, 3, 1.6);

	imshow("before", src);
	imshow("after", dis);
	waitKey();

	return 0;
}*/
