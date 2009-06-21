#include "loadingwidget.h"

LoadingWidget::LoadingWidget(QWidget *parent) : QWidget(parent) {

    QPalette p = palette();
    p.setBrush(QPalette::Window, Qt::black);
    p.setBrush(QPalette::Text, Qt::white);
    setPalette(p);

    setAutoFillBackground(true);

    QBoxLayout *layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);

    QFont bigFont;
    bigFont.setPointSize(bigFont.pointSize()*4);

    titleLabel = new QLabel(this);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setForegroundRole(QPalette::Text);
    titleLabel->setWordWrap(true);
    titleLabel->setFont(bigFont);
    titleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(titleLabel);

    QFont biggerFont;
    biggerFont.setPointSize(biggerFont.pointSize()*2);

    descriptionLabel = new QLabel(this);
    descriptionLabel->setAlignment(Qt::AlignCenter);
    descriptionLabel->setForegroundRole(QPalette::Text);
    descriptionLabel->setWordWrap(true);
    descriptionLabel->setFont(biggerFont);
    descriptionLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(descriptionLabel);

    progressBar = new QProgressBar(this);
    progressBar->hide();
    layout->addWidget(progressBar);

    setLayout(layout);
}

void LoadingWidget::setVideo(Video *video) {
    QString title = video->title();
    // enhance legibility by splitting the title
    title = title.replace(" - ", "<p>");
    title = title.replace("] ", "]<p>");
    titleLabel->setText(title);
    descriptionLabel->setText(video->description());
    progressBar->hide();
}

void LoadingWidget::bufferStatus(int percent) {
    qDebug() << percent;
    progressBar->setShown(percent > 0);
    progressBar->setValue(percent);
}

void LoadingWidget::paintEvent(QPaintEvent *) {

    /*
    QPainter painter(this);
    painter.fillRect(0, 0, width(), height(), Qt::black);
    */

}
