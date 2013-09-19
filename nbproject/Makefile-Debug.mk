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
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/MockCommands.o \
	${OBJECTDIR}/MockItems.o \
	${OBJECTDIR}/MockRows.o \
	${OBJECTDIR}/analyzer2/Analyzer.o \
	${OBJECTDIR}/analyzer2/Information.o \
	${OBJECTDIR}/analyzer2/LFCCommand.o \
	${OBJECTDIR}/analyzer2/LfcAACommand.o \
	${OBJECTDIR}/analyzer2/LfcCommandTable.o \
	${OBJECTDIR}/analyzer2/LfcCpCommand.o \
	${OBJECTDIR}/analyzer2/LfcCrCommand.o \
	${OBJECTDIR}/analyzer2/LfcDelReplicaCommand.o \
	${OBJECTDIR}/analyzer2/LfcLrCommand.o \
	${OBJECTDIR}/analyzer2/LfcLsCommand.o \
	${OBJECTDIR}/analyzer2/LfcMkdirCommand.o \
	${OBJECTDIR}/analyzer2/LfcPingDBCommand.o \
	${OBJECTDIR}/analyzer2/LfcRepCommand.o \
	${OBJECTDIR}/analyzer2/LfcRmDirCommand.o \
	${OBJECTDIR}/analyzer2/LfcServCommand.o \
	${OBJECTDIR}/analyzer2/LfcUtimeCommand.o \
	${OBJECTDIR}/analyzer2/states/LstatState.o \
	${OBJECTDIR}/analyzer2/states/MkDirState.o \
	${OBJECTDIR}/analyzer2/states/PingDBState.o \
	${OBJECTDIR}/analyzer2/states/ReplicaCpDelRepState.o \
	${OBJECTDIR}/analyzer2/states/ReplicaState.o \
	${OBJECTDIR}/analyzer2/states/ServState.o \
	${OBJECTDIR}/analyzer2/states/StartSessState.o \
	${OBJECTDIR}/analyzer2/states/State.o \
	${OBJECTDIR}/analyzer2/states/UtimeState.o \
	${OBJECTDIR}/analyzer2/states/lfc_aa_states/StartTransStateAA.o \
	${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState.o \
	${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState2.o \
	${OBJECTDIR}/analyzer2/states/lfc_del_states/DelAll.o \
	${OBJECTDIR}/analyzer2/states/lfc_del_states/DelRemain.o \
	${OBJECTDIR}/analyzer2/states/lfc_del_states/DelReplica.o \
	${OBJECTDIR}/analyzer2/states/lfc_rep_states/BadReplicaState.o \
	${OBJECTDIR}/analyzer2/states/lfc_rep_states/ReplicateStateTransaction.o \
	${OBJECTDIR}/analyzer2/states/lfc_rm_dir/RmDirState.o \
	${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirRecursiveState.o \
	${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o \
	${OBJECTDIR}/filter/Counter.o \
	${OBJECTDIR}/filter/Filter.o \
	${OBJECTDIR}/filter/sorters/CommandSorter.o \
	${OBJECTDIR}/filter/sorters/FileSorter.o \
	${OBJECTDIR}/filter/sorters/SiteSorter.o \
	${OBJECTDIR}/filter/sorters/Sorter.o \
	${OBJECTDIR}/filter/sorters/SuccessSorter.o \
	${OBJECTDIR}/filter/sorters/UserSorter.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/presenter/Presenter.o

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
CCFLAGS=-Wall -O2
CXXFLAGS=-Wall -O2

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f5

${TESTDIR}/TestFiles/f5: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f5 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/MockCommands.o: MockCommands.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/MockCommands.o MockCommands.cpp

${OBJECTDIR}/MockItems.o: MockItems.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/MockItems.o MockItems.cpp

${OBJECTDIR}/MockRows.o: MockRows.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/MockRows.o MockRows.cpp

${OBJECTDIR}/analyzer2/Analyzer.o: analyzer2/Analyzer.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/Analyzer.o analyzer2/Analyzer.cpp

${OBJECTDIR}/analyzer2/Information.o: analyzer2/Information.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/Information.o analyzer2/Information.cpp

${OBJECTDIR}/analyzer2/LFCCommand.o: analyzer2/LFCCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LFCCommand.o analyzer2/LFCCommand.cpp

${OBJECTDIR}/analyzer2/LfcAACommand.o: analyzer2/LfcAACommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcAACommand.o analyzer2/LfcAACommand.cpp

${OBJECTDIR}/analyzer2/LfcCommandTable.o: analyzer2/LfcCommandTable.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcCommandTable.o analyzer2/LfcCommandTable.cpp

${OBJECTDIR}/analyzer2/LfcCpCommand.o: analyzer2/LfcCpCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcCpCommand.o analyzer2/LfcCpCommand.cpp

${OBJECTDIR}/analyzer2/LfcCrCommand.o: analyzer2/LfcCrCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcCrCommand.o analyzer2/LfcCrCommand.cpp

${OBJECTDIR}/analyzer2/LfcDelReplicaCommand.o: analyzer2/LfcDelReplicaCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcDelReplicaCommand.o analyzer2/LfcDelReplicaCommand.cpp

${OBJECTDIR}/analyzer2/LfcLrCommand.o: analyzer2/LfcLrCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcLrCommand.o analyzer2/LfcLrCommand.cpp

${OBJECTDIR}/analyzer2/LfcLsCommand.o: analyzer2/LfcLsCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcLsCommand.o analyzer2/LfcLsCommand.cpp

${OBJECTDIR}/analyzer2/LfcMkdirCommand.o: analyzer2/LfcMkdirCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcMkdirCommand.o analyzer2/LfcMkdirCommand.cpp

${OBJECTDIR}/analyzer2/LfcPingDBCommand.o: analyzer2/LfcPingDBCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcPingDBCommand.o analyzer2/LfcPingDBCommand.cpp

${OBJECTDIR}/analyzer2/LfcRepCommand.o: analyzer2/LfcRepCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcRepCommand.o analyzer2/LfcRepCommand.cpp

${OBJECTDIR}/analyzer2/LfcRmDirCommand.o: analyzer2/LfcRmDirCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcRmDirCommand.o analyzer2/LfcRmDirCommand.cpp

${OBJECTDIR}/analyzer2/LfcServCommand.o: analyzer2/LfcServCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcServCommand.o analyzer2/LfcServCommand.cpp

${OBJECTDIR}/analyzer2/LfcUtimeCommand.o: analyzer2/LfcUtimeCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcUtimeCommand.o analyzer2/LfcUtimeCommand.cpp

${OBJECTDIR}/analyzer2/states/LstatState.o: analyzer2/states/LstatState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/LstatState.o analyzer2/states/LstatState.cpp

${OBJECTDIR}/analyzer2/states/MkDirState.o: analyzer2/states/MkDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/MkDirState.o analyzer2/states/MkDirState.cpp

${OBJECTDIR}/analyzer2/states/PingDBState.o: analyzer2/states/PingDBState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/PingDBState.o analyzer2/states/PingDBState.cpp

${OBJECTDIR}/analyzer2/states/ReplicaCpDelRepState.o: analyzer2/states/ReplicaCpDelRepState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/ReplicaCpDelRepState.o analyzer2/states/ReplicaCpDelRepState.cpp

${OBJECTDIR}/analyzer2/states/ReplicaState.o: analyzer2/states/ReplicaState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/ReplicaState.o analyzer2/states/ReplicaState.cpp

${OBJECTDIR}/analyzer2/states/ServState.o: analyzer2/states/ServState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/ServState.o analyzer2/states/ServState.cpp

${OBJECTDIR}/analyzer2/states/StartSessState.o: analyzer2/states/StartSessState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/StartSessState.o analyzer2/states/StartSessState.cpp

${OBJECTDIR}/analyzer2/states/State.o: analyzer2/states/State.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/State.o analyzer2/states/State.cpp

${OBJECTDIR}/analyzer2/states/UtimeState.o: analyzer2/states/UtimeState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/UtimeState.o analyzer2/states/UtimeState.cpp

${OBJECTDIR}/analyzer2/states/lfc_aa_states/StartTransStateAA.o: analyzer2/states/lfc_aa_states/StartTransStateAA.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_aa_states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_aa_states/StartTransStateAA.o analyzer2/states/lfc_aa_states/StartTransStateAA.cpp

${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState.o: analyzer2/states/lfc_cr_states/StartTransState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_cr_states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState.o analyzer2/states/lfc_cr_states/StartTransState.cpp

${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState2.o: analyzer2/states/lfc_cr_states/StartTransState2.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_cr_states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState2.o analyzer2/states/lfc_cr_states/StartTransState2.cpp

${OBJECTDIR}/analyzer2/states/lfc_del_states/DelAll.o: analyzer2/states/lfc_del_states/DelAll.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_del_states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelAll.o analyzer2/states/lfc_del_states/DelAll.cpp

${OBJECTDIR}/analyzer2/states/lfc_del_states/DelRemain.o: analyzer2/states/lfc_del_states/DelRemain.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_del_states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelRemain.o analyzer2/states/lfc_del_states/DelRemain.cpp

${OBJECTDIR}/analyzer2/states/lfc_del_states/DelReplica.o: analyzer2/states/lfc_del_states/DelReplica.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_del_states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelReplica.o analyzer2/states/lfc_del_states/DelReplica.cpp

${OBJECTDIR}/analyzer2/states/lfc_rep_states/BadReplicaState.o: analyzer2/states/lfc_rep_states/BadReplicaState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_rep_states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_rep_states/BadReplicaState.o analyzer2/states/lfc_rep_states/BadReplicaState.cpp

${OBJECTDIR}/analyzer2/states/lfc_rep_states/ReplicateStateTransaction.o: analyzer2/states/lfc_rep_states/ReplicateStateTransaction.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_rep_states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_rep_states/ReplicateStateTransaction.o analyzer2/states/lfc_rep_states/ReplicateStateTransaction.cpp

${OBJECTDIR}/analyzer2/states/lfc_rm_dir/RmDirState.o: analyzer2/states/lfc_rm_dir/RmDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_rm_dir
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_rm_dir/RmDirState.o analyzer2/states/lfc_rm_dir/RmDirState.cpp

${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirRecursiveState.o: analyzer2/states/lfs_ls_states/OpenDirRecursiveState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfs_ls_states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirRecursiveState.o analyzer2/states/lfs_ls_states/OpenDirRecursiveState.cpp

${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o: analyzer2/states/lfs_ls_states/OpenDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfs_ls_states
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o analyzer2/states/lfs_ls_states/OpenDirState.cpp

${OBJECTDIR}/filter/Counter.o: filter/Counter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/Counter.o filter/Counter.cpp

${OBJECTDIR}/filter/Filter.o: filter/Filter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/Filter.o filter/Filter.cpp

${OBJECTDIR}/filter/sorters/CommandSorter.o: filter/sorters/CommandSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/CommandSorter.o filter/sorters/CommandSorter.cpp

${OBJECTDIR}/filter/sorters/FileSorter.o: filter/sorters/FileSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/FileSorter.o filter/sorters/FileSorter.cpp

${OBJECTDIR}/filter/sorters/SiteSorter.o: filter/sorters/SiteSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/SiteSorter.o filter/sorters/SiteSorter.cpp

${OBJECTDIR}/filter/sorters/Sorter.o: filter/sorters/Sorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/Sorter.o filter/sorters/Sorter.cpp

${OBJECTDIR}/filter/sorters/SuccessSorter.o: filter/sorters/SuccessSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/SuccessSorter.o filter/sorters/SuccessSorter.cpp

${OBJECTDIR}/filter/sorters/UserSorter.o: filter/sorters/UserSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/UserSorter.o filter/sorters/UserSorter.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/presenter/Presenter.o: presenter/Presenter.cpp 
	${MKDIR} -p ${OBJECTDIR}/presenter
	${RM} $@.d
	$(COMPILE.cc) -g -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/presenter/Presenter.o presenter/Presenter.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/AnalyzerRunner.o ${TESTDIR}/tests/AnalyzerTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f3: ${TESTDIR}/filter/tests/FilterRunner.o ${TESTDIR}/filter/tests/FilterTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS} `cppunit-config --libs`   

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/ParserRunner.o ${TESTDIR}/tests/ParserTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs` `cppunit-config --libs`   

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/PresenterRunner.o ${TESTDIR}/tests/PresenterTests.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS} `cppunit-config --libs` `cppunit-config --libs`   


${TESTDIR}/tests/AnalyzerRunner.o: tests/AnalyzerRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/AnalyzerRunner.o tests/AnalyzerRunner.cpp


${TESTDIR}/tests/AnalyzerTest.o: tests/AnalyzerTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/AnalyzerTest.o tests/AnalyzerTest.cpp


${TESTDIR}/filter/tests/FilterRunner.o: filter/tests/FilterRunner.cpp 
	${MKDIR} -p ${TESTDIR}/filter/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/filter/tests/FilterRunner.o filter/tests/FilterRunner.cpp


${TESTDIR}/filter/tests/FilterTest.o: filter/tests/FilterTest.cpp 
	${MKDIR} -p ${TESTDIR}/filter/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/filter/tests/FilterTest.o filter/tests/FilterTest.cpp


${TESTDIR}/tests/ParserRunner.o: tests/ParserRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/ParserRunner.o tests/ParserRunner.cpp


${TESTDIR}/tests/ParserTests.o: tests/ParserTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/ParserTests.o tests/ParserTests.cpp


${TESTDIR}/tests/PresenterRunner.o: tests/PresenterRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/PresenterRunner.o tests/PresenterRunner.cpp


${TESTDIR}/tests/PresenterTests.o: tests/PresenterTests.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. `cppunit-config --cflags` -MMD -MP -MF $@.d -o ${TESTDIR}/tests/PresenterTests.o tests/PresenterTests.cpp


${OBJECTDIR}/MockCommands_nomain.o: ${OBJECTDIR}/MockCommands.o MockCommands.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MockCommands.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/MockCommands_nomain.o MockCommands.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/MockCommands.o ${OBJECTDIR}/MockCommands_nomain.o;\
	fi

${OBJECTDIR}/MockItems_nomain.o: ${OBJECTDIR}/MockItems.o MockItems.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/MockItems.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/MockItems_nomain.o MockItems.cpp;\
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
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/MockRows_nomain.o MockRows.cpp;\
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
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/Analyzer_nomain.o analyzer2/Analyzer.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/Analyzer.o ${OBJECTDIR}/analyzer2/Analyzer_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/Information_nomain.o: ${OBJECTDIR}/analyzer2/Information.o analyzer2/Information.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/Information.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/Information_nomain.o analyzer2/Information.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/Information.o ${OBJECTDIR}/analyzer2/Information_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LFCCommand_nomain.o: ${OBJECTDIR}/analyzer2/LFCCommand.o analyzer2/LFCCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LFCCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LFCCommand_nomain.o analyzer2/LFCCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LFCCommand.o ${OBJECTDIR}/analyzer2/LFCCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcAACommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcAACommand.o analyzer2/LfcAACommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcAACommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcAACommand_nomain.o analyzer2/LfcAACommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcAACommand.o ${OBJECTDIR}/analyzer2/LfcAACommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcCommandTable_nomain.o: ${OBJECTDIR}/analyzer2/LfcCommandTable.o analyzer2/LfcCommandTable.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcCommandTable.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcCommandTable_nomain.o analyzer2/LfcCommandTable.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcCommandTable.o ${OBJECTDIR}/analyzer2/LfcCommandTable_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcCpCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcCpCommand.o analyzer2/LfcCpCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcCpCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcCpCommand_nomain.o analyzer2/LfcCpCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcCpCommand.o ${OBJECTDIR}/analyzer2/LfcCpCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcCrCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcCrCommand.o analyzer2/LfcCrCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcCrCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcCrCommand_nomain.o analyzer2/LfcCrCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcCrCommand.o ${OBJECTDIR}/analyzer2/LfcCrCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcDelReplicaCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcDelReplicaCommand.o analyzer2/LfcDelReplicaCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcDelReplicaCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcDelReplicaCommand_nomain.o analyzer2/LfcDelReplicaCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcDelReplicaCommand.o ${OBJECTDIR}/analyzer2/LfcDelReplicaCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcLrCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcLrCommand.o analyzer2/LfcLrCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcLrCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcLrCommand_nomain.o analyzer2/LfcLrCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcLrCommand.o ${OBJECTDIR}/analyzer2/LfcLrCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcLsCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcLsCommand.o analyzer2/LfcLsCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcLsCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcLsCommand_nomain.o analyzer2/LfcLsCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcLsCommand.o ${OBJECTDIR}/analyzer2/LfcLsCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcMkdirCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcMkdirCommand.o analyzer2/LfcMkdirCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcMkdirCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcMkdirCommand_nomain.o analyzer2/LfcMkdirCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcMkdirCommand.o ${OBJECTDIR}/analyzer2/LfcMkdirCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcPingDBCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcPingDBCommand.o analyzer2/LfcPingDBCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcPingDBCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcPingDBCommand_nomain.o analyzer2/LfcPingDBCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcPingDBCommand.o ${OBJECTDIR}/analyzer2/LfcPingDBCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcRepCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcRepCommand.o analyzer2/LfcRepCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcRepCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcRepCommand_nomain.o analyzer2/LfcRepCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcRepCommand.o ${OBJECTDIR}/analyzer2/LfcRepCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcRmDirCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcRmDirCommand.o analyzer2/LfcRmDirCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcRmDirCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcRmDirCommand_nomain.o analyzer2/LfcRmDirCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcRmDirCommand.o ${OBJECTDIR}/analyzer2/LfcRmDirCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcServCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcServCommand.o analyzer2/LfcServCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcServCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcServCommand_nomain.o analyzer2/LfcServCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcServCommand.o ${OBJECTDIR}/analyzer2/LfcServCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/LfcUtimeCommand_nomain.o: ${OBJECTDIR}/analyzer2/LfcUtimeCommand.o analyzer2/LfcUtimeCommand.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/LfcUtimeCommand.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/LfcUtimeCommand_nomain.o analyzer2/LfcUtimeCommand.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/LfcUtimeCommand.o ${OBJECTDIR}/analyzer2/LfcUtimeCommand_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/LstatState_nomain.o: ${OBJECTDIR}/analyzer2/states/LstatState.o analyzer2/states/LstatState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/LstatState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/LstatState_nomain.o analyzer2/states/LstatState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/LstatState.o ${OBJECTDIR}/analyzer2/states/LstatState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/MkDirState_nomain.o: ${OBJECTDIR}/analyzer2/states/MkDirState.o analyzer2/states/MkDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/MkDirState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/MkDirState_nomain.o analyzer2/states/MkDirState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/MkDirState.o ${OBJECTDIR}/analyzer2/states/MkDirState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/PingDBState_nomain.o: ${OBJECTDIR}/analyzer2/states/PingDBState.o analyzer2/states/PingDBState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/PingDBState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/PingDBState_nomain.o analyzer2/states/PingDBState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/PingDBState.o ${OBJECTDIR}/analyzer2/states/PingDBState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/ReplicaCpDelRepState_nomain.o: ${OBJECTDIR}/analyzer2/states/ReplicaCpDelRepState.o analyzer2/states/ReplicaCpDelRepState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/ReplicaCpDelRepState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/ReplicaCpDelRepState_nomain.o analyzer2/states/ReplicaCpDelRepState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/ReplicaCpDelRepState.o ${OBJECTDIR}/analyzer2/states/ReplicaCpDelRepState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/ReplicaState_nomain.o: ${OBJECTDIR}/analyzer2/states/ReplicaState.o analyzer2/states/ReplicaState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/ReplicaState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/ReplicaState_nomain.o analyzer2/states/ReplicaState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/ReplicaState.o ${OBJECTDIR}/analyzer2/states/ReplicaState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/ServState_nomain.o: ${OBJECTDIR}/analyzer2/states/ServState.o analyzer2/states/ServState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/ServState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/ServState_nomain.o analyzer2/states/ServState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/ServState.o ${OBJECTDIR}/analyzer2/states/ServState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/StartSessState_nomain.o: ${OBJECTDIR}/analyzer2/states/StartSessState.o analyzer2/states/StartSessState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/StartSessState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/StartSessState_nomain.o analyzer2/states/StartSessState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/StartSessState.o ${OBJECTDIR}/analyzer2/states/StartSessState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/State_nomain.o: ${OBJECTDIR}/analyzer2/states/State.o analyzer2/states/State.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/State.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/State_nomain.o analyzer2/states/State.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/State.o ${OBJECTDIR}/analyzer2/states/State_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/UtimeState_nomain.o: ${OBJECTDIR}/analyzer2/states/UtimeState.o analyzer2/states/UtimeState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/UtimeState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/UtimeState_nomain.o analyzer2/states/UtimeState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/UtimeState.o ${OBJECTDIR}/analyzer2/states/UtimeState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfc_aa_states/StartTransStateAA_nomain.o: ${OBJECTDIR}/analyzer2/states/lfc_aa_states/StartTransStateAA.o analyzer2/states/lfc_aa_states/StartTransStateAA.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_aa_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfc_aa_states/StartTransStateAA.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_aa_states/StartTransStateAA_nomain.o analyzer2/states/lfc_aa_states/StartTransStateAA.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfc_aa_states/StartTransStateAA.o ${OBJECTDIR}/analyzer2/states/lfc_aa_states/StartTransStateAA_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState_nomain.o: ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState.o analyzer2/states/lfc_cr_states/StartTransState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_cr_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState_nomain.o analyzer2/states/lfc_cr_states/StartTransState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState.o ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState2_nomain.o: ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState2.o analyzer2/states/lfc_cr_states/StartTransState2.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_cr_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState2.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState2_nomain.o analyzer2/states/lfc_cr_states/StartTransState2.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState2.o ${OBJECTDIR}/analyzer2/states/lfc_cr_states/StartTransState2_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfc_del_states/DelAll_nomain.o: ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelAll.o analyzer2/states/lfc_del_states/DelAll.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_del_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelAll.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelAll_nomain.o analyzer2/states/lfc_del_states/DelAll.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelAll.o ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelAll_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfc_del_states/DelRemain_nomain.o: ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelRemain.o analyzer2/states/lfc_del_states/DelRemain.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_del_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelRemain.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelRemain_nomain.o analyzer2/states/lfc_del_states/DelRemain.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelRemain.o ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelRemain_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfc_del_states/DelReplica_nomain.o: ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelReplica.o analyzer2/states/lfc_del_states/DelReplica.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_del_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelReplica.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelReplica_nomain.o analyzer2/states/lfc_del_states/DelReplica.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelReplica.o ${OBJECTDIR}/analyzer2/states/lfc_del_states/DelReplica_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfc_rep_states/BadReplicaState_nomain.o: ${OBJECTDIR}/analyzer2/states/lfc_rep_states/BadReplicaState.o analyzer2/states/lfc_rep_states/BadReplicaState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_rep_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfc_rep_states/BadReplicaState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_rep_states/BadReplicaState_nomain.o analyzer2/states/lfc_rep_states/BadReplicaState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfc_rep_states/BadReplicaState.o ${OBJECTDIR}/analyzer2/states/lfc_rep_states/BadReplicaState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfc_rep_states/ReplicateStateTransaction_nomain.o: ${OBJECTDIR}/analyzer2/states/lfc_rep_states/ReplicateStateTransaction.o analyzer2/states/lfc_rep_states/ReplicateStateTransaction.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_rep_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfc_rep_states/ReplicateStateTransaction.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_rep_states/ReplicateStateTransaction_nomain.o analyzer2/states/lfc_rep_states/ReplicateStateTransaction.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfc_rep_states/ReplicateStateTransaction.o ${OBJECTDIR}/analyzer2/states/lfc_rep_states/ReplicateStateTransaction_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfc_rm_dir/RmDirState_nomain.o: ${OBJECTDIR}/analyzer2/states/lfc_rm_dir/RmDirState.o analyzer2/states/lfc_rm_dir/RmDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfc_rm_dir
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfc_rm_dir/RmDirState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfc_rm_dir/RmDirState_nomain.o analyzer2/states/lfc_rm_dir/RmDirState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfc_rm_dir/RmDirState.o ${OBJECTDIR}/analyzer2/states/lfc_rm_dir/RmDirState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirRecursiveState_nomain.o: ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirRecursiveState.o analyzer2/states/lfs_ls_states/OpenDirRecursiveState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfs_ls_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirRecursiveState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirRecursiveState_nomain.o analyzer2/states/lfs_ls_states/OpenDirRecursiveState.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirRecursiveState.o ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirRecursiveState_nomain.o;\
	fi

${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState_nomain.o: ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o analyzer2/states/lfs_ls_states/OpenDirState.cpp 
	${MKDIR} -p ${OBJECTDIR}/analyzer2/states/lfs_ls_states
	@NMOUTPUT=`${NM} ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/analyzer2/states/lfs_ls_states/OpenDirState_nomain.o analyzer2/states/lfs_ls_states/OpenDirState.cpp;\
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
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/Counter_nomain.o filter/Counter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filter/Counter.o ${OBJECTDIR}/filter/Counter_nomain.o;\
	fi

${OBJECTDIR}/filter/Filter_nomain.o: ${OBJECTDIR}/filter/Filter.o filter/Filter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filter/Filter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/Filter_nomain.o filter/Filter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filter/Filter.o ${OBJECTDIR}/filter/Filter_nomain.o;\
	fi

${OBJECTDIR}/filter/sorters/CommandSorter_nomain.o: ${OBJECTDIR}/filter/sorters/CommandSorter.o filter/sorters/CommandSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filter/sorters/CommandSorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/CommandSorter_nomain.o filter/sorters/CommandSorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filter/sorters/CommandSorter.o ${OBJECTDIR}/filter/sorters/CommandSorter_nomain.o;\
	fi

${OBJECTDIR}/filter/sorters/FileSorter_nomain.o: ${OBJECTDIR}/filter/sorters/FileSorter.o filter/sorters/FileSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filter/sorters/FileSorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/FileSorter_nomain.o filter/sorters/FileSorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filter/sorters/FileSorter.o ${OBJECTDIR}/filter/sorters/FileSorter_nomain.o;\
	fi

${OBJECTDIR}/filter/sorters/SiteSorter_nomain.o: ${OBJECTDIR}/filter/sorters/SiteSorter.o filter/sorters/SiteSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filter/sorters/SiteSorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/SiteSorter_nomain.o filter/sorters/SiteSorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filter/sorters/SiteSorter.o ${OBJECTDIR}/filter/sorters/SiteSorter_nomain.o;\
	fi

${OBJECTDIR}/filter/sorters/Sorter_nomain.o: ${OBJECTDIR}/filter/sorters/Sorter.o filter/sorters/Sorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filter/sorters/Sorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/Sorter_nomain.o filter/sorters/Sorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filter/sorters/Sorter.o ${OBJECTDIR}/filter/sorters/Sorter_nomain.o;\
	fi

${OBJECTDIR}/filter/sorters/SuccessSorter_nomain.o: ${OBJECTDIR}/filter/sorters/SuccessSorter.o filter/sorters/SuccessSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filter/sorters/SuccessSorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/SuccessSorter_nomain.o filter/sorters/SuccessSorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filter/sorters/SuccessSorter.o ${OBJECTDIR}/filter/sorters/SuccessSorter_nomain.o;\
	fi

${OBJECTDIR}/filter/sorters/UserSorter_nomain.o: ${OBJECTDIR}/filter/sorters/UserSorter.o filter/sorters/UserSorter.cpp 
	${MKDIR} -p ${OBJECTDIR}/filter/sorters
	@NMOUTPUT=`${NM} ${OBJECTDIR}/filter/sorters/UserSorter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/filter/sorters/UserSorter_nomain.o filter/sorters/UserSorter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/filter/sorters/UserSorter.o ${OBJECTDIR}/filter/sorters/UserSorter_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/presenter/Presenter_nomain.o: ${OBJECTDIR}/presenter/Presenter.o presenter/Presenter.cpp 
	${MKDIR} -p ${OBJECTDIR}/presenter
	@NMOUTPUT=`${NM} ${OBJECTDIR}/presenter/Presenter.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/presenter/Presenter_nomain.o presenter/Presenter.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/presenter/Presenter.o ${OBJECTDIR}/presenter/Presenter_nomain.o;\
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
	${RM} ${TESTDIR}/TestFiles/f5

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
