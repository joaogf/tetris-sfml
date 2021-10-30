TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt

LIBS+= -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

INCLUDEPATH += include/

SOURCES += src/main.cpp \
    src/game-scenery.cpp \
    src/drawable-system.cpp \
    src/tetris-minos.cpp \
    src/drawable-tetrisminos.cpp \
    src/drawable-tetrisminos-factory.cpp \
    src/event-system.cpp \
    src/collision-system.cpp

HEADERS += \
    include/tetris-header.h \
    include/game-scenery.h \
    include/drawable-system.h \
    include/tetris-minos.h \
    include/drawable-tetrisminos.h \
    include/tetrisminos-one.h \
    include/drawable-tetrisminos-factory.h \
    include/tetrisminos-two.h \
    include/tetrisminos-three.h \
    include/tetrisminos-four.h \
    include/tetrisminos-five.h \
    include/tetrisminos-three-inverted.h \
    include/event-system.h \
    include/collision-system.h
