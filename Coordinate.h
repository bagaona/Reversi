//
// Created by or on 02/11/17.
//

#ifndef EX2_COORDINATE_H
#define EX2_COORDINATE_H


class Coordinate {
private:
    const int row;
    const int col;
public:
    Coordinate(int x1,int y1);
    int getRow() const ;
    int getCol() const;
    bool operator ==(const Coordinate &other) const {
        return row == other.getRow() && col == other.getCol(); }
    bool operator <(const Coordinate &other) const {
        return ((row < other.getRow())
                || ((row == other.getRow()) && (col < other.getCol())));  }
};


#endif //EX2_COORDINATE_H
