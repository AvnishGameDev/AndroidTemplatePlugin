// Copyright AvnishGameDev 2024.

#include "%PLUGIN_NAME%BPLibrary.h"
#include "%PLUGIN_NAME%.h"

#if PLATFORM_ANDROID

#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#define INIT_JAVA_METHOD(name, signature) \
if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true)) { \
name = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, #name, signature, false); \
check(name != NULL); \
} else { \
check(0); \
}

#define DECLARE_JAVA_METHOD(name) \
static jmethodID name = NULL;

DECLARE_JAVA_METHOD(AndroidThunkJava_AndroidAPI_ShowToast);	// Here goes the name of the method in the Java side

#endif

U%PLUGIN_NAME%BPLibrary::U%PLUGIN_NAME%BPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
#if PLATFORM_ANDROID
	// Same here, but we add the Java signature (the type of the parameters is between the parameters, and the return type is added at the end,
    // here the return type is V for "void")
    // More details here about Java signatures: http://www.rgagnon.com/javadetails/java-0286.html
	INIT_JAVA_METHOD(AndroidThunkJava_AndroidAPI_ShowToast, "(Ljava/lang/String;)V");
#endif
}

#if PLATFORM_ANDROID
#undef DECLARE_JAVA_METHOD
#undef INIT_JAVA_METHOD
#endif

void U%PLUGIN_NAME%BPLibrary::Android_ShowToast(const FString& Message)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		// First step, we convert the FString (UE) parameter to a JNI parameter that will hold a String
		jstring JavaString = Env->NewStringUTF(TCHAR_TO_UTF8(*Message));

		// Then we call the method, with the Java String parameter.
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, AndroidThunkJava_AndroidAPI_ShowToast, JavaString);
	}
#endif
}

