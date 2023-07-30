cmake_minimum_required(VERSION 3.12)
project(Utils VERSION 1.0.0 DESCRIPTION "Basic utilities")

add_compile_definitions(IS_BUILT_AS_LIBRARY=1)

find_package(Qt6 COMPONENTS Core Network REQUIRED)

# Define the library target
add_library(Utils SHARED src/Utils.cpp)

target_link_libraries(Utils PRIVATE Qt::Core Qt::Network)

# Set the include directories for users of this library
target_include_directories(Utils PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

# Install rules
install(TARGETS Utils
        EXPORT UtilsConfig
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib)

install(DIRECTORY include/ DESTINATION include)

# Generate and install the package configuration
install(EXPORT UtilsConfig
        NAMESPACE Base::
        DESTINATION cmake)