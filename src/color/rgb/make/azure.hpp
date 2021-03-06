#ifndef color_rgb_make_azure
#define color_rgb_make_azure

// ::color::make::azure( c )

 namespace color
  {
   namespace make
    { //RGB equivalents: std::array<double,3>( { 240.0/255.0, 1, 1 } ) - rgb(240,255,255) - #f0ffff

     template< typename tag_name >
      inline
      void azure( ::color::model< ::color::category::rgb< tag_name > > & color_parameter )
       {
        typedef ::color::category::rgb< tag_name     > category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::rgb< double >      right_type;

        static left_type local( right_type( { 0.9375, 1, 1 } ) );

        color_parameter = local;
       }

    }
  }

#endif
