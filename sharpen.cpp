Mat sharpen(const Mat &img, Mat &result)//锐化算子
{
	result.create(img.rows, img.cols, img.type());
	int nl = img.rows;
	int nc = img.cols * img.channels();
	for (int j = 1; j < nl - 1; j++)
	{
		const uchar* previous = img.ptr<const uchar>(j - 1);//上一行
		const uchar* current = img.ptr<const uchar>(j);//当前行
		const uchar* next = img.ptr<const uchar>(j + 1);//下一行
		uchar* output = result.ptr<uchar>(j);//输出行
		for (int i = 1; i < nc - 1; i++)
		{
			 output[i]= saturate_cast<uchar>(5 * current[i] - current[i-1]
				- current[i- 1] - previous[i] - next[i]);
		}
	}
	//将未处理的像素设置为0
	result.row(0).setTo(Scalar(0));
	result.row(result.rows - 1).setTo(Scalar(0));
	result.col(0).setTo(Scalar(0));
	result.col(result.cols - 1).setTo(Scalar(0));
	return result;


	//Method 2  cv::filter2D
	//构造滤波核
	//
	//    0  -1  0
	//    -1  5  -1 
	//     0  -1  0
	//
	Mat kernel(3, 3, CV_32F, Scalar(0));
	kernel.at<float>(1, 1) = 5.0;
	kernel.at<float>(0, 1) = -1.0;
	kernel.at<float>(1, 0) = -1.0;
	kernel.at<float>(1, 2) = -1.0;
	kernel.at<float>(2, 1) = -1.0;

	cout << kernel << endl;
	filter2D(img, result, -1, kernel);
	return result;
}