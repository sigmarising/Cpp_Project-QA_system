#ifndef QTFUNC_H
#define QTFUNC_H

#include <QListWidget>
#include <QListWidgetItem>
#include <list>
#include <string>
using namespace std;

namespace func {
    class Qtfunc    {
    public:
        Qtfunc();
        // 向指定的列表中添加
        static void ListWidget_AddWidget(QListWidget *TargetList, list<string>sourceList, QWidget *StyleWidget);

    };
}

#endif // QTFUNC_H
