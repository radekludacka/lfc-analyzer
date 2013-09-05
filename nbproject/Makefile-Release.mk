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
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/17412522/MockCommands.o \
	${OBJECTDIR}/_ext/1800792019/Information.o \
	${OBJECTDIR}/_ext/1800792019/LfcAACommand.o \
	${OBJECTDIR}/_ext/1800792019/LfcCpCommand.o \
	${OBJECTDIR}/_ext/1800792019/LfcDelReplicaCommand.o \
	${OBJECTDIR}/_ext/1800792019/LfcLrCommand.o \
	${OBJECTDIR}/_ext/1800792019/LfcMkdirCommand.o \
	${OBJECTDIR}/_ext/1800792019/LfcPingDBCommand.o \
	${OBJECTDIR}/_ext/1800792019/LfcRepCommand.o \
	${OBJECTDIR}/_ext/1800792019/LfcRmDirCommand.o \
	${OBJECTDIR}/_ext/1800792019/LfcServCommand.o \
	${OBJECTDIR}/_ext/1800792019/LfcUtimeCommand.o \
	${OBJECTDIR}/_ext/1781719998/LstatState.o \
	${OBJECTDIR}/_ext/1781719998/MkDirState.o \
	${OBJECTDIR}/_ext/1781719998/PingDBState.o \
	${OBJECTDIR}/_ext/1781719998/ReplicaCpDelRepState.o \
	${OBJECTDIR}/_ext/1781719998/ReplicaState.o \
	${OBJECTDIR}/_ext/1781719998/ServState.o \
	${OBJECTDIR}/_ext/1781719998/StartSessState.o \
	${OBJECTDIR}/_ext/1781719998/UtimeState.o \
	${OBJECTDIR}/_ext/1152981978/StartTransStateAA.o \
	${OBJECTDIR}/_ext/1396044971/StartTransState.o \
	${OBJECTDIR}/_ext/1396044971/StartTransState2.o \
	${OBJECTDIR}/_ext/1541828867/DelAll.o \
	${OBJECTDIR}/_ext/1541828867/DelRemain.o \
	${OBJECTDIR}/_ext/1541828867/DelReplica.o \
	${OBJECTDIR}/_ext/1616743893/BadReplicaState.o \
	${OBJECTDIR}/_ext/1616743893/ReplicateStateTransaction.o \
	${OBJECTDIR}/_ext/327138736/RmDirState.o \
	${OBJECTDIR}/_ext/1070216355/OpenDirRecursiveState.o \
	${OBJECTDIR}/_ext/1273540945/Filter.o \
	${OBJECTDIR}/_ext/1208396726/CommandSorter.o \
	${OBJECTDIR}/_ext/1208396726/FileSorter.o \
	${OBJECTDIR}/_ext/1208396726/SiteSorter.o \
	${OBJECTDIR}/_ext/1208396726/Sorter.o \
	${OBJECTDIR}/_ext/1208396726/SuccessSorter.o \
	${OBJECTDIR}/_ext/1208396726/UserSorter.o \
	${OBJECTDIR}/_ext/1723276753/Presenter.o \
	${OBJECTDIR}/MockItems.o \
	${OBJECTDIR}/MockRows.o \
	${OBJECTDIR}/analyzer2/Analyzer.o \
	${OBJECTDIR}/analyzer2/LFCCommand.o \
	${OBJECTDIR}/analyzer2/LfcCommandTable.o \
	${OBJECTDIR}/analyzer2/LfcCrCommand.o \
	${OBJECTDIR}/analyzer2/LfcLsCommand.o \
	${OBJECTDIR}/analyzer2/states/State.o \
	${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o \
	${OBJECTDIR}/filter/Counter.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f4

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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lfc-analyzer

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lfc-analyzer: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lfc-analyzer ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/17412522/MockCommands.o: /home/radek/NetBeansProjects/LFC_analyzer/MockCommands.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/17412522
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/17412522/MockCommands.o /home/radek/NetBeansProjects/LFC_analyzer/MockCommands.cpp

${OBJECTDIR}/_ext/1800792019/Information.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/Information.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/Information.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/Information.cpp

${OBJECTDIR}/_ext/1800792019/LfcAACommand.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcAACommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcAACommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcAACommand.cpp

${OBJECTDIR}/_ext/1800792019/LfcCpCommand.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcCpCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcCpCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcCpCommand.cpp

${OBJECTDIR}/_ext/1800792019/LfcDelReplicaCommand.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcDelReplicaCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcDelReplicaCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcDelReplicaCommand.cpp

${OBJECTDIR}/_ext/1800792019/LfcLrCommand.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcLrCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcLrCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcLrCommand.cpp

${OBJECTDIR}/_ext/1800792019/LfcMkdirCommand.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcMkdirCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcMkdirCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcMkdirCommand.cpp

${OBJECTDIR}/_ext/1800792019/LfcPingDBCommand.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcPingDBCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcPingDBCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcPingDBCommand.cpp

${OBJECTDIR}/_ext/1800792019/LfcRepCommand.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcRepCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcRepCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcRepCommand.cpp

${OBJECTDIR}/_ext/1800792019/LfcRmDirCommand.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcRmDirCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcRmDirCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcRmDirCommand.cpp

${OBJECTDIR}/_ext/1800792019/LfcServCommand.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcServCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcServCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcServCommand.cpp

${OBJECTDIR}/_ext/1800792019/LfcUtimeCommand.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcUtimeCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcUtimeCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcUtimeCommand.cpp

${OBJECTDIR}/_ext/1781719998/LstatState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/LstatState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/LstatState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/LstatState.cpp

${OBJECTDIR}/_ext/1781719998/MkDirState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/MkDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/MkDirState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/MkDirState.cpp

${OBJECTDIR}/_ext/1781719998/PingDBState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/PingDBState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/PingDBState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/PingDBState.cpp

${OBJECTDIR}/_ext/1781719998/ReplicaCpDelRepState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ReplicaCpDelRepState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/ReplicaCpDelRepState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ReplicaCpDelRepState.cpp

${OBJECTDIR}/_ext/1781719998/ReplicaState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ReplicaState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/ReplicaState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ReplicaState.cpp

${OBJECTDIR}/_ext/1781719998/ServState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ServState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/ServState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ServState.cpp

${OBJECTDIR}/_ext/1781719998/StartSessState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/StartSessState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/StartSessState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/StartSessState.cpp

${OBJECTDIR}/_ext/1781719998/UtimeState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/UtimeState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/UtimeState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/UtimeState.cpp

${OBJECTDIR}/_ext/1152981978/StartTransStateAA.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_aa_states/StartTransStateAA.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1152981978
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1152981978/StartTransStateAA.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_aa_states/StartTransStateAA.cpp

${OBJECTDIR}/_ext/1396044971/StartTransState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_cr_states/StartTransState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1396044971
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1396044971/StartTransState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_cr_states/StartTransState.cpp

${OBJECTDIR}/_ext/1396044971/StartTransState2.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_cr_states/StartTransState2.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1396044971
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1396044971/StartTransState2.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_cr_states/StartTransState2.cpp

${OBJECTDIR}/_ext/1541828867/DelAll.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelAll.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1541828867
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1541828867/DelAll.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelAll.cpp

${OBJECTDIR}/_ext/1541828867/DelRemain.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelRemain.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1541828867
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1541828867/DelRemain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelRemain.cpp

${OBJECTDIR}/_ext/1541828867/DelReplica.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelReplica.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1541828867
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1541828867/DelReplica.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelReplica.cpp

${OBJECTDIR}/_ext/1616743893/BadReplicaState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rep_states/BadReplicaState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1616743893
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1616743893/BadReplicaState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rep_states/BadReplicaState.cpp

${OBJECTDIR}/_ext/1616743893/ReplicateStateTransaction.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rep_states/ReplicateStateTransaction.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1616743893
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1616743893/ReplicateStateTransaction.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rep_states/ReplicateStateTransaction.cpp

${OBJECTDIR}/_ext/327138736/RmDirState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rm_dir/RmDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/327138736
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/327138736/RmDirState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rm_dir/RmDirState.cpp

${OBJECTDIR}/_ext/1070216355/OpenDirRecursiveState.o: /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfs_ls_states/OpenDirRecursiveState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1070216355
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1070216355/OpenDirRecursiveState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfs_ls_states/OpenDirRecursiveState.cpp

${OBJECTDIR}/_ext/1273540945/Filter.o: /home/radek/NetBeansProjects/LFC_analyzer/filter/Filter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1273540945
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1273540945/Filter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/Filter.cpp

${OBJECTDIR}/_ext/1208396726/CommandSorter.o: /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/CommandSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/CommandSorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/CommandSorter.cpp

${OBJECTDIR}/_ext/1208396726/FileSorter.o: /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/FileSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/FileSorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/FileSorter.cpp

${OBJECTDIR}/_ext/1208396726/SiteSorter.o: /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/SiteSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/SiteSorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/SiteSorter.cpp

${OBJECTDIR}/_ext/1208396726/Sorter.o: /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/Sorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/Sorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/Sorter.cpp

${OBJECTDIR}/_ext/1208396726/SuccessSorter.o: /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/SuccessSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/SuccessSorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/SuccessSorter.cpp

${OBJECTDIR}/_ext/1208396726/UserSorter.o: /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/UserSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/UserSorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/UserSorter.cpp

${OBJECTDIR}/_ext/1723276753/Presenter.o: /home/radek/NetBeansProjects/LFC_analyzer/presenter/Presenter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1723276753
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1723276753/Presenter.o /home/radek/NetBeansProjects/LFC_analyzer/presenter/Presenter.cpp

${OBJECTDIR}/MockItems.o: MockItems.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/MockItems.o MockItems.cpp

${OBJECTDIR}/MockRows.o: MockRows.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/MockRows.o MockRows.cpp

${OBJECTDIR}/analyzer2/Analyzer.o: analyzer2/Analyzer.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/Analyzer.o analyzer2/Analyzer.cpp

${OBJECTDIR}/analyzer2/LFCCommand.o: analyzer2/LFCCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LFCCommand.o analyzer2/LFCCommand.cpp

${OBJECTDIR}/analyzer2/LfcCommandTable.o: analyzer2/LfcCommandTable.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcCommandTable.o analyzer2/LfcCommandTable.cpp

${OBJECTDIR}/analyzer2/LfcCrCommand.o: analyzer2/LfcCrCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcCrCommand.o analyzer2/LfcCrCommand.cpp

${OBJECTDIR}/analyzer2/LfcLsCommand.o: analyzer2/LfcLsCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcLsCommand.o analyzer2/LfcLsCommand.cpp

${OBJECTDIR}/analyzer2/states/State.o: analyzer2/states/State.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/State.o analyzer2/states/State.cpp

${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o: analyzer2/states/lfs_ls_states/OpenDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfs_ls_states
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o analyzer2/states/lfs_ls_states/OpenDirState.cpp

${OBJECTDIR}/filter/Counter.o: filter/Counter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/Counter.o filter/Counter.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -O2 -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/AnalyzerRunner.o ${TESTDIR}/tests/AnalyzerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/_ext/8307683/FilterRunner.o ${TESTDIR}/_ext/8307683/FilterTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/ParserRunner.o ${TESTDIR}/tests/ParserTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/_ext/1331574488/PresenterRunner.o ${TESTDIR}/_ext/1331574488/PresenterTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs`   


${TESTDIR}/tests/AnalyzerRunner.o: tests/AnalyzerRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/AnalyzerRunner.o tests/AnalyzerRunner.cpp


${TESTDIR}/tests/AnalyzerTest.o: tests/AnalyzerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/AnalyzerTest.o tests/AnalyzerTest.cpp


${TESTDIR}/_ext/8307683/FilterRunner.o: /home/radek/NetBeansProjects/LFC_analyzer/filter/tests/FilterRunner.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/8307683
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/_ext/8307683/FilterRunner.o /home/radek/NetBeansProjects/LFC_analyzer/filter/tests/FilterRunner.cpp


${TESTDIR}/_ext/8307683/FilterTest.o: /home/radek/NetBeansProjects/LFC_analyzer/filter/tests/FilterTest.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/8307683
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/_ext/8307683/FilterTest.o /home/radek/NetBeansProjects/LFC_analyzer/filter/tests/FilterTest.cpp


${TESTDIR}/tests/ParserRunner.o: tests/ParserRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/ParserRunner.o tests/ParserRunner.cpp


${TESTDIR}/tests/ParserTests.o: tests/ParserTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/ParserTests.o tests/ParserTests.cpp


${TESTDIR}/_ext/1331574488/PresenterRunner.o: /home/radek/NetBeansProjects/LFC_analyzer/tests/PresenterRunner.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1331574488
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/_ext/1331574488/PresenterRunner.o /home/radek/NetBeansProjects/LFC_analyzer/tests/PresenterRunner.cpp


${TESTDIR}/_ext/1331574488/PresenterTests.o: /home/radek/NetBeansProjects/LFC_analyzer/tests/PresenterTests.cpp 
	${MKDIR} -p ${TESTDIR}/_ext/1331574488
	${RM} $@.d
	$(COMPILE.cc) -O2 `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/_ext/1331574488/PresenterTests.o /home/radek/NetBeansProjects/LFC_analyzer/tests/PresenterTests.cpp


${OBJECTDIR}/_ext/17412522/MockCommands_nomain.o: ${OBJECTDIR}/_ext/17412522/MockCommands.o /home/radek/NetBeansProjects/LFC_analyzer/MockCommands.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/17412522
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/17412522/MockCommands.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/17412522/MockCommands_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/MockCommands.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/17412522/MockCommands.o ${OBJECTDIR}/_ext/17412522/MockCommands_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/Information_nomain.o: ${OBJECTDIR}/_ext/1800792019/Information.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/Information.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/Information.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/Information_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/Information.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/Information.o ${OBJECTDIR}/_ext/1800792019/Information_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/LfcAACommand_nomain.o: ${OBJECTDIR}/_ext/1800792019/LfcAACommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcAACommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/LfcAACommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcAACommand_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcAACommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/LfcAACommand.o ${OBJECTDIR}/_ext/1800792019/LfcAACommand_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/LfcCpCommand_nomain.o: ${OBJECTDIR}/_ext/1800792019/LfcCpCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcCpCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/LfcCpCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcCpCommand_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcCpCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/LfcCpCommand.o ${OBJECTDIR}/_ext/1800792019/LfcCpCommand_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/LfcDelReplicaCommand_nomain.o: ${OBJECTDIR}/_ext/1800792019/LfcDelReplicaCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcDelReplicaCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/LfcDelReplicaCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcDelReplicaCommand_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcDelReplicaCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/LfcDelReplicaCommand.o ${OBJECTDIR}/_ext/1800792019/LfcDelReplicaCommand_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/LfcLrCommand_nomain.o: ${OBJECTDIR}/_ext/1800792019/LfcLrCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcLrCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/LfcLrCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcLrCommand_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcLrCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/LfcLrCommand.o ${OBJECTDIR}/_ext/1800792019/LfcLrCommand_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/LfcMkdirCommand_nomain.o: ${OBJECTDIR}/_ext/1800792019/LfcMkdirCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcMkdirCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/LfcMkdirCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcMkdirCommand_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcMkdirCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/LfcMkdirCommand.o ${OBJECTDIR}/_ext/1800792019/LfcMkdirCommand_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/LfcPingDBCommand_nomain.o: ${OBJECTDIR}/_ext/1800792019/LfcPingDBCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcPingDBCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/LfcPingDBCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcPingDBCommand_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcPingDBCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/LfcPingDBCommand.o ${OBJECTDIR}/_ext/1800792019/LfcPingDBCommand_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/LfcRepCommand_nomain.o: ${OBJECTDIR}/_ext/1800792019/LfcRepCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcRepCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/LfcRepCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcRepCommand_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcRepCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/LfcRepCommand.o ${OBJECTDIR}/_ext/1800792019/LfcRepCommand_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/LfcRmDirCommand_nomain.o: ${OBJECTDIR}/_ext/1800792019/LfcRmDirCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcRmDirCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/LfcRmDirCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcRmDirCommand_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcRmDirCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/LfcRmDirCommand.o ${OBJECTDIR}/_ext/1800792019/LfcRmDirCommand_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/LfcServCommand_nomain.o: ${OBJECTDIR}/_ext/1800792019/LfcServCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcServCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/LfcServCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcServCommand_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcServCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/LfcServCommand.o ${OBJECTDIR}/_ext/1800792019/LfcServCommand_nomain.o;\
	fi

${OBJECTDIR}/_ext/1800792019/LfcUtimeCommand_nomain.o: ${OBJECTDIR}/_ext/1800792019/LfcUtimeCommand.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcUtimeCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1800792019
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1800792019/LfcUtimeCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1800792019/LfcUtimeCommand_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/LfcUtimeCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1800792019/LfcUtimeCommand.o ${OBJECTDIR}/_ext/1800792019/LfcUtimeCommand_nomain.o;\
	fi

${OBJECTDIR}/_ext/1781719998/LstatState_nomain.o: ${OBJECTDIR}/_ext/1781719998/LstatState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/LstatState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1781719998/LstatState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/LstatState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/LstatState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1781719998/LstatState.o ${OBJECTDIR}/_ext/1781719998/LstatState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1781719998/MkDirState_nomain.o: ${OBJECTDIR}/_ext/1781719998/MkDirState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/MkDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1781719998/MkDirState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/MkDirState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/MkDirState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1781719998/MkDirState.o ${OBJECTDIR}/_ext/1781719998/MkDirState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1781719998/PingDBState_nomain.o: ${OBJECTDIR}/_ext/1781719998/PingDBState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/PingDBState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1781719998/PingDBState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/PingDBState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/PingDBState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1781719998/PingDBState.o ${OBJECTDIR}/_ext/1781719998/PingDBState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1781719998/ReplicaCpDelRepState_nomain.o: ${OBJECTDIR}/_ext/1781719998/ReplicaCpDelRepState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ReplicaCpDelRepState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1781719998/ReplicaCpDelRepState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/ReplicaCpDelRepState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ReplicaCpDelRepState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1781719998/ReplicaCpDelRepState.o ${OBJECTDIR}/_ext/1781719998/ReplicaCpDelRepState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1781719998/ReplicaState_nomain.o: ${OBJECTDIR}/_ext/1781719998/ReplicaState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ReplicaState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1781719998/ReplicaState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/ReplicaState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ReplicaState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1781719998/ReplicaState.o ${OBJECTDIR}/_ext/1781719998/ReplicaState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1781719998/ServState_nomain.o: ${OBJECTDIR}/_ext/1781719998/ServState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ServState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1781719998/ServState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/ServState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/ServState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1781719998/ServState.o ${OBJECTDIR}/_ext/1781719998/ServState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1781719998/StartSessState_nomain.o: ${OBJECTDIR}/_ext/1781719998/StartSessState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/StartSessState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1781719998/StartSessState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/StartSessState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/StartSessState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1781719998/StartSessState.o ${OBJECTDIR}/_ext/1781719998/StartSessState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1781719998/UtimeState_nomain.o: ${OBJECTDIR}/_ext/1781719998/UtimeState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/UtimeState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1781719998
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1781719998/UtimeState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1781719998/UtimeState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/UtimeState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1781719998/UtimeState.o ${OBJECTDIR}/_ext/1781719998/UtimeState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1152981978/StartTransStateAA_nomain.o: ${OBJECTDIR}/_ext/1152981978/StartTransStateAA.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_aa_states/StartTransStateAA.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1152981978
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1152981978/StartTransStateAA.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1152981978/StartTransStateAA_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_aa_states/StartTransStateAA.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1152981978/StartTransStateAA.o ${OBJECTDIR}/_ext/1152981978/StartTransStateAA_nomain.o;\
	fi

${OBJECTDIR}/_ext/1396044971/StartTransState_nomain.o: ${OBJECTDIR}/_ext/1396044971/StartTransState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_cr_states/StartTransState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1396044971
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1396044971/StartTransState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1396044971/StartTransState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_cr_states/StartTransState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1396044971/StartTransState.o ${OBJECTDIR}/_ext/1396044971/StartTransState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1396044971/StartTransState2_nomain.o: ${OBJECTDIR}/_ext/1396044971/StartTransState2.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_cr_states/StartTransState2.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1396044971
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1396044971/StartTransState2.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1396044971/StartTransState2_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_cr_states/StartTransState2.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1396044971/StartTransState2.o ${OBJECTDIR}/_ext/1396044971/StartTransState2_nomain.o;\
	fi

${OBJECTDIR}/_ext/1541828867/DelAll_nomain.o: ${OBJECTDIR}/_ext/1541828867/DelAll.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelAll.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1541828867
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1541828867/DelAll.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1541828867/DelAll_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelAll.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1541828867/DelAll.o ${OBJECTDIR}/_ext/1541828867/DelAll_nomain.o;\
	fi

${OBJECTDIR}/_ext/1541828867/DelRemain_nomain.o: ${OBJECTDIR}/_ext/1541828867/DelRemain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelRemain.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1541828867
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1541828867/DelRemain.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1541828867/DelRemain_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelRemain.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1541828867/DelRemain.o ${OBJECTDIR}/_ext/1541828867/DelRemain_nomain.o;\
	fi

${OBJECTDIR}/_ext/1541828867/DelReplica_nomain.o: ${OBJECTDIR}/_ext/1541828867/DelReplica.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelReplica.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1541828867
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1541828867/DelReplica.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1541828867/DelReplica_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_del_states/DelReplica.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1541828867/DelReplica.o ${OBJECTDIR}/_ext/1541828867/DelReplica_nomain.o;\
	fi

${OBJECTDIR}/_ext/1616743893/BadReplicaState_nomain.o: ${OBJECTDIR}/_ext/1616743893/BadReplicaState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rep_states/BadReplicaState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1616743893
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1616743893/BadReplicaState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1616743893/BadReplicaState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rep_states/BadReplicaState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1616743893/BadReplicaState.o ${OBJECTDIR}/_ext/1616743893/BadReplicaState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1616743893/ReplicateStateTransaction_nomain.o: ${OBJECTDIR}/_ext/1616743893/ReplicateStateTransaction.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rep_states/ReplicateStateTransaction.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1616743893
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1616743893/ReplicateStateTransaction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1616743893/ReplicateStateTransaction_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rep_states/ReplicateStateTransaction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1616743893/ReplicateStateTransaction.o ${OBJECTDIR}/_ext/1616743893/ReplicateStateTransaction_nomain.o;\
	fi

${OBJECTDIR}/_ext/327138736/RmDirState_nomain.o: ${OBJECTDIR}/_ext/327138736/RmDirState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rm_dir/RmDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/327138736
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/327138736/RmDirState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/327138736/RmDirState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfc_rm_dir/RmDirState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/327138736/RmDirState.o ${OBJECTDIR}/_ext/327138736/RmDirState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1070216355/OpenDirRecursiveState_nomain.o: ${OBJECTDIR}/_ext/1070216355/OpenDirRecursiveState.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfs_ls_states/OpenDirRecursiveState.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1070216355
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1070216355/OpenDirRecursiveState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1070216355/OpenDirRecursiveState_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/analyzer2/states/lfs_ls_states/OpenDirRecursiveState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1070216355/OpenDirRecursiveState.o ${OBJECTDIR}/_ext/1070216355/OpenDirRecursiveState_nomain.o;\
	fi

${OBJECTDIR}/_ext/1273540945/Filter_nomain.o: ${OBJECTDIR}/_ext/1273540945/Filter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/Filter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1273540945
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1273540945/Filter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1273540945/Filter_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/filter/Filter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1273540945/Filter.o ${OBJECTDIR}/_ext/1273540945/Filter_nomain.o;\
	fi

${OBJECTDIR}/_ext/1208396726/CommandSorter_nomain.o: ${OBJECTDIR}/_ext/1208396726/CommandSorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/CommandSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1208396726/CommandSorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/CommandSorter_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/CommandSorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1208396726/CommandSorter.o ${OBJECTDIR}/_ext/1208396726/CommandSorter_nomain.o;\
	fi

${OBJECTDIR}/_ext/1208396726/FileSorter_nomain.o: ${OBJECTDIR}/_ext/1208396726/FileSorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/FileSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1208396726/FileSorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/FileSorter_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/FileSorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1208396726/FileSorter.o ${OBJECTDIR}/_ext/1208396726/FileSorter_nomain.o;\
	fi

${OBJECTDIR}/_ext/1208396726/SiteSorter_nomain.o: ${OBJECTDIR}/_ext/1208396726/SiteSorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/SiteSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1208396726/SiteSorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/SiteSorter_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/SiteSorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1208396726/SiteSorter.o ${OBJECTDIR}/_ext/1208396726/SiteSorter_nomain.o;\
	fi

${OBJECTDIR}/_ext/1208396726/Sorter_nomain.o: ${OBJECTDIR}/_ext/1208396726/Sorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/Sorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1208396726/Sorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/Sorter_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/Sorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1208396726/Sorter.o ${OBJECTDIR}/_ext/1208396726/Sorter_nomain.o;\
	fi

${OBJECTDIR}/_ext/1208396726/SuccessSorter_nomain.o: ${OBJECTDIR}/_ext/1208396726/SuccessSorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/SuccessSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1208396726/SuccessSorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/SuccessSorter_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/SuccessSorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1208396726/SuccessSorter.o ${OBJECTDIR}/_ext/1208396726/SuccessSorter_nomain.o;\
	fi

${OBJECTDIR}/_ext/1208396726/UserSorter_nomain.o: ${OBJECTDIR}/_ext/1208396726/UserSorter.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/UserSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1208396726
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1208396726/UserSorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1208396726/UserSorter_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/filter/sorters/UserSorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1208396726/UserSorter.o ${OBJECTDIR}/_ext/1208396726/UserSorter_nomain.o;\
	fi

${OBJECTDIR}/_ext/1723276753/Presenter_nomain.o: ${OBJECTDIR}/_ext/1723276753/Presenter.o /home/radek/NetBeansProjects/LFC_analyzer/presenter/Presenter.cpp 
	${MKDIR} -p ${OBJECTDIR}/_ext/1723276753
	@NMOUTPUT=`${NM} ${OBJECTDIR}/_ext/1723276753/Presenter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/_ext/1723276753/Presenter_nomain.o /home/radek/NetBeansProjects/LFC_analyzer/presenter/Presenter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/_ext/1723276753/Presenter.o ${OBJECTDIR}/_ext/1723276753/Presenter_nomain.o;\
	fi

${OBJECTDIR}/MockItems_nomain.o: ${OBJECTDIR}/MockItems.o MockItems.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MockItems.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/MockItems_nomain.o MockItems.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MockItems.o ${OBJECTDIR}/MockItems_nomain.o;\
	fi

${OBJECTDIR}/MockRows_nomain.o: ${OBJECTDIR}/MockRows.o MockRows.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MockRows.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/MockRows_nomain.o MockRows.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MockRows.o ${OBJECTDIR}/MockRows_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/Analyzer_nomain.o: ${OBJECTDIR}/analyzer2/Analyzer.o analyzer2/Analyzer.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/Analyzer.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/Analyzer_nomain.o analyzer2/Analyzer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/Analyzer.o ${OBJECTDIR}/analyzer2/Analyzer_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LFCCommand_nomain.o: ${OBJECTDIR}/analyzer2/LFCCommand.o analyzer2/LFCCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LFCCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LFCCommand_nomain.o analyzer2/LFCCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LFCCommand.o ${OBJECTDIR}/analyzer2/LFCCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcCommandTable_nomain.o: ${OBJECTDIR}/analyzer2/LfcCommandTable.o analyzer2/LfcCommandTable.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcCommandTable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcCommandTable_nomain.o analyzer2/LfcCommandTable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcCommandTable.o ${OBJECTDIR}/analyzer2/LfcCommandTable_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcCrCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcCrCommand.o analyzer2/LfcCrCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcCrCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcCrCommand_nomain.o analyzer2/LfcCrCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcCrCommand.o ${OBJECTDIR}/analyzer2/LfcCrCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcLsCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcLsCommand.o analyzer2/LfcLsCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcLsCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcLsCommand_nomain.o analyzer2/LfcLsCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcLsCommand.o ${OBJECTDIR}/analyzer2/LfcLsCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/State_nomain.o: ${OBJECTDIR}/analyzer2/states/State.o analyzer2/states/State.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/State.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/State_nomain.o analyzer2/states/State.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/State.o ${OBJECTDIR}/analyzer2/states/State_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState_nomain.o: ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o analyzer2/states/lfs_ls_states/OpenDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfs_ls_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState_nomain.o analyzer2/states/lfs_ls_states/OpenDirState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState_nomain.o;\
	fi

${OBJECTDIR}/filter/Counter_nomain.o: ${OBJECTDIR}/filter/Counter.o filter/Counter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filter/Counter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/Counter_nomain.o filter/Counter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filter/Counter.o ${OBJECTDIR}/filter/Counter_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lfc-analyzer

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
