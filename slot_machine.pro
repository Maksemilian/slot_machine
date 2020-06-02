TEMPLATE = app
CONFIG += console c++11
! include( format.astylerc){
    error( "Couldn't find the format.astylerc file!" )
}
win32 {
INCLUDEPATH += $${PWD}/lib/win32
INCLUDEPATH += $${PWD}/lib/win32/freetype-2/include
INCLUDEPATH += $${PWD}/lib/win32/soil
INCLUDEPATH += $${PWD}/lib/win32/boost

LIBS += -L$${PWD}/lib/win32/boost -lboost_filesystem_win
LIBS += -L$${PWD}/lib/win32/soil/lib -lSOIL
LIBS += -L$${PWD}/lib/win32/freetype-2/lib -lfreetype

# требуется glut32.dll в win os а для linuxa no
LIBS += -L$${PWD}/lib/win32/GL -lglut32
LIBS += -lopengl32
}

unix {
INCLUDEPATH += $${PWD}/lib/linux/freetype/include
INCLUDEPATH += $${PWD}/lib/linux/boost

LIBS += -L$${PWD}/lib/linux/freetype -lfreetype
LIBS += -L$${PWD}/lib/linux/boost -lboost_filesystem

LIBS += -lglut -lGL -lGLU -lSOIL
}

SOURCES += \
    go_slot_machine.cpp \
    go_token.cpp \
    go_wheel.cpp \
    game.cpp \
    ro_slot_machine.cpp \
    ro_token.cpp \
    ro_wheel.cpp \
    go_blink_button.cpp \
    ro_blink_button.cpp \
    s_texture_loader.cpp \
    s_timer.cpp \
    s_font.cpp \
    s_geometry.cpp \
    _main.cpp \
    s_fps.cpp \
    s_time.cpp \
    go_game_object.cpp \
    ro_renderable_object.cpp \
    renderer_text.cpp \
    renderer_game.cpp

HEADERS += \
    game.h \
    go_slot_machine.h \
    go_token.h \
    go_wheel.h \
    ro_slot_machine.h \
    ro_token.h \
    ro_wheel.h \
    go_blink_button.h \
    ro_blink_button.h \
    s_texture_loader.h \
    s_timer.h \
    s_geometry.h \
    s_fps.h \
    s_font.h \
    go_game_object.h \
    ro_renderable_object.h \
    renderer_text.h \
    s_time.h \
    renderer_game.h
