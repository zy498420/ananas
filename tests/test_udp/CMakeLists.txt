INCLUDE(${PROJECT_SOURCE_DIR}/CMakeCommon)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})

ADD_EXECUTABLE(client_udptest TestClient.cc)
ADD_EXECUTABLE(server_udptest TestServer.cc)

SET(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)

TARGET_LINK_LIBRARIES(client_udptest ananas)
TARGET_LINK_LIBRARIES(server_udptest ananas)

ADD_DEPENDENCIES(client_udptest ananas)
ADD_DEPENDENCIES(server_udptest ananas)

