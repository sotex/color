#ifndef color_yiq_yiq_
#define color_yiq_yiq_

#include "../generic/type/type.hpp"

#include "./category.hpp"
#include "./akin/akin.hpp"
#include "./trait/trait.hpp"

#include "../generic/model.hpp"



namespace color
 {
  namespace _internal
   {

    template< typename type_name >
     struct pick_yiq
      {
       typedef ::color::category::yiq_uint32 category_type;
      };


    template<> struct pick_yiq< std::uint8_t   >{ typedef ::color::category::yiq_uint8   category_type; };
    template<> struct pick_yiq< std::uint16_t  >{ typedef ::color::category::yiq_uint16  category_type; };
    template<> struct pick_yiq< std::uint32_t  >{ typedef ::color::category::yiq_uint32  category_type; };
    template<> struct pick_yiq< std::uint64_t  >{ typedef ::color::category::yiq_uint64  category_type; };
    template<> struct pick_yiq< float          >{ typedef ::color::category::yiq_float   category_type; };
    template<> struct pick_yiq< double         >{ typedef ::color::category::yiq_double  category_type; };
    template<> struct pick_yiq< long    double >{ typedef ::color::category::yiq_ldouble category_type; };
   }

  template< typename type_name >
   using yiq = ::color::model< typename ::color::_internal::pick_yiq< type_name >::category_type >;

 }





#include "./place/place.hpp"

#include "./get/get.hpp"
#include "./set/set.hpp"

#include "./convert/convert.hpp"
#include "./make/make.hpp"


#endif
