QT     += core gui widgets
CONFIG += c++11

TARGET = BrainTraining
TEMPLATE = app


SOURCES += bmain.cpp\
bio.cpp\
bgames.cpp\
bgamesettings.cpp\
binit.cpp\
bwidget.cpp\
math/bmathgen.cpp\
math/bmathmain.cpp\
math/bmathutil.cpp\
math/bmathwidget.cpp\
widgets/bmainmenu.cpp\
widgets/bleaderboadrds.cpp\
widgets/bgamebutton.cpp\
widgets/bsettingswidgets.cpp\
widgets/bstatistics.cpp


HEADERS  += bmain.h\
bio.h\
bgames.h\
bgamesettings.h\
binit.h\
bwidget.h\
math/bmathgen.h\
math/bmathmain.h\
math/bmathutil.h\
math/bmathwidget.h\
widgets/bmainmenu.h\
widgets/bleaderboadrds.h\
widgets/bgamebutton.h\
widgets/bsettingswidgets.h\
widgets/bstatistics.cpp


RESOURCES += res.qrc

RC_FILE = res.rc
