//for msvc2010 sp1 compiler
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include "frminputtool.h"
#include <QApplication>
#include "myhelper.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/main.ico"));
    myHelper::setUTF8Code();
    frmInputTool w;
    w.show();

    return a.exec();
}
