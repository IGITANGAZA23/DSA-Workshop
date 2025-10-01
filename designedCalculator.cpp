#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <string>
#include <sstream>
#include <stdexcept>
#include <cctype>

Fl_Input* display;

double evaluate(const std::string& expr) {
    std::istringstream ss(expr);
    double result, num;
    char op;

    ss >> result;
    while (ss >> op >> num) {
        switch (op) {
            case '+': result += num; break;
            case '-': result -= num; break;
            case '*': result *= num; break;
            case '/':
                if (num == 0) throw std::runtime_error("Divide by zero");
                result /= num;
                break;
            default: break;
        }
    }
    return result;
}
void button_cb(Fl_Widget* w, void*) {
    const char* label = w->label();
    std::string text = display->value();

    if (std::string(label) == "AC") {
        display->value("");
    } else if (std::string(label) == "DEL") {
        if (!text.empty()) {
            text.pop_back();
            display->value(text.c_str());
        }
    } else if (std::string(label) == "%") {
        if (!text.empty()) {
            int i = text.size() - 1;
            while (i >= 0 && (isdigit(text[i]) || text[i] == '.')) i--;
            std::string lastNum = text.substr(i + 1);
            if (!lastNum.empty()) {
                double num = std::stod(lastNum);
                num = num / 100.0;
                text = text.substr(0, i + 1) + std::to_string(num);
                display->value(text.c_str());
            }
        }
    } else if (std::string(label) == "=") {
        try {
            double res = evaluate(text);
            display->value(std::to_string(res).c_str());
        } catch (...) {
            display->value("Cannot divide by 0");
        }
    } else {
        text += label;
        display->value(text.c_str());
    }
}

int main() {
    Fl_Window* win = new Fl_Window(280, 400, "Noble Calculator");
    win->color(FL_BLACK);

    display = new Fl_Input(10, 10, 260, 40);
    display->readonly(1);
    display->color(FL_BLACK);
    display->textcolor(FL_WHITE);
    display->textsize(24);

    const char* labels[5][4] = {
        {"AC", "DEL", "%", "/"},
        {"7", "8", "9", "*"},
        {"4", "5", "6", "-"},
        {"1", "2", "3", "+"},
        {"0", ".", "=", ""}
    };

    int btnSize = 60;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (labels[i][j][0] == '\0') continue;

            int x = 10 + j * 65;
            int y = 60 + i * 65;

            Fl_Button* b = new Fl_Button(x, y, btnSize, btnSize, labels[i][j]);
            b->callback(button_cb);

            b->box(FL_FLAT_BOX);
            b->labelsize(20);

            std::string lab = labels[i][j];
            if (lab == "AC" || lab == "DEL" || lab == "%") {
                b->color(FL_GRAY);
                b->labelcolor(FL_BLACK);
            } else if (lab == "/" || lab == "*" || lab == "-" || lab == "+" || lab == "=") {
                b->color(FL_DARK_YELLOW);
                b->labelcolor(FL_WHITE);
            } else {
                b->color(FL_DARK3);
                b->labelcolor(FL_WHITE);
            }
        }
    }

    win->end();
    win->show();
    return Fl::run();
}
