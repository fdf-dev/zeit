if(WITH_QT6)
    set(test_LIBS Qt6::Core Qt6::Gui Qt6::Test)
    set(test_QT_INCLUDE_DIRECTORIES ${Qt6Core_INCLUDE_DIRS} ${Qt6Gui_INCLUDE_DIRS})
else()
    set(test_LIBS Qt5::Core Qt5::Gui Qt5::Test)
    set(test_QT_INCLUDE_DIRECTORIES ${Qt5Core_INCLUDE_DIRS} ${Qt5Gui_INCLUDE_DIRS})
endif()
set(tests_SRCS tests.cpp)
add_executable(tests ${tests_SRCS})
target_include_directories(tests PRIVATE ${test_QT_INCLUDE_DIRECTORIES}
                           ${CMAKE_CURRENT_SOURCE_DIR}/../crontablib
                           ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(tests crontab ${test_LIBS})
target_compile_features(tests PRIVATE cxx_nullptr)
