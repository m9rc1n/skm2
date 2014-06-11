RTDS_GEN_DIR=c:\users\marcin\documents\github\skm2\ccg
RTDS_CLASSES_DIR=c:\users\marcin\documents\github\skm2\ccg
RTDS_TEMPLATES_DIR=c:\rtds\share\ccg\windows

RTDS_CC=mingw32-gcc
RTDS_LNK=$(RTDS_CC)
RTDS_CC_INCLUDES=-I"." -I"${RTDS_TEMPLATES_DIR}" -I"${RTDS_HOME}\share\ccg\trace\formattrace" -I"${RTDS_HOME}\share\ccg\common" -I"$(RTDS_CLASSES_DIR)"
RTDS_CC_OPTIONS=-DRTDS_FORMAT_TRACE -I"." -I"${RTDS_TEMPLATES_DIR}" -I"${RTDS_HOME}\share\ccg\trace\formattrace" -I"${RTDS_HOME}\share\ccg\common" -DRTDS_MSC_TRACER -I"$(RTDS_CLASSES_DIR)" -DRTDS_SOCKET_IP_ADDRESS=192.168.0.11 -DRTDS_SOCKET_PORT=49250 
RTDS_LNK_OPTIONS=

RTDS_RM=cmd /c del

RTDS_OBJECTS = \
	rtds_env.o \
	pmechanizmbadaniatopologii.o \
	ppojedynczadrogadowolnegowezlawp.o \
	pdrogikomunikacjiwp.o \
	rtds_encdecmsgdata.o \
	rtds_start.o \
	pwezelbrzegowy.o \
	RTDS_String.o \
	rtds_os.o \
	rtds_tcp_client.o \
	rtds_formattrace.o


RTDS_ADDL_OBJECTS = \
	C:/RTDS/share/3rdparty/MinGW/lib/libws2_32.a

RTDS_EXT_OBJECTS =

RTDS_TARGET_BASE_NAME=Protocol_BSP
RTDS_TARGET_EXTENSION=.exe

all: $(RTDS_TARGET_BASE_NAME)$(RTDS_TARGET_EXTENSION)

$(RTDS_TARGET_BASE_NAME)$(RTDS_TARGET_EXTENSION): $(RTDS_OBJECTS) $(RTDS_ADDL_OBJECTS) $(RTDS_EXT_OBJECTS)
	$(RTDS_LNK) $(RTDS_LNK_OPTIONS) -o "$@" $(RTDS_OBJECTS) $(RTDS_ADDL_OBJECTS) $(RTDS_EXT_OBJECTS)

rtds_env.o: $(RTDS_TEMPLATES_DIR)\rtds_env.c Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

pmechanizmbadaniatopologii.o: $(RTDS_GEN_DIR)\pmechanizmbadaniatopologii.c $(RTDS_GEN_DIR)\pmechanizmbadaniatopologii.h $(RTDS_GEN_DIR)\rtds_messages.h $(RTDS_GEN_DIR)\rtds_gen.h $(RTDS_GEN_DIR)\bblokwezlapomiarowego.h $(RTDS_GEN_DIR)\protocol_bsp.h $(RTDS_GEN_DIR)\rtds_commontypes.h $(RTDS_GEN_DIR)\rtds_string.h $(RTDS_GEN_DIR)\rtds_set.h Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

ppojedynczadrogadowolnegowezlawp.o: $(RTDS_GEN_DIR)\ppojedynczadrogadowolnegowezlawp.c $(RTDS_GEN_DIR)\ppojedynczadrogadowolnegowezlawp.h $(RTDS_GEN_DIR)\rtds_messages.h $(RTDS_GEN_DIR)\rtds_gen.h $(RTDS_GEN_DIR)\bblokwezlapomiarowego.h $(RTDS_GEN_DIR)\protocol_bsp.h $(RTDS_GEN_DIR)\rtds_commontypes.h $(RTDS_GEN_DIR)\rtds_string.h $(RTDS_GEN_DIR)\rtds_set.h Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

