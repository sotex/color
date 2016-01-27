#ifndef color_cmyk_get_green
#define color_cmyk_get_green

// ::color::get::green( c )

#include "../../rgb/akin/cmyk.hpp"
#include "../../rgb/trait/component.hpp"

#include "../category.hpp"

#include "../../_internal/normalize.hpp"
#include "../../_internal/diverse.hpp"
#include "../../generic/trait/scalar.hpp"


 namespace color
  {
   namespace get
    {


     template< typename tag_name >
      inline
      typename ::color::trait::component< typename ::color::akin::rgb<::color::category::cmyk< tag_name > >::akin_type >::return_type
      green( ::color::_internal::model< ::color::category::cmyk< tag_name > > const& color_parameter )
       {
        typedef ::color::category::cmyk< tag_name > category_type;
        typedef typename ::color::trait::scalar< category_type >::instance_type   scalar_type;

        typedef typename ::color::akin::rgb< category_type >::akin_type     akin_type;

        typedef ::color::_internal::diverse< akin_type >       diverse_type;
        typedef ::color::_internal::normalize< category_type > normalize_type;
 
        scalar_type value = /* TODO */
               0.2126 * normalize_type::template process<0>( color_parameter.template get<0>() )
             + 0.7152 * normalize_type::template process<1>( color_parameter.template get<1>() )
             + 0.0722 * normalize_type::template process<2>( color_parameter.template get<2>() );

        return diverse_type::template process<0>( value );
       }

    }
  }

#endif