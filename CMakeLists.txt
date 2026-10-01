cmake_minimum_required(VERSION 3.10)
project(olcPack VERSION 1.03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(olcPack)
target_sources(olcPack
    PRIVATE
    src/olcPack.cpp
    src/olcResourcePack.cpp
    src/olcResourcePack.h
)

# Allow emscripten access to the host filesystem
if(EMSCRIPTEN)
    target_link_options(olcPack
        PRIVATE
        -sNODERAWFS
    )
endif()

# ---------------------------------------------------------------
# Install rules
# ---------------------------------------------------------------
include(GNUInstallDirs)

install(TARGETS olcPack
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Optional extras, if you have them:
install(FILES README.md LICENSE DESTINATION ${CMAKE_INSTALL_DOCDIR})

# ---------------------------------------------------------------
# Packaging (CPack)
# ---------------------------------------------------------------
set(CPACK_PACKAGE_NAME "olcPack")
set(CPACK_PACKAGE_VENDOR "Moros1138")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "olc resource pack tool")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "olcPack")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

if(WIN32)
    # NSIS must be installed (https://nsis.sourceforge.io)
    set(CPACK_GENERATOR "NSIS;ZIP")
    set(CPACK_NSIS_MODIFY_PATH ON)   # offer to add to PATH
elseif(APPLE)
    set(CPACK_GENERATOR "DragNDrop;TGZ")
else()
    set(CPACK_GENERATOR "DEB;RPM;TGZ")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Moros1138 <moros1138@gmail.com>")
    set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
endif()

include(CPack)
