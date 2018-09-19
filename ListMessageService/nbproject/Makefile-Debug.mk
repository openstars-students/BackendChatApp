#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/ServerApp.o \
	${OBJECTDIR}/src/ServiceModel.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/thrift/gen-cpp/TDataService.o \
	${OBJECTDIR}/thrift/gen-cpp/TListMessageService.o \
	${OBJECTDIR}/thrift/gen-cpp/listmessageservice_constants.o \
	${OBJECTDIR}/thrift/gen-cpp/listmessageservice_types.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=../../corelibs/OpenStorage/lib/libopenstoraged.a ../../corelibs/BaseFoundation/lib/libbasefoundationd.a ../../contribs/ApacheThrift/lib/libapachethriftd.a ../../contribs/SpecialContribs/lib/libspecialcontribsd.a ../../contribs/Poco/lib/libpocoalld.a ../../contribs/LibEvent/lib/libeventd.a -ldl -lpthread -lrt

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk bin/listmessageserviced

bin/listmessageserviced: ../../corelibs/OpenStorage/lib/libopenstoraged.a

bin/listmessageserviced: ../../corelibs/BaseFoundation/lib/libbasefoundationd.a

bin/listmessageserviced: ../../contribs/ApacheThrift/lib/libapachethriftd.a

bin/listmessageserviced: ../../contribs/SpecialContribs/lib/libspecialcontribsd.a

bin/listmessageserviced: ../../contribs/Poco/lib/libpocoalld.a

bin/listmessageserviced: ../../contribs/LibEvent/lib/libeventd.a

bin/listmessageserviced: ${OBJECTFILES}
	${MKDIR} -p bin
	${LINK.cc} -o bin/listmessageserviced ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/ServerApp.o: src/ServerApp.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServerApp.o src/ServerApp.cpp

${OBJECTDIR}/src/ServiceModel.o: src/ServiceModel.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServiceModel.o src/ServiceModel.cpp

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/thrift/gen-cpp/TDataService.o: thrift/gen-cpp/TDataService.cpp
	${MKDIR} -p ${OBJECTDIR}/thrift/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -g -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift/gen-cpp/TDataService.o thrift/gen-cpp/TDataService.cpp

${OBJECTDIR}/thrift/gen-cpp/TListMessageService.o: thrift/gen-cpp/TListMessageService.cpp
	${MKDIR} -p ${OBJECTDIR}/thrift/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -g -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift/gen-cpp/TListMessageService.o thrift/gen-cpp/TListMessageService.cpp

${OBJECTDIR}/thrift/gen-cpp/listmessageservice_constants.o: thrift/gen-cpp/listmessageservice_constants.cpp
	${MKDIR} -p ${OBJECTDIR}/thrift/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -g -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift/gen-cpp/listmessageservice_constants.o thrift/gen-cpp/listmessageservice_constants.cpp

${OBJECTDIR}/thrift/gen-cpp/listmessageservice_types.o: thrift/gen-cpp/listmessageservice_types.cpp
	${MKDIR} -p ${OBJECTDIR}/thrift/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -g -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift/gen-cpp/listmessageservice_types.o thrift/gen-cpp/listmessageservice_types.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
