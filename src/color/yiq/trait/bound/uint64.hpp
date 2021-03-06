#ifndef color_yiq_trait_bound_uint64
#define color_yiq_trait_bound_uint64

#include "../../category.hpp"

#include "../../../_internal/utility/bound/general.hpp"

#include "../../../generic/trait/bound.hpp"



namespace color
 {
  namespace trait
   {

    template< >
     struct bound< ::color::category::yiq_uint64 >
      : public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > 
      {
      };

   }
 }

#endif
