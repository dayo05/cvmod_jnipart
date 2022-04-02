#ifndef CV_MAIN_HEADER
#define CV_MAIN_HEADER

#pragma warning(disable:4996)

#include <jni.h>

extern "C" {
	JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_loadImage(JNIEnv*, jobject, jstring);
	JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_loadVideo(JNIEnv* env, jobject obj, jstring jname);
	JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_nextFrame(JNIEnv* env, jobject obj);
	JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageWidth(JNIEnv*, jobject);
	JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageHeight(JNIEnv*, jobject);
	JNIEXPORT jint Java_me_ddayo_cvmod_client_gui_CvUtil_getImageChannels(JNIEnv*, jobject);
	JNIEXPORT jboolean Java_me_ddayo_cvmod_client_gui_CvUtil_isVideoFinished(JNIEnv* env, jobject obj);
	JNIEXPORT jlong Java_me_ddayo_cvmod_client_gui_CvUtil_getMatrix(JNIEnv*, jobject);
}
#endif