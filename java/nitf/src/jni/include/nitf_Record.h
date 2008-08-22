/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class nitf_Record */

#ifndef _Included_nitf_Record
#define _Included_nitf_Record
#ifdef __cplusplus
extern "C" {
#endif
#undef nitf_Record_INVALID_ADDRESS
#define nitf_Record_INVALID_ADDRESS 0L
/*
 * Class:     nitf_Record
 * Method:    construct
 * Signature: (Lnitf/Version;)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_construct
  (JNIEnv *, jobject, jobject);

/*
 * Class:     nitf_Record
 * Method:    destructMemory
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_nitf_Record_destructMemory
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    makeClone
 * Signature: ()Lnitf/CloneableObject;
 */
JNIEXPORT jobject JNICALL Java_nitf_Record_makeClone
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    getHeader
 * Signature: ()Lnitf/FileHeader;
 */
JNIEXPORT jobject JNICALL Java_nitf_Record_getHeader
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    getImages
 * Signature: ()[Lnitf/ImageSegment;
 */
JNIEXPORT jobjectArray JNICALL Java_nitf_Record_getImages
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    getGraphics
 * Signature: ()[Lnitf/GraphicSegment;
 */
JNIEXPORT jobjectArray JNICALL Java_nitf_Record_getGraphics
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    getLabels
 * Signature: ()[Lnitf/LabelSegment;
 */
JNIEXPORT jobjectArray JNICALL Java_nitf_Record_getLabels
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    getTexts
 * Signature: ()[Lnitf/TextSegment;
 */
JNIEXPORT jobjectArray JNICALL Java_nitf_Record_getTexts
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    getDataExtensions
 * Signature: ()[Lnitf/DESegment;
 */
JNIEXPORT jobjectArray JNICALL Java_nitf_Record_getDataExtensions
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    getReservedExtensions
 * Signature: ()[Lnitf/RESegment;
 */
JNIEXPORT jobjectArray JNICALL Java_nitf_Record_getReservedExtensions
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    newImageSegment
 * Signature: ()Lnitf/ImageSegment;
 */
JNIEXPORT jobject JNICALL Java_nitf_Record_newImageSegment
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    newGraphicSegment
 * Signature: ()Lnitf/GraphicSegment;
 */
JNIEXPORT jobject JNICALL Java_nitf_Record_newGraphicSegment
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    newTextSegment
 * Signature: ()Lnitf/TextSegment;
 */
JNIEXPORT jobject JNICALL Java_nitf_Record_newTextSegment
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    newDESegment
 * Signature: ()Lnitf/DESegment;
 */
JNIEXPORT jobject JNICALL Java_nitf_Record_newDESegment
  (JNIEnv *, jobject);

/*
 * Class:     nitf_Record
 * Method:    removeImageSegment
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_removeImageSegment
  (JNIEnv *, jobject, jint);

/*
 * Class:     nitf_Record
 * Method:    removeGraphicSegment
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_removeGraphicSegment
  (JNIEnv *, jobject, jint);

/*
 * Class:     nitf_Record
 * Method:    removeLabelSegment
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_removeLabelSegment
  (JNIEnv *, jobject, jint);

/*
 * Class:     nitf_Record
 * Method:    removeTextSegment
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_removeTextSegment
  (JNIEnv *, jobject, jint);

/*
 * Class:     nitf_Record
 * Method:    removeDataExtensionSegment
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_removeDataExtensionSegment
  (JNIEnv *, jobject, jint);

/*
 * Class:     nitf_Record
 * Method:    removeReservedExtensionSegment
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_removeReservedExtensionSegment
  (JNIEnv *, jobject, jint);

/*
 * Class:     nitf_Record
 * Method:    moveImageSegment
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_moveImageSegment
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     nitf_Record
 * Method:    moveGraphicSegment
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_moveGraphicSegment
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     nitf_Record
 * Method:    moveTextSegment
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_moveTextSegment
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     nitf_Record
 * Method:    moveLabelSegment
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_moveLabelSegment
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     nitf_Record
 * Method:    moveDataExtensionSegment
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_moveDataExtensionSegment
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     nitf_Record
 * Method:    moveReservedExtensionSegment
 * Signature: (II)V
 */
JNIEXPORT void JNICALL Java_nitf_Record_moveReservedExtensionSegment
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     nitf_Record
 * Method:    getVersion
 * Signature: ()Lnitf/Version;
 */
JNIEXPORT jobject JNICALL Java_nitf_Record_getVersion
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
