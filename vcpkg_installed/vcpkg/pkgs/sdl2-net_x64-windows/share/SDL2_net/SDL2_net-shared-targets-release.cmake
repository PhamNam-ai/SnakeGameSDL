#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL2_net::SDL2_net" for configuration "Release"
set_property(TARGET SDL2_net::SDL2_net APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(SDL2_net::SDL2_net PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/SDL2_net.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "SDL2::SDL2"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/SDL2_net.dll"
  )

list(APPEND _cmake_import_check_targets SDL2_net::SDL2_net )
list(APPEND _cmake_import_check_files_for_SDL2_net::SDL2_net "${_IMPORT_PREFIX}/lib/SDL2_net.lib" "${_IMPORT_PREFIX}/bin/SDL2_net.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
