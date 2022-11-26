cmake_minimum_required(VERSION 3.9)

set(APP_NAME 7DaysToCry)
project(APP_NAME)

add_executable(${APP_NAME}
	main.cpp
)
target_include_directories(${APP_NAME} PRIVATE
	include
	${CMAKE_CURRENT_SOURCE_DIR}/deps/EchoEngine
	#${CMAKE_CURRENT_SOURCE_DIR}/deps/EchoEngine/deps
)

set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")
#set(RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/")
set(APP_TYPE_3D "")
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/EchoEngine)
target_link_libraries(${APP_NAME}
	EchoEngine
)

add_custom_command(TARGET ${APP_NAME} POST_BUILD
    COMMAND echo Starting copy......
)

IF (WIN32)
	add_custom_command(TARGET ${APP_NAME} POST_BUILD
		COMMAND xcopy /s /d /y 
			"\"${CMAKE_CURRENT_SOURCE_DIR}/data\""
			"\"${CMAKE_BINARY_DIR}/$<CONFIGURATION>/data/*\""
	)
ELSE()
	add_custom_command(TARGET ${APP_NAME} POST_BUILD
		COMMAND cp -u 
			"\"${CMAKE_CURRENT_SOURCE_DIR}/data\""
			"\"${CMAKE_BINARY_DIR}/$<CONFIGURATION>/data/*\""
	)
ENDIF()

add_custom_command(TARGET ${APP_NAME} POST_BUILD
    COMMAND echo Finished copy......
)