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

#include "pWezelBrzegowy.h"
#include "RTDS_messages.h"
#include "RTDS_gen.h"

#define RTDS_PROCESS_NUMBER RTDS_process_pWezelBrzegowy
#define RTDS_PROCESS_NAME pWezelBrzegowy

/*
** PROCESS pWezelBrzegowy:
** -----------------------
*/

RTDS_TASK_ENTRY_POINT(pWezelBrzegowy)
  {
  short RTDS_transitionExecuted;
  int RTDS_savedSdlState = 0;

  int i;
  void * RTDS_myLocals[1];
  void ** RTDS_localsStack[1];
  RTDS_MSG_DATA_DECL



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




  /* Initial transition */
  do	/* Dummy do/while(0) to be able to do 'break's */
    {
    RTDS_myLocals[0] = (void*)&i;
    RTDS_localsStack[0] = RTDS_myLocals;
    RTDS_start_label:
    RTDS_SET_TIMER(RTDS_message_t, (0 + 1) * 100);
    RTDS_SDL_STATE_SET(RTDS_state_NoExternalCommunication);
    break;
    } while (0);

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
        /* Transitions for state NoExternalCommunication */
        case RTDS_state_NoExternalCommunication:
          switch(RTDS_currentContext->currentMessage->messageNumber)
            {
            /* Transition for state NoExternalCommunication - message t */
            case RTDS_message_t:
              RTDS_MSG_QUEUE_SEND_TO_NAME(RTDS_message_sExternalCommunication, 0, NULL, "pPojedynczaDrogaDowolnegoWezlaWP", RTDS_process_pPojedynczaDrogaDowolnegoWezlaWP);
              RTDS_SDL_STATE_SET(RTDS_state_ExternalCommunication);
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
