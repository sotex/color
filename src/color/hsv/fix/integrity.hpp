#ifndef  color_hsv_fix_integrity
#define  color_hsv_fix_integrity

#include "../category.hpp"
#include "../../generic/fix/integrity.hpp"
#include "../trait/bound.hpp"


 namespace color
  {
   namespace fix
    {
     namespace _internal
      {
       namespace _privateHSV
        {

         template< typename category_name >
          struct integrity
           {
            public:
              typedef category_name  category_type;

              typedef typename ::color::model<category_type>  model_type;
              typedef typename ::color::trait::bound<category_type>      bound_type;

              static void process( model_type &result )
               {
                if( result.template get<0>() < bound_type::template minimum<0>() )
                 {
                  result.template set<0>( bound_type::template minimum<0>() );
                  return;
                 }
                if( bound_type::template maximum<0>() < result.template get<0>() ) 
                 {
                  result.template set<0>( bound_type::template maximum<0>() );
                  return;
                 }
               }

              static void process(  model_type &result, model_type const& right )
               {
                result = right;
                if( result.template get<0>() < bound_type::template minimum<0>() )
                 {
                  result.template set<0>( bound_type::template minimum<0>() );
                  return;
                 }
                if( bound_type::template maximum<0>() < result.template get<0>() ) 
                 {
                  result.template set<0>( bound_type::template maximum<0>() );      
                  return;
                 }
               }

           };

      }

       //template<> struct integrity< ::color::category::hsv_uint8   > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_uint8  >{ };
       //template<> struct integrity< ::color::category::hsv_uint16  > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_uint16 >{ };
       //template<> struct integrity< ::color::category::hsv_uint32  > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_uint32 >{ };
       //template<> struct integrity< ::color::category::hsv_uint64  > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_uint64 >{ };
       template<> struct integrity< ::color::category::hsv_float   > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_float  >{ };
       template<> struct integrity< ::color::category::hsv_double  > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_double >{ };
       template<> struct integrity< ::color::category::hsv_ldouble > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_ldouble>{ };

      }
    }
  }

#endif
