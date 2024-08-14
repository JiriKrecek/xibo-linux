project(logger)

add_library(${PROJECT_NAME}
    Logging.cpp
    Logging.hpp
    XmlLoggerSink.hpp
    XmlLogsRepo.cpp
    XmlLogsRepo.hpp
    XmlLogsRetriever.cpp
    XmlLogsRetriever.hpp
)

target_link_libraries(${PROJECT_NAME}
    dt
    ${SPDLOG_LINK_LIBRARIES}
)
