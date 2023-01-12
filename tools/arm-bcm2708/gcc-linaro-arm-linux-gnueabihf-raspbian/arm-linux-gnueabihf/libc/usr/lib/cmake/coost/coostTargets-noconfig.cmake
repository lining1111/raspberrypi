#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "coost::co" for configuration ""
set_property(TARGET coost::co APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(coost::co PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libco.so.3.0.0"
  IMPORTED_SONAME_NOCONFIG "libco.so.3"
  )

list(APPEND _IMPORT_CHECK_TARGETS coost::co )
list(APPEND _IMPORT_CHECK_FILES_FOR_coost::co "${_IMPORT_PREFIX}/lib/libco.so.3.0.0" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
