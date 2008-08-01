/* =========================================================================
 * This file is part of NITRO
 * =========================================================================
 * 
 * (C) Copyright 2004 - 2008, General Dynamics - Advanced Information Systems
 *
 * NITRO is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public 
 * License along with this program; if not, If not, 
 * see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __NITF_TRE_H__
#define __NITF_TRE_H__

#include "nitf/System.h"
#include "nitf/Field.h"
#include "nitf/IntStack.h"
#include "nitf/Pair.h"
#include "nitf/List.h"
#include "nitf/TREDescription.h"

/*!
 * Pass this into the id of nitf_TRE_construct to bypass the plug-in registry,
 * yet still create the TRE type expected. 
 */
#define NITF_TRE_RAW "raw_data"

#define NITF_MAX_TAG 32
#define NITF_ETAG_SZ 6
#define NITF_EL_SZ 5


/** This is used in the constructor, to specify
  * that you want to use the default length for
  * the TRE
  */
#define NITF_TRE_DEFAULT_LENGTH 0

/** If the length field of a TREDescription contains this value,
  * it means that the field should be computed based on a previous field value.
  * Any field that uses this for its length MUST be preceded by a NITF_COMP_LEN
  * field.
  */
#define NITF_TRE_CONDITIONAL_LENGTH -100

/** This is used in the TRE Descriptions, for the length field
  * if we want the rest of the data to fill the current field
  */
#define NITF_TRE_GOBBLE -1


NITF_CXX_GUARD



/* Control values that are put in the TREDescription data_type field */
enum
{
    NITF_LOOP = NITF_BINARY + 1,    /*!< data_type control loop */
    NITF_ENDLOOP,                   /*!< data_type control end loop */
    NITF_IF,                        /*!< data_type control if */
    NITF_ENDIF,                     /*!< data_type control endif */
    NITF_COMP_LEN,                  /*!< data_type computes the length of the next field */
    NITF_END                        /*!< data_type end marker */
};

/* This can be used if the user wants to loop a constant number of times */
/* Set the TREDescription label to NITF_CONST_N, and the number in the tag */
/* Example: {NITF_LOOP, 0, NITF_CONST_N, "4096"} */
#define NITF_CONST_N    "CONSTANT"          /*!< TREDescription label value */
#define NITF_FUNCTION   "FUNCTION"

struct _nitf_Record;

struct _nitf_TREHandler;
/*!
 * The TRE structure, which contains the description of the TRE, as well as
 * the Field data.
 */
typedef struct _nitf_TRE
{
	struct _nitf_TREHandler* handler;  /*! The plug-in handler */
	NITF_DATA* priv;                   /*! Private data the plug-in knows about */
    char tag[NITF_MAX_TAG + 1];        /* the TRE tag */
} nitf_TRE;


struct _nitf_TREEnumerator;

/*!
 * Increments the TREEnumerator
 */
typedef NITF_BOOL (*NITF_TRE_ITERATOR_INCREMENT)(struct _nitf_TREEnumerator**,
                                                 nitf_Error*);

/*!
 * Gets a pointer to the nitf_Pair at the current location of the TRE Enumerator
 */
typedef nitf_Pair* (*NITF_TRE_ITERATOR_GET)(struct _nitf_TREEnumerator*,
                                            nitf_Error*);


typedef struct _nitf_TREEnumerator
{
	NITF_TRE_ITERATOR_INCREMENT next;
	NITF_TRE_ITERATOR_GET get;
	NITF_DATA* data;
} nitf_TREEnumerator;

#define NITF_TRE_END NULL

/*============================================================================*/
/*===========================BEGIN TRE HANDLER API============================*/
/*============================================================================*/

/*!
 * The plug-in is allowed to do some initialization to prepare the TRE
 * \param tre       The TRE to initialize
 * \param id        An optional ID used to further specify a specific version, etc.
 * \param error     The error object
 * \return          NITF_FAILURE if an error occurred, otherwise NITF_SUCCESS
 */
typedef NITF_BOOL (*NITF_TRE_INIT) (nitf_TRE* tre,
                                    const char* id,
                                    nitf_Error * error);

/*!
 * Read data from the given IOHandle, parsing it however the plug-in desires.
 * \param io        The IOHandle we are reading from
 * \param length    The length of the TRE (i.e. # of bytes to read)
 * \param tre       The associated TRE
 * \param record    The associated Record object
 * \param error     The error object
 * \return          NITF_FAILURE if an error occurred, otherwise NITF_SUCCESS
 */
