#ifndef color_cmy_make_thistle
#define color_cmy_make_thistle

// ::color::make::thistle( c )

 namespace color
  {
   namespace make
    { //RGB equivalents: std::array<double,3>( { 0.847059, 0.74902, 0.847059 } ) - rgb(216,191,216) - #D8BFD8

     template< typename tag_name >
      inline
      void thistle( ::color::model< ::color::category::cmy< tag_name > > & color_parameter )
       {
        typedef ::color::category::cmy< tag_name >         category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::cmy< double >      right_type;

        static left_type local( right_type( { 0.152941176, 0.250980392, 0.152941176 } ) );

        color_parameter = local;
       }

    }
  }

#endif
