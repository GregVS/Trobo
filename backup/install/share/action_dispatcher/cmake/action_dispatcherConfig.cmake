# generated from catkin/cmake/template/pkgConfig.cmake.in

# append elements to a list and remove existing duplicates from the list
# copied from catkin/cmake/list_append_deduplicate.cmake to keep pkgConfig
# self contained
macro(_list_append_deduplicate listname)
  if(NOT "${ARGN}" STREQUAL "")
    if(${listname})
      list(REMOVE_ITEM ${listname} ${ARGN})
    endif()
    list(APPEND ${listname} ${ARGN})
  endif()
endmacro()

# append elements to a list if they are not already in the list
# copied from catkin/cmake/list_append_unique.cmake to keep pkgConfig
# self contained
macro(_list_append_unique listname)
  foreach(_item ${ARGN})
    list(FIND ${listname} ${_item} _index)
    if(_index EQUAL -1)
      list(APPEND ${listname} ${_item})
    endif()
  endforeach()
endmacro()

# pack a list of libraries with optional build configuration keywords
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_pack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  set(_argn ${ARGN})
  list(LENGTH _argn _count)
  set(_index 0)
  while(${_index} LESS ${_count})
    list(GET _argn ${_index} lib)
    if("${lib}" MATCHES "^(debug|optimized|general)$")
      math(EXPR _index "${_index} + 1")
      if(${_index} EQUAL ${_count})
        message(FATAL_ERROR "_pack_libraries_with_build_configuration() the list of libraries '${ARGN}' ends with '${lib}' which is a build configuration keyword and must be followed by a library")
      endif()
      list(GET _argn ${_index} library)
      list(APPEND ${VAR} "${lib}${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}${library}")
    else()
      list(APPEND ${VAR} "${lib}")
    endif()
    math(EXPR _index "${_index} + 1")
  endwhile()
endmacro()

# unpack a list of libraries with optional build configuration keyword prefixes
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_unpack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  foreach(lib ${ARGN})
    string(REGEX REPLACE "^(debug|optimized|general)${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}(.+)$" "\\1;\\2" lib "${lib}")
    list(APPEND ${VAR} "${lib}")
  endforeach()
endmacro()


if(action_dispatcher_CONFIG_INCLUDED)
  return()
endif()
set(action_dispatcher_CONFIG_INCLUDED TRUE)

# set variables for source/devel/install prefixes
if("FALSE" STREQUAL "TRUE")
  set(action_dispatcher_SOURCE_PREFIX /home/greg/trobo_cpp/src/action_dispatcher)
  set(action_dispatcher_DEVEL_PREFIX /home/greg/trobo_cpp/devel)
  set(action_dispatcher_INSTALL_PREFIX "")
  set(action_dispatcher_PREFIX ${action_dispatcher_DEVEL_PREFIX})
else()
  set(action_dispatcher_SOURCE_PREFIX "")
  set(action_dispatcher_DEVEL_PREFIX "")
  set(action_dispatcher_INSTALL_PREFIX /home/greg/trobo_cpp/install)
  set(action_dispatcher_PREFIX ${action_dispatcher_INSTALL_PREFIX})
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "WARNING: package 'action_dispatcher' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message("${_msg}")
endif()

# flag project as catkin-based to distinguish if a find_package()-ed project is a catkin project
set(action_dispatcher_FOUND_CATKIN_PROJECT TRUE)

if(NOT " " STREQUAL " ")
  set(action_dispatcher_INCLUDE_DIRS "")
  set(_include_dirs "")
  if(NOT " " STREQUAL " ")
    set(_report "Check the issue tracker '' and consider creating a ticket if the problem has not been reported yet.")
  elseif(NOT " " STREQUAL " ")
    set(_report "Check the website '' for information and consider reporting the problem.")
  else()
    set(_report "Report the problem to the maintainer 'greg <greg@todo.todo>' and request to fix the problem.")
  endif()
  foreach(idir ${_include_dirs})
    if(IS_ABSOLUTE ${idir} AND IS_DIRECTORY ${idir})
      set(include ${idir})
    elseif("${idir} " STREQUAL "include ")
      get_filename_component(include "${action_dispatcher_DIR}/../../../include" ABSOLUTE)
      if(NOT IS_DIRECTORY ${include})
        message(FATAL_ERROR "Project 'action_dispatcher' specifies '${idir}' as an include dir, which is not found.  It does not exist in '${include}'.  ${_report}")
      endif()
    else()
      message(FATAL_ERROR "Project 'action_dispatcher' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '/home/greg/trobo_cpp/install/${idir}'.  ${_report}")
    endif()
    _list_append_unique(action_dispatcher_INCLUDE_DIRS ${include})
  endforeach()
