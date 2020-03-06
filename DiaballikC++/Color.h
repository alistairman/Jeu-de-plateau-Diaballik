#ifndef COLOR_H
#define COLOR_H

enum class Color{
    BLACK,
    WHITE,
    NO
};

Color getBlack();
Color getWhite();
Color getNo();


Color getBlack(){
    return Color::BLACK;
}
Color getWhite(){
    return Color::WHITE;
}
Color getNo(){
    return Color::NO;
}



#endif // COLOR_H
