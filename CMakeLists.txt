# CMakeList.txt: EDDA 的 CMake 專案，在此包含來源及定義
# 專案專屬邏輯。
#
cmake_minimum_required (VERSION 3.17)

# 將來源新增到此專案的可執行檔。
add_executable (EDDA "EDDA.cpp" "io/load.h" "dataset/Grid.h" "distribution/Distribution.h" "dataset/DataSet.h")

# TODO: 新增測試，並視需要安裝目標。

SET(VTKm_DIR D:\\vtkm-build\\lib\\cmake\\vtkm-1.5)
#set_directory_properties( PROPERTIES COMPILE_DEFINITIONS "" )
find_package(VTKm REQUIRED)
include_directories(D:\\vtkm-build\\vtkm)
target_link_libraries(EDDA vtkm_worklet) 