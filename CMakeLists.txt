cmake_minimum_required(VERSION 3.5)

PROJECT(NPSANA)

SET(NPSANA_LIB npsana)
SET(PROJ_DIR ${PROJECT_SOURCE_DIR})

SET(NPSANA_ROOTMAP ${CMAKE_CURRENT_BINARY_DIR}/libnpsana_rdict.pcm ${CMAKE_CURRENT_BINARY_DIR}/libnpsana.rootmap)

IF( NOT CMAKE_BUILD_TYPE )
    SET( CMAKE_BUILD_TYPE Debug )
ENDIF()

list(APPEND CMAKE_PREFIX_PATH $ENV{ROOTSYS})

# ROOT
FIND_PACKAGE(ROOT 6.0.0 REQUIRED)
INCLUDE(${ROOT_USE_FILE})

INCLUDE_DIRECTORIES(${PROJ_DIR}/include)
SET(SRC_DIR ${PROJ_DIR}/source)

SET( CMAKE_CXX_FLAGS "-g -Wall -std=c++14 -fPIC -Wno-misleading-indentation" )

ROOT_GENERATE_DICTIONARY(G__npsana TCaloBase.h TCaloBlock.h TCaloCluster.h TCaloGeometry.h TCaloCalibration.h TWaveform.h LINKDEF include/TCaloBaseLinkDef.h)

ADD_LIBRARY(${NPSANA_LIB} SHARED source/TCaloBase.cc source/TCaloBlock.cc source/TCaloCluster.cc source/TCaloGeometry.cc source/TWaveform.cc G__npsana.cxx)

TARGET_LINK_LIBRARIES(${NPSANA_LIB} ${ROOT_LIBRARIES})

INSTALL(TARGETS ${NPSANA_LIB} DESTINATION lib)
INSTALL(FILES ${NPSANA_ROOTMAP} DESTINATION lib)

