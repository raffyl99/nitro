/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class nitf_LabelSegment */

#ifndef _Included_nitf_LabelSegment
#define _Included_nitf_LabelSegment
#ifdef __cplusplus
extern "C" {
#endif
#undef nitf_LabelSegment_INVALID_ADDRESS
#define nitf_LabelSegment_INVALID_ADDRESS 0L
/*
 * Class:     nitf_LabelSegment
 * Method:    getSubheader
 * Signature: ()Lnitf/LabelSubheader;
 */
JNIEXPORT jobject JNICALL Java_nitf_LabelSegment_getSubheader
  (JNIEnv *, jobject);

/*
 * Class:     nitf_LabelSegment
 * Method:    getOffset
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_nitf_LabelSegment_getOffset
  (JNIEnv *, jobject);

/*
 * Class:     nitf_LabelSegment
 * Method:    getEnd
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_nitf_LabelSegment_getEnd
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
