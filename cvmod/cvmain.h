#ifndef CV_MAIN_HEADER
#define CV_MAIN_HEADER

#pragma warning(disable:4996)

#include <jni.h>

#define JNIVARS		JNIEnv* env, jobject obj
#define JNI_POINTER jlong

extern "C" {
	JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_loadImage(JNIVARS, jstring);
	JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_loadVideo(JNIVARS, jstring jname);
	JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_nextFrame(JNIVARS);
	JNIEXPORT jint        Java_me_ddayo_cvmod_client_gui_CvUtil_getImageWidth(JNIVARS);
	JNIEXPORT jint        Java_me_ddayo_cvmod_client_gui_CvUtil_getImageHeight(JNIVARS);
	JNIEXPORT jint        Java_me_ddayo_cvmod_client_gui_CvUtil_getImageChannels(JNIVARS);
	JNIEXPORT jboolean    Java_me_ddayo_cvmod_client_gui_CvUtil_isVideoFinished(JNIVARS);
	JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_setFrame(JNIVARS, jlong pos);
	JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_setMillisecond(JNIVARS, jlong pos);
	JNIEXPORT JNI_POINTER Java_me_ddayo_cvmod_client_gui_CvUtil_getMatrix(JNIVARS);
}
#endif