#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>

#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <complex>
using namespace cv;
using namespace std;
class ParallelMandelbrot : public ParallelLoopBody
{
public:
	ParallelMandelbrot(Mat &img, const float x1, const float y1, const float scaleX, const float scaleY)
		: m_img(img), m_x1(x1), m_y1(y1), m_scaleX(scaleX), m_scaleY(scaleY)
	{
	}
	virtual void operator ()(const Range& range) const
	{
		for (int r = range.start; r < range.end; r++)
		{
			int i = r / m_img.cols;
			int j = r % m_img.cols;
			float x0 = j / m_scaleX + m_x1;
			float y0 = i / m_scaleY + m_y1;
			complex<float> z0(x0, y0);
			uchar value = (uchar)(z0);
			m_img.ptr<uchar>(i)[j] = value;
		}
	}
	ParallelMandelbrot& operator=(const ParallelMandelbrot &) {
		return *this;
	};
private:
	Mat &m_img;
	float m_x1;
	float m_y1;
	float m_scaleX;
	float m_scaleY;
};