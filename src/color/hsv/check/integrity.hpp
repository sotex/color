#ifndef color_hsv_check_integrity
#define color_hsv_check_integrity

// ::color::check::integrity< category >( model )

#include "../../generic/check/integrity.hpp"
#include "../category.hpp"

namespace color
 {
  namespace check
   {
    namespace _internal
     {

      template<>
       struct integrity< ::color::category::hsv_float>
        {
         public:
          typedef ::color::category::hsv_float category_type;

          typedef ::color::model<category_type>          model_type;
          typedef ::color::trait::bound< category_type >        bound_type;

          static bool process( model_type const& m )
           {
            if( m.template get<0>() < bound_type::template minimum<0>() ) { return false; }
            if( bound_type::template maximum<0>() < m.template get<0>() ) { return false; }
            return true;
           }
        };

      template<>
       struct integrity< ::color::category::hsv_double >
        {
         public:
          typedef ::color::category::hsv_double category_type;
      
          typedef ::color::model<category_type>          model_type;
          typedef ::color::trait::bound< category_type >        bound_type;
      
          static bool process( model_type const& m )
           {
            if( m.template get<0>() < bound_type::template minimum<0>() ) { return false; }
            if( bound_type::template maximum<0>() < m.template get<0>() ) { return false; }
            return true;
           }
        };

      template<>
       struct integrity< ::color::category::hsv_ldouble >
        {
         public:
          typedef ::color::category::hsv_ldouble category_type;

          typedef ::color::model<category_type>          model_type;
          typedef ::color::trait::bound< category_type >        bound_type;

          static bool process( model_type const& m )
           {
            if( m.template get<0>() < bound_type::template minimum<0>() ) { return false; }
            if( bound_type::template maximum<0>() < m.template get<0>() ) { return false; }
            return true;
           }
        };

     }
   }
 }

#endif
