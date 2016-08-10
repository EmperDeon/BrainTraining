cmake_minimum_required(VERSION 3.3)
project(BrainTraining)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "-std=c++14")

find_package(Qt5Core)
find_package(Qt5Widgets)
#find_package(Qt5Declarative)
#find_package(Qt5Concurrent)

set(P_S
		res/res.rc

		b_main.cpp
		b_games.cpp

		widgets/bW_leaderBoard.cpp
		widgets/bW_mainMenu.cpp
		widgets/bW_mainWindow.cpp
		widgets/bW_statistics.cpp
		widgets/util/bWU_gameButton.cpp
		widgets/util/bWU_settingsWidgets.cpp

		util/bU_io.cpp
		util/bU_io_init.cpp
		util/bU_math.cpp

		# Games

		math/expr/bME_gen.cpp
		math/expr/bME_main.cpp
		math/expr/bME_widget.cpp
		)

set(P_H
		b_main.h
		b_games.h

		widgets/bW_leaderBoard.h
		widgets/bW_mainMenu.h
		widgets/bW_mainWindow.h
		widgets/bW_statistics.h
		widgets/util/bWU_gameButton.h
		widgets/util/bWU_settingsWidgets.h

		util/bU_io.h
		util/bU_io_init.h
		util/bU_math.h

		# Games

		math/expr/bME_gen.h
		math/expr/bME_main.h
		math/expr/bME_widget.h
		)

qt5_wrap_cpp(GENERATED_SOURCES ${P_H})
qt5_add_resources(RES res/res.qrc)

add_executable(BrainTraining ${P_S} ${P_H} ${RES})
qt5_use_modules(BrainTraining Core Widgets)
target_compile_features(BrainTraining PRIVATE cxx_range_for)
target_link_libraries(BrainTraining ${Qt5Core_QTMAIN_LIBRARIES})