# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Uni/4. Semester/cpp-game/cmake-build-release/_deps/box2d-src"
  "D:/Uni/4. Semester/cpp-game/cmake-build-release/_deps/box2d-build"
  "D:/Uni/4. Semester/cpp-game/cmake-build-release/_deps/box2d-subbuild/box2d-populate-prefix"
  "D:/Uni/4. Semester/cpp-game/cmake-build-release/_deps/box2d-subbuild/box2d-populate-prefix/tmp"
  "D:/Uni/4. Semester/cpp-game/cmake-build-release/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp"
  "D:/Uni/4. Semester/cpp-game/cmake-build-release/_deps/box2d-subbuild/box2d-populate-prefix/src"
  "D:/Uni/4. Semester/cpp-game/cmake-build-release/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Uni/4. Semester/cpp-game/cmake-build-release/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Uni/4. Semester/cpp-game/cmake-build-release/_deps/box2d-subbuild/box2d-populate-prefix/src/box2d-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
