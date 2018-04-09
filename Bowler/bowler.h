//
// Created by steph on 4/1/2018.
//

#ifndef BOWLER_BOWLER_H
#define BOWLER_BOWLER_H

#include <string>
#include <iostream>
using namespace std;

class bowler {
private:
    string first;
    string last;
    int    score1;
    int    score2;
    int    score3;
    double avg;

public:
    bowler() {
        first  = "";
        last   = "";
        score1 = 0;
        score2 = 0;
        score3 = 0;
        avg    = 0;
    }

    bowler(const string &first, const string &last, int score1, int score2, int score3, double avg) : first(first),
                                                                                                      last(last),
                                                                                                      score1(score1),
                                                                                                      score2(score2),
                                                                                                      score3(score3),
                                                                                                      avg(avg) {}

    bowler( bowler temp ) {
        first  = temp.first;
        last   = temp.last;
        score1 = temp.score1;
        score1 = temp.score2;
        score1 = temp.score3;
        avg    = temp.avg;
    }

    bowler& operator= ( const bowler &temp ) {
        first  = temp.first;
        last   = temp.last;
        score1 = temp.score1;
        score1 = temp.score2;
        score1 = temp.score3;
        avg    = temp.avg;
        return *this;
    }

    double getAvg() const {
        return avg;
    }

    void setAvg( double avg ) {
        bowler::avg = avg;
    }

    const string &getFirst() const {
        return first;
    }

    void setFirst( const string &first ) {
        bowler::first = first;
    }

    const string &getLast() const {
        return last;
    }

    void setLast( const string &last ) {
        bowler::last = last;
    }

    int getScore1() const {
        return score1;
    }

    void setScore1( int score1 ) {
        bowler::score1 = score1;
    }

    int getScore2() const {
        return score2;
    }

    void setScore2( int score2 ) {
        bowler::score2 = score2;
    }

    int getScore3() const {
        return score3;
    }

    void setScore3( int score3 ) {
        bowler::score3 = score3;
    }

    bool operator== ( bowler user ) {
        if( user.avg == this->avg )
            return true;

        return false;
    }

    bool operator> ( bowler user ) {
        if( this->avg > user.avg )
            return true;

        return false;
    }

    bool operator< ( bowler user ) {
        if( this->avg < user.avg )
            return true;

        return false;
    }
};


#endif //BOWLER_BOWLER_H
