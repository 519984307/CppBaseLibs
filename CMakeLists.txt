cmake_minimum_required(VERSION 3.12)

project(Base VERSION 1.0.0 DESCRIPTION "Base repository containing reusable packages")

# Optionally, set a custom install directory for the packages
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

# Include subdirectories for each component
add_subdirectory(QUtils)
# add_subdirectory(another_component) - Add other components if needed

####################################################################################

# Export configuration
include(CMakePackageConfigHelpers)

# Generate the package configuration file
configure_package_config_file(
        BaseConfig.cmake.in
        ${CMAKE_BINARY_DIR}/BaseConfig.cmake
        INSTALL_DESTINATION cmake
)

# Install the package configuration file
install(
        FILES ${CMAKE_BINARY_DIR}/BaseConfig.cmake
        DESTINATION cmake
)
