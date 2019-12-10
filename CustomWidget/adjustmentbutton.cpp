#include "adjustmentbutton.h"
#include "ui_adjustmentbutton.h"
#include <QTimer>

AdjustmentButton::AdjustmentButton(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AdjustmentButton)
{
    ui->setupUi(this);

    number = 0;
    timerTimeout = 0;
    timer_high = new QTimer(this);
    timer_low = new QTimer(this);
    ui->label->setAlignment(Qt::AlignCenter);


    connect(timer_high,&QTimer::timeout, this, &AdjustmentButton::doIncrement);
    connect(timer_low, &QTimer::timeout, this, &AdjustmentButton::doDecrement);
    connect(timer_high,&QTimer::timeout, this, &AdjustmentButton::doMoreIncrement);
    connect(timer_low, &QTimer::timeout, this, &AdjustmentButton::doMoreDecrement);


    connect(ui->pushButton_high, &QPushButton::pressed, this, &AdjustmentButton::buttonPressed_high);
    connect(ui->pushButton_high, &QPushButton::released, this, &AdjustmentButton::buttonReleased_high);

    connect(ui->pushButton_moreHigh, &QPushButton::pressed, this, &AdjustmentButton::buttonPressed_moreHigh);
    connect(ui->pushButton_moreHigh, &QPushButton::released, this, &AdjustmentButton::buttonReleased_moreHigh);

    connect(ui->pushButton_low, &QPushButton::pressed, this, &AdjustmentButton::buttonPressed_low);
    connect(ui->pushButton_low, &QPushButton::released, this, &AdjustmentButton::buttonReleased_low);

    connect(ui->pushButton_moreLow, &QPushButton::pressed, this, &AdjustmentButton::buttonPressed_moreLow);
    connect(ui->pushButton_moreLow, &QPushButton::released, this, &AdjustmentButton::buttonReleased_moreLow);
}

AdjustmentButton::~AdjustmentButton()
{
    delete ui;
}

void AdjustmentButton::buttonPressed_high()
{
timerTimeout = 5000;
doIncrement();
}

void AdjustmentButton::buttonReleased_high()
{
timer_high->stop();
}

void AdjustmentButton::buttonPressed_moreHigh()
{
timerTimeout = 5000;
doMoreIncrement();
}

void AdjustmentButton::buttonReleased_moreHigh()
{
timer_high->stop();
}

void AdjustmentButton::buttonPressed_low()
{
timerTimeout = 5000;
doDecrement();
}

void AdjustmentButton::buttonReleased_low()
{
timer_low->stop();
}
void AdjustmentButton::buttonPressed_moreLow()
{
timerTimeout = 5000;
doMoreDecrement();
}

void AdjustmentButton::buttonReleased_moreLow()
{
timer_low->stop();
}

void AdjustmentButton::doIncrement()
{
++number;
ui->label->setText(QString("Value: %1").arg(number));
if(timerTimeout > 50)
timerTimeout = timerTimeout / 2;
timer_high->start(timerTimeout);
}

void AdjustmentButton::doDecrement()

{
number--;
ui->label->setText(QString("Value: %1").arg(number));
if(timerTimeout > 50)
timerTimeout = timerTimeout / 2;
timer_low->start(timerTimeout);
}

void AdjustmentButton::doMoreIncrement()
{
number=number+5;
ui->label->setText(QString("Value: %1").arg(number));
if(timerTimeout > 50)
timerTimeout = timerTimeout / 2;
timer_high->start(timerTimeout);
}

void AdjustmentButton::doMoreDecrement()

{
number=number-5;
ui->label->setText(QString("Value: %1").arg(number));
if(timerTimeout > 50)
timerTimeout = timerTimeout / 2;
timer_low->start(timerTimeout);
}


