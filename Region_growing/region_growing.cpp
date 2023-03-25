#include "region_growing.h"
region_growing_sf::region_growing_sf()
{
}
region_growing_sf::~region_growing_sf(){
	counter1 = 0;
}
int region_growing_sf::counter1 = 0;
void region_growing_sf::set_input_image(Mat *image){
	srcImage = image->clone();
}
int region_growing_sf::gray_diff(Point2i curr_point, Point2i nebor_point){
	if (srcImage.type() == CV_8UC1)
	{
		Mat_<uchar>img_ = srcImage;
		int curr_gray = img_(curr_point.x, curr_point.y);
		int nebor_gray = img_(nebor_point.x, nebor_point.y);
		int diff = int(sqrt(pow((curr_gray - nebor_gray), 2)));
		return diff;
	}
	else if (srcImage.type() == CV_8UC3)
	{
		double diff = 0;
		Mat_<Vec3b>img_ = srcImage;
		int curr_gray, nebor_gray;
		for (int i = 0; i < 3; i++)
		{
			curr_gray = img_(curr_point.x, curr_point.y)[i];
			nebor_gray = img_(nebor_point.x, nebor_point.y)[i];
			diff += pow((curr_gray - nebor_gray), 2);
		}
		return int(sqrt(diff));
	}
	else
	{
		cout << "暂时不支持其他波段" << endl;
		return -1;
	}
}
void region_growing_sf::region_growing(Point2i seed){
	int rows = srcImage.rows;
	int cols = srcImage.cols;
	int grow_direction[8][2] = { { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 } };
	vector<Point2i>cluster_ave;
	vector<int>result_temp;
	result_temp.resize(srcImage.cols, 0);
	result.resize(srcImage.rows, result_temp);

	int counter_result = 0, label_number = 0;;
	int result_pix_number = srcImage.rows*srcImage.cols;
	while (counter_result < result_pix_number)
	{
		queue<Point2i>seed_vec;
		seed_vec.push(seed);
		cluster_ave.push_back(seed);
		counter_result++;
		label_number++;
		result[seed.x][seed.y] = label_number;
		while (!seed_vec.empty())
		{
			Point2i curr_seed;
			curr_seed = seed_vec.front();
			seed_vec.pop();
			for (int i = 0; i < 8; i++)
			{
				Point2i neighbor_seed(curr_seed.x + grow_direction[i][0], curr_seed.y + grow_direction[i][1]);
				if (neighbor_seed.x<0 || neighbor_seed.x>rows - 1 || neighbor_seed.y < 0 || neighbor_seed.y>cols - 1)
				{
					continue;
				}
				else
				{
					int gray_diff_ = gray_diff(curr_seed, neighbor_seed);
					if (result[neighbor_seed.x][neighbor_seed.y] == 0 && gray_diff_ < threshold_&&gray_diff_ >= 0)
					{
						result[neighbor_seed.x][neighbor_seed.y] = label_number;
						counter_result++;
						seed_vec.push(neighbor_seed);
						cluster_ave.push_back(neighbor_seed);
					}
				}
			}
		}
		cluster_.push_back(cluster_ave);
		cluster_ave.clear();
		int row_ = counter1;
		for (; row_ < rows; row_++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (result[row_][j] == 0)
				{
					seed.x = row_;
					seed.y = j;
					counter1 = row_;
					goto here;
				}
			}
		}
	here:;
	}
}
void region_growing_sf::region_Auto(){
	RNG rng((unsigned)(time(NULL)));
	int rows = srcImage.rows;
	int cols = srcImage.cols;
	Point2i seed;
	seed.x = rng() % rows;
	seed.y = rng() % cols;
	region_growing(seed);//区域生长
	int cluster_number = cluster_.size(), ave_number;
	int grow_direction[8][2] = { { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 } };
	switch (method)
	{
	case 1: //默认
	{
		cluster_final = cluster_;
		break;
	}
	case 2://合并
	{
		vector<int>label_temp;
		for (int i = 0; i < cluster_number; i++)
		{
			ave_number = cluster_[i].size();
			if (ave_number < min_number)
			{
				for (int j = 0; j < ave_number; j++)
				{
					//开始统计邻域内的标签
					for (int k = 0; k < 8; k++)
					{
						Point2i neighbor_(cluster_[i][j].x + grow_direction[k][0], cluster_[i][j].y + grow_direction[k][1]);
						if (neighbor_.x<0 || neighbor_.x>rows - 1 || neighbor_.y < 0 || neighbor_.y>cols - 1)
						{
							continue;
						}
						else
						{
							label_temp.push_back(result[neighbor_.x][neighbor_.y]);
						}
					}
				}
				sort(label_temp.begin(), label_temp.end());
				auto last = std::unique(label_temp.begin(), label_temp.end());
				label_temp.erase(last, label_temp.end()); //删除
				int nebor_label_num = label_temp.size();
				vector<int>temp_label_max;
				for (int h = 0; h < nebor_label_num; h++)
				{
					temp_label_max.push_back(cluster_[label_temp[h] - 1].size());
				}
				int maxPosition = max_element(temp_label_max.begin(), temp_label_max.end()) - temp_label_max.begin();
				cluster_[label_temp[maxPosition] - 1].insert(cluster_[label_temp[maxPosition] - 1].end(), cluster_[i].begin(), cluster_[i].end());
				for (int p = 0; p < cluster_[i].size(); p++)
				{
					result[cluster_[i][p].x][cluster_[i][p].y] = label_temp[maxPosition];
				}
				cluster_[i].clear();
				label_temp.clear();
				temp_label_max.clear();
			}
		}
		for (int o = 0; o < cluster_.size(); o++)
		{
			if (cluster_[o].size() != 0)
			{
				cluster_final.push_back(cluster_[o]);
			}
		}
		break;
	}
	case 3://删除
	{
		int cluster_number = cluster_.size(), ave_number;
		//剔除
		for (int i = 0; i < cluster_.size(); i++)
		{
			int num = cluster_[i].size();
			if (num > min_number)
			{
				cluster_final.push_back(cluster_[i]);
			}
		}
		break;
	}
	default:

		break;
	}
	clusters_image.create(srcImage.size(), CV_8UC3);
	clusters_image.setTo(Scalar(0, 0, 0));
	for (int i = 0; i < cluster_final.size(); i++)
	{
		Vec3b rgb = Vec3b(rng() % 255, rng() % 255, rng() % 255);//随机赋予颜色
		for (int j = 0; j < cluster_final[i].size(); j++){
			clusters_image.at<Vec3b>(cluster_final[i][j].x, cluster_final[i][j].y) = rgb;
		}
	}
}
void region_growing_sf::region_peo(Point2i seed){
	Mat mask(srcImage.size(), CV_8UC1);
	mask.setTo(255);
	clusters_image.create(srcImage.size(), CV_8UC3);
	clusters_image.setTo(Scalar(0, 0, 0));
	int rows = srcImage.rows;
	int cols = srcImage.cols;
	queue<Point2i>seed_vec;
	seed_vec.push(seed);
	int grow_direction[8][2] = { { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, 1 }, { -1, 1 }, { -1, 0 } };
	RNG rng((unsigned)(time(NULL)));//根据系统时间刷新随机数
	Vec3b rgb = Vec3b(rng() % 255, rng() % 255, rng() % 255);
	clusters_image.at<Vec3b>(seed.x, seed.y) = rgb;
	mask.at<uchar>(seed.x, seed.y) = uchar(0);
	while (!seed_vec.empty())
	{
		Point2i curr_seed;
		curr_seed = seed_vec.front();
		seed_vec.pop();
		for (int i = 0; i < 8; i++)
		{
			Point2i neighbor_seed(curr_seed.x + grow_direction[i][0], curr_seed.y + grow_direction[i][1]);
			if (neighbor_seed.x<0 || neighbor_seed.x>rows - 1 || neighbor_seed.y < 0 || neighbor_seed.y>cols - 1)
			{
				continue;
			}
			else
			{
				int gray_diff_ = gray_diff(curr_seed, neighbor_seed);
				if (mask.at<uchar>(neighbor_seed.x, neighbor_seed.y) == 255 && gray_diff_ < threshold_&&gray_diff_ >= 0)
				{
					clusters_image.at<Vec3b>(neighbor_seed.x, neighbor_seed.y) = rgb;
					mask.at<uchar>(neighbor_seed.x, neighbor_seed.y) = 0;
					seed_vec.push(neighbor_seed);
				}
			}
		}
	}
	srcImage.copyTo(clusters_image, mask);
}
void region_growing_sf::output_image(Mat &output_image_){
	output_image_ = clusters_image;
}










