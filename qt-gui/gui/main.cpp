#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "romanvalidator.h"
#include "romanconverter.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<RomanValidator>("number.roman", 1, 0, "RomanValidator");
    qmlRegisterType<RomanConverter>("number.roman", 1, 0, "RomanConverter");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
