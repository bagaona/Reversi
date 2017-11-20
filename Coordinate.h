//
// Created by or on 02/11/17.
//

#ifndef EX2_COORDINATE_H
#define EX2_COORDINATE_H


class Coordinate {
private:
    const int x;
    const int y;
public:
    Coordinate(int x1,int y1);
    int getX() const ;
    int getY() const;
    bool operator ==(const Coordinate &other) const { return x == other.getX() && y == other.getY() ;}
    bool operator <(const Coordinate &other) const { return x < other.getX();}
};


#endif //EX2_COORDINATE_H
