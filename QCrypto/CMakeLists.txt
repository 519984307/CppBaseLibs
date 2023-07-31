cmake_minimum_required(VERSION 3.12)
project(QCrypto VERSION 1.0.0 DESCRIPTION "Basic crypto library")

add_compile_definitions(IS_BUILT_AS_LIBRARY=1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Find required Qt5 or Qt6 dependencies
find_package(QT NAMES Qt6 Qt5)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Network REQUIRED)

# Define the library target
add_library(QCrypto SHARED
        src/Hash.cpp
        src/X509Certificate.cpp)

target_link_libraries(QCrypto PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Network)
target_include_directories(QCrypto PRIVATE include/QCrypto)

# Set the include directories for users of this library
target_include_directories(QCrypto PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

# Install rules
install(TARGETS QCrypto
        EXPORT QCryptoConfig
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)

# Generate and install the package configuration
install(EXPORT QCryptoConfig
        NAMESPACE Base::
        DESTINATION cmake)