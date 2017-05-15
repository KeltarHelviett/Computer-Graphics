cmake_minimum_required(VERSION 3.6)
project(CG)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLUT REQUIRED)
find_package(ImageMagick COMPONENTS Magick++)

SET(CMAKE_C_FLAGS_DEBUG "-D_DEBUG")
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Shader.cpp include/Shader.h src/ShaderProgram.cpp include/ShaderProgram.h src/Window.cpp include/Window.h src/Matrix4.cpp include/Matrix4.h include/Vector.h include/gl_math.h src/Quaternion.cpp include/Quaternion.h src/gl_math.cpp src/Camera.cpp include/Camera.h src/EventHandler.cpp include/EventHandler.h src/Event.cpp include/Event.h src/KeyboardEventHandler.cpp include/KeyboardEventHandler.h src/CameraEventHandler.cpp include/CameraEventHandler.h src/MouseEventHandler.cpp include/MouseEventHandler.h src/MouseEventArgs.cpp include/MouseEventArgs.h src/Point.cpp include/Point.h src/Texture.cpp include/Texture.h src/Light.cpp include/Light.h src/Model.cpp include/Model.h src/GameManager.cpp include/GameManager.h include/TestUtils.h src/TestUtils.cpp)
add_executable(CG ${SOURCE_FILES})

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${ImageMagick_INCLUDE_DIRS})
target_link_libraries(CG ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLEW_LIBRARIES} ${ImageMagick_LIBRARIES})