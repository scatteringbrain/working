# from book for Application Develop... 

# (1)
cmake_minimum_required(VERSION 3.16...3.27)
project(draft) #seems like it should be the folder name? 

# (2)
find_package(Geant4 REQUIRED ui_all vis_all)

# (3)
#include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# (4)
add_executable(solenoid1 solenoid1.cc ${sources} ${headers})
target_include_directories(solenoid1 PRIVATE include) # this causes errors? ---> no
target_link_libraries(solenoid1 ${Geant4_LIBRARIES})# problem is here .. 

# (5)
set(SOLENOID1_SCRIPTS
#solenoid.in
#solenoid.out
#init_vis.mac
#run1.mac
#run2.mac
#vis.mac
)
foreach(_script ${SOLENOID1_SCRIPTS})
configure_file(
${PROJECT_SOURCE_DIR}/${_script}
${PROJECT_BINARY_DIR}/${_script}
COPYONLY
)
endforeach()
