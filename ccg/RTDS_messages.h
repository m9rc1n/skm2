#ifndef _RTDS_MESSAGES_H_
#define _RTDS_MESSAGES_H_

#include "RTDS_CommonTypes.h"
#include "Protocol_BSP.h"

#ifdef __cplusplus
extern "C" {
#endif


/* DATA TYPES FOR MESSAGES */

/* MACRO FOR DECLARATIONS FOR MESSAGE SEND/RECEIVE */

#ifndef RTDS_MSG_DATA_DECL
#define RTDS_MSG_DATA_DECL unsigned char * RTDS_msgData;
#endif  /* RTDS_MSG_DATA_DECL defined */


#ifdef __cplusplus
}
#endif

#endif /* defined(_RTDS_MESSAGES_H_) */

