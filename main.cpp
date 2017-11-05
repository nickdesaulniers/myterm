#include <memory>

#include <QApplication>
#include <QKeySequence>
#include <QMainWindow>

#include "qtermwidget.h"

int main (int argc, char** argv) {
  QApplication app(argc, argv);
  std::unique_ptr<QMainWindow> mainWindow = std::make_unique<QMainWindow>();
  std::unique_ptr<QTermWidget> console = std::make_unique<QTermWidget>();
  QFont font = QApplication::font();
  font.setFamily("Monospace");
  font.setPointSize(12);
  console->setTerminalFont(font);
  QObject::connect(console.get(), SIGNAL(finished()), mainWindow.get(), SLOT(close()));
  mainWindow->setCentralWidget(console.get());
  mainWindow->show();
  return app.exec();
}
