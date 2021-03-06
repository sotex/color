#ifndef color_rgb_make_chocolate
#define color_rgb_make_chocolate

// ::color::make::chocolate( c )

 namespace color
  {
   namespace make
    { //RGB equivalent std::array<double,3>( { 210.0/255.0, 105.0/255.0, 30.0/255.0 } ) - rgb(210,105,30) - #D2691E

     template< typename tag_name >
      inline
      void chocolate( ::color::model< ::color::category::rgb< tag_name > > & color_parameter )
       {
        typedef ::color::category::rgb< tag_name     > category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::rgb< std::uint8_t >      right_type;

        static left_type local( right_type( { 0xD2, 0x69, 0x1E } ) );

        color_parameter = local;
       }

    }
  }

#endif
