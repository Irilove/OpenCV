void colorReduce(Mat &img, int div)
{
	//获取图像的行数、列数、通道数
	//int nl = img.rows;//行数
	//int nc = img.cols * img.channels();
	////遍历像素
	//for (int j = 0; j < nl; j++)
	//{
	//	//得到第j行的首地址
	//	uchar* data = img.ptr<uchar>(j);
	//	for (int i = 0; i < nc; i++)
	//	{
	//		data[i] = data[i] / div *div + div / 26;
	//		//像素处理完成
	//	}//行处理完成
	//}


	double duration = static_cast<double>(getTickCount());
	//使用迭代器
	Mat_<Vec3b>::iterator it = img.begin<Vec3b>();//得到初始位置的迭代器

	Mat_<Vec3b>::iterator itend = img.end<Vec3b>();//得到终止位置的迭代器

	//遍历所有像素
	for (; it != itend; it+=2)
	{
		//处理每个像素
		(*it)[0] = (*it)[0] / div *div + div / 2;
		(*it)[1] = (*it)[1] / div *div + div / 2;
		(*it)[2] = (*it)[2] / div *div + div / 2;
	}
	duration = static_cast<double>(getTickCount()) - duration;
	duration = duration / getTickFrequency();//运行时间 ms
	cout << duration << endl;
}