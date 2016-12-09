#include "frminputtool.h"
#include "ui_frminputtool.h"
#include "frminput.h"
#include "frminputnew.h"
#include "frminputnum.h"
#include "frminputuser.h"

frmInputTool::frmInputTool(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::frmInputTool)
{
	ui->setupUi(this);
	this->initForm();
}

frmInputTool::~frmInputTool()
{
	delete ui;
}

void frmInputTool::initForm()
{
	setWindowTitle("输入法调用示例");
	ui->txt->setProperty("noinput", true);

	//以下方法打开中文输入法
    frmInput::Instance()->init("control", "silvery", 10, 10);

	//以下方法打开新版中文输入法
//	frmInputNew::Instance()->init("control", "black", 12, 10, 700, 230, 20, 20, 6, 45);

	//以下方法打开定制中文输入法
	//frmInputUser::Instance()->init("bottom", 20, 18, 1280, 350, 45, 45, 7, 60);

	//以下方法打开数字键盘
	//frmInputNum::Instance()->init("black", 10);
}

void frmInputTool::on_btnDialog_clicked()
{
    QDialog *dialog = new QDialog;
    QLineEdit *txt = new QLineEdit(dialog);
	txt->setVisible(true);
    dialog->setWindowFlags(Qt::WindowStaysOnTopHint);
    dialog->show();
}

void frmInputTool::on_btnInputDialog_clicked()
{
	QInputDialog *d = new QInputDialog(this);
	connect(d, SIGNAL(accepted()), this, SLOT(accepted()));
	connect(d, SIGNAL(textValueChanged(QString)), this, SLOT(textValueChanged(QString)));
	d->show();
}

void frmInputTool::on_btnFileDialog_clicked()
{
	QFileDialog *d = new QFileDialog(this);
	connect(d, SIGNAL(fileSelected(QString)), this, SLOT(fileSelected(QString)));
	d->show();
}

void frmInputTool::accepted()
{
	QInputDialog *d = (QInputDialog *)sender();
	QString text = QString("result: %1").arg(d->textValue());
	ui->lineEdit->setText(text);
}

void frmInputTool::textValueChanged(QString text)
{
	ui->lineEdit->setText(text);
}

void frmInputTool::fileSelected(QString fileName)
{
	QString text = QString("fileName: %1").arg(fileName);
	ui->lineEdit->setText(text);

	QFile file(fileName);

	if (file.open(QFile::ReadOnly | QFile::Text)) {
		QByteArray ba = file.readAll();
		QTextCodec *codec = QTextCodec::codecForName("UTF-8");
		QString str = codec->toUnicode(ba);
		ui->textEdit->setText(str);
		file.close();
	}
}
