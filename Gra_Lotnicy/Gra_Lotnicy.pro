TEMPLATE = app
CONFIG += console c++17a
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += "C:/SFML-2.5.1/include"
LIBS += -L"C:/SFML-2.5.1/lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

SOURCES += \
        lotnicy.cpp \
        main.cpp

HEADERS += \
    balon_soj.h \
    balon_wr.h \
    bron.h \
    obiekt.h \
    ranking.h \
    samolot_soj.h \
    samolot_wr.h \
    serca.h \
    tlo.h
