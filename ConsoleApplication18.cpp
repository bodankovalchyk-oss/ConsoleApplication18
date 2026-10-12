
#include <iostream>
#include <string>
using namespace std;

struct Coord {
    int x;
    int y;
};

class Rectangle {
private:
    int width;
    int height;
    char symbol;
    Coord position;

public:
    Rectangle() : width(5), height(3), symbol('*'), position{ 0, 0 } {}

    Rectangle(int size)
        : width(size > 0 ? size : 5),
        height(size > 0 ? size : 3),
        symbol('*'), position{ 0, 0 } {
    }

    Rectangle(int w, int h)
        : width(w > 0 ? w : 5),
        height(h > 0 ? h : 3),
        symbol('*'), position{ 0, 0 } {
    }

    void Show() const {
        if (width <= 0 || height <= 0 ||
            position.x < 0 || position.y < 0) {
            cout << "Invalid data!\n";
            return;
        }

        cout << "\nPosition: X=" << position.x
            << ", Y=" << position.y << '\n';

        for (int i = 0; i < position.y; i++)
            cout << '\n';

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < position.x; j++)
                cout << ' ';

            for (int j = 0; j < width; j++)
                cout << symbol;

            cout << '\n';
        }
    }

    void ChangeSize(int dh, int dw) {
        if (height + dh <= 0 || width + dw <= 0) {
            cout << "Invalid size!\n";
            return;
        }

        height += dh;
        width += dw;
    }

    void Move(int dx, int dy) {
        if (position.x + dx < 0 || position.y + dy < 0) {
            cout << "Invalid coordinates!\n";
            return;
        }

        position.x += dx;
        position.y += dy;
    }

    void SetSymbol(char s) {
        symbol = s;
    }
};

int main() {
    Rectangle r1;
    Rectangle r2(5);
    Rectangle r3(8, 4);

    cout << "Default rectangle:\n";
    r1.Show();

    cout << "\nSquare:\n";
    r2.Show();

    cout << "\nRectangle 8x4:\n";
    r3.Show();

    cout << "\nChange size:\n";
    r3.ChangeSize(2, 3);
    r3.Show();

    cout << "\nMove rectangle:\n";
    r3.Move(2, 1);
    r3.Show();

    cout << "\nChange symbol:\n";
    r3.SetSymbol('#');
    r3.Show();

    return 0;
}