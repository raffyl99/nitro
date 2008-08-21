/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class nitf_FieldWarning */

#ifndef _Included_nitf_FieldWarning
#define _Included_nitf_FieldWarning
#ifdef __cplusplus
extern "C" {
#endif
#undef nitf_FieldWarning_INVALID_ADDRESS
#define nitf_FieldWarning_INVALID_ADDRESS 0L
/*
 * Class:     nitf_FieldWarning
 * Method:    destructMemory
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nitf_FieldWarning_destructMemory
  (JNIEnv *, jobject);

/*
 * Class:     nitf_FieldWarning
 * Method:    getFieldName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_nitf_FieldWarning_getFieldName
  (JNIEnv *, jobject);

/*
 * Class:     nitf_FieldWarning
 * Method:    getField
 * Signature: ()Lnitf/Field;
 */
JNIEXPORT jobject JNICALL Java_nitf_FieldWarning_getField
  (JNIEnv *, jobject);

/*
 * Class:     nitf_FieldWarning
 * Method:    getWarning
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_nitf_FieldWarning_getWarning
  (JNIEnv *, jobject);

/*
 * Class:     nitf_FieldWarning
 * Method:    getFileOffset
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_nitf_FieldWarning_getFileOffset
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
