#ifndef color_cmy_trait_component_uint16
#define color_cmy_trait_component_uint16

#include "../../category.hpp"

#include "../../../_internal/utility/component/array.hpp"

#include "../../../generic/trait/component.hpp"



namespace color
 {
  namespace trait
   {

    template< >
     struct component< ::color::category::cmy_uint16 >
      : public ::color::_internal::utility::component::array< std::uint16_t, unsigned >
      {
      };

   }
 }

#endif
