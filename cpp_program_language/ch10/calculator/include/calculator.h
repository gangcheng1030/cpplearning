#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <iostream>
#include <string>
#include <map>

using namespace std;

void calculate();

extern int no_of_errors;
extern map<string, double> table; // 符号表

enum class Kind : char {
    name, number, end,
    plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rp=')'
};

struct Token {
    Kind kind;
    string string_value;
    double number_value;
};

class Token_stream {
public:
    Token_stream(istream& s) : ip{&s}, owns{false} {}
    Token_stream(istream* p) : ip{p}, owns{true} {}

    ~Token_stream() { close(); }

    Token get(); // 读取并返回下一个单词
    const Token& current() { return ct; } // 刚刚读入的单词

    void set_input(istream& s)
    {
        close();
        ip = &s;
        owns = false;
    }

    void set_input(istream* p)
    {
        close();
        ip = p;
        owns = true;
    }

private:
    void close()
    {
        if (owns) {
            delete ip;
        }
    }

    istream* ip;
    bool owns;
    Token ct {Kind::end};
};

#endif //CALCULATOR_CALCULATOR_H
