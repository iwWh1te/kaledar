#include <QApplication>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QCalendarWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Календарь");

    QGridLayout *layout = new QGridLayout(&window);

    QLabel *label = new QLabel("Выберите дату:");
    layout->addWidget(label, 0, 0);

    QCalendarWidget *calendar = new QCalendarWidget();
    layout->addWidget(calendar, 1, 0, 1, 2);

    QPushButton *button = new QPushButton("Показать дату");
    layout->addWidget(button, 2, 0, 1, 2);

    QLabel *resultLabel = new QLabel();
    layout->addWidget(resultLabel, 3, 0, 1, 2);

    // Обработка нажатия кнопки
    QObject::connect(button, &QPushButton::clicked, [=]() {
        QDate selectedDate = calendar->selectedDate();
        QString result = "Выбранная дата: " + selectedDate.toString("dd.MM.yyyy");
        resultLabel->setText(result);
    });

    window.setLayout(layout);
    window.show();

    return app.exec();
}
