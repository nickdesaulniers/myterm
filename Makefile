default:
	clang++ `pkg-config --cflags --libs Qt5Widgets qtermwidget5` -fPIC -std=c++14 main.cpp -o myterm

clean:
	rm -f *.o myterm
