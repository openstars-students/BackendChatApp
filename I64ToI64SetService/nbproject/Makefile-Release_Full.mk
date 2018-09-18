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
CND_CONF=Release_Full
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
	${OBJECTDIR}/thrift/gen-cpp/TI64ToI64SetService.o \
	${OBJECTDIR}/thrift/gen-cpp/TI64ToI64SetServiceR.o \
	${OBJECTDIR}/thrift/gen-cpp/i64toi64set_shared_constants.o \
	${OBJECTDIR}/thrift/gen-cpp/i64toi64set_shared_types.o \
	${OBJECTDIR}/thrift/gen-cpp/i64toi64setservice_constants.o \
	${OBJECTDIR}/thrift/gen-cpp/i64toi64setservice_types.o


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
LDLIBSOPTIONS=../../corelibs/CuteStorage/lib/libcutestorage.a ../../corelibs/OpenStorage/lib/libopenstorage.a ../../corelibs/BaseFoundation/lib/libbasefoundation.a ../../contribs/ApacheThrift/lib/libapachethrift.a ../../contribs/SpecialContribs/lib/libspecialcontribs.a ../../contribs/Poco/lib/libpocoall.a ../../contribs/LibEvent/lib/libevent.a -ldl -lpthread -lrt

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk bin/i64toi64setservice

bin/i64toi64setservice: ../../corelibs/CuteStorage/lib/libcutestorage.a

bin/i64toi64setservice: ../../corelibs/OpenStorage/lib/libopenstorage.a

bin/i64toi64setservice: ../../corelibs/BaseFoundation/lib/libbasefoundation.a

bin/i64toi64setservice: ../../contribs/ApacheThrift/lib/libapachethrift.a

bin/i64toi64setservice: ../../contribs/SpecialContribs/lib/libspecialcontribs.a

bin/i64toi64setservice: ../../contribs/Poco/lib/libpocoall.a

bin/i64toi64setservice: ../../contribs/LibEvent/lib/libevent.a

bin/i64toi64setservice: ${OBJECTFILES}
	${MKDIR} -p bin
	${LINK.cc} -o bin/i64toi64setservice ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/ServerApp.o: src/ServerApp.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServerApp.o src/ServerApp.cpp

${OBJECTDIR}/src/ServiceModel.o: src/ServiceModel.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ServiceModel.o src/ServiceModel.cpp

${OBJECTDIR}/src/main.o: src/main.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/thrift/gen-cpp/TI64ToI64SetService.o: thrift/gen-cpp/TI64ToI64SetService.cpp
	${MKDIR} -p ${OBJECTDIR}/thrift/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift/gen-cpp/TI64ToI64SetService.o thrift/gen-cpp/TI64ToI64SetService.cpp

${OBJECTDIR}/thrift/gen-cpp/TI64ToI64SetServiceR.o: thrift/gen-cpp/TI64ToI64SetServiceR.cpp
	${MKDIR} -p ${OBJECTDIR}/thrift/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift/gen-cpp/TI64ToI64SetServiceR.o thrift/gen-cpp/TI64ToI64SetServiceR.cpp

${OBJECTDIR}/thrift/gen-cpp/i64toi64set_shared_constants.o: thrift/gen-cpp/i64toi64set_shared_constants.cpp
	${MKDIR} -p ${OBJECTDIR}/thrift/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift/gen-cpp/i64toi64set_shared_constants.o thrift/gen-cpp/i64toi64set_shared_constants.cpp

${OBJECTDIR}/thrift/gen-cpp/i64toi64set_shared_types.o: thrift/gen-cpp/i64toi64set_shared_types.cpp
	${MKDIR} -p ${OBJECTDIR}/thrift/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift/gen-cpp/i64toi64set_shared_types.o thrift/gen-cpp/i64toi64set_shared_types.cpp

${OBJECTDIR}/thrift/gen-cpp/i64toi64setservice_constants.o: thrift/gen-cpp/i64toi64setservice_constants.cpp
	${MKDIR} -p ${OBJECTDIR}/thrift/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift/gen-cpp/i64toi64setservice_constants.o thrift/gen-cpp/i64toi64setservice_constants.cpp

${OBJECTDIR}/thrift/gen-cpp/i64toi64setservice_types.o: thrift/gen-cpp/i64toi64setservice_types.cpp
	${MKDIR} -p ${OBJECTDIR}/thrift/gen-cpp
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -DHAVE_CONFIG_H -Iinc -I../../contribs/LibEvent/include -I../../contribs/Boost/include -I../../contribs/Poco/include -I../../contribs/ApacheThrift/include -I../../contribs/SpecialContribs/include -Ithrift/gen-cpp -I../../contribs/SpecialContribs/src/hashkit -I../../contribs/SpecialContribs/src/libstatgrab -I../../contribs/SpecialContribs/include/kyotocabinet -I../../contribs/SpecialContribs/include/leveldb -I../../contribs/SpecialContribs/src/ -I../../corelibs/BaseFoundation/include -I../../corelibs/OpenStorage/inc -I../../corelibs/BaseFoundation/thrift/gen-cpp -IClient -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/thrift/gen-cpp/i64toi64setservice_types.o thrift/gen-cpp/i64toi64setservice_types.cpp

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
