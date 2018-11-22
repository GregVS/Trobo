#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "srv_wrapper::srv_wrapper" for configuration "Debug"
set_property(TARGET srv_wrapper::srv_wrapper APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(srv_wrapper::srv_wrapper PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libsrv_wrapper.so"
  IMPORTED_SONAME_DEBUG "libsrv_wrapper.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS srv_wrapper::srv_wrapper )
list(APPEND _IMPORT_CHECK_FILES_FOR_srv_wrapper::srv_wrapper "${_IMPORT_PREFIX}/lib/libsrv_wrapper.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
