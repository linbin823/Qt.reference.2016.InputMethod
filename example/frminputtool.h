#ifndef FRMINPUTTOOL_H
#define FRMINPUTTOOL_H

#include <QWidget>

namespace Ui
{
class frmInputTool;
}

class frmInputTool : public QWidget
{
    Q_OBJECT

public:
    explicit frmInputTool(QWidget *parent = 0);
    ~frmInputTool();

private:
    Ui::frmInputTool *ui;

private slots:
    void initForm();
    void accepted();
    void textValueChanged(QString text);
    void fileSelected(QString fileName);

private slots:
    void on_btnDialog_clicked();
    void on_btnInputDialog_clicked();
    void on_btnFileDialog_clicked();
};

#endif // FRMINPUTTOOL_H
