project(media)
pkg_check_modules(GSTREAMER REQUIRED
    gstreamer-1.0>=1.16.2
    gstreamer-base-1.0>=1.16.2
    gstreamer-plugins-base-1.0>=1.16.2
    gstreamer-pbutils-1.0>=1.16.2
    gstreamer-video-1.0>=1.16.2
    gstreamer-gl-1.0>=1.16.2
    gstreamer-app-1.0>=1.16.2)
pkg_check_modules(WEBKITGTK REQUIRED webkit2gtk-4.1>=2.42.1)

# TODO split into dirs
file(GLOB CONTROL_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.*pp
    ${CMAKE_CURRENT_SOURCE_DIR}/image/*.*pp
    ${CMAKE_CURRENT_SOURCE_DIR}/player/*.*pp
    ${CMAKE_CURRENT_SOURCE_DIR}/player/audio/*.*pp
    ${CMAKE_CURRENT_SOURCE_DIR}/player/video/*.*pp
    ${CMAKE_CURRENT_SOURCE_DIR}/webview/*.*pp
)

add_library(${PROJECT_NAME}
    ${CONTROL_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    ${GSTREAMER_LINK_LIBRARIES}
    ${WEBKITGTK_LINK_LIBRARIES}
    common
    transitions
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${GSTREAMER_INCLUDE_DIRS}
    ${WEBKITGTK_INCLUDE_DIRS}
)
