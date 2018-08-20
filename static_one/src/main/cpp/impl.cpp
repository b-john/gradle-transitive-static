
#include "static_one.h"


// If dependency on static_two removed & removed from build.gradle, will break app compilation.
#include "static_two.h"

void Foo ()
{
   FancyPrint ("In static library one");
}
