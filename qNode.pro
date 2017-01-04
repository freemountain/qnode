TEMPLATE = subdirs

SUBDIRS += \
    lib \
    cli \
    test \
    nativeModule

cli.depends = lib
test.depends = lib

CONFIG += ordered

OTHER_FILES += js/*
