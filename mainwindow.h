#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget * = nullptr);
    ~MainWindow();
protected:
    void mousePressEvent(QMouseEvent *event) override;
private slots:
    void on_sideMenuButtonClicked();
    void on_btn_theme_clicked();
    void on_btn_menu_clicked();
private:
    Ui::MainWindow *ui;
    bool actualTheme = true;
    QString lightTheme;
    QString darkTheme;
    QString borderMenustyleSheet;
};

#endif // MAINWINDOW_H
