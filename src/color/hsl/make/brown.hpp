#ifndef color_hsl_make_brown
#define color_hsl_make_brown

// ::color::make::brown( c )

 namespace color
  {
   namespace make
    { //RGB equivalents: std::array<double,3>( { 0.647059, 0.164706, 0.164706 } ) - rgb(165,42,42) - #A52A2A

     template< typename tag_name >
      inline
      void brown( ::color::model< ::color::category::hsl< tag_name > > & color_parameter )
       {
        typedef ::color::category::hsl< tag_name >         category_left_type;
        typedef ::color::model< category_left_type  > left_type;

        typedef ::color::hsl< double >      right_type;

        static left_type local( right_type( { 0, 59.4202899, 40.5882353 } ) );

        color_parameter = local;
       }

    }
  }

#endif
