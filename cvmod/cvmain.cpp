#include "cvmain.h"

using namespace cv;

static Mat image;
static void* a;
static std::vector<uchar> encodedImage = std::vector<uchar>();
static std::vector<int> param = std::vector<int>(2);

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

JNIEXPORT jobject Java_me_ddayo_cvmod_client_gui_CvUtil_getImageByteBuffer(JNIEnv* env, jobject obj)
{
	int imsize = image.cols * image.rows * image.channels();
	encodedImage.resize(imsize);
	imencode(".bmp", image, encodedImage);
	env->NewDirectByteBuffer(&encodedImage[0], imsize);
}

JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_getBmpImage(JNIEnv* env, jobject obj)
{
	return (long)image.data;
}