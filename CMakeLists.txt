# CMakeList.txt: projekt CMake dla elementu ZaawansowaneJezykiProgramowania, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

project ("ZaawansowaneJezykiProgramowania")

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (ZaawansowaneJezykiProgramowania "03/main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ZaawansowaneJezykiProgramowania PROPERTY CXX_STANDARD 20)
endif()

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
