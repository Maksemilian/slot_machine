TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG += qt

#windows
win32 {
INCLUDEPATH += $${PWD}/lib/freetype-2/include
INCLUDEPATH += $${PWD}/lib
INCLUDEPATH += $${PWD}/lib/soil
INCLUDEPATH += $${PWD}/lib/boost

LIBS += -L$${PWD}/lib/boost -lboost_filesystem_wind
LIBS += -L$${PWD}/lib/soil/lib -lSOIL
LIBS += -L$${PWD}/lib/freetype-2/lib -lfreetype
# требуется glut32.dll в win os а для linuxa no
LIBS += -L$${PWD}/lib/GL -lglut32
LIBS += -lgdi32 -lopengl32 -lglu32
#-lglaux
}

#LIBS+= $${PWD}/lib/freetype -lfreetype

#unix:INCLUDEPATH += $${PWD}/lib/freetype/include
#unix:INCLUDEPATH += $${PWD}/lib/boost

#unix:LIBS += -L$${PWD}/lib/boost -lboost_filesystem

#unix:LIBS += -lglut -lGL -lGLU -lSOIL -lfreetype

SOURCES += \
    button.cpp \
    font.cpp \
    game_object.cpp \
    go_slot_machine.cpp \
    go_token.cpp \
    go_wheel.cpp \
        main.cpp \
    geometry.cpp \
    game.cpp \
    ro_slot_machine.cpp \
    ro_token.cpp \
    ro_wheel.cpp \
    texture.cpp \
    widget.cpp

HEADERS += \
    button.h \
    font.h \
    fps.h \
    game_object.h \
    geometry.h \
    game.h \
    go_slot_machine.h \
    go_token.h \
    go_wheel.h \
    renderer.h \
    ro_slot_machine.h \
    ro_token.h \
    ro_wheel.h \
    texture.h \
    timer.h \
    widget.h
