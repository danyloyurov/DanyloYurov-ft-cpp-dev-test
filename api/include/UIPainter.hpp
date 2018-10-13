#ifndef UIPAINTER_HPP
#define UIPAINTER_HPP

#include <string>

class UIPainter {
public:
    void showMessage(const std::string& message) const;

public:
    static UIPainter& Instance() {
        static UIPainter instance;
        return instance;
    }

private:
    UIPainter();
    UIPainter(UIPainter const&);
    void operator=(UIPainter const&);
};

#endif
