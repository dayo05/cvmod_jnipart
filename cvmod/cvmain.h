#ifndef CV_MAIN_HEADER
#define CV_MAIN_HEADER

#pragma warning(disable:4996)

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <jni.h>
#include <vector>

extern "C" {
	JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_loadImage(JNIEnv*, jobject, jstring);
	JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageWidth(JNIEnv*, jobject);
	JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageHeight(JNIEnv*, jobject);
	JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageChannels(JNIEnv*, jobject);
	JNIEXPORT jobject Java_me_ddayo_cvmod_client_gui_CvUtil_getImageByteBuffer(JNIEnv* env, jobject obj);
	JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_getBmpImage(JNIEnv*, jobject);
}
#endif