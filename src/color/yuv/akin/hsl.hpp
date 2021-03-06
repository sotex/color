#ifndef color_yuv_akin_hsl
#define color_yuv_akin_hsl

#include "../../generic/akin/yuv.hpp"
#include "../category.hpp"
#include "../../hsl/category.hpp"

namespace color
 {
  namespace akin
   {

    template< >struct yuv< ::color::category::hsl_uint8   >{ typedef ::color::category::yuv_uint8   akin_type; };
    template< >struct yuv< ::color::category::hsl_uint16  >{ typedef ::color::category::yuv_uint16  akin_type; };
    template< >struct yuv< ::color::category::hsl_uint32  >{ typedef ::color::category::yuv_uint32  akin_type; };
    template< >struct yuv< ::color::category::hsl_uint64  >{ typedef ::color::category::yuv_uint64  akin_type; };
    template< >struct yuv< ::color::category::hsl_float   >{ typedef ::color::category::yuv_float   akin_type; };
    template< >struct yuv< ::color::category::hsl_double  >{ typedef ::color::category::yuv_double  akin_type; };
    template< >struct yuv< ::color::category::hsl_ldouble >{ typedef ::color::category::yuv_ldouble akin_type; };

   }
 }

#endif
