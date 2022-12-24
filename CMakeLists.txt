#cmake_minimum_required(VERSION 3.5)

#project(otus_cpp_task_7 LANGUAGES CXX)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(otus_cpp_task_7 main.cpp Commandes.h Commandes.cpp)

cmake_minimum_required(VERSION 3.2)

project(otus_cpp_task_7 VERSION 0.0 ${PATCH_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(version.h.in version.h)

add_executable(otus_cpp_task_7 main.cpp
    Commandes.cpp Commandes.h Observe.h Observe.cpp)

set_target_properties(otus_cpp_task_7 PROPERTIES
        CXX_STANDART 14
        CXX_STANDART_REQUIRED ON
        COMPILE_OPTION -Wpedantic -Wall -Wextra
        )

install(TARGETS otus_cpp_task_7 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# это,чтобы на почту приходило уведомление, собралось или нет, если проект большой, то полезно)))
set(CPACK_PACKAGE_CONTACT Alttaira@yandex.ru)

# тесты сделаю потом ко всем заданиям, когда до них доползу)))
# про тетсты помню, но пока не доползла(((
include(CPack)
