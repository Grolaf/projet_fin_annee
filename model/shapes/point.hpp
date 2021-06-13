#ifndef __POINT_HPP_INCLUDED__
#define __POINT_HPP_INCLUDED__
#include <iostream>

class Point
{
    private:
        int m_x;
        int m_y;

    public:

        /***************************************************************************************************/
        /**     Builders and destroyers : */

        Point();
        Point(int coord);
        Point(int x, int y);

        ~Point();


        /***************************************************************************************************/
        /*      Methods     */

        void move(int x, int y);

        bool XEqualsY() const;

        float Distance(Point const& p) const;
        float Distance(int x, int y) const;
        void write(std::ostream& file) const;
        void read(std::istream& file);

        /***************************************************************************************************/
        /*      Getters     */

        int GetX() const;
        int GetY() const;

        /***************************************************************************************************/
        /*      Setters     */

        void SetX(int x);
        void SetY(int y);

        /***************************************************************************************************/
        /*      Static methods     */


};

#endif

