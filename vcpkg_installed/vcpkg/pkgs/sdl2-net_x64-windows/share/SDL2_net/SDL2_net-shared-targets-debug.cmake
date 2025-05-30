#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SDL2_net::SDL2_net" for configuration "Debug"
set_property(TARGET SDL2_net::SDL2_net APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(SDL2_net::SDL2_net PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/debug/lib/SDL2_netd.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "SDL2::SDL2"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/debug/bin/SDL2_netd.dll"
  )

list(APPEND _cmake_import_check_targets SDL2_net::SDL2_net )
list(APPEND _cmake_import_check_files_for_SDL2_net::SDL2_net "${_IMPORT_PREFIX}/debug/lib/SDL2_netd.lib" "${_IMPORT_PREFIX}/debug/bin/SDL2_netd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
