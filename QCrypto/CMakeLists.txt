cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME QCrypto)
project(${PROJECT_NAME} VERSION 1.0.0 DESCRIPTION "Basic crypto library")

add_compile_definitions(IS_BUILT_AS_LIBRARY=1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find required Qt5 or Qt6 dependencies
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network REQUIRED)

# Define the library target - SHARED by default
if(NOT DEFINED QBASE_LIB_TYPE)
    set(QBASE_LIB_TYPE SHARED)
endif()
add_library(${PROJECT_NAME} ${QBASE_LIB_TYPE}
        src/Hash.cpp
        src/X509Certificate.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)
target_include_directories(${PROJECT_NAME} PRIVATE include/${PROJECT_NAME})

# Set the include directories for users of this library
target_include_directories(${PROJECT_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

# Install rules
install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME}Config
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)

# Generate and install the package configuration
install(EXPORT ${PROJECT_NAME}Config
        NAMESPACE Base::
        DESTINATION cmake)