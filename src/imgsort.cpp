#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

template <uchar Channels>
void SortImage(cv::Mat &I)
{
	using VecType = cv::Vec<uchar, Channels>;

	VecType *pixelsInRow = new VecType[I.cols];
	for(int row = 0; row < I.rows; ++row)
	{
		for(int col = 0; col < I.cols; ++col)
		{
			pixelsInRow[col] = I.at<VecType>(row, col);
		}

		for(int channel = I.channels()-1; channel >= 0; --channel)
		{
			std::stable_sort(pixelsInRow, pixelsInRow + I.cols, [&channel](VecType a, VecType b) {
				return a[channel] < b[channel];
			});
		}

		for(int col = 0; col < I.cols; ++col)
		{
			I.at<VecType>(row, col) = pixelsInRow[col];
		}
	}
	delete[] pixelsInRow;
}

int main(int argc, char* argv[])
{
	cv::Mat image = cv::imread(argv[1], cv::IMREAD_UNCHANGED);
	//cv::cvtColor(image, image, cv::COLOR_BGR2HSV);
	switch (image.channels())
	{
		case 1: SortImage<1>(image);
			break;
		case 3: SortImage<3>(image);
			break;
		case 4: SortImage<4>(image);
			break;
		default: std::cout << std::string("The input image has ") + std::to_string(image.channels()) + std::string(" channels, which is not supported." + std::string("\n"));
			return(1);
	}
	//cv::cvtColor(image, image, cv::COLOR_HSV2BGR);
	cv::imwrite(argv[2], image);

	return 0;
}

