/* Project: c:\users\marcin\documents\github\skm2 - copy\protocol_bsp.rdp */
/* Diagram: C:\Users\Marcin\Documents\GitHub\skm2 - Copy\Protocol_BSP.rdd */

#include "RTDS_MACRO.h"
#ifdef __cplusplus
extern "C" {
#endif

/* DEFINES FOR STATES */
#define RTDS_state_FoundRoutes 1
#define RTDS_state_OneRoute 2
#define RTDS_state_OnePath 3
#define RTDS_state_NoRoute 4
#define RTDS_state_TopologyProbed 5
#define RTDS_state_NoPath 6
#define RTDS_state_TopologyNotProbed 7
#define RTDS_state_MultipleRoutes 8
#define RTDS_state_ExternalCommunication 9
#define RTDS_state_RTDS_Idle 10
#define RTDS_state_MultiplePaths 11
#define RTDS_state_NoExternalCommunication 12

/* DEFINES FOR SIGNALS AND TIMERS */
#define RTDS_message_sMultipleRoutes 1
#define RTDS_message_sNotLastOnRoute 2
#define RTDS_message_sFirmwarePart 3
#define RTDS_message_sTopologyProbing 4
#define RTDS_message_sNoEchoDown 5
#define RTDS_message_sEcho 6
#define RTDS_message_sNoExternalCommunication 7
#define RTDS_message_sAliasDefinition 8
#define RTDS_message_sRouteAdded 9
#define RTDS_message_sNoRoute 10
#define RTDS_message_sPathBlocked 11
#define RTDS_message_sLastOnRoute 12
#define RTDS_message_sEmergencyTrigger 13
#define RTDS_message_sUpdateFirmware 14
#define RTDS_message_sData 15
#define RTDS_message_sAddRoute 16
#define RTDS_message_sNoEchoUp 17
#define RTDS_message_sTopologyNotProbed 18
#define RTDS_message_sMissingFirmwarePart 19
#define RTDS_message_sNewAliases 20
#define RTDS_message_sEchoDetected 21
#define RTDS_message_sRemoveRoute 22
#define RTDS_message_sSendWithEcho 23
#define RTDS_message_sExternalCommunication 24
#define RTDS_message_t 25
#define RTDS_message_sDown 26
#define RTDS_message_sConfirmation 27
#define RTDS_message_sRouteRemoved 28
#define RTDS_message_sRouteUpdated 29
#define RTDS_message_sExternalCommunicationError 30
#define RTDS_message_sNoNewAliases 31

/* DEFINES FOR SEMAPHORES */

/* DEFINES FOR PROCESSES */
#define RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP 1
#define RTDS_process_pMechanizmBadaniaTopologii 2
#define RTDS_process_pDrogiKomunikacjiWP 3
#define RTDS_process_RTDS_Env 4
#define RTDS_process_pWezelBrzegowy 5

/* PROCESS PROTOTYPES */
RTDS_TASK_ENTRY_POINT_PROTO(pPojedynczaDrogaDowolnegoWezlaWP);
RTDS_TASK_ENTRY_POINT_PROTO(pMechanizmBadaniaTopologii);
RTDS_TASK_ENTRY_POINT_PROTO(pDrogiKomunikacjiWP);
RTDS_TASK_ENTRY_POINT_PROTO(RTDS_Env);
RTDS_TASK_ENTRY_POINT_PROTO(pWezelBrzegowy);

#ifdef __cplusplus
}
#endif

