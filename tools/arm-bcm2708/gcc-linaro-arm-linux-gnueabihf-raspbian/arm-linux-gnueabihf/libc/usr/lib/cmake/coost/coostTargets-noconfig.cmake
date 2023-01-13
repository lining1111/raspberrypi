#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "coost::co" for configuration ""
set_property(TARGET coost::co APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(coost::co PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "ASM;CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libco.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS coost::co )
list(APPEND _IMPORT_CHECK_FILES_FOR_coost::co "${_IMPORT_PREFIX}/lib/libco.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
