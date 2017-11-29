# TEMPLATE = app
TARGET = virtualkeyboardqmldemo
QT += qml quick
SOURCES += main.cpp
CONFIG += c++11
LIBS += -lqsgepaper

DEPLOYMENT_PATH = /usr/share/$$TARGET
DEFINES += DEPLOYMENT_PATH=\\\"$$DEPLOYMENT_PATH\\\"

target.path = $$DEPLOYMENT_PATH
INSTALLS += target

RESOURCES += \
    qmlappdemo.qrc

qml.files += \
    ButtonFlatStyle.qml \
    Main.qml \
    MainContainer.qml \
    MainDesigner.qml \
    MainQuickControls.qml \
    ProgressBarFlatStyle.qml \
    SliderFlatStyle.qml \
    Style.qml \
    Syringe.qml \
    TextFieldFlatStyle.qml

qml.path = $$DEPLOYMENT_PATH
INSTALLS += qml

qml_content.files += \
    content/ScrollBar.qml \
    content/TextArea.qml \
    content/TextBase.qml \
    content/TextField.qml

qml_content.path = $$DEPLOYMENT_PATH/content
INSTALLS += qml_content

DISTFILES += \
    StyleHelper.aml \
    Style.qml
