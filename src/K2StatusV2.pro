#-------------------------------------------------
#
# Project created by QtCreator 2016-06-21T13:15:28
#
#-------------------------------------------------

QT       += core gui network printsupport xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = K2StatusV2
TEMPLATE = app


SOURCES += main.cpp\
        k2statusv2.cpp \
    aboutme.cpp \
    metadatatable.cpp \
    k2udpsock.cpp \
    ewmessagemgr.cpp \
    udpconfig.cpp \
    stninfo.cpp \
    k2logger.cpp \
    qcustomplot.cpp \
    k2graph.cpp

HEADERS  += k2statusv2.h \
    include/ew_packet.h \
    include/k2info.h \
    include/k2pktdef.h \
    include/nkwhdrs.h \
    include/TableDef.h \
    aboutme.h \
    metadatatable.h \
    k2udpsock.h \
    ewmessagemgr.h \
    udpconfig.h \
    stninfo.h \
    k2logger.h \
    qcustomplot.h \
    k2graph.h

FORMS    += k2statusv2.ui \
    aboutme.ui \
    udpconfig.ui \
    k2graph.ui
