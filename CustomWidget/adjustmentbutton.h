#ifndef ADJUSTMENTBUTTON_H
#define ADJUSTMENTBUTTON_H

#include <QWidget>

class QTimer;

QT_BEGIN_NAMESPACE
namespace Ui { class AdjustmentButton; }
QT_END_NAMESPACE

class AdjustmentButton : public QWidget
{
    Q_OBJECT

public:
    AdjustmentButton(QWidget *parent = nullptr);
    ~AdjustmentButton();

protected slots:
    void buttonPressed_high();
    void buttonReleased_high();
    void buttonPressed_moreHigh();
    void buttonReleased_moreHigh();
    void buttonPressed_low();
    void buttonReleased_low();
    void buttonPressed_moreLow();
    void buttonReleased_moreLow();
    void doIncrement();
    void doDecrement();
    void doMoreIncrement();
    void doMoreDecrement();

private:
    Ui::AdjustmentButton *ui;
    QTimer *timer_high, *timer_low;
    int timerTimeout;
    int number;
};
#endif // ADJUSTMENTBUTTON_H
