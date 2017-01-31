#!/bin/bash

PROJECT_PATH="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )/../"
TARGET_APP=$1

./build/tools/qbs/bin/qbs install --install-root $PROJECT_PATH/dist -p $TARGET_APP
macdeployqt $PROJECT_PATH/dist/$TARGET_APP.app -qmldir=$PROJECT_PATH/src/libquark/qml
