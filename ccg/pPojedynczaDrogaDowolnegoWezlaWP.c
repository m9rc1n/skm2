/* ***************************************************************** */
/* $(RTDS_HOME)/share/ccg/windows/bricks/RTDS_Include.c begins       */
/* PragmaDev RTDS win32 integration                                  */

/* Include unistd when using a unix based system or cygwin */
#ifdef __CYGWIN__
#include <unistd.h>
#else
#include <stdlib.h>
#endif

#include "RTDS_MACRO.h"

#if defined( RTDS_FORMAT_TRACE )
#include "RTDS_FormatTrace.h"
#endif

/* $(RTDS_HOME)/share/ccg/windows/bricks/RTDS_Include.c ends         */
/* ***************************************************************** */

#include "pPojedynczaDrogaDowolnegoWezlaWP.h"
#include "RTDS_messages.h"
#include "RTDS_gen.h"

#define RTDS_PROCESS_NUMBER RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP
#define RTDS_PROCESS_NAME pPojedynczaDrogaDowolnegoWezlaWP

/*
** PROCESS pPojedynczaDrogaDowolnegoWezlaWP:
** -----------------------------------------
*/

RTDS_TASK_ENTRY_POINT(pPojedynczaDrogaDowolnegoWezlaWP)
  {
  short RTDS_transitionExecuted;
  int RTDS_savedSdlState = 0;

  int paths = 0;
  RTDS_MSG_DATA_DECL

  void * RTDS_myLocals[1];
  void ** RTDS_localsStack[1];


  #include "pPojedynczaDrogaDowolnegoWezlaWP_tempVars.h"

  /* ***************************************************************** */
  /* $(RTDS_HOME)/share/ccg/windows/bricks/RTDS_Process_begin.c begins */
  /* PragmaDev RTDS win32 integration                                  */

  int RTDS_sdlStatePrev = 0;
  RTDS_TimerState * RTDS_timer;
  RTDS_TimerState * RTDS_prevTimer;
  RTDS_SdlInstanceId * RTDS_senderId = NULL;

  RTDS_currentContext->readSaveQueue = NULL;
  RTDS_currentContext->writeSaveQueue = NULL;

  /* Synchronize processes at startup time */
  RTDS_START_SYNCHRO_WAIT;

  /* $(RTDS_HOME)/share/ccg/windows/bricks/RTDS_Process_begin.c ends */
  /* *************************************************************** */


  RTDS_myLocals[0] = (void*)&paths;
  RTDS_localsStack[0] = RTDS_myLocals;


  /* Initial transition */
  RTDS_SDL_STATE_SET(RTDS_state_NoPath);

  /* ****************************************************************** */
  /* $(RTDS_HOME)/share/ccg/windows/bricks/RTDS_Proc_loopStart.c begins */
  /* PragmaDev RTDS win32 integration                                   */

  /* Event loop */
  for ( ; ; )
    {

    /* $(RTDS_HOME)/share/ccg/windows/bricks/RTDS_Proc_loopStart.c ends */
    /* *************************************************************** */

    /* *************************************************************** */
    /* $(RTDS_HOME)/share/ccg/windows/bricks/RTDS_Proc_middle.c begins */
    /* PragmaDev RTDS win32 integration                                */

    /* Check saved messages */
    if ( RTDS_currentContext->readSaveQueue != NULL )
      {
      RTDS_currentContext->currentMessage = RTDS_currentContext->readSaveQueue;
      RTDS_currentContext->readSaveQueue = RTDS_currentContext->readSaveQueue->next;
      }
    /* If no saved messages left, get message from process's message queue */
    else
      {
      RTDS_currentContext->currentMessage = ( RTDS_MessageHeader * )RTDS_MALLOC( sizeof( RTDS_MessageHeader ) );
      RTDS_MSG_QUEUE_READ( RTDS_currentContext->currentMessage );
      RTDS_currentContext->currentMessage->next = NULL;
      }

    /* Discard cancelled timers */
    if ( RTDS_currentContext->currentMessage->timerUniqueId != 0 )
      {
      RTDS_prevTimer = NULL;
      for ( RTDS_timer = RTDS_currentContext->timerList ;RTDS_timer != NULL; RTDS_timer = RTDS_timer->next )
        {
        /* If timer found and cancelled */
        if ( RTDS_timer->timerUniqueId == RTDS_currentContext->currentMessage->timerUniqueId )
          {
          if ( RTDS_timer->state == RTDS_TIMER_CANCELLED )
            {
            /* Discard current message */
            RTDS_FREE( RTDS_currentContext->currentMessage );
            RTDS_currentContext->currentMessage = NULL;
            /* Remove it from list of timers */
            if ( RTDS_prevTimer == NULL )
              {
              RTDS_currentContext->timerList = RTDS_currentContext->timerList->next;
              }
            else
              {
              RTDS_prevTimer->next = RTDS_timer->next;
              }
            CloseHandle(RTDS_timer->watchDogId);
            RTDS_FREE( RTDS_timer );
            }
          break;
          }
        RTDS_prevTimer = RTDS_timer;
        }
      /* If the timer could not be found in the list. Consider it as cancelled and discard current message */
      if ( RTDS_timer == NULL )
        {
        RTDS_FREE( RTDS_currentContext->currentMessage );
        RTDS_currentContext->currentMessage = NULL;
        }
      }

    /* Let's process the message ! */
    if ( RTDS_currentContext->currentMessage != NULL )
      {
      RTDS_SIMULATOR_TRACE( RTDS_messageReceived, RTDS_currentContext->currentMessage, SELF, RTDS_currentContext );
      RTDS_senderId = RTDS_currentContext->currentMessage->sender;
      RTDS_sdlStatePrev = RTDS_currentContext->sdlState;
      /* $(RTDS_HOME)/share/ccg/windows/bricks/RTDS_Proc_middle.c ends */
      /* ************************************************************* */

      /* Double switch state / signal */
      RTDS_transitionExecuted = 1;
      switch(RTDS_currentContext->sdlState)
        {
        /* Transitions for state OnePath */
        case RTDS_state_OnePath:
          switch(RTDS_currentContext->currentMessage->messageNumber)
            {
            /* Transition for state OnePath - message sTopologyProbing */
            case RTDS_message_sTopologyProbing:
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteUpdated, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_SDL_STATE_SET(RTDS_state_OnePath);
              break;
            /* Transition for state OnePath - message sRouteUpdated */
            case RTDS_message_sRouteUpdated:
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteUpdated, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_SDL_STATE_SET(RTDS_state_OnePath);
              break;
            /* Transition for state OnePath - message sRouteRemoved */
            case RTDS_message_sRouteRemoved:
              paths = paths - 1;
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteRemoved, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRemoveRoute, 0, NULL, "pDrogiKomunikacjiWP", RTDS_process_pDrogiKomunikacjiWP);
              RTDS_SDL_STATE_SET(RTDS_state_NoPath);
              break;
            /* Transition for state OnePath - message sRouteAdded */
            case RTDS_message_sRouteAdded:
              paths = paths + 1;
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteUpdated, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_SDL_STATE_SET(RTDS_state_MultiplePaths);
              break;
            default:
              RTDS_transitionExecuted = 0;
              break;
            } /* End of switch on message */
          break;
        /* Transitions for state NoPath */
        case RTDS_state_NoPath:
          switch(RTDS_currentContext->currentMessage->messageNumber)
            {
            /* Transition for state NoPath - message sRouteAdded */
            case RTDS_message_sRouteAdded:
              paths = paths + 1;
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteAdded, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sAddRoute, 0, NULL, "pDrogiKomunikacjiWP", RTDS_process_pDrogiKomunikacjiWP);
              RTDS_SDL_STATE_SET(RTDS_state_OnePath);
              break;
            /* Transition for state NoPath - message sRouteUpdated */
            case RTDS_message_sRouteUpdated:
              paths = paths + 1;
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteAdded, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sAddRoute, 0, NULL, "pDrogiKomunikacjiWP", RTDS_process_pDrogiKomunikacjiWP);
              RTDS_SDL_STATE_SET(RTDS_state_OnePath);
              break;
            /* Transition for state NoPath - message sExternalCommunication */
            case RTDS_message_sExternalCommunication:
              paths = paths + 1;
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteAdded, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sAddRoute, 0, NULL, "pDrogiKomunikacjiWP", RTDS_process_pDrogiKomunikacjiWP);
              RTDS_SDL_STATE_SET(RTDS_state_OnePath);
              break;
            default:
              RTDS_transitionExecuted = 0;
              break;
            } /* End of switch on message */
          break;
        /* Transitions for state MultiplePaths */
        case RTDS_state_MultiplePaths:
          switch(RTDS_currentContext->currentMessage->messageNumber)
            {
            /* Transition for state MultiplePaths - message sRouteAdded */
            case RTDS_message_sRouteAdded:
              paths = paths + 1;
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteUpdated, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_SDL_STATE_SET(RTDS_state_MultiplePaths);
              break;
            /* Transition for state MultiplePaths - message sRouteRemoved */
            case RTDS_message_sRouteRemoved:
              paths = paths - 1;
              if ( !((RTDS_BOOLEAN)(paths > 1)) )
                {
                RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteUpdated, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
                }
              else if ( (RTDS_BOOLEAN)(paths > 1) )
                {
                RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteUpdated, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
                RTDS_SDL_STATE_SET(RTDS_state_MultiplePaths);
                break;
                }
              RTDS_SDL_STATE_SET(RTDS_state_OnePath);
              break;
            /* Transition for state MultiplePaths - message sRouteUpdated */
            case RTDS_message_sRouteUpdated:
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteUpdated, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_SDL_STATE_SET(RTDS_state_MultiplePaths);
              break;
            /* Transition for state MultiplePaths - message sTopologyProbing */
            case RTDS_message_sTopologyProbing:
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sRouteUpdated, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_SDL_STATE_SET(RTDS_state_MultiplePaths);
              break;
            default:
              RTDS_transitionExecuted = 0;
              break;
            } /* End of switch on message */
          break;
        default:
          RTDS_transitionExecuted = 0;
          break;
        } /* End of switch(RTDS_currentContext->sdlState) */
      /* ************************************************************ */
      /* $(RTDS_HOME)/share/ccg/windows/bricks/RTDS_Proc_end.c begins */
      /* PragmaDev RTDS win32 integration                             */
      RTDS_TransitionCleanUp( RTDS_currentContext, RTDS_sdlStatePrev );
      } /* End of if ( RTDS_currentContext->currentMessage != NULL ) to execute transition */
    } /* End of for ( ; ; ) */

  /* $(RTDS_HOME)/share/ccg/windows/bricks/RTDS_Proc_end.c ends */
  /* ********************************************************** */
  }
