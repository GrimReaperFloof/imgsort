#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

void SortImage3b(cv::Mat &I);
void SortImage4b(cv::Mat &I);

int main(int argc, char* argv[])
{
	cv::Mat image = cv::imread(argv[1], cv::IMREAD_UNCHANGED);
	//cv::cvtColor(image, image, cv::COLOR_BGR2HSV);
	switch (image.channels())
	{
		case 3: SortImage3b(image);
			break;
		case 4: SortImage4b(image);
			break;
		default: std::cout << std::string("The input image has ") + std::to_string(image.channels()) + std::string(" channels, which is not supported." + std::string("\n"));
			return(1);
	}
	//cv::cvtColor(image, image, cv::COLOR_HSV2BGR);
	cv::imwrite(argv[2], image);

	return 0;
}

void SortImage3b(cv::Mat &I)
{
	for(int row = 0; row < I.rows; ++row)
	{
		cv::Vec3b *pixelsInRow = new cv::Vec3b[I.cols];
		for(int col = 0; col < I.cols; ++col)
		{
			pixelsInRow[col] = I.at<cv::Vec3b>(row, col);
		}

		for(int channel = I.channels()-1; channel >= 0; --channel)
		{
			std::stable_sort(pixelsInRow, pixelsInRow + I.cols, [&channel](cv::Vec3b a, cv::Vec3b b) {
				return a[channel] < b[channel];
			});
		}

		for(int col = 0; col < I.cols; ++col)
		{
			I.at<cv::Vec3b>(row, col) = pixelsInRow[col];
		}
		delete[] pixelsInRow;
	}
}

void SortImage4b(cv::Mat &I)
{
	for(int row = 0; row < I.rows; ++row)
	{
		cv::Vec4b *pixelsInRow = new cv::Vec4b[I.cols];
		for(int col = 0; col < I.cols; ++col)
		{
			pixelsInRow[col] = I.at<cv::Vec4b>(row, col);
		}

		for(int channel = I.channels()-1; channel >= 0; --channel)
		{
			std::stable_sort(pixelsInRow, pixelsInRow + I.cols, [&channel](cv::Vec4b a, cv::Vec4b b) {
				return a[channel] < b[channel];
			});
		}

		for(int col = 0; col < I.cols; ++col)
		{
			I.at<cv::Vec4b>(row, col) = pixelsInRow[col];
		}
		delete[] pixelsInRow;
	}
}
