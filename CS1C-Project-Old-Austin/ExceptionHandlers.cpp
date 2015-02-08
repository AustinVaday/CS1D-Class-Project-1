
#include "ExceptionHandlers.h"

NotFound::NotFound()
{
    qDebug() << endl <<  "Constructed NotFound Exception " << endl;

}



NotFound::~NotFound()
{

}

EmptyList::EmptyList()
{
    qDebug() << endl <<  "Constructed EmptyLIist Exception " << endl;

}
EmptyList::~EmptyList()
{
    qDebug() << endl <<  "Constructed NotFound Exception " << endl;

}

OutOfRange::OutOfRange()
{
    qDebug() << endl <<  "Constructed OutOfRange Exception " << endl;

}

OutOfRange::~OutOfRange()
{

}
