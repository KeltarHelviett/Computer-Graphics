cmake_minimum_required(VERSION 3.6)
project(CG)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(ImageMagick COMPONENTS Magick++)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Shader.cpp Shader.h ShaderProgram.cpp ShaderProgram.h Window.cpp Window.h Matrix4.cpp Matrix4.h Vector.cpp Vector.h gl_math.h Quaternion.cpp Quaternion.h gl_math.cpp Camera.cpp Camera.h EventHandler.cpp EventHandler.h Event.cpp Event.h KeyboardEventHandler.cpp KeyboardEventHandler.h CameraEventHandler.cpp CameraEventHandler.h MouseEventHandler.cpp MouseEventHandler.h MouseEventArgs.cpp MouseEventArgs.h Point.cpp Point.h Texture.cpp Texture.h)
add_executable(CG ${SOURCE_FILES})

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${ImageMagick_INCLUDE_DIRS})
target_link_libraries(CG ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES} ${ImageMagick_LIBRARIES})