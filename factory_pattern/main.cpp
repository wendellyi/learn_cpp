#include "SimpleFactory.h"
#include "AbstractFactory.h"

int main(void)
{
    Creator creator;
    Product* dvd = creator.factory(Creator::TYPE_DVD);
    Product* cd = creator.factory(Creator::TYPE_CD);

    dvd->play();
    cd->play();

    ///////////////////////////////////////////////////////////
    DVDFactory dvdFactory;
    CDFactory cdFactory;
    AbstractDisk *Dvd = dvdFactory.create();
    AbstractDisk *Cd = cdFactory.create();

    Dvd->play();
    Cd->play();

    return 0;
}