typedef NITF_BOOL (*NITF_TRE_READER)(nitf_IOHandle io,
                                     nitf_Uint32 length,
                                     nitf_TRE *tre,
                                     struct _nitf_Record *record,
                                     nitf_Error *error);


/*!
 * Returns a nitf_List* of Fields that match the input XPath-like pattern.
 * \param tre       The associated TRE
 * \param pattern   The XPath pattern used to search for fields
 * \param error     The error object
 * \return          nitf_List* of fields, or NULL if an error occurred
 */
typedef nitf_List* (*NITF_TRE_FIND)(nitf_TRE * tre,
                                    const char *pattern,
                                    nitf_Error* error);


/*!
 * Sets a field in the given TRE. It is up to the plug-in to 
 * \param tre           The associated TRE
 * \param tag           The name of the field
 * \param data          The data (void*) to set the field to
 * \param dataLength    The size of the data
 * \param error         The error object
 * \return              NITF_FAILURE if an error occurred, otherwise NITF_SUCCESS
 */
typedef NITF_BOOL (*NITF_TRE_FIELD_SET)(nitf_TRE * tre,
                                        const char *tag,
                                        NITF_DATA * data,
                                        size_t dataLength,
                                        nitf_Error * error);

/*!
 * Returns the one Field with the given tag ID
 * \param tre       The associated TRE
 * \param tag       The tag, or name of the field to return
 * \return          the nitf_Field*, or NULL if it doesn't exist (or error)
 */
typedef nitf_Field* (*NITF_TRE_FIELD_GET)(nitf_TRE * tre,
                                          const char *tag);

/*!
 * Sets a field in the given TRE. It is up to the plug-in to 
 * \param io        The IOHandle to write to
 * \param tre       The associated TRE to write
 * \param record    The associated Record object
 * \param error The error object
 * \return          NITF_FAILURE if an error occurred, otherwise NITF_SUCCESS
 */
typedef NITF_BOOL (*NITF_TRE_WRITER)(nitf_IOHandle io,
                                     nitf_TRE* tre,
                                     struct _nitf_Record* record,
                                     nitf_Error *error);

/*!
 * Returns the current size of the TRE. 
 * \param tre       The associated TRE
 * \param error     The error object
 * \return          The size of the TRE, or -1 if an error occurred
 */
typedef int (*NITF_TRE_SIZE)(nitf_TRE *tre, nitf_Error *error);

/*!
 * Sets a field in the given TRE. It is up to the plug-in to 
 * \param source    The source TRE to clone
 * \param dest      The destination TRE, where the source will be cloned to
 * \param error     The error object
 * \return          NITF_FAILURE if an error occurred, otherwise NITF_SUCCESS
 */
typedef NITF_BOOL (*NITF_TRE_CLONE)(nitf_TRE *source,
                                    nitf_TRE *dest,
                                    nitf_Error *error);

/*!
 * Destroy any internal data associated with the given TRE. You should not
 * destroy the TRE. It will be deleted by the library. 
 * \param tre       The associated TRE
 */
typedef void (*NITF_TRE_DESTRUCT)(nitf_TRE*);

/*!
 * Returns a nitf_TREEnumerator for the TRE 
 * \param tre       The associated TRE
 * \param error     The error object
 * \return          an enumerator, or NULL if an error occurred
 */
typedef nitf_TREEnumerator* (*NITF_TRE_ITERATOR)(nitf_TRE *tre,
                                                 nitf_Error *error);



/*!
 * \brief The TRE Handler Interface
 * 
 * This interface should be fulfilled by any plug-in that wants to handle a TRE.
 * View the documentation above for each of the methods below.
 * In addition to the methods, there is an optional data field (of type
 * NITF_DATA*) which allows the plug-in to store data associated with the
 * Handler.
 * 
 */
typedef struct _nitf_TREHandler
{
    /* The init method gets called when creating a TRE from scratch */
    NITF_TRE_INIT init;
    
    /* The read method gets called when reading a TRE from an IOHandle */
    NITF_TRE_READER read;
    
    /* setField is called by the setField proxy of the TRE API */
    NITF_TRE_FIELD_SET setField;
    
    /* getField is called by the getField proxy of the TRE API */
    NITF_TRE_FIELD_GET getField;
    
    /* find is called by the find proxy of the TRE API */
    NITF_TRE_FIND find;
    
    /* write gets called when writing the TRE to an output IOHandle */
    NITF_TRE_WRITER write;
    
    /* begin is called by the begin proxy of the TRE API */
    NITF_TRE_ITERATOR begin;
    
    /* getCurrentSize is called by the getCurrentSize proxy of the TRE API */
    NITF_TRE_SIZE getCurrentSize;
    
    /* clone is called when a TRE is cloned */
    NITF_TRE_CLONE clone;
    
    /*
     * destruct is called when a TRE is destroyed - NOT when the handler is.
     * destruct is an optional operation and doesn't need to be provided by
     * plug-in implementations
     */
    NITF_TRE_DESTRUCT destruct;
    
    /* optional data that contains handler-wide data for supporting TREs of
     * the type that the plug-in handles
     */
    NITF_DATA* data;
} nitf_TREHandler;

