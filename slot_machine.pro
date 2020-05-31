TEMPLATE = app
CONFIG += console c++11

win32 {
INCLUDEPATH += $${PWD}/lib/win32
INCLUDEPATH += $${PWD}/lib/win32/freetype-2/include
INCLUDEPATH += $${PWD}/lib/win32/soil
INCLUDEPATH += $${PWD}/lib/win32/boost

LIBS += -L$${PWD}/lib/win32/boost -lboost_filesystem_wind
LIBS += -L$${PWD}/lib/win32/soil/lib -lSOIL
LIBS += -L$${PWD}/lib/win32/freetype-2/lib -lfreetype

# требуется glut32.dll в win os а для linuxa no
LIBS += -L$${PWD}/lib/win32/GL -lglut32
LIBS += -lgdi32 -lopengl32 -lglu32
}

unix {
INCLUDEPATH += $${PWD}/lib/linux/freetype/include
INCLUDEPATH += $${PWD}/lib/linux/boost

LIBS += -L$${PWD}/lib/linux/freetype -lfreetype
LIBS += -L$${PWD}/lib/linux/boost -lboost_filesystem

LIBS += -lglut -lGL -lGLU -lSOIL
}

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
    timer.cpp \
    widget.cpp \
    go_blink_button.cpp \
    ro_blink_button.cpp

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
    widget.h \
    go_blink_button.h \
    ro_blink_button.h \
    rendereable_object.h
