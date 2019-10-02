//
// Created by ida on 12.09.19.
//

#ifndef NUMBERCHECK_H
#define NUMBERCHECK_H

enum class state {
    S,
    D1,
    PM1,
    DOT,
    E,
    D2,
    PM2
};

namespace numbercheck {
    class FloatingPointChecker {
    public:
        bool check(std::string s) {
            idx = 0;

            state current{state::S};
            while (idx < s.length()) {
                switch(current) {
                    case state::S:
                        if (isdigit(s[idx])) {
                            current = state::D1;
                        } else if (s[idx] == '+' || s[idx] == '-') {
                            current = state::PM1;
                        } else if (s[idx] == '.') {
                            current = state::DOT;
                        } else {
                            return false;
                        }
                        idx++;
                        break;
                    case state::D1:
                        if (isdigit(s[idx])) {
                            current = state::D1;
                        } else if (s[idx] == '.') {
                            current = state::DOT;
                        } else {
                            return false;
                        }
                        idx++;
                        break;
                    case state::PM1:
                        if (isdigit(s[idx])) {
                            current = state::D1;
                        } else if (s[idx] == '.') {
                            current = state::DOT;
                        } else {
                            return false;
                        }
                        idx++;
                        break;
                    case state::DOT:
                        if (isdigit(s[idx])) {
                            current = state::D2;
                        } else if (s[idx] == 'e') {
                            current = state::E;
                        } else {
                            return false;
                        }
                        idx++;
                        break;
                    case state::D2:
                        if (isdigit(s[idx])) {
                            current = state::D2;
                        } else if (s[idx] == 'e') {
                            current = state::E;
                        } else {
                            return false;
                        }
                        idx++;
                        break;
                    case state::E:
                        if (isdigit(s[idx])) {
                            current = state::D2;
                        } else if (s[idx] == '+' || s[idx] == '-') {
                            current = state::PM2;
                        } else {
                            return false;
                        }
                        idx++;
                        break;
                    case state::PM2:
                        if (isdigit(s[idx])) {
                            current = state::D2;
                        } else {
                            return false;
                        }
                        idx++;
                        break;
                }
            }
            if (current == state::D1 || current == state::DOT || current == state::D2) {
                return true;
            } else {
                return false;
            }
        }

    private:
        long unsigned int idx{0};
    };

}

#endif //NUMBERCHECK_H
