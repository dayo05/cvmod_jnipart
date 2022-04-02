#include "cvmain.h"
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;

static Mat image;
static VideoCapture video;

JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_loadImage(JNIEnv* env, jobject obj, jstring jname)
{
	auto name = env->GetStringUTFChars(jname, nullptr);
	image = imread(name, IMREAD_UNCHANGED);
	if (image.channels() != 4)
		cvtColor(image, image, COLOR_BGR2RGBA);
	else cvtColor(image, image, COLOR_BGRA2RGBA);
	
	env->ReleaseStringUTFChars(jname, name);
	return (long)image.data;
}

JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_loadVideo(JNIEnv* env, jobject obj, jstring jname)
{
	auto name = env->GetStringUTFChars(jname, nullptr);
	video = VideoCapture(name);
	if(!video.isOpened())
	{
		printf("Video is not opened");
		return (long)nullptr;
	}
	video >> image;
	if (image.channels() != 4)
		cvtColor(image, image, COLOR_BGR2RGBA);
	else cvtColor(image, image, COLOR_BGRA2RGBA);
	env->ReleaseStringUTFChars(jname, name);
	return (long)image.data;
}

JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_nextFrame(JNIEnv* env, jobject obj)
{
	video >> image;
	if (image.channels() != 4)
		cvtColor(image, image, COLOR_BGR2RGBA);
	else cvtColor(image, image, COLOR_BGRA2RGBA);
	return (long)image.data;
}

JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageWidth(JNIEnv* env, jobject obj)
{
	return image.cols;
}

JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageHeight(JNIEnv* env, jobject obj)
{
	return image.rows;
}

JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageChannels(JNIEnv* env, jobject obj)
{
	return image.channels();
}

JNIEXPORT jboolean Java_me_ddayo_cvmod_client_gui_CvUtil_isVideoFinished(JNIEnv* env, jobject obj)
{
	return image.empty();
}

JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_getMatrix(JNIEnv* env, jobject obj)
{
	return (long)image.data;
}