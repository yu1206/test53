
#include "MSRCR.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 
#include <io.h>
#include <Windows.h>
#include "opencv\cv.h"
#include "opencv\highgui.h"
#include <direct.h>
using namespace cv;
using namespace std;

extern int readDir(char *dirName, vector<string> &filesName);
int test53(int argc, char *argv[])
{



	srand((unsigned)time(NULL));

	string imgpath1 = "E:\\车牌分类6\\0src-6train\\src\\6-8模糊";
	string savepath = "E:\\车牌分类6\\0src-6train\\src-roi\\6-8模糊";
	mkdir(savepath.c_str());
	vector<string> v1_img_;
	readDir((char*)imgpath1.c_str(), v1_img_);

	for (int i = 0; i < v1_img_.size(); i++)
	{
		string imagename = v1_img_[i];

		

		int npos = imagename.find_last_of('\\');
		int npos2 = imagename.find_last_of('.');

		string name1 = imagename.substr(npos + 1, npos2 - npos - 1);
		Mat img = imread(imagename.c_str());

		cout << imagename.c_str() << endl;

		if (img.data == NULL)
		{
			printf("img.data = NULL！\n");
			system("pause");
			continue;
		}
		int width = img.cols; int height = img.rows;

		Mat roi=img(Rect(0,height/2,width,height/2));

		char file[1024];
		sprintf(file, "%s\\%s.jpg", savepath.c_str(), name1.c_str());
		imwrite(file, roi);


		int jjjj = 0;
	}
	return 0;
}









