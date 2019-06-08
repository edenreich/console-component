

add_library(commandline
    application.cpp
    include/console/application_interface.h
    include/console/application.h
    include/console/command.h
    include/console/types/colors.h
    include/console/types/exit_code.h
    include/console/types/metadata.h
)

target_include_directories(commandline PUBLIC "$(CMAKE_CURRENT_SOURCE_DIR)/src")