/*============================================================================*/
/*===========================END TRE HANDLER API==============================*/
/*============================================================================*/

/*!
 *  Construct a TRE Skeleton (for Reader).
 *  and the offset within the file
 *  \param tag The name of the TRE
 *  \param error The error to populate on failure
 *  \return The newly constructed TRE
 *
 */
NITFPROT(nitf_TRE *) nitf_TRE_createSkeleton(const char* tag,
        nitf_Error * error);

/*!
 *  Construct an actual TRE (for users of the library)
 *  \param tag Name of TRE
 *  \param desc a description structure, or if null, uses default for name
 *  \param error Error to populate if something bad happens
 *  \return A new TRE or NULL on failure
 */
NITFAPI(nitf_TRE *) nitf_TRE_construct(const char* tag,
                                       const char* id,
                                       nitf_Error * error);



/*!
 *  Clone this object.  This is a deep copy operation.
 *  This is a serious problem since this is the first thing
 *  people will want to do.  Possible solution: put desc inside
 *  of the TRE.  Alternate possibility: call TRE plugin
 *  handler explicitly
 *  \param source The source object
 *  \param error  An error to populate upon failure
 *  \return A new object that is identical to the old
 */
NITFAPI(nitf_TRE *) nitf_TRE_clone(nitf_TRE * tre, nitf_Error * error);


/*!
 *  Destroy the TRE.
 *  \param tre The tre to destroy
 */
NITFAPI(void) nitf_TRE_destruct(nitf_TRE ** tre);


/*!
 * Returns 1 if the given tag exists in the TRE
 * \param tre the TRE
 * \param tag the tag we want to check for existence
 * \return 1 on success, 0 on failure
 */
NITFAPI(NITF_BOOL) nitf_TRE_exists(nitf_TRE * tre, const char *tag);


/*!
 * Sets the field for the given tag in the tre
 * If the field was never set, a new field is created
 * If the field already existed, the old one is updated
 * \param tre the TRE
 * \param tag the tag we want to check for existence
 * \param data the data to store in the field
 * \param dataLength the length of the data
 * \param error The error to populate on failure
 * \return 1 on success, 0 on failure
 */
NITFAPI(NITF_BOOL) nitf_TRE_setField(nitf_TRE * tre,
                                     const char *tag,
                                     NITF_DATA * data,
                                     size_t dataLength,
                                     nitf_Error * error);
		   
/*!
 *  This function retrieves all fields that match the pattern.  Exactly
 *  how and what patterns are supported is up to the plug-in -- here
 *  we are simply an interface broker, making plug-in capabilities exposed
 *  to our users.  In TREUtils, our default behavior is to find any
 *  fields with an occurence of the string.  For XML TREs, we assume that
 *  the user will be building an XPath expression, and that a plug-in should
 *  support that capability.
 *
 *  \since 2.0
 *  \param tre The TRE
 *  \param A pattern to match
 *  \param error The error if one occurs
 *  \return A nitf_List of nitf_Pair*, or NULL if no matches
 *  \todo How to tell if its an error or failure to retrieve -- probably
 *  need another parameter
 *
 */
NITFAPI(nitf_List*) nitf_TRE_find(nitf_TRE* tre,
				  const char* pattern,
				  nitf_Error* error);


/*!
 * 
 *  Gets a field by its (exact) name.  The retrieval is here for basic
 *  symmetry and to prevent the application developer from playing with
 *  the model directly.  We really want them to have an opaque view of
 *  the TREs internals
 *  \todo What about the error?
 *
 *  \since 2.0
 *
 *  \param tre The TRE
 *  \param tag The tag name
 *  \return Return NULL if no such field exists in the TRE, otherwise, the value
 */
NITFAPI(nitf_Field*) nitf_TRE_getField(nitf_TRE* tre,
				       const char* tag);


NITFAPI(nitf_TREEnumerator*) nitf_TRE_begin(nitf_TRE* tre, nitf_Error* error);


NITFAPI(int) nitf_TRE_getCurrentSize(nitf_TRE* tre, nitf_Error* error);


NITF_CXX_ENDGUARD

#endif
