/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class nitf_Writer */

#ifndef _Included_nitf_Writer
#define _Included_nitf_Writer
#ifdef __cplusplus
extern "C" {
#endif
#undef nitf_Writer_INVALID_ADDRESS
#define nitf_Writer_INVALID_ADDRESS 0L
/*
 * Class:     nitf_Writer
 * Method:    construct
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nitf_Writer_construct
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Writer
 * Method:    destructMemory
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nitf_Writer_destructMemory
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Writer
 * Method:    getImageWriters
 * Signature: ()[Lnitf/ImageWriter;
 */
JNIEXPORT jobjectArray JNICALL Java_nitf_Writer_getImageWriters
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Writer
 * Method:    getNumImageWriters
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_nitf_Writer_getNumImageWriters
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Writer
 * Method:    getTextWriters
 * Signature: ()[Lnitf/SegmentWriter;
 */
JNIEXPORT jobjectArray JNICALL Java_nitf_Writer_getTextWriters
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Writer
 * Method:    getNumTextWriters
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_nitf_Writer_getNumTextWriters
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Writer
 * Method:    getOutputHandle
 * Signature: ()Lnitf/IOHandle;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getOutputHandle
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Writer
 * Method:    getRecord
 * Signature: ()Lnitf/Record;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getRecord
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Writer
 * Method:    prepare
 * Signature: (Lnitf/Record;Lnitf/IOHandle;)Z
 */
JNIEXPORT jboolean JNICALL Java_nitf_Writer_prepare
  (JNIEnv *, jobject, jobject, jobject);

/*
 * Class:     nitf_Writer
 * Method:    getNewImageWriter
 * Signature: (I)Lnitf/ImageWriter;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getNewImageWriter
  (JNIEnv *, jobject, jint);

/*
 * Class:     nitf_Writer
 * Method:    getNewTextWriter
 * Signature: (I)Lnitf/SegmentWriter;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getNewTextWriter
  (JNIEnv *, jobject, jint);

/*
 * Class:     nitf_Writer
 * Method:    getNewGraphicWriter
 * Signature: (I)Lnitf/SegmentWriter;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getNewGraphicWriter
  (JNIEnv *, jobject, jint);

/*
 * Class:     nitf_Writer
 * Method:    getNewDEWriter
 * Signature: (I)Lnitf/SegmentWriter;
 */
JNIEXPORT jobject JNICALL Java_nitf_Writer_getNewDEWriter
  (JNIEnv *, jobject, jint);

/*
 * Class:     nitf_Writer
 * Method:    write
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_nitf_Writer_write
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
