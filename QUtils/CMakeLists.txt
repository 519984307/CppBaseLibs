cmake_minimum_required(VERSION 3.12)
project(QUtils VERSION 1.0.0 DESCRIPTION "Basic utilities")

add_compile_definitions(IS_BUILT_AS_LIBRARY=1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find required Qt5 or Qt6 dependencies
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network REQUIRED)

# Define the library target
add_library(QUtils SHARED src/QUtils.cpp)

target_link_libraries(QUtils PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)

# Set the include directories for users of this library
target_include_directories(QUtils PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

# Install rules
install(TARGETS QUtils
        EXPORT QUtilsConfig
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)

# Generate and install the package configuration
install(EXPORT QUtilsConfig
        NAMESPACE Base::
        DESTINATION cmake)