endif()

set(libraries "")
foreach(library ${libraries})
  # keep build configuration keywords, target names and absolute libraries as-is
  if("${library}" MATCHES "^(debug|optimized|general)$")
    list(APPEND action_dispatcher_LIBRARIES ${library})
  elseif(TARGET ${library})
    list(APPEND action_dispatcher_LIBRARIES ${library})
  elseif(IS_ABSOLUTE ${library})
    list(APPEND action_dispatcher_LIBRARIES ${library})
  else()
    set(lib_path "")
    set(lib "${library}-NOTFOUND")
    # since the path where the library is found is returned we have to iterate over the paths manually
    foreach(path /home/greg/trobo_cpp/install/lib;/home/greg/trobo_cpp/devel/lib;/home/greg/Arduino/ros/devel/lib;/home/greg/trobo/devel/lib;/opt/ros/melodic/lib)
      find_library(lib ${library}
        PATHS ${path}
        NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
      if(lib)
        set(lib_path ${path})
        break()
      endif()
    endforeach()
    if(lib)
      _list_append_unique(action_dispatcher_LIBRARY_DIRS ${lib_path})
      list(APPEND action_dispatcher_LIBRARIES ${lib})
    else()
      # as a fall back for non-catkin libraries try to search globally
      find_library(lib ${library})
      if(NOT lib)
        message(FATAL_ERROR "Project '${PROJECT_NAME}' tried to find library '${library}'.  The library is neither a target nor built/installed properly.  Did you compile project 'action_dispatcher'?  Did you find_package() it before the subdirectory containing its code is included?")
      endif()
      list(APPEND action_dispatcher_LIBRARIES ${lib})
    endif()
  endif()
endforeach()

set(action_dispatcher_EXPORTED_TARGETS "")
# create dummy targets for exported code generation targets to make life of users easier
foreach(t ${action_dispatcher_EXPORTED_TARGETS})
  if(NOT TARGET ${t})
    add_custom_target(${t})
  endif()
endforeach()

set(depends "")
foreach(depend ${depends})
  string(REPLACE " " ";" depend_list ${depend})
  # the package name of the dependency must be kept in a unique variable so that it is not overwritten in recursive calls
  list(GET depend_list 0 action_dispatcher_dep)
  list(LENGTH depend_list count)
  if(${count} EQUAL 1)
    # simple dependencies must only be find_package()-ed once
    if(NOT ${action_dispatcher_dep}_FOUND)
      find_package(${action_dispatcher_dep} REQUIRED NO_MODULE)
    endif()
  else()
    # dependencies with components must be find_package()-ed again
    list(REMOVE_AT depend_list 0)
    find_package(${action_dispatcher_dep} REQUIRED NO_MODULE ${depend_list})
  endif()
  _list_append_unique(action_dispatcher_INCLUDE_DIRS ${${action_dispatcher_dep}_INCLUDE_DIRS})

  # merge build configuration keywords with library names to correctly deduplicate
  _pack_libraries_with_build_configuration(action_dispatcher_LIBRARIES ${action_dispatcher_LIBRARIES})
  _pack_libraries_with_build_configuration(_libraries ${${action_dispatcher_dep}_LIBRARIES})
  _list_append_deduplicate(action_dispatcher_LIBRARIES ${_libraries})
  # undo build configuration keyword merging after deduplication
  _unpack_libraries_with_build_configuration(action_dispatcher_LIBRARIES ${action_dispatcher_LIBRARIES})

  _list_append_unique(action_dispatcher_LIBRARY_DIRS ${${action_dispatcher_dep}_LIBRARY_DIRS})
  list(APPEND action_dispatcher_EXPORTED_TARGETS ${${action_dispatcher_dep}_EXPORTED_TARGETS})
endforeach()

set(pkg_cfg_extras "")
foreach(extra ${pkg_cfg_extras})
  if(NOT IS_ABSOLUTE ${extra})
    set(extra ${action_dispatcher_DIR}/${extra})
  endif()
  include(${extra})
endforeach()
