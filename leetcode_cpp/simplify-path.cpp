class Solution {
public:
    string simplifyPath(string path) {
        int length = path.size();
        string result;
        if (length == 0 || path[0] != '/') {
            return path;
        }
        stack<string> paths;
        string dir_name;
        int pi = 0;
        while (pi < length) {
            while (path[pi] == '/' ) {
                pi++;
            }
            if (pi == length) {
                break;
            }
            if (path[pi] == '.') {
                if ((pi + 1) == length) {
                    break;
                }
                if (path[pi + 1] == '/') {  // (./)
                    pi += 2;
                } else if (path[pi + 1] == '.') {  // (..)
                    if ((pi + 2) == length || (path[pi +2] == '/')) {   // (../)(..)
                        if (!paths.empty()) {
                            paths.pop();
                        }
                        pi += 3;
                    } else {
                        dir_name = "..";
                        pi += 2;
                        while (pi < length && path[pi] != '/') {
                            dir_name.push_back(path[pi]);
                            pi++;
                        }
                        paths.push(dir_name);
                        dir_name.clear();
                    }
                } else {
                    dir_name = ".";
                    pi += 1;
                    while (pi < length && path[pi] != '/') {
                        dir_name.push_back(path[pi]);
                        pi++;
                    }
                    paths.push(dir_name);
                    dir_name.clear();
                }
            } else {
                while (pi < length && path[pi] != '/') {
                    dir_name.push_back(path[pi]);
                    pi++;
                }
                paths.push(dir_name);
                dir_name.clear();
            }
        }
        if (paths.size() == 0) {
            return "/";
        }
        while (!paths.empty()) {
            result.insert(0, paths.top());
            paths.pop();
            result.insert(0, "/");
        }
        return result;
    }
};