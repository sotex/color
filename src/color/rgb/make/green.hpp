#ifndef color_rgb_make_green
#define color_rgb_make_green

// ::color::make::green( c )

 namespace color
  {
   namespace make
    { //RGB equivalent std::array<double,3>( { 0, 0.5, 0 } ) - rgb(0,127,0) - #007F00

     template< typename tag_name >
      inline
      void green( ::color::model< ::color::category::rgb< tag_name > > & color_parameter )
       {
        typedef ::color::category::rgb< tag_name     > category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::rgb< double >      right_type;

        static left_type local( right_type( { 0, 0.5, 0 } ) );

        color_parameter = local;
       }

    }
  }

#endif
