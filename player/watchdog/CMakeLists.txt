project(xibo-watchdog)

find_package(Boost REQUIRED program_options)

add_executable(${PROJECT_NAME}
    main.cpp
    ProcessWatcher.cpp
    ProcessWatcher.hpp
)

target_link_libraries(${PROJECT_NAME}
    config
    Boost::program_options
)
