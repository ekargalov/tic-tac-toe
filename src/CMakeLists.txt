# CMakeList.txt: проект CMake для tic-tac-toe; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (tic-tac-toe "tic-tac-toe.cpp" "tic-tac-toe.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET tic-tac-toe PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
