//
// Created by gang cheng on 2021/5/30.
//

#include "include/calculator.h"

double expr(bool get);

Token_stream ts{cin};
int no_of_errors;
map<string, double> table; // 符号表

double error(const string &s) {
    no_of_errors++;
    cout << "error: " << s << '\n';
    return 1;
}

Token Token_stream::get() {
    char ch;

    do { // 跳过除'\n'之外的其他空白符
        if (!ip->get(ch)) return ct = {Kind::end};
    } while (ch != '\n' && isspace(ch));

    switch (ch) {
        case 0:
            return ct = {Kind::end};
        case ';':
        case '\n':
            return ct = {Kind::print};
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return ct = {static_cast<Kind>(ch)};
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '.': {
            ip->putback(ch);
            *ip >> ct.number_value;
            ct.kind = Kind::number;
            return ct;
        }
        default:
            if (isalpha(ch)) {
                ct.string_value = ch;
                while (ip->get(ch) && isalnum(ch))
                    ct.string_value += ch;
                ip->putback(ch);
                ct.kind = Kind::name;
                return ct;
            }

            error("bad token");
            return ct = {Kind::print};
    }
}

double prim(bool get) {
    if (get) ts.get();

    switch (ts.current().kind) {
        case Kind::number: {
            double v = ts.current().number_value;
            ts.get();
            return v;
        }
        case Kind::name: {
            double &v = table[ts.current().string_value];
            if (ts.get().kind == Kind::assign) v = expr(true);
            return v;
        }
        case Kind::minus: {
            return -prim(true);
        }
        case Kind::lp: {
            auto e = expr(true);
            if (ts.current().kind != Kind::rp) return error("')' expected.");
            ts.get(); // 吃掉了')'
            return e;
        }
        default:
            return error("primary expected.");
    }
}

double term(bool get) {
    double left = prim(get);

    for (;;) {
        switch (ts.current().kind) {
            case Kind::mul:
                left *= prim(true);
                break;
            case Kind::div:
                if (auto d = prim(true)) {
                    left /= d;
                    break;
                }
                return error("divide by 0");
            default:
                return left;
        }
    }
}

double expr(bool get) {
    double left = term(get);

    for (;;) {
        switch (ts.current().kind) {
            case Kind::plus:
                left += term(true);
                break;
            case Kind::minus:
                left -= term(true);
                break;
            default:
                return left;
        }
    }
}

void calculate() {
    for (;;) {
        ts.get();
        if (ts.current().kind == Kind::end) break;
        if (ts.current().kind == Kind::print) continue;
        cout << expr(false) << '\n';
    }
}