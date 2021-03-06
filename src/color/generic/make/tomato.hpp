#ifndef  color_generic_make_tomato
#define color_generic_make_tomato

// ::color::make::tomato( c )

// TODO #include "model.hpp"
// TODO #include "constant/make.hpp"

 namespace color
  {

   namespace make
    {

     template< typename category_name >
      void tomato( ::color::model< category_name > & color_parameter )
       {
        typedef ::color::model< category_name > model_type;
        typedef typename model_type::index_type index_type;

        // Do nothing to force specialization
       }

     template< typename category_name >
      inline
      ::color::model< category_name >
      tomato()
       {
        typedef ::color::model< category_name > model_type;
        static model_type dummy;
        // TODO Will call every time, That is no good.
        ::color::make::tomato( dummy );

        // Do nothing to force specialization
        return dummy;
       }

    }

    namespace constant
     {

      struct tomato /*: public ::color::constant::_base */ {};
      using  tomato_t    = ::color::constant::tomato;
      using  tomato_type = ::color::constant::tomato;

      template< typename category_name >
       struct make<::color::constant::tomato, category_name >
        {
         typedef category_name              category_type;
         typedef ::color::constant::tomato       color_type;

         typedef typename ::color::trait::container<category_type>::output_type       container_output_type;

         inline static void process( container_output_type & m )
          {
           m = ::color::make::tomato<category_type>( ).container();
          }

        };

     }

  }

#endif
