#include "cli.h"
#include <windows.h>

int main( int argc, char* argv[] )
{
    /* Задача 13.1.45
        Прочитать текстовый файл. � еализовать функцию замены одного слова на другое.
        */
    cli app( argc, argv );
    return app.exec();
}
