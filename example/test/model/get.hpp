#include <iomanip>
#include <iostream>

#include "color/color.hpp"
#include "../print.hpp"

template< typename category_name >
 void test_generic_get()
  {
   //std::cout << std::endl;
   //std::cout << "{{{{ {{{{ {{{{ {{{{ {{{{ {{{{ {{{{ {{{{ {{{{ {{{{ {{{{ {{{{ {{{{ {{{{ {{{{ {{{{"<< std::endl;
   //std::cout << "begin - " << __FUNCTION__ ;
   //std::cout << "  < " << typeid( category_name ).name()   << " > ()" << std::endl;
   //std::cout << std::endl;

   typedef color::model< category_name > model_type;
   typedef typename model_type::component_type     component_type;

   model_type   c;
   color::make::black(c);
   color::make::gray50(c);

   color::get::alpha( c ) ;
   color::get::gray( c )  ;
   color::get::red( c )   ;
   color::get::green( c ) ;
   color::get::blue( c )  ;
   color::get::hue( c )   ;

   //std::cout << std::endl;
   //std::cout << "end - " << __FUNCTION__ ;
   //std::cout << "  < " << typeid( category_name ).name()   << " > ()" << std::endl;
   //std::cout << "}}}} }}}} }}}} }}}} }}}} }}}} }}}} }}}} }}}} }}}} }}}} }}}} }}}} }}}} }}}} }}}}" << std::endl;
 }