pdrogikomunikacjiwp.o: $(RTDS_GEN_DIR)\pdrogikomunikacjiwp.c $(RTDS_GEN_DIR)\pdrogikomunikacjiwp.h $(RTDS_GEN_DIR)\rtds_messages.h $(RTDS_GEN_DIR)\rtds_gen.h $(RTDS_GEN_DIR)\bblokwezlapomiarowego.h $(RTDS_GEN_DIR)\protocol_bsp.h $(RTDS_GEN_DIR)\rtds_commontypes.h $(RTDS_GEN_DIR)\rtds_string.h $(RTDS_GEN_DIR)\rtds_set.h Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

rtds_encdecmsgdata.o: $(RTDS_GEN_DIR)\rtds_encdecmsgdata.c Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

rtds_start.o: $(RTDS_GEN_DIR)\rtds_start.c Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

pwezelbrzegowy.o: $(RTDS_GEN_DIR)\pwezelbrzegowy.c $(RTDS_GEN_DIR)\pwezelbrzegowy.h $(RTDS_GEN_DIR)\rtds_messages.h $(RTDS_GEN_DIR)\rtds_gen.h $(RTDS_GEN_DIR)\bblokwezlabrzegowego.h $(RTDS_GEN_DIR)\protocol_bsp.h $(RTDS_GEN_DIR)\rtds_commontypes.h $(RTDS_GEN_DIR)\rtds_string.h $(RTDS_GEN_DIR)\rtds_set.h Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

RTDS_String.o: $(RTDS_GEN_DIR)\rtds_string.c Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

rtds_os.o: $(RTDS_TEMPLATES_DIR)\rtds_os.c Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

rtds_tcp_client.o: $(RTDS_TEMPLATES_DIR)\rtds_tcp_client.c Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

rtds_formattrace.o: $(RTDS_HOME)\share\ccg\trace\formattrace\rtds_formattrace.c Makefile
	$(RTDS_CC) $(RTDS_CC_OPTIONS) -c -o "$@" "$<"

RTDS_clean:
	$(RTDS_RM) $(RTDS_TARGET_BASE_NAME)$(RTDS_TARGET_EXTENSION)
	$(RTDS_RM) "rtds_env.o"
	$(RTDS_RM) "pmechanizmbadaniatopologii.o"
	$(RTDS_RM) "ppojedynczadrogadowolnegowezlawp.o"
	$(RTDS_RM) "pdrogikomunikacjiwp.o"
	$(RTDS_RM) "rtds_encdecmsgdata.o"
	$(RTDS_RM) "rtds_start.o"
	$(RTDS_RM) "pwezelbrzegowy.o"
	$(RTDS_RM) "RTDS_String.o"
	$(RTDS_RM) "rtds_os.o"
	$(RTDS_RM) "rtds_tcp_client.o"
	$(RTDS_RM) "rtds_formattrace.o"

RTDS_mrproper: RTDS_clean
	$(RTDS_RM) "pMechanizmBadaniaTopologii.h"
	$(RTDS_RM) "RTDS_messages.h"
	$(RTDS_RM) "RTDS_gen.h"
	$(RTDS_RM) "pMechanizmBadaniaTopologii.c"
	$(RTDS_RM) "bBlokWezlaBrzegowego.h"
	$(RTDS_RM) "bBlokWezlaPomiarowego.h"
	$(RTDS_RM) "pPojedynczaDrogaDowolnegoWezlaWP.c"
	$(RTDS_RM) "pWezelBrzegowy.h"
	$(RTDS_RM) "pDrogiKomunikacjiWP.c"
	$(RTDS_RM) "Protocol_BSP.h"
	$(RTDS_RM) "RTDS_encdecMsgData.c"
	$(RTDS_RM) "pPojedynczaDrogaDowolnegoWezlaWP.h"
	$(RTDS_RM) "RTDS_Start.c"
	$(RTDS_RM) "pDrogiKomunikacjiWP.h"
	$(RTDS_RM) "pWezelBrzegowy.c"
	$(RTDS_RM) RTDS_gen.ini
	$(RTDS_RM) Makefile
