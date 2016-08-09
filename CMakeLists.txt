cmake_minimum_required(VERSION 3.3)
project(BrainTraining)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_FLAGS "-std=c++11")

find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Network)
find_package(Qt5Declarative)
find_package(Qt5Concurrent)

set(P_S
		res.rc

		bmain.cpp
		bio.cpp
		bgames.cpp
		bgamesettings.cpp
		binit.cpp
		bwidget.cpp

		math/bmathgen.cpp
		math/bmathmain.cpp
		math/bmathutil.cpp
		math/bmathwidget.cpp

		widgets/bgamebutton.cpp
		widgets/bleaderboard.cpp
		widgets/bmainmenu.cpp
		widgets/bsettingswidgets.cpp
		widgets/bstatistics.cpp
		)

set(P_H
  bmain.h
  bio.h
		bgames.h
		bgamesettings.h
		binit.h
  bwidget.h

		math/bmathgen.h
		math/bmathmain.h
		math/bmathutil.h
		math/bmathwidget.h

		widgets/bgamebutton.h
		widgets/bleaderboard.h
		widgets/bmainmenu.h
		widgets/bsettingswidgets.h
		widgets/bstatistics.h
		)

qt5_wrap_cpp(GENERATED_SOURCES ${P_H})
qt5_add_resources(RES res.qrc)

add_executable(BrainTraining ${P_S} ${P_H} ${RES})
qt5_use_modules(BrainTraining Core Widgets Network Concurrent)
target_compile_features(BrainTraining PRIVATE cxx_range_for)
target_link_libraries(BrainTraining ${Qt5Core_QTMAIN_LIBRARIES})