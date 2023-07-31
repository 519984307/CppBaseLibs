# Qt Base Libs

## How to build
The following steps will build base libs and will generate the relevant CMake config 
files to be used within find_package()

```cmake
1. mkdir build
2. cd build
3. cmake -G "MinGW Makefiles" -DCMAKE_PREFIX_PATH="C:/Qt/6.4.1/mingw_64/lib/cmake" ..
4. cmake --build . --target install
```

## How to use generated files in CMake projects
```cmake
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/libs/base/install")
find_package(Base COMPONENTS QUtils REQUIRED)
...
target_link_libraries(BaseLibsTest PUBLIC Qt6::Core Base::QUtils)
```