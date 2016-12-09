#ifndef FRMINPUTNUM_H
#define FRMINPUTNUM_H

#include <QtGui>
#include <QtSql>
#if (QT_VERSION > QT_VERSION_CHECK(5,0,0))
#include <QtWidgets>
#endif

namespace Ui
{
class frmInputNum;
}

class frmInputNum : public QWidget
{
	Q_OBJECT

public:
	explicit frmInputNum(QWidget *parent = 0);
	~frmInputNum();

	//单例模式,保证一个程序只存在一个输入法实例对象
	static frmInputNum *Instance()
	{
		if (!_instance) {
			static QMutex mutex;
			QMutexLocker locker(&mutex);

			if (!_instance) {
				_instance = new frmInputNum;
			}
		}

		return _instance;
	}

	//初始化面板状态,包括字体大小
    void init(QString style, int fontSize);

protected:
	//事件过滤器,处理鼠标按下弹出输入法面板
	bool eventFilter(QObject *obj, QEvent *event);
	//鼠标拖动事件
	void mouseMoveEvent(QMouseEvent *e);
	//鼠标按下事件
	void mousePressEvent(QMouseEvent *e);
	//鼠标松开事件
	void mouseReleaseEvent(QMouseEvent *);

private slots:
	//焦点改变事件槽函数处理
	void focusChanged(QWidget *oldWidget, QWidget *nowWidget);
	//输入法面板按键处理
	void btnClicked();
	//改变输入法面板样式
	void changeStyle(QString topColor, QString bottomColor,
	                 QString borderColor, QString textColor);
	//定时器处理退格键
	void reClicked();
	//显示面板
    void showPanel();

private:
	Ui::frmInputNum *ui;
	static frmInputNum *_instance;       //实例对象

	int deskWidth;                  //桌面宽度
	int deskHeight;                 //桌面高度
	int frmWidth;                   //窗体宽度
	int frmHeight;                  //窗体高度

	bool isPress;                   //是否长按退格键
	QPushButton *btnPress;          //长按按钮
	QTimer *timerPress;             //退格键定时器
	bool checkPress();              //校验当前长按的按钮

	QPoint mousePoint;              //鼠标拖动自定义标题栏时的坐标
	bool mousePressed;              //鼠标是否按下

	bool isFirst;                   //是否首次加载
    void initForm();                //初始化窗体数据
    void initProperty();            //初始化属性
    void changeStyle();             //改变样式

	QWidget *currentWidget;         //当前焦点的对象
	QLineEdit *currentLineEdit;     //当前焦点的单行文本框
	QTextEdit *currentTextEdit;     //当前焦点的多行文本框
	QPlainTextEdit *currentPlain;   //当前焦点的富文本框
	QTextBrowser *currentBrowser;   //当前焦点的文本浏览框

	QString currentEditType;        //当前焦点控件的类型
	QString currentStyle;           //当前输入法面板样式
	int currentFontSize;            //当前输入法面板字体大小
	void insertValue(QString value);//插入值到当前焦点控件
	void deleteValue();             //删除当前焦点控件的一个字符

};

#endif // FRMINPUTNUM_H
