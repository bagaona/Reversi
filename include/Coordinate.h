//
// Created by or on 02/11/17.
//

#ifndef REVERSI_COORDINATE_H
#define REVERSI_COORDINATE_H


class Coordinate {
private:
    const int row;
    const int col;
public:
    Coordinate(int x1,int y1);
    int getRow() const ;
    int getCol() const;
    bool operator ==(const Coordinate &other) const;
    bool operator <(const Coordinate &other) const;
};


#endif //EX2_COORDINATE_H
