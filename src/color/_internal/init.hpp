#ifndef color_generic_init
#define color_generic_init

// ::color::make::white( c )

#include "../generic/trait/index.hpp"
#include "../generic/trait/container.hpp"
#include "../generic/trait/component.hpp"


 namespace color
  {
   namespace _internal
    {

     template< typename category_name >
      void init
       (
          typename ::color::trait::container< category_name >::output_type                                    container
        , std::initializer_list< typename ::color::trait::component< category_name >::instance_type > const&  ilist
       )
       {
        typedef ::color::trait::container< category_name >                      container_trait_type;

        typedef typename ::color::trait::index< category_name >::instance_type     index_type;

        //TODO C++14 static_assert( ilist.size() < container_trait_type::size_enum, "Initizlizer list size do not mach model/format length." );

        auto ili = ilist.begin();
        index_type index=0;
        for( ; index < std::min( container_trait_type::size(), ilist.size() ) ; ++index, ++ili )
         {
          container_trait_type::set( container, index, *ili );
         }
       };

    }
  }

#endif
