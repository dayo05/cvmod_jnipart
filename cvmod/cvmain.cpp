#include "cvmain.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

#include <opencv2/core/ocl.hpp>

using namespace cv;

static Mat image;
static VideoCapture video;

#define RET_NULLPTR return (long)nullptr;
#define RET_IMAGE return (long)image.data;
#define VALIDATE_EMPTY if(image.empty()) RET_NULLPTR
#define NEXT_FRAME video >> image;
#define CONVERT_TO_RGBA if(image.channels() != 4) cvtColor(image, image, COLOR_BGR2RGBA); else cvtColor(image, image, COLOR_BGRA2RGBA);

JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_loadImage(JNIVARS, jstring jname)
{
	auto name = env->GetStringUTFChars(jname, nullptr);
	image = imread(name, IMREAD_UNCHANGED);
	env->ReleaseStringUTFChars(jname, name);

	VALIDATE_EMPTY
	CONVERT_TO_RGBA
	
	RET_IMAGE
}

JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_loadVideo(JNIVARS, jstring jname)
{
	auto name = env->GetStringUTFChars(jname, nullptr);
	video = VideoCapture(name);
	if(!video.isOpened())
	{
		printf("Video is not opened");
		RET_NULLPTR
	}
	NEXT_FRAME
	env->ReleaseStringUTFChars(jname, name);
	VALIDATE_EMPTY
	CONVERT_TO_RGBA

	RET_IMAGE
}

JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_nextFrame(JNIVARS)
{
	NEXT_FRAME
	VALIDATE_EMPTY
	CONVERT_TO_RGBA

	RET_IMAGE
}

JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageWidth(JNIVARS)
{
	return image.cols;
}

JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageHeight(JNIVARS)
{
	return image.rows;
}

JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageChannels(JNIVARS)
{
	return image.channels();
}

JNIEXPORT jboolean Java_me_ddayo_cvmod_client_gui_CvUtil_isVideoFinished(JNIVARS)
{
	return image.empty();
}

JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_setFrame(JNIVARS, jlong pos)
{
	video.set(CAP_PROP_POS_FRAMES, pos);
	NEXT_FRAME
	VALIDATE_EMPTY
	CONVERT_TO_RGBA
	RET_IMAGE
}

JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_setMillisecond(JNIVARS, jlong pos)
{
	video.set(CAP_PROP_POS_MSEC, pos);
	//NEXT_FRAME
	//Mat i;
	//video.read(i);
	UMat row;
	video >> row;
	//i.copyTo(row);
	//VALIDATE_EMPTY
	if (row.empty()) RET_NULLPTR
	//CONVERT_TO_RGBA
	UMat k;
	if (row.channels() == 3)
		cvtColor(row, k, COLOR_BGR2RGBA);
	else cvtColor(row, k, COLOR_BGRA2RGBA);
	
	k.copyTo(image);
	RET_IMAGE
}

JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_getMatrix(JNIVARS)
{
	RET_IMAGE
}