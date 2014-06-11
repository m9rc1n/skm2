#include "Protocol_BSP.h"
#include "RTDS_messages.h"
#include "RTDS_gen.h"
#include <string.h>
#include <stdio.h>
#ifdef softOSE
/* ctype is broken with OSE/SoftKernel => define our own macros */
#define isxdigit(C) (( (C) >= '0' && (C) <= '9') || ( (C) >= 'A' && (C) <= 'F' ) || ( (C) >= 'a' && (C) <= 'f' ))
#define isalnum(C)  (( (C) >= '0' && (C) <= '9') || ( (C) >= 'A' && (C) <= 'Z' ) || ( (C) >= 'a' && (C) <= 'z' ))
#define isspace(C)  ( (C) == ' ' || (C) == '\t' || (C) == '\n' || (C) == '\r')
#else
#include <ctype.h>
#endif

#include "RTDS_MACRO.h"

#ifndef RTDS_PARAM_CODEC_CHUNK_SIZE
#define RTDS_PARAM_CODEC_CHUNK_SIZE 1024
#endif

#define RTDS_MEM_RESET(PTR, SIZE) { unsigned char * p = (unsigned char*)(PTR); unsigned i = 0; while ( i < SIZE) p[i++] = 0; }
/*
 * FUNCTION RTDS_extendNCat:
 * -------------------------
 * Adds a given string to the buffer containing the text for a message data, extending it if needed
 * Parameters:
 * - buffer: a pointer on the buffer containing the data
 * - allocatedChunks: a pointer on the number of already allocated chunks in buffer
 * - string2Add: the string to add to the buffer
 */

static void RTDS_extendNCat(char ** buffer, long * allocatedChunks, char * string2Add)
  {
  int length;
  char * oldBuffer = *buffer;
  int i;
  
  /* If buffer is null, no memory left => over */
  if ( *buffer == NULL ) return;
  /* If buffer is not big enough */
  length = strlen(*buffer) + strlen(string2Add);
  if ( *allocatedChunks * RTDS_PARAM_CODEC_CHUNK_SIZE < length )
    {
    /* Reallocate it */
    *allocatedChunks = 1 + length / RTDS_PARAM_CODEC_CHUNK_SIZE;
    *buffer = (char*)RTDS_MALLOC(RTDS_PARAM_CODEC_CHUNK_SIZE * (*allocatedChunks) + 1);
    if ( *buffer == NULL )
      {
      RTDS_FREE(oldBuffer);
      return;
      }
    for ( i = 0; oldBuffer[i] != '\0'; i++ ) (*buffer)[i] = oldBuffer[i];
    (*buffer)[i] = '\0';
    RTDS_FREE(oldBuffer);
    }
  /* Add string */
  strcat(*buffer, string2Add);
  }

/* FUNCTION PROTOTYPES */

/*
 * FUNCTION RTDS_messageDataToString:
 * ----------------------------------
 */

void RTDS_messageDataToString(char ** buffer, long messageNumber, long dataLength, void * dataPointer, int level)
  {
  long chunks = 1, i;               /* Number of allocated chunks */
  long *allocatedChunks = &chunks;  /* Pointer on it to pass to fucntions that may change it */
  char RTDS_tmpString[64];

  /* Allocate first chunk */
  *buffer = (char*)RTDS_MALLOC(RTDS_PARAM_CODEC_CHUNK_SIZE + 1);
  if ( *buffer == NULL ) return;
  **buffer = '\0';
  /* Convert data to string according to message number */
  switch(messageNumber)
    {
    default:
      for ( i = 0; i < dataLength; i ++ )
        {
        if ( i == 0 )
          sprintf(RTDS_tmpString, "%02X", ((unsigned char*)dataPointer)[i]);
        else
          sprintf(RTDS_tmpString, " %02X", ((unsigned char*)dataPointer)[i]);
        RTDS_extendNCat(buffer, allocatedChunks, RTDS_tmpString);
        }
      break;
    }
  }

/*
 * FUNCTION RTDS_stringToMessageData:
 * ----------------------------------
 */

char * RTDS_stringToMessageData(long messageNumber, long * dataLength, void ** dataPointer, char * dataString)
  {
  long i, j;

  /* Convert data from string according to message number */
  switch(messageNumber)
    {
    default:
      /* Compute number of bytes in data */
      i = 0; *dataLength = 0;
      while ( isxdigit((int)(dataString[i])) || isspace((int)(dataString[i])) )
        {
        while ( isspace((int)(dataString[i])) ) i++;
        if ( isxdigit((int)(dataString[i])) )
          {
          i++; *dataLength += 1;
          if ( isxdigit((int)(dataString[i])) ) i++;
          }
        }
      /* Allocate space */
      *dataPointer = (void*)RTDS_MALLOC(*dataLength);
      if ( *dataPointer == NULL ) return dataString;
      /* Get actual bytes */
      i = 0;
      for ( j = 0; j < *dataLength; j++ )
        {
        char byte[3];
        while ( isspace((int)(dataString[i])) ) i++;
        byte[0] = dataString[i];
        i++;
        if ( isxdigit((int)(dataString[i])) )
          {
          byte[1] = dataString[i];
          byte[2] = '\0';
          i++;
          }
        else
          {
          byte[1] = '\0';
          }
        ((unsigned char *)*dataPointer)[j] = strtol(byte, NULL, 16);
        }
      return &(dataString[i]);
      break;
    }
  return dataString;
  }

