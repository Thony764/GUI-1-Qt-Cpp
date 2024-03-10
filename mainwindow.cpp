#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Guardar el estilo de hoja del centralwidget cuando se inicia la aplicación
    lightTheme = ui->centralwidget->styleSheet();

    // Crear el tema oscuro basado en el claro
    darkTheme = lightTheme;

    // Añadir las modificaciones específicas para #centralwidget, #side_menu y #main_body al tema oscuro
    darkTheme += "*{color: #ffffff; }"
                 "#centralwidget { background-color: #181818;}"
                 "#side_menu { background-color: #1f1f1f; border-radius: 20px; border: 1px solid rgba(0, 0, 0, 0); }"
                 "#main_body { background-color: #363636; border-radius: 10px; }";

    // Definir el estilo de hoja inicial para resaltar el borde de side_menu
    borderMenustyleSheet = "#side_menu {border-radius: 20px; border: 1px solid #026ec1; }";

    // Al precionar un boton de side_menu agregar borde
    for (auto button : ui->side_menu->findChildren<QPushButton *>())
    {
        connect(button, &QPushButton::clicked, this, &MainWindow::on_sideMenuButtonClicked);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // Llama a la implementación de la clase base para manejar el evento mousePressEvent
    QMainWindow::mousePressEvent(event);

    // Verifica si el mouse está sobre side_menu
    if (ui->side_menu->underMouse())
    {
        ui->side_menu->setStyleSheet(borderMenustyleSheet);
    }
    else
    {
        // Si el mouse no está sobre side_menu, restablecer el estilo a un estado vacío
        QString emptyStyleSheet = "#side_menu {}";
        ui->side_menu->setStyleSheet(emptyStyleSheet);
    }
}

void MainWindow::on_sideMenuButtonClicked()
{
    // Cambia el estilo cuando el botón del menú lateral es clickeado
    ui->side_menu->setStyleSheet(borderMenustyleSheet);
}

void MainWindow::on_btn_theme_clicked()
{
    // Cambia el tema oscuro o claro según el estado actual
    if (actualTheme == true)
    {
        ui->centralwidget->setStyleSheet(darkTheme);
        ui->btn_theme->setIcon(QIcon(":/img/iconos/sun.svg"));
    }
    else
    {
        ui->centralwidget->setStyleSheet(lightTheme);
        ui->btn_theme->setIcon(QIcon(":/img/iconos/moon.svg"));
    }

    actualTheme = !actualTheme; // Cambia el estado del tema
}

void MainWindow::on_btn_menu_clicked()
{
    // Muestra u oculta el menú lateral y cambia el icono del botón de menú
    if (ui->side_menu->isHidden())
    {
        ui->side_menu->show();
        ui->side_menu->setStyleSheet(borderMenustyleSheet);
        ui->btn_menu->setIcon(QIcon(":/img/iconos/menu.svg"));
    }
    else
    {
        ui->side_menu->hide();
        ui->btn_menu->setIcon(QIcon(":/img/iconos/chevron-left.svg"));
    }
}
