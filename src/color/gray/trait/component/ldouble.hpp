#ifndef color_gray_trait_component_ldouble
#define color_gray_trait_component_ldouble

#include "../../category.hpp"

#include "../../../_internal/utility/component/array.hpp"

#include "../../../generic/trait/component.hpp"



namespace color
 {
  namespace trait
   {

    template< >
     struct component< ::color::category::gray_ldouble >
      : public ::color::_internal::utility::component::array< long double, unsigned >
      {
      };

   }
 }

#endif