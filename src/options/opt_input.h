#ifndef OPT_TABINPUT_H
#define OPT_TABINPUT_H

#include "optionstab.h"
#include "psicon.h"

class QWidget;
class QTreeWidgetItem;

class OptionsTabInput : public OptionsTab
{
    Q_OBJECT
public:
    OptionsTabInput(QObject *parent);
    ~OptionsTabInput();

    QWidget *widget();
    void applyOptions();
    void restoreOptions();
    void setData(PsiCon *psi, QWidget *);

private:
    QStringList obtainDefaultLang() const;
    void fillList();
    void setChecked();
    void updateDictLists();
    bool isTreeViewEmpty();

private slots:
    void itemToggled(bool toggled);
    void itemChanged(QTreeWidgetItem *item, int column);

private:
    QWidget *w_;
    PsiCon *psi_;
    QStringList availableDicts_;
    QStringList loadedDicts_;
    QStringList defaultLangs_;
};

#endif // OPT_TABINPUT_H