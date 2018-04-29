#ifndef QUADRANGULATE


#define QUADRANGULATE
#include "Point.h"
#include "Quadrilateral.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
class Quadrangulate
{

    public:

        Quadrangulate();
        virtual ~Quadrangulate();
        vector<Point*> ConvexSpiral(vector<Point>&);
        void Quadrangulation(vector<Point>&, vector<Quadrilateral>&, bool);
        vector<pair<Point*,Point*> > getDiagonals();

        vector<Point*> Spiral;
        bool d_check;
    //protected:
        
    private:
};
#endif //QUADRANGULATE