#ifndef __POINT_HPP_INCLUDED__
#define __POINT_HPP_INCLUDED__

class Point
{
    public:

        /***************************************************************************************************/
        /**     Builders and destroyers : */

        Point();
        Point(int coord);
        Point(int x, int y);

        ~Point();

        void Display() const;

        /***************************************************************************************************/
        /*      Methods     */

        void move(int x, int y);

        bool XEqualsY() const;

        float Distance(Point const& p) const;
        float Distance(int x, int y) const;

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


        static int GetPointCount();

    private:
        int m_x;
        int m_y;

        static int m_pointCount;

};

#endif

