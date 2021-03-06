#include <iostream>
#include <iomanip>

#include "color/color.hpp"

void fix_rgb();

int main( int argc, char *argv[] )
 {
  fix_rgb();

  return EXIT_SUCCESS;
 }

void fix_rgb()
 {
  color::rgb<double>  r;

  // Do some initialization
  color::make::red( r );

  // First check has to be false i.e ther is no overburn
  std::cout << color::check::overburn( r ) << std::endl;

  r.set<0>( 20.0 );

  // This one has to return true, i.e there is overburn
  std::cout << color::check::overburn( r ) << std::endl;

  // Fix
  color::fix::overburn( r );

  // Check fix
  std::cout << color::check::overburn( r ) << std::endl;
 }
