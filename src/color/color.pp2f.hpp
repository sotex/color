
namespace color {
namespace akin {

template< typename category_name >
struct cmy {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct cmyk {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct gray {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct hsl {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct hsv {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct rgb {
	typedef void akin_type;

};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct yiq {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace akin {

template< typename category_name >
struct yuv {
	typedef category_name category_type;
	typedef void akin_type;
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace type {

template< typename index_name >
struct index {
public:
	typedef index_name instance_type;

	typedef instance_type const const_type;

	typedef instance_type const& return_image_type;
	typedef instance_type return_type;
	typedef instance_type & return_original_type;

	typedef instance_type const& input_const_type, param_const_input_type;
	typedef instance_type input_type, param_input_type;
	typedef instance_type & output_type, param_output_type;
	typedef instance_type & transmit_type, param_transmit_type;
};

}
}
}
}

namespace color {
namespace trait {

template< typename category_name >
struct index
		: public ::color::_internal::utility::type::index< unsigned > {
public:

	typedef ::color::_internal::utility::type::index< unsigned > utility_type;

	typedef typename utility_type::instance_type instance_type;

	typedef typename utility_type::const_type const_type;

	typedef typename utility_type::return_image_type return_image_type;
	typedef typename utility_type::return_original_type return_original_type;

	typedef typename utility_type::input_const_type input_const_type;
	typedef typename utility_type::input_type input_type;
	typedef typename utility_type::output_type output_type;
};

}
}

namespace color {
namespace trait {

template< typename category_name , unsigned index_size = 0 >
struct component {
public:
	typedef unsigned char instance_type;
	typedef instance_type const const_type;

	typedef instance_type const return_image_type;
	typedef instance_type const return_const_ref_type;
	typedef instance_type return_type;
	typedef instance_type return_ref_type;

	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;

};

}
}

namespace color {
namespace trait {

template< typename category_name >
struct container {
public:
	typedef unsigned int instance_type;

	typedef instance_type const const_type;

	typedef instance_type const return_image_type;
	typedef instance_type const& return_const_ref_type;
	typedef instance_type & return_type;
	typedef instance_type & return_ref_type;

	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type, param_output_type;

	typedef ::color::trait::index< category_name > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::trait::component< category_name > component_trait_type;
	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;
	typedef typename component_trait_type::instance_type component_type;

	typedef void set_return_type;

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		return (component_type)((container >> (index << 3)) & 0xFF);
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		return (component_type)((container >> (index << 3)) & 0xFF);
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		container = (container & ~(0xFF << (index << 3))) | (((instance_type)value) << (index << 3));
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		container = (container & ~(0xFF << (index << 3))) | (((instance_type)value) << (index << 3));
	}

	static index_return_image_type size() {
		static index_instance_type length = 4;
		return length;
	}
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace type {

template < typename number_name, typename image_name = number_name const& >
struct bound {
public:
	typedef number_name number_type;
	typedef image_name image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value=0;
		return value;
	}

	static image_type minimum() {
		static number_type value=0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<bool, bool const& > {
	typedef bool number_type;
	typedef bool const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = true;
		return value;
	}

	static image_type minimum() {
		static number_type value = false;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<std::uint8_t, std::uint8_t const& > {
	typedef std::uint8_t number_type;
	typedef std::uint8_t const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = 255;
		return value;
	}

	static image_type minimum() {
		static number_type value = 0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<std::uint16_t, std::uint16_t const& > {
	typedef std::uint16_t number_type;
	typedef std::uint16_t const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = 0xFFFF;
		return value;
	}

	static image_type minimum() {
		static number_type value = 0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<std::uint32_t, std::uint32_t const& > {
	typedef std::uint32_t number_type;
	typedef std::uint32_t const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = 0xFFFFFFFF;
		return value;
	}

	static image_type minimum() {
		static number_type value = 0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<std::uint64_t, std::uint64_t const& > {
	typedef std::uint64_t number_type;
	typedef std::uint64_t const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = 0xFFFFFFFFFFFFFFFFu;
		return value;
	}

	static image_type minimum() {
		static number_type value = 0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<float, float const& > {
	typedef float number_type;
	typedef float const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value=1;
		return value;
	}

	static image_type minimum() {
		static number_type value=0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<double, double const& > {
	typedef double number_type;
	typedef double const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value=1;
		return value;
	}

	static image_type minimum() {
		static number_type value=0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}
};

template <>
struct bound<long double, long double const& > {
	typedef long double number_type;
	typedef long double const& image_type;

	typedef bound<number_type,image_type> this_type;

	static image_type maximum() {
		static number_type value = 1;
		return value;
	}

	static image_type minimum() {
		static number_type value = 0;
		return value;
	}

	static image_type range() {
		static number_type value = this_type::maximum() - this_type::minimum();
		return value;
	}

};

}
}
}
}

namespace color {
namespace _internal {
namespace utility {
namespace type {

template < typename type_name >
struct traitC {
public:
	typedef type_name instance_type;

	typedef instance_type const const_type;

	typedef instance_type const& return_image_type;
	typedef instance_type return_type;

	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;

};

}
}
}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename value_name, typename index_name >
struct general {
public:
	typedef value_name value_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< value_name > component_trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename component_trait_type::instance_type component_instance_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	typedef ::color::_internal::utility::type::bound< component_instance_type, component_return_const_type > bound_type;

	template< index_instance_type index >
	static component_return_const_type maximum() {
		static const component_instance_type component = bound_type::maximum();
		return component;
	}

	static component_return_const_type maximum(index_input_const_type index) {
		static const component_instance_type component = bound_type::maximum();
		return component;
	}

	template< index_instance_type index >
	static component_return_const_type minimum() {
		static const component_instance_type component = bound_type::minimum();
		return component;
	}

	static component_return_const_type minimum(index_input_const_type index) {
		static const component_instance_type component = bound_type::minimum();
		return component;
	}

	template< index_instance_type index >
	static component_return_const_type range() {
		static const component_instance_type component = bound_type::range();
		return component;
	}

	static component_return_const_type range(index_input_const_type index) {
		static const component_instance_type component = bound_type::range();
		return component;
	}
};

}
}
}
}

namespace color {

namespace trait {
template< typename category_name >
struct bound
		: public ::color::_internal::utility::bound::general
		<
		typename ::color::trait::component< category_name >::instance_type
		,typename ::color::trait::index< category_name >::instance_type
		> {
public:
	typedef category_name category_type;

	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::index< category_name > index_trait_type;

	typedef typename component_trait_type::instance_type component_instance_type;
	typedef typename index_trait_type::instance_type index_instance_type;

	typedef ::color::_internal::utility::bound::general<component_instance_type, index_instance_type > general_type;

	using general_type::minimum;
	using general_type::maximum;
	using general_type::range;
};

}
}

namespace color {
namespace _internal {

template< typename category_name >
struct trait
		: public ::color::trait::index< category_name >
		, public ::color::trait::container< category_name >
		, public ::color::trait::component< category_name >
		, public ::color::trait::bound< category_name > {
public:
	typedef ::color::trait::index< category_name > index_trait_type;
	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::container< category_name > container_trait_type;
	typedef ::color::trait::bound< category_name > bound_trait_type;

	typedef typename index_trait_type::instance_type index_type;
	typedef typename index_trait_type::const_type index_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::input_type index_input_type;

	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::return_type component_return_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;
	typedef typename component_trait_type::input_type component_input_type;

	typedef typename container_trait_type::instance_type container_type;
	typedef typename container_trait_type::const_type container_const_type;
	typedef typename container_trait_type::return_image_type container_return_const_type;
	typedef typename container_trait_type::return_type container_return_type;
	typedef typename container_trait_type::input_const_type container_input_const_type;
	typedef typename container_trait_type::input_type container_input_type;

	typedef typename container_trait_type::set_return_type set_return_type;

	using bound_trait_type::minimum;
	using bound_trait_type::maximum;
	using bound_trait_type::range;
};

}
}

namespace color {
namespace trait {

template< typename category_name >
struct scalar {
public:
	typedef double instance_type;

	static bool is_small(instance_type const& value) {
		return (-1e-6 < value) && (value < 1e-6);
	}
};

}
}

namespace color {
namespace _internal {

template< typename category_name >
struct diverse {
public:
	typedef typename ::color::trait::scalar<category_name>::instance_type scalar_type;
	typedef ::color::trait::bound< category_name > bound_trait_type;
	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::index< category_name > index_trait_type;

	typedef typename component_trait_type::instance_type component_instance_type;
	typedef typename component_trait_type::return_type component_return_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	static
	component_return_type
	process(scalar_type const& normal, index_input_const_type index) {
		scalar_type divergent = normal;
		divergent *= bound_trait_type::range(index);
		divergent += bound_trait_type::minimum(index);
		return component_instance_type(divergent);
	}

	template< index_instance_type index_size >
	static
	component_return_type
	process(scalar_type const& normal) {
		scalar_type divergent = normal;
		divergent *= bound_trait_type::template range<index_size>();
		divergent += bound_trait_type::template minimum<index_size>();
		return component_instance_type(divergent);
	}
};

}
}
namespace color {
namespace _internal {

template< typename category_name >
struct normalize {
public:
	typedef typename ::color::trait::scalar<category_name>::instance_type scalar_type;
	typedef ::color::trait::bound< category_name > bound_trait_type;
	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::index< category_name > index_trait_type;

	typedef typename component_trait_type::instance_type component_instance_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	static
	scalar_type
	process(component_input_const_type divergent, index_input_const_type index) {
		scalar_type normal = static_cast<component_instance_type>(divergent);
		normal -= bound_trait_type::minimum(index);
		normal /= bound_trait_type::range(index);
		return normal;
	}

	template< index_instance_type index_size >
	static
	scalar_type
	process(component_input_const_type divergent) {
		scalar_type normal = static_cast<component_instance_type>(divergent);
		normal -= bound_trait_type::template minimum<index_size>();
		normal /= bound_trait_type::template range<index_size>();
		return normal;
	}

};

}
}

namespace color {
namespace _internal {

template
<
typename category_left_name
,typename category_right_name
,typename scalar_name = double
>
struct reformat {
public:
	typedef category_left_name category_left_type;
	typedef category_right_name category_right_type;
	typedef scalar_name scalar_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef typename ::color::trait::component< category_left_name >::return_type left_component_return_type;
	typedef typename ::color::trait::index< category_left_name >::input_const_type left_index_const_input_type;
	typedef typename ::color::trait::index< category_left_name >::instance_type left_index_instance_type;

	typedef typename ::color::trait::component< category_right_name >::input_const_type right_component_const_input_type;
	typedef typename ::color::trait::index< category_right_name >::input_const_type right_index_const_input_type;
	typedef typename ::color::trait::index< category_right_name >::instance_type right_index_instance_type;

	static
	left_component_return_type
	process
	(
		left_index_const_input_type left_index
		,right_component_const_input_type right_component
		,right_index_const_input_type right_index
	) {
		return diverse_type::process
			   (
				   normalize_type::process
				   (
					   right_component
					   ,right_index
				   )
				   , left_index
			   );
	}

	template
	<
	left_index_instance_type left_index_size
	>
	static
	left_component_return_type
	process
	(
		right_component_const_input_type right_component
		,right_index_const_input_type right_index
	) {
		return diverse_type::template process< left_index_size >
		(
			normalize_type::process
			(
				right_component
				,right_index
			)
		);
	}

	template
	<
	left_index_instance_type left_index_size
	,right_index_instance_type right_index_size
	>
	static
	left_component_return_type
	process
	(
		right_component_const_input_type right_component
	) {
		return diverse_type::template process< left_index_size >
		(
			normalize_type::template process< right_index_size >
			(
				right_component
			)
		);
	}
};

}
}

namespace color {
namespace _internal {

template< typename category_left_name, typename category_right_name >
struct convert {
public:
	typedef category_left_name category_left_type;
	typedef category_right_name category_right_type;

	typedef ::color::trait::index<category_left_type> index_trait_type;
	typedef typename index_trait_type::instance_type index_type;

	typedef ::color::trait::container< category_left_type > container_left_trait_type;
	typedef ::color::trait::container< category_right_type > container_right_trait_type;

	typedef ::color::trait::component<category_left_type> component_trait_type;
	typedef typename component_trait_type::instance_type component_left_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		typedef ::color::_internal::reformat< category_left_type, category_right_type > reformat_type;
		static const index_type min_common_size = std::min< index_type >(container_left_trait_type::size(), container_right_trait_type::size());
		component_left_type value;
		for(index_type index=0; index < min_common_size; ++index) {
			value = reformat_type::process(index, container_right_trait_type::get(right, index), index);
			container_left_trait_type::set(left, index, value);
		}
	}
};

template< typename category_name >
struct convert< category_name,category_name > {
public:

	typedef ::color::trait::container< category_name > container_trait_type;

	typedef typename container_trait_type::input_type container_input_type;
	typedef typename container_trait_type::input_const_type container_const_input_type;

	static void process
	(
		container_input_type left
		,container_const_input_type right
	) {
		left = right;
	}

};

}
}
namespace color {
namespace _internal {

template< typename category_name >
void init
(
	typename ::color::trait::container< category_name >::output_type container
	, std::initializer_list< typename ::color::trait::component< category_name >::instance_type > const& ilist
) {
	typedef ::color::trait::container< category_name > container_trait_type;
	typedef typename ::color::trait::index< category_name >::instance_type index_type;
	auto ili = ilist.begin();
	index_type index=0;
	for(; index < std::min(container_trait_type::size(), ilist.size()) ; ++index, ++ili) {
		container_trait_type::set(container, index, *ili);
	}
};

}
}

namespace color {
namespace _internal {

template< typename category_name >
class model {
public:
	typedef category_name category_type;

	typedef ::color::trait::index< category_name > index_trait_type;
	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::container< category_name > container_trait_type;
	typedef ::color::trait::bound< category_name > bound_trait_type, bound_type;

	typedef ::color::_internal::trait<category_type> trait_type;

	typedef typename index_trait_type::instance_type index_type;
	typedef typename index_trait_type::const_type index_const_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef typename trait_type::component_type component_type;
	typedef typename trait_type::component_const_type component_const_type;
	typedef typename trait_type::component_return_const_type component_return_const_type;
	typedef typename trait_type::component_return_type component_return_type;
	typedef typename trait_type::component_input_const_type component_input_const_type;
	typedef typename trait_type::component_input_type component_input_type;

	typedef typename trait_type::container_type container_type;
	typedef typename trait_type::container_const_type container_const_type;
	typedef typename trait_type::container_return_const_type container_return_const_type;
	typedef typename trait_type::container_input_const_type container_input_const_type;
	typedef typename trait_type::container_return_type container_return_type;

	typedef typename trait_type::set_return_type set_return_type;

	model() {
	}

	explicit model(container_input_const_type container)
		:m_container(container) {
	}

	explicit model(std::initializer_list<component_type > const& ilist) {
		::color::_internal::init<category_name>(this->m_container, ilist);
	}

	template< typename other_category_name >
	explicit model(::color::_internal::model<other_category_name> const& that) {
		::color::_internal::convert<category_name, other_category_name>::process(this->m_container, that.container());
	}

	template< typename other_category_name >
	model operator=(::color::_internal::model<other_category_name> const& that) {
		::color::_internal::convert<category_name, other_category_name>::process(this->m_container, that.container());
		return *this;
	}

	component_return_const_type
	get(index_input_const_type index)const {
		return container_trait_type::get(this->m_container, index);
	}

	template< index_type index >
	component_return_const_type
	get()const {
		return container_trait_type::template get<index>(this->m_container);
	}
	set_return_type
	set(index_input_const_type index, component_input_const_type component) {
		return container_trait_type::set(this->m_container, index, component);
	}

	template< index_type index >
	set_return_type
	set(component_input_const_type component) {
		container_trait_type::template set<index>(this->m_container, component);
	}

	component_return_const_type operator[](index_input_const_type index)const {
		return this->get(index);
	}

	container_return_const_type container()const {
		return this->m_container;
	}
	container_return_type container() {
		return this->m_container;
	}

	static unsigned size() {
		return container_trait_type::size();
	}

private:
	container_type m_container;
};

}
}

namespace color {
namespace check {
namespace _internal {

template< typename category_name >
struct integrity {
public:
	typedef category_name category_type;

	typedef ::color::_internal::model<category_type> model_type;

	static bool process(model_type const& m) {
		return true;
	}

};
}

template< typename category_name >
inline
bool integrity(::color::_internal::model<category_name> const& m) {
	return ::color::check::_internal::integrity<category_name>::process(m);
}

}
}

namespace color {
namespace check {
namespace _internal {

template< typename category_name >
struct overburn {
public:
	typedef category_name category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound<category_type> bound_type;
	typedef ::color::trait::container< category_name > container_trait_type;
	typedef ::color::trait::index<category_type> index_trait_type;

	typedef typename index_trait_type::instance_type index_type;

	static index_type process(model_type const& m) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			if(m.get(index) < bound_type::minimum(index)) {
				return index;
				continue;
			}
			if(bound_type::maximum(index) < m.get(index)) {
				return index;
				continue;
			}
		}
		return container_trait_type::size();
	}

};
}

template< typename category_name >
inline
typename ::color::trait::index<category_name>::instance_type
overburn(::color::_internal::model<category_name> const& m) {
	return ::color::check::_internal::overburn<category_name>::process(m);
}

}
}

namespace color {
namespace compare {

template < typename category_left_name, typename category_right_name >
bool equal(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return left.container() == ::color::_internal::model< category_left_name >(right).container();
}

template < typename category_name >
bool equal(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return left.container() == right.container();
}

template < typename category_left_name, typename category_right_name >
inline
bool
operator ==(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return ::color::compare::equal(left, right);
}

template< typename category_name >
inline
bool
operator ==(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return ::color::compare::equal(left, right);
}

}
}
namespace color {
namespace compare {

template < typename category_left_name, typename category_right_name >
bool different(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return left.container() != ::color::_internal::model< category_left_name >(right).container();
}

template < typename category_name >
bool different(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return left.container() != right.container();
}

template < typename category_left_name, typename category_right_name >
inline
bool
operator !=(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return ::color::compare::different(left, right);
}

template< typename category_name >
inline
bool
operator !=(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return ::color::compare::different(left, right);
}

}
}

namespace color {
namespace compare {

template < typename category_left_name, typename category_right_name >
bool great_or_equal(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return left.container() >= ::color::_internal::model< category_left_name >(right).container();
}

template < typename category_name >
bool great_or_equal(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return left.container() >= right.container();
}

template < typename category_left_name, typename category_right_name >
inline
bool
operator >=(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return ::color::compare::great_or_equal(left, right);
}

template< typename category_name >
inline
bool
operator >=(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return ::color::compare::great_or_equal(left, right);
}

}
}
namespace color {
namespace compare {

template < typename category_left_name, typename category_right_name >
bool great_strict(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return left.container() > ::color::_internal::model< category_left_name >(right).container();
}

template < typename category_name >
bool great_strict(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return left.container() > right.container();
}

template < typename category_left_name, typename category_right_name >
inline
bool
operator >(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return ::color::compare::great_strict(left, right);
}

template< typename category_name >
inline
bool
operator >(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return ::color::compare::great_strict(left, right);
}

}
}
namespace color {
namespace compare {

template < typename category_left_name, typename category_right_name >
bool less_or_equal(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return left.container() <= ::color::_internal::model< category_left_name >(right).container();
}

template < typename category_name >
bool less_or_equal(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return left.container() <= right.container();
}

template < typename category_left_name, typename category_right_name >
inline
bool
operator <=(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return ::color::compare::less_or_equal(left, right);
}

template< typename category_name >
inline
bool
operator <=(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return ::color::compare::less_or_equal(left, right);
}

}
}
namespace color {
namespace compare {

template < typename category_left_name, typename category_right_name >
bool less_strict(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return left.container() < ::color::_internal::model< category_left_name >(right).container();
}

template < typename category_name >
bool less_strict(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return left.container() < right.container();
}

template < typename category_left_name, typename category_right_name >
inline
bool
operator <(::color::_internal::model< category_left_name > const& left, ::color::_internal::model< category_right_name > const& right) {
	return ::color::compare::less_strict(left, right);
}

template< typename category_name >
inline
bool
operator <(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return ::color::compare::less_strict(left, right);
}

}
}

namespace color {
namespace category {

namespace _internal {
struct gray_bool {};
struct gray_uint8 {};
struct gray_uint16 {};
struct gray_uint24 {};
struct gray_uint32 {};
struct gray_uint48 {};
struct gray_uint64 {};
struct gray_float {};
struct gray_double {};
struct gray_ldouble {};
}

template< typename tag_name >
struct gray {
	typedef void category_name;
};

using gray_bool = gray< ::color::category::_internal::gray_bool >;
using gray_uint8 = gray< ::color::category::_internal::gray_uint8 >;
using gray_uint16 = gray< ::color::category::_internal::gray_uint16 >;
using gray_uint24 = gray< ::color::category::_internal::gray_uint24 >;
using gray_uint32 = gray< ::color::category::_internal::gray_uint32 >;
using gray_uint48 = gray< ::color::category::_internal::gray_uint48 >;
using gray_uint64 = gray< ::color::category::_internal::gray_uint64 >;
using gray_float = gray< ::color::category::_internal::gray_float >;
using gray_double = gray< ::color::category::_internal::gray_double >;
using gray_ldouble = gray< ::color::category::_internal::gray_ldouble >;

}
}

namespace color {
namespace category {

namespace _internal {
struct cmy_bool {};
struct cmy_uint8 {};
struct cmy_uint16 {};
struct cmy_uint24 {};
struct cmy_uint32 {};
struct cmy_uint48 {};
struct cmy_uint64 {};
struct cmy_float {};
struct cmy_double {};
struct cmy_ldouble {};
}

template< typename tag_name >
struct cmy {
	typedef void category_name;
};

using cmy_bool = cmy< ::color::category::_internal::cmy_bool >;
using cmy_uint8 = cmy< ::color::category::_internal::cmy_uint8 >;
using cmy_uint16 = cmy< ::color::category::_internal::cmy_uint16 >;
using cmy_uint24 = cmy< ::color::category::_internal::cmy_uint24 >;
using cmy_uint32 = cmy< ::color::category::_internal::cmy_uint32 >;
using cmy_uint48 = cmy< ::color::category::_internal::cmy_uint48 >;
using cmy_uint64 = cmy< ::color::category::_internal::cmy_uint64 >;
using cmy_float = cmy< ::color::category::_internal::cmy_float >;
using cmy_double = cmy< ::color::category::_internal::cmy_double >;
using cmy_ldouble = cmy< ::color::category::_internal::cmy_ldouble >;

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::cmy_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::cmy_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::cmy_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::cmy_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::cmy_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::cmy_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::cmy_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace category {

namespace _internal {
struct cmyk_bool {};
struct cmyk_uint8 {};
struct cmyk_uint16 {};
struct cmyk_uint24 {};
struct cmyk_uint32 {};
struct cmyk_uint48 {};
struct cmyk_uint64 {};
struct cmyk_float {};
struct cmyk_double {};
struct cmyk_ldouble {};
}

template< typename tag_name >
struct cmyk {
	typedef void category_name;
};

using cmyk_bool = cmyk< ::color::category::_internal::cmyk_bool >;
using cmyk_uint8 = cmyk< ::color::category::_internal::cmyk_uint8 >;
using cmyk_uint16 = cmyk< ::color::category::_internal::cmyk_uint16 >;
using cmyk_uint24 = cmyk< ::color::category::_internal::cmyk_uint24 >;
using cmyk_uint32 = cmyk< ::color::category::_internal::cmyk_uint32 >;
using cmyk_uint48 = cmyk< ::color::category::_internal::cmyk_uint48 >;
using cmyk_uint64 = cmyk< ::color::category::_internal::cmyk_uint64 >;
using cmyk_float = cmyk< ::color::category::_internal::cmyk_float >;
using cmyk_double = cmyk< ::color::category::_internal::cmyk_double >;
using cmyk_ldouble = cmyk< ::color::category::_internal::cmyk_ldouble >;

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::cmyk_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::cmyk_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::cmyk_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::cmyk_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::cmyk_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::cmyk_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::cmyk_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::gray_bool > {
	typedef ::color::category::gray_bool akin_type;
};
template< >struct gray< ::color::category::gray_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::gray_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::gray_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::gray_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::gray_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::gray_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::gray_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace category {

namespace _internal {
struct hsl_bool {};
struct hsl_uint8 {};
struct hsl_uint16 {};
struct hsl_uint24 {};
struct hsl_uint32 {};
struct hsl_uint48 {};
struct hsl_uint64 {};
struct hsl_float {};
struct hsl_double {};
struct hsl_ldouble {};
}

template< typename tag_name >
struct hsl {
	typedef void category_name;
};

using hsl_bool = hsl< ::color::category::_internal::hsl_bool >;
using hsl_uint8 = hsl< ::color::category::_internal::hsl_uint8 >;
using hsl_uint16 = hsl< ::color::category::_internal::hsl_uint16 >;
using hsl_uint24 = hsl< ::color::category::_internal::hsl_uint24 >;
using hsl_uint32 = hsl< ::color::category::_internal::hsl_uint32 >;
using hsl_uint48 = hsl< ::color::category::_internal::hsl_uint48 >;
using hsl_uint64 = hsl< ::color::category::_internal::hsl_uint64 >;
using hsl_float = hsl< ::color::category::_internal::hsl_float >;
using hsl_double = hsl< ::color::category::_internal::hsl_double >;
using hsl_ldouble = hsl< ::color::category::_internal::hsl_ldouble >;

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::hsl_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::hsl_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::hsl_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::hsl_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::hsl_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::hsl_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::hsl_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace category {

namespace _internal {
struct hsv_bool {};
struct hsv_uint8 {};
struct hsv_uint16 {};
struct hsv_uint24 {};
struct hsv_uint32 {};
struct hsv_uint48 {};
struct hsv_uint64 {};
struct hsv_float {};
struct hsv_double {};
struct hsv_ldouble {};
}

template< typename tag_name >
struct hsv {
	typedef void category_name;
};

using hsv_bool = hsv< ::color::category::_internal::hsv_bool >;
using hsv_uint8 = hsv< ::color::category::_internal::hsv_uint8 >;
using hsv_uint16 = hsv< ::color::category::_internal::hsv_uint16 >;
using hsv_uint24 = hsv< ::color::category::_internal::hsv_uint24 >;
using hsv_uint32 = hsv< ::color::category::_internal::hsv_uint32 >;
using hsv_uint48 = hsv< ::color::category::_internal::hsv_uint48 >;
using hsv_uint64 = hsv< ::color::category::_internal::hsv_uint64 >;
using hsv_float = hsv< ::color::category::_internal::hsv_float >;
using hsv_double = hsv< ::color::category::_internal::hsv_double >;
using hsv_ldouble = hsv< ::color::category::_internal::hsv_ldouble >;

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::hsv_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::hsv_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::hsv_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::hsv_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::hsv_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::hsv_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::hsv_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace category {

namespace _internal {
struct rgb_uint8 {};
struct rgb_uint16 {};
struct rgb_uint24 {};
struct rgb_uint32 {};
struct rgb_uint48 {};
struct rgb_uint64 {};
struct rgb_float {};
struct rgb_double {};
struct rgb_ldouble {};
}

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position >
struct rgb_scramble {};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
struct rgba_scramble {};

template< typename tag_name >
struct rgb {

};

using rgb_uint8 = rgb< ::color::category::_internal::rgb_uint8 >;
using rgb_uint16 = rgb< ::color::category::_internal::rgb_uint16 >;
using rgb_uint24 = rgb< ::color::category::_internal::rgb_uint24 >;
using rgb_uint32 = rgb< ::color::category::_internal::rgb_uint32 >;
using rgb_uint48 = rgb< ::color::category::_internal::rgb_uint48 >;
using rgb_uint64 = rgb< ::color::category::_internal::rgb_uint64 >;
using rgb_float = rgb< ::color::category::_internal::rgb_float >;
using rgb_double = rgb< ::color::category::_internal::rgb_double >;
using rgb_ldouble = rgb< ::color::category::_internal::rgb_ldouble >;

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::rgb_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::rgb_uint16 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::rgb_uint32 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::rgb_uint64 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::rgb_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::rgb_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::rgb_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace category {

namespace _internal {
struct yiq_bool {};
struct yiq_uint8 {};
struct yiq_uint16 {};
struct yiq_uint24 {};
struct yiq_uint32 {};
struct yiq_uint48 {};
struct yiq_uint64 {};
struct yiq_float {};
struct yiq_double {};
struct yiq_ldouble {};
}

template< typename tag_name >
struct yiq {
	typedef void category_name;
};

using yiq_bool = yiq< ::color::category::_internal::yiq_bool >;
using yiq_uint8 = yiq< ::color::category::_internal::yiq_uint8 >;
using yiq_uint16 = yiq< ::color::category::_internal::yiq_uint16 >;
using yiq_uint24 = yiq< ::color::category::_internal::yiq_uint24 >;
using yiq_uint32 = yiq< ::color::category::_internal::yiq_uint32 >;
using yiq_uint48 = yiq< ::color::category::_internal::yiq_uint48 >;
using yiq_uint64 = yiq< ::color::category::_internal::yiq_uint64 >;
using yiq_float = yiq< ::color::category::_internal::yiq_float >;
using yiq_double = yiq< ::color::category::_internal::yiq_double >;
using yiq_ldouble = yiq< ::color::category::_internal::yiq_ldouble >;

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::yiq_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::yiq_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::yiq_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::yiq_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::yiq_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::yiq_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::yiq_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace category {

namespace _internal {
struct yuv_bool {};
struct yuv_uint8 {};
struct yuv_uint16 {};
struct yuv_uint24 {};
struct yuv_uint32 {};
struct yuv_uint48 {};
struct yuv_uint64 {};
struct yuv_float {};
struct yuv_double {};
struct yuv_ldouble {};
}

template< typename tag_name >
struct yuv {
	typedef void category_name;
};

using yuv_bool = yuv< ::color::category::_internal::yuv_bool >;
using yuv_uint8 = yuv< ::color::category::_internal::yuv_uint8 >;
using yuv_uint16 = yuv< ::color::category::_internal::yuv_uint16 >;
using yuv_uint24 = yuv< ::color::category::_internal::yuv_uint24 >;
using yuv_uint32 = yuv< ::color::category::_internal::yuv_uint32 >;
using yuv_uint48 = yuv< ::color::category::_internal::yuv_uint48 >;
using yuv_uint64 = yuv< ::color::category::_internal::yuv_uint64 >;
using yuv_float = yuv< ::color::category::_internal::yuv_float >;
using yuv_double = yuv< ::color::category::_internal::yuv_double >;
using yuv_ldouble = yuv< ::color::category::_internal::yuv_ldouble >;

}
}

namespace color {
namespace akin {

template< >struct gray< ::color::category::yuv_uint8 > {
	typedef ::color::category::gray_uint8 akin_type;
};
template< >struct gray< ::color::category::yuv_uint16 > {
	typedef ::color::category::gray_uint16 akin_type;
};
template< >struct gray< ::color::category::yuv_uint32 > {
	typedef ::color::category::gray_uint32 akin_type;
};
template< >struct gray< ::color::category::yuv_uint64 > {
	typedef ::color::category::gray_uint64 akin_type;
};
template< >struct gray< ::color::category::yuv_float > {
	typedef ::color::category::gray_float akin_type;
};
template< >struct gray< ::color::category::yuv_double > {
	typedef ::color::category::gray_double akin_type;
};
template< >struct gray< ::color::category::yuv_ldouble > {
	typedef ::color::category::gray_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::gray_double >
		: public ::color::_internal::utility::bound::general< double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::gray_float >
		: public ::color::_internal::utility::bound::general< float, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::gray_ldouble >
		: public ::color::_internal::utility::bound::general< long double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::gray_uint16 >
		: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::gray_uint32 >
		: public ::color::_internal::utility::bound::general< std::uint32_t, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::gray_uint64 >
		: public ::color::_internal::utility::bound::general< std::uint64_t, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::gray_uint8 >
		: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename value_name, typename index_name >
struct array {
public:
	typedef value_name value_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< value_name > utility_trait_type;

	typedef typename utility_trait_type::instance_type instance_type;
	typedef typename utility_trait_type::const_type const_type;
	typedef typename utility_trait_type::return_image_type return_image_type;
	typedef typename utility_trait_type::return_type return_type;
	typedef typename utility_trait_type::input_const_type input_const_type;
	typedef typename utility_trait_type::input_type input_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_bool >
		: public ::color::_internal::utility::component::array< bool, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_double >
		: public ::color::_internal::utility::component::array< double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_float >
		: public ::color::_internal::utility::component::array< float, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_ldouble >
		: public ::color::_internal::utility::component::array< long double, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace type {

template < typename type_name >
struct traitP {
public:
	typedef type_name instance_type;

	typedef instance_type const const_type;

	typedef instance_type const return_image_type;
	typedef instance_type return_type;

	typedef instance_type const& input_const_type;
	typedef instance_type input_type;

};

}
}
}
}

namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename unsigned_name, typename index_name >
struct Unsigned {
public:
	typedef unsigned_name unsigned_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitP< unsigned_type > utility_trait_type;

	typedef typename utility_trait_type::instance_type instance_type;
	typedef typename utility_trait_type::const_type const_type;
	typedef typename utility_trait_type::return_image_type return_image_type;
	typedef typename utility_trait_type::return_type return_type;
	typedef typename utility_trait_type::input_const_type input_const_type;
	typedef typename utility_trait_type::input_type input_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_uint16 >
		: public ::color::_internal::utility::component::Unsigned< std::uint16_t, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_uint32 >
		: public ::color::_internal::utility::component::Unsigned< std::uint32_t, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_uint64 >
		: public ::color::_internal::utility::component::Unsigned< std::uint64_t, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::gray_uint8 >
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template< typename index_name >
struct boolean {
public:

	typedef index_name index_type;
	typedef bool value_type;

	typedef bool instance_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitC< value_type > component_trait_type;

	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;
	typedef typename component_trait_type::instance_type component_type;

	typedef void set_return_type;

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		return container;
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		return container;
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		container = value;
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		container = value;
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = 1;
		return local_length;
	}
};
}
}
}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_bool >
		: public ::color::_internal::utility::container::boolean< unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template< typename value_name, unsigned length >
struct array {
public:

	typedef value_name value_type;

	typedef std::array< value_name, length> instance_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< typename instance_type::size_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::const_type index_const_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitC< value_name > component_trait_type;

	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef void set_return_type;

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		return container[index];
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		return container[index];
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		container[index] = value;
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		container[index] = value;
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = length;
		return local_length;
	}
};
}
}
}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_double >
		: public ::color::_internal::utility::container::array< double, 1 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_float >
		: public ::color::_internal::utility::container::array< float, 1 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_ldouble >
		: public ::color::_internal::utility::container::array< long double, 1 > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template< typename unsigned_name, typename value_name, typename index_name, unsigned length, unsigned width >
struct Unsigned {
public:

	typedef unsigned_name unsigned_type;
	typedef value_name value_type;
	typedef index_name index_type;
	typedef unsigned_name instance_type;

	typedef ::color::_internal::utility::container::Unsigned<unsigned_name,value_name,index_name,length,width> this_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitP< value_name > component_trait_type;

	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef void set_return_type;

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		return (component_type)((container >> (index * width)) & mask());
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		return (component_type)((container >> (index * width)) & mask());
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		container = (container & ~(this_type::mask() << (index * width))) | ((instance_type(value) << (index * width)));
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		container = (container & ~(this_type::mask() << (index * width))) | ((instance_type(value)) << (index * width));
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = length;
		return local_length;
	}
private:
	static return_image_type mask() {
		static instance_type local_mask = (((instance_type(1) << (width-1)) - instance_type(1))<< 1) + instance_type(1);
		return local_mask;
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_uint16 >
		: public ::color::_internal::utility::container::Unsigned< std::uint16_t, std::uint16_t, unsigned, 1, 16 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_uint32 >
		: public ::color::_internal::utility::container::Unsigned< std::uint32_t, std::uint32_t, unsigned, 1, 32 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_uint64 >
		: public ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint64_t, unsigned, 1, 64 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::gray_uint8 >
		: public ::color::_internal::utility::container::Unsigned< std::uint8_t, std::uint8_t, unsigned, 1, 8 > {
};

}
}

namespace color {
namespace trait {

template< >
struct index< ::color::category::gray_bool >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::gray_double >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::gray_float >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::gray_ldouble >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::gray_uint16 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::gray_uint32 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::gray_uint64 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::gray_uint8 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct red {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -1 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
red() {
	return ::color::place::_internal::red<category_name>::position();
}

}
}

namespace color {
namespace trait {

template< >
struct index< ::color::category::rgb_double >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::rgb_float >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::rgb_ldouble >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::rgb_uint16 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::rgb_uint32 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::rgb_uint64 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::rgb_uint8 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::rgb_uint24 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::rgb_uint48 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct red< ::color::category::rgb< tag_name > > {
public:
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position >
struct red< ::color::category::rgb< ::color::category::rgb_scramble< value_name, red_position, green_position, blue_position > > > {
public:
	typedef ::color::category::rgb_scramble< value_name, red_position, green_position, blue_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = red_position };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct green {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -8 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
green() {
	return ::color::place::_internal::green<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct green< ::color::category::rgb< tag_name > > {
public:
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position >
struct green< ::color::category::rgb< ::color::category::rgb_scramble< value_name, red_position, green_position, blue_position > > > {
public:
	typedef ::color::category::rgb_scramble< value_name, red_position, green_position, blue_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = green_position };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct blue {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -11 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
blue() {
	return ::color::place::_internal::blue<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct blue< ::color::category::rgb< tag_name > > {
public:
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position >
struct blue< ::color::category::rgb< ::color::category::rgb_scramble< value_name, red_position, green_position, blue_position > > > {
public:
	typedef ::color::category::rgb_scramble< value_name, red_position, green_position, blue_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = blue_position };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct alpha {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -10 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
alpha() {
	return ::color::place::_internal::alpha<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename value_name, unsigned red_position, unsigned green_position, unsigned blue_position, unsigned alpha_position >
struct alpha< ::color::category::rgb< ::color::category::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > > > {
public:
	typedef ::color::category::rgba_scramble< value_name, red_position, green_position, blue_position, alpha_position > scramble_type;
	typedef ::color::category::rgb< scramble_type > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = red_position };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::gray_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::gray_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::gray_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::gray_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::gray_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::gray_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::gray_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_double >
		: public ::color::_internal::utility::component::array< double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_float >
		: public ::color::_internal::utility::component::array< float, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_ldouble >
		: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename index_name >
struct cnent655
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, index_name > {
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_uint16 >
		: public ::color::_internal::utility::component::cnent655< unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_uint32 >
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_uint64 >
		: public ::color::_internal::utility::component::Unsigned< std::uint16_t, unsigned> {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename index_name >
struct cnent332
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, index_name > {
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_uint8 >
		: public ::color::_internal::utility::component::cnent332< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_uint24 >
		: public ::color::_internal::utility::component::array< std::uint8_t, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::rgb_uint48 >
		: public ::color::_internal::utility::component::array< std::uint16_t, unsigned > {
};

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::gray<tag_name> >::akin_type >::return_type
red(::color::_internal::model< ::color::category::gray<tag_name> > const& color_parameter) {
	typedef ::color::category::gray<tag_name> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<red_p,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::gray<tag_name> >::akin_type >::return_type
green(::color::_internal::model< ::color::category::gray<tag_name> > const& color_parameter) {
	typedef ::color::category::gray<tag_name> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<green_p,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::gray<tag_name> >::akin_type >::return_type
blue(::color::_internal::model< ::color::category::gray<tag_name> > const& color_parameter) {
	typedef ::color::category::gray<tag_name> category_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<blue_p,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name >
typename ::color::trait::component< ::color::category::gray<tag_name> >::return_type
gray(::color::_internal::model< ::color::category::gray<tag_name> > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace make {

inline
void black(::color::_internal::model< color::category::gray_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void black(::color::_internal::model< color::category::gray_uint16 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void black(::color::_internal::model< color::category::gray_uint32 > & color_parameter) {
	color_parameter.container() = 0x0u;
}

inline
void black(::color::_internal::model< color::category::gray_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0x0ul);
}

inline
void black(::color::_internal::model< color::category::gray_float > & color_parameter) {
	color_parameter.container() = std::array<float,1>({0});
}

inline
void black(::color::_internal::model< color::category::gray_double> & color_parameter) {
	color_parameter.container() = std::array<double,1>({0});
}

inline
void black(::color::_internal::model< color::category::gray_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,1>({0});
}

}
}

namespace color {
namespace make {

inline
void gray50(::color::_internal::model< color::category::gray_uint8 > & color_parameter) {
	color_parameter.container() = 0x7f;
}

inline
void gray50(::color::_internal::model< color::category::gray_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fff;
}

inline
void gray50(::color::_internal::model< color::category::gray_uint32 > & color_parameter) {
	color_parameter.container() = 0x7FFFFFFF;
}

inline
void gray50(::color::_internal::model< color::category::gray_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0x7fffffffffffffffu);
}

inline
void gray50(::color::_internal::model< color::category::gray_float > & color_parameter) {
	color_parameter.container() = std::array<float,1>({0.5});
}

inline
void gray50(::color::_internal::model< color::category::gray_double> & color_parameter) {
	color_parameter.container() = std::array<double,1>({0.5});
}

inline
void gray50(::color::_internal::model< color::category::gray_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,1>({0.5});
}

}
}

namespace color {
namespace make {

inline
void white(::color::_internal::model< color::category::gray_uint8 > & color_parameter) {
	color_parameter.container() = 0xff;
}

inline
void white(::color::_internal::model< color::category::gray_uint16 > & color_parameter) {
	color_parameter.container() = 0xffff;
}

inline
void white(::color::_internal::model< color::category::gray_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff;
}

inline
void white(::color::_internal::model< color::category::gray_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0xffffffffffffu);
}

inline
void white(::color::_internal::model< color::category::gray_float > & color_parameter) {
	color_parameter.container() = std::array<float,1>({ 1 });
}

inline
void white(::color::_internal::model< color::category::gray_double> & color_parameter) {
	color_parameter.container() = std::array<double,1>({ 1 });
}

inline
void white(::color::_internal::model< color::category::gray_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,1>({ 1 });
}

}
}

namespace color {
namespace make {

inline
void red(::color::_internal::model< color::category::gray_uint8 > & color_parameter) {
	color_parameter.container() = 0x36;
}

inline
void red(::color::_internal::model< color::category::gray_uint16 > & color_parameter) {
	color_parameter.container() = 0x3671;
}

inline
void red(::color::_internal::model< color::category::gray_uint32 > & color_parameter) {
	color_parameter.container() = 0x3671bb2eu;
}

inline
void red(::color::_internal::model< color::category::gray_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0x3671bb2e3ed7ac00ul);
}

inline
void red(::color::_internal::model< color::category::gray_float > & color_parameter) {
	color_parameter.container() = std::array<float,1>({ 0.2126729 });
}

inline
void red(::color::_internal::model< color::category::gray_double> & color_parameter) {
	color_parameter.container() = std::array<double,1>({ 0.2126729 });
}

inline
void red(::color::_internal::model< color::category::gray_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,1>({ 0.2126729 });
}

}
}

namespace color {
namespace make {

inline
void green(::color::_internal::model< color::category::gray_uint8 > & color_parameter) {
	color_parameter.container() = 0x5b;
}

inline
void green(::color::_internal::model< color::category::gray_uint16 > & color_parameter) {
	color_parameter.container() = 0x5b89;
}

inline
void green(::color::_internal::model< color::category::gray_uint32 > & color_parameter) {
	color_parameter.container() = 0x5b8a1b76u;
}

inline
void green(::color::_internal::model< color::category::gray_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0x5b8a1b7754cb3400ul);
}

inline
void green(::color::_internal::model< color::category::gray_float > & color_parameter) {
	color_parameter.container() = std::array<float,1>({ 0.7151522/2 });
}

inline
void green(::color::_internal::model< color::category::gray_double> & color_parameter) {
	color_parameter.container() = std::array<double,1>({ 0.7151522/2 });
}

inline
void green(::color::_internal::model< color::category::gray_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,1>({ 0.7151522/2 });
}

}
}

namespace color {
namespace make {

inline
void blue(::color::_internal::model< color::category::gray_uint8 > & color_parameter) {
	color_parameter.container() = 0x12;
}

inline
void blue(::color::_internal::model< color::category::gray_uint16 > & color_parameter) {
	color_parameter.container() = 0x1279;
}

inline
void blue(::color::_internal::model< color::category::gray_uint32 > & color_parameter) {
	color_parameter.container() = 0x127a0f90u;
}

inline
void blue(::color::_internal::model< color::category::gray_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0x127a0f9096bb9900ul);
}

inline
void blue(::color::_internal::model< color::category::gray_float > & color_parameter) {
	color_parameter.container() = std::array<float,1>({ 0.0721750 });
}

inline
void blue(::color::_internal::model< color::category::gray_double> & color_parameter) {
	color_parameter.container() = std::array<double,1>({ 0.0721750 });
}

inline
void blue(::color::_internal::model< color::category::gray_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,1>({ 0.0721750 });
}

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::cmy_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::cmy_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::cmy_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::cmy_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::cmy_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::cmy_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::cmy_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::cmyk_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::cmyk_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::cmyk_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::cmyk_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::cmyk_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::cmyk_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::cmyk_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::gray_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::gray_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::gray_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::gray_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::gray_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::gray_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::gray_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::hsl_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::hsl_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::hsl_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::hsl_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::hsl_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::hsl_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::hsl_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::hsv_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::hsv_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::hsv_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::hsv_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::hsv_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::hsv_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::hsv_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::rgb_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::rgb_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::rgb_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::rgb_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::rgb_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::rgb_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::rgb_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::yiq_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::yiq_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::yiq_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::yiq_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::yiq_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::yiq_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::yiq_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct cmy< ::color::category::yuv_uint8 > {
	typedef ::color::category::cmy_uint8 akin_type;
};
template< >struct cmy< ::color::category::yuv_uint16 > {
	typedef ::color::category::cmy_uint16 akin_type;
};
template< >struct cmy< ::color::category::yuv_uint32 > {
	typedef ::color::category::cmy_uint32 akin_type;
};
template< >struct cmy< ::color::category::yuv_uint64 > {
	typedef ::color::category::cmy_uint64 akin_type;
};
template< >struct cmy< ::color::category::yuv_float > {
	typedef ::color::category::cmy_float akin_type;
};
template< >struct cmy< ::color::category::yuv_double > {
	typedef ::color::category::cmy_double akin_type;
};
template< >struct cmy< ::color::category::yuv_ldouble > {
	typedef ::color::category::cmy_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmy_double >
		: public ::color::_internal::utility::bound::general< double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmy_float >
		: public ::color::_internal::utility::bound::general< float, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmy_ldouble >
		: public ::color::_internal::utility::bound::general< long double, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name >
struct bound556 {
public:
	typedef std::uint16_t unsigned_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitP< unsigned_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 31, 31, 63 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 31, 31, 63 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type value=0;
		return value;
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type value=0;
		return value;
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type max_list[] = { 31, 31, 63 };
		return max_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type max_list[] = { 31, 31, 63 };
		return max_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmy_uint16 >
		: public ::color::_internal::utility::bound::bound556< unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename container_name, unsigned width_size, typename index_name >
struct intrinsic {
public:
	typedef container_name container_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< container_type > component_trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename component_trait_type::instance_type component_instance_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	typedef ::color::_internal::utility::bound::intrinsic< container_name, width_size, index_name > this_type;

	template< index_instance_type index >
	static component_return_const_type maximum() {
		static const component_instance_type component = (((container_type(1) << (width_size-1)) - container_name(1)) << 1) + container_type(1);
		return component;
	}

	static component_return_const_type maximum(index_input_const_type index) {
		static const component_instance_type component = (((container_type(1) << (width_size-1)) - container_type(1)) << 1) + container_type(1);
		return component;
	}

	template< index_instance_type index >
	static component_return_const_type minimum() {
		static const component_instance_type component = 0;
		return component;
	}

	static component_return_const_type minimum(index_input_const_type index) {
		static const component_instance_type component = 0;
		return component;
	}

	template< index_instance_type index >
	static component_return_const_type range() {
		static const component_instance_type component = this_type::template maximum<index>() - this_type::template minimum<index>();
		return component;
	}

	static component_return_const_type range(index_input_const_type index) {
		static const component_instance_type component = this_type::maximum(index) - this_type::minimum(index);
		return component;
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmy_uint32 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 8, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmy_uint64 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 16, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name >
struct bound332 {
public:
	typedef std::uint8_t unsigned_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitP< unsigned_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 7, 7, 3 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 7, 7, 3 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type value=0;
		return value;
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type value=0;
		return value;
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type max_list[] = { 7, 7, 3 };
		return max_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type max_list[] = { 7, 7, 3 };
		return max_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::cmy_uint8 >
		: public ::color::_internal::utility::bound::bound332< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::cmy_double >
		: public ::color::_internal::utility::component::array< double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::cmy_float >
		: public ::color::_internal::utility::component::array< float, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::cmy_ldouble >
		: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace component {

template< typename index_name >
struct cnent556
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, index_name > {
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::cmy_uint16 >
		: public ::color::_internal::utility::component::cnent556< unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::cmy_uint32 >
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::cmy_uint64 >
		: public ::color::_internal::utility::component::Unsigned< std::uint16_t, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::cmy_uint8 >
		: public ::color::_internal::utility::component::cnent332< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::cmy_double >
		: public ::color::_internal::utility::container::array< double, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::cmy_float >
		: public ::color::_internal::utility::container::array< float, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::cmy_ldouble >
		: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template< typename index_name >
struct cner556 {
public:

	typedef index_name index_type;

	typedef std::uint8_t value_type;
	typedef std::uint16_t instance_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitP< value_type > component_trait_type;

	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef void set_return_type;

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		switch(index) {
		case(0):
			return ((container >> 0) & 31);
		case(1):
			return ((container >> 5) & 31);
		case(2):
			return ((container >> 10) & 63);
		}
		return 0;
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		switch(index) {
		case(0):
			return ((container >> 0) & 31);
		case(1):
			return ((container >> 5) & 31);
		case(2):
			return ((container >> 10) & 63);
		}
		return 0;
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		switch(index) {
		case(0) :
			container = (container & ~(31 << (0))) | (((instance_type)value) << (0));
			break;
		case(1) :
			container = (container & ~(31 << (5))) | (((instance_type)value) << (5));
			break;
		case(2) :
			container = (container & ~(63 << (10))) | (((instance_type)value) << (10));
			break;
		}
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		switch(index) {
		case(0) :
			container = (container & ~(31 << (0))) | (((instance_type)value) << (0));
			break;
		case(1) :
			container = (container & ~(31 << (5))) | (((instance_type)value) << (5));
			break;
		case(2) :
			container = (container & ~(63 << (10))) | (((instance_type)value) << (10));
			break;
		}
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = 3;
		return local_length;
	}
};
}
}
}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::cmy_uint16 >
		: public ::color::_internal::utility::container::cner556< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::cmy_uint32 >
		: public ::color::_internal::utility::container::Unsigned< std::uint32_t, std::uint8_t, unsigned, 3, 8 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::cmy_uint64 >
		: public ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint16_t, unsigned, 3, 16 > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template< typename index_name >
struct cner332 {
public:

	typedef index_name index_type;

	typedef std::uint8_t value_type;
	typedef std::uint8_t instance_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitP< value_type > component_trait_type;

	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef void set_return_type;

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		switch(index) {
		case(0):
			return ((container >> 0) & 7);
		case(1):
			return ((container >> 3) & 7);
		case(2):
			return ((container >> 5) & 3);
		}
		return 0;
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		switch(index) {
		case(0):
			return ((container >> 0) & 7);
		case(1):
			return ((container >> 3) & 7);
		case(2):
			return ((container >> 6) & 3);
		}
		return 0;
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		switch(index) {
		case(0) :
			container = (container & ~(7 << (0))) | (((instance_type)value) << (0));
			break;
		case(1) :
			container = (container & ~(7 << (3))) | (((instance_type)value) << (3));
			break;
		case(2) :
			container = (container & ~(3 << (6))) | (((instance_type)value) << (6));
			break;
		}
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		switch(index) {
		case(0) :
			container = (container & ~(7 << (0))) | (((instance_type)value) << (0));
			break;
		case(1) :
			container = (container & ~(7 << (3))) | (((instance_type)value) << (3));
			break;
		case(2) :
			container = (container & ~(3 << (6))) | (((instance_type)value) << (6));
			break;
		}
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = 3;
		return local_length;
	}
};
}
}
}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::cmy_uint8 >
		: public ::color::_internal::utility::container::cner332< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct index< ::color::category::cmy_double >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmy_float >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmy_ldouble >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmy_uint16 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmy_uint32 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmy_uint64 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmy_uint8 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct cyan {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -1 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
cyan() {
	return ::color::place::_internal::cyan<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct cyan< ::color::category::cmy< tag_name > > {
public:
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct magenta {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -1 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
magenta() {
	return ::color::place::_internal::magenta<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct magenta< ::color::category::cmy< tag_name > > {
public:
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct yellow {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -1 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
yellow() {
	return ::color::place::_internal::yellow<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct yellow< ::color::category::cmy< tag_name > > {
public:
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::cmy_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::cmy_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::cmy_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::cmy_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::cmy_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::cmy_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::cmy_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace operation {
namespace _internal {

template< typename category_name>
struct invert {
public:
	typedef category_name category_type;

	typedef ::color::trait::index<category_type> index_trait_type;
	typedef ::color::trait::bound<category_type> bound_type;
	typedef ::color::trait::component< category_name > component_trait_type;
	typedef ::color::trait::container< category_name > container_trait_type;

	typedef typename ::color::_internal::model<category_type> model_type;

	typedef typename component_trait_type::input_const_type component_input_const_type;
	typedef typename component_trait_type::return_type component_return_type;

	typedef typename index_trait_type::instance_type index_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	static component_return_type
	component
	(
		component_input_const_type component
		,index_input_const_type index
	) {
		return bound_type::range(index) - component;
	}

	template< index_type index_size >
	static
	component_return_type
	component(component_input_const_type component) {
		return bound_type::template range<index_size>() - component;
	}

	static void process(model_type &result) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, component(result.get(index), index));
		}
	}

	static void process(model_type &result, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, component(right.get(index), index));
		}
	}

};
}

template< typename category_name >
void invert
(
	::color::_internal::model<category_name> & result
) {
	::color::operation::_internal::invert<category_name>::process(result);
}

template< typename category_name >
void invert
(
	::color::_internal::model<category_name> & result
	,::color::_internal::model<category_name> const& right
) {
	::color::operation::_internal::invert<category_name>::process(result, right);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmy< tag_name > >::akin_type >::return_type
red(::color::_internal::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	typedef ::color::operation::_internal::invert< category_type > invert_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<red_p,0>(invert_type::template component<0>(color_parameter.template get<0>()));
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmy< tag_name > >::akin_type >::return_type
green(::color::_internal::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	typedef ::color::operation::_internal::invert< category_type > invert_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<green_p,2>(invert_type::template component<2>(color_parameter.template get<2>()));
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmy< tag_name > >::akin_type >::return_type
blue(::color::_internal::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	typedef ::color::operation::_internal::invert< category_type > invert_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<blue_p,2>(invert_type::template component<2>(color_parameter.template get<2>()));
}

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::cmy_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::cmy_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::cmy_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::cmy_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::cmy_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::cmy_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::cmy_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::yiq_double >
		: public ::color::_internal::utility::component::array< double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::yiq_float >
		: public ::color::_internal::utility::component::array< float, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::yiq_ldouble >
		: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::yiq_uint16 >
		: public ::color::_internal::utility::component::cnent556< unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::yiq_uint32 >
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::yiq_uint64 >
		: public ::color::_internal::utility::component::Unsigned< std::uint16_t, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::yiq_uint8 >
		: public ::color::_internal::utility::component::cnent332< unsigned > {
};

}
}

namespace color {
namespace constant {

template< typename category_name>
struct yiq {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::constant::yiq<category_type> this_type;

	static scalar_type const a11() {
		return 1.0000000000000000000;
	}
	static scalar_type const a12() {
		return 0.9562948323208939905;
	}
	static scalar_type const a13() {
		return 0.6210251254447287141;
	}
	static scalar_type const a21() {
		return 1.0000000000000000000;
	}
	static scalar_type const a22() {
		return -0.2721214740839773195;
	}
	static scalar_type const a23() {
		return -0.6473809535176157222;
	}
	static scalar_type const a31() {
		return 1.0000000000000000000;
	}
	static scalar_type const a32() {
		return -1.1069899085671282160;
	}
	static scalar_type const a33() {
		return 1.7046149754988293290;
	}

	static scalar_type const b11() {
		return 0.2990000000000000000;
	}
	static scalar_type const b12() {
		return 0.5870000000000000000;
	}
	static scalar_type const b13() {
		return 0.1140000000000000000;
	}
	static scalar_type const b21() {
		return 0.5957161349127745527;
	}
	static scalar_type const b22() {
		return -0.2744528378392564636;
	}
	static scalar_type const b23() {
		return -0.3212632970735180890;
	}
	static scalar_type const b31() {
		return 0.2114564021201178664;
	}
	static scalar_type const b32() {
		return -0.5225910452916111683;
	}
	static scalar_type const b33() {
		return 0.3111346431714933019;
	}

	static scalar_type const i_min() {
		return -0.5957161349127745527;
	}
	static scalar_type const i_max() {
		return 0.5957161349127745527;
	}
	static scalar_type const i_range() {
		return 2*0.5957161349127745527;
	}

	static scalar_type const q_min() {
		return - 0.5225910452916111683;
	}
	static scalar_type const q_max() {
		return 0.5225910452916111683;
	}
	static scalar_type const q_range() {
		return 2*0.5225910452916111683;
	}

	static scalar_type i_deverse(scalar_type const& normal) {
		return this_type::i_range() * normal + this_type::i_min();
	}
	static scalar_type i_normalize(scalar_type const& divert) {
		return (divert + this_type::i_min()) /this_type::i_range();
	}

	static scalar_type q_deverse(scalar_type const& normal) {
		return this_type::q_range() * normal + this_type::q_min();
	}
	static scalar_type q_normalize(scalar_type const& divert) {
		return (divert + this_type::q_min()) /this_type::q_range();
	}
};

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::yiq< ::color::category::cmy< tag_name > >::akin_type >::return_type
inphase(::color::_internal::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::yiq<category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::yiq< akin_type > yiq_const_type;
	scalar_type value =
		+ yiq_const_type::b21() * (1 - normalize_type::template process<0>(color_parameter.template get<0>()))
		+ yiq_const_type::b22() * (1 - normalize_type::template process<1>(color_parameter.template get<1>()))
		+ yiq_const_type::b23() * (1 - normalize_type::template process<2>(color_parameter.template get<2>()))
		;
	value = yiq_const_type::i_normalize(value);
	return diverse_type::template process<1>(value);
}

}
}

namespace color {
namespace get {

template< typename tag_name>
inline
typename ::color::_internal::model< typename ::color::akin::yiq< ::color::category::cmy< tag_name > >::akin_type >::component_const_type
quadrature(::color::_internal::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::yiq<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::yiq< akin_type > yiq_const_type;
	scalar_type value =
		+ yiq_const_type::b31() * (1 - normalize_type::template process<0>(color_parameter.template get<0>()))
		+ yiq_const_type::b32() * (1 - normalize_type::template process<1>(color_parameter.template get<1>()))
		+ yiq_const_type::b33() * (1 - normalize_type::template process<2>(color_parameter.template get<2>()))
		;
	value = yiq_const_type::q_normalize(value);
	return diverse_type::template process<2>(value);
}

}
}

namespace color {
namespace constant {

template< typename category_name>
struct gray {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::constant::gray<category_type> this_type;

	static scalar_type const Rc() {
		return 0.2126729;
	}
	static scalar_type const Gc() {
		return 0.7151522;
	}
	static scalar_type const Bc() {
		return 0.0721750;
	}
};

}
}
namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::cmy<tag_name> >::akin_type >::return_type
gray(::color::_internal::model< ::color::category::cmy<tag_name> > const& color_parameter) {
	typedef ::color::category::cmy< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::gray< akin_type > gray_const_type;
	scalar_type value =
		gray_const_type::Rc() * (1 - normalize_type::template process<0>(color_parameter.template get<0>()))
		+ gray_const_type::Gc() * (1 - normalize_type::template process<1>(color_parameter.template get<1>()))
		+ gray_const_type::Bc() * (1 - normalize_type::template process<2>(color_parameter.template get<2>()));
	return diverse_type::template process<0>(value);
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::_internal::model< ::color::category::cmy<tag_name> > & color_parameter,
	typename ::color::_internal::model< ::color::category::cmy<tag_name> >::component_input_const_type component_parameter
) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	typedef ::color::operation::_internal::invert< akin_type > invert_type;
	typedef ::color::_internal::reformat< category_type, akin_type > reformat_type;
	color_parameter.template set<0>(reformat_type::template process<0,0>(invert_type::template component<0>(component_parameter)));
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::_internal::model< ::color::category::cmy<tag_name> > & color_parameter,
	typename ::color::_internal::model< ::color::category::cmy<tag_name> >::component_input_const_type component_parameter
) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::akin::rgb< category_type >::akin_type akin_type;
	typedef ::color::operation::_internal::invert< akin_type > invert_type;
	typedef ::color::_internal::reformat< category_type, akin_type > reformat_type;
	color_parameter.template set<1>(reformat_type::template process<1,1>(invert_type::template component<1>(component_parameter)));
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::_internal::model< ::color::category::cmy<tag_name> > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::cmy< tag_name > >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::cmy<tag_name > category_type;
	typedef typename ::color::akin::rgb<category_type >::akin_type akin_type;
	typedef ::color::operation::_internal::invert< akin_type > invert_type;
	typedef ::color::_internal::reformat<category_type, akin_type > reformat_type;
	color_parameter.template set<2>(reformat_type::template process<2,2>(invert_type::template component<2>(component_parameter)));
}

}
}

namespace color {
namespace operation {
namespace _internal {

template< typename category_name>
struct addition {
public:
	typedef category_name category_type;

	typedef ::color::trait::container< category_type > container_trait_type;
	typedef ::color::trait::index< category_type > index_trait_type;
	typedef ::color::_internal::model<category_type> model_type;

	typedef typename index_trait_type::instance_type index_type;

	static void process(model_type &result, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, result.get(index) + right.get(index));
		}
	}

	static void process(model_type &result, model_type const& left, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, left.get(index) + right.get(index));
		}
	}
};

}

template< typename category_name >
void addition
(
	::color::_internal::model<category_name> & result
	,::color::_internal::model<category_name> const& right
) {
	::color::operation::_internal::addition<category_name>::process(result, right);
}

template< typename category_name >
void addition
(
	::color::_internal::model<category_name> & result
	,::color::_internal::model<category_name> const& left
	,::color::_internal::model<category_name> const& right
) {
	::color::operation::_internal::addition<category_name>::process(result, left, right);
}

}
}

namespace color {
namespace operation {
namespace _internal {
template< typename category_name >
struct subtract {
public:
	typedef category_name category_type;

	typedef ::color::trait::index<category_type> index_trait_type;
	typedef ::color::trait::container< category_type > container_trait_type;

	typedef ::color::_internal::model<category_type> model_type;

	typedef typename index_trait_type::instance_type index_type;

	static void process(model_type &result, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, result.get(index) - right.get(index));
		}
	}

	static void process(model_type &result, model_type const& left, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, left.get(index) - right.get(index));
		}
	}

};
}

template< typename category_name >
void subtract
(
	::color::_internal::model<category_name> & result
	,color::_internal::model<category_name> const& right
) {
	::color::operation::_internal::subtract<category_name>::process(result, right);
}

template< typename category_name >
void subtract
(
	::color::_internal::model<category_name> & result
	,color::_internal::model<category_name> const& left
	,color::_internal::model<category_name> const& right
) {
	::color::operation::_internal::subtract<category_name>::process(result, left, right);
}

}
}

namespace color {
namespace operation {
namespace _internal {
template< typename category_name, typename scalar_name >
struct scale {
public:
	typedef category_name category_type;
	typedef scalar_name scalar_type;
	typedef scalar_type const& scalar_const_input_type;

	typedef ::color::trait::container< category_type > container_trait_type;

	typedef ::color::trait::index<category_type> index_trait_type;

	typedef typename color::_internal::model<category_type> model_type;

	typedef model_type & model_input_type;
	typedef model_type const& model_const_input_type;

	typedef typename index_trait_type::instance_type index_type;

	static void process(model_input_type result, scalar_const_input_type const& scalar) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, result.get(index) * scalar);
		}
	}

	static void process(model_input_type result, scalar_const_input_type scalar, model_const_input_type right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, scalar * right.get(index));
		}
	}

};
}

template< typename category_name, typename scalar_name >
void scale
(
	color::_internal::model<category_name> & result
	,scalar_name const& scalar
) {
	color::operation::_internal::scale<category_name,scalar_name>::process(result, scalar);
}

template< typename category_name, typename scalar_name >
void scale
(
	color::_internal::model<category_name> & result
	,scalar_name const& scalar
	,color::_internal::model<category_name> const& right
) {
	color::operation::_internal::scale<category_name,scalar_name>::process(result, scalar, right);
}

}
}

namespace color {
namespace operation {
namespace arithmetic {

template< typename category_name >
inline
::color::_internal::model< category_name >
operator +(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	::color::_internal::model< category_name > result;
	::color::operation::addition(result, left, right);
	return result;
}

template< typename category_name>
inline
::color::_internal::model< category_name > &
operator +=(::color::_internal::model< category_name > & result, ::color::_internal::model< category_name > const& right) {
	::color::operation::addition(result, right);
	return result;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
operator -(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	::color::_internal::model< category_name > result;
	::color::operation::subtract(result, left, right);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::_internal::model< category_name >
operator *
(
	scalar_name const& left
	,::color::_internal::model< category_name > const& right
) {
	::color::_internal::model< category_name > result;
	::color::operation::scale(result, left, right);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::_internal::model< category_name >
operator *
(
	::color::_internal::model< category_name > const & left
	,scalar_name const & right
) {
	::color::_internal::model< category_name > result;
	::color::operation::scale(result, right, left);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::_internal::model< category_name >
operator /
(
	::color::_internal::model< category_name > const & left
	,scalar_name const & right
) {
	::color::_internal::model< category_name > result;
	::color::operation::scale(result, scalar_name(1) / right, left);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::_internal::model< category_name > &
operator -=(::color::_internal::model< category_name > & result, scalar_name const& left) {
	::color::operation::subtract(result, left);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::_internal::model< category_name > &
operator *=(::color::_internal::model< category_name > & result, scalar_name const& scalar) {
	::color::operation::scale(result, scalar);
	return result;
}

template< typename category_name, typename scalar_name >
inline
::color::_internal::model< category_name > &
operator /=(::color::_internal::model< category_name > & result, scalar_name const& scalar) {
	::color::operation::scale(result, scalar_name(1) / scalar);
	return result;
}

}

}
}

namespace color {
namespace operation {
namespace _internal {

template< typename category_name >
struct convex {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;

	typedef scalar_type const& scalar_const_input_type;

	typedef ::color::trait::index<category_type> index_trait_type;
	typedef ::color::trait::container< category_type > container_trait_type;
	typedef ::color::_internal::model<category_type> model_type;

	typedef model_type & model_input_type;
	typedef model_type const& model_const_input_type;

	typedef typename index_trait_type::instance_type index_type;

	static void process(model_input_type result, scalar_const_input_type scalar, model_const_input_type right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, scalar * result.get(index) +(scalar_type(1) - scalar) *right.get(index));
		}
	}

	static void process(model_input_type result, model_const_input_type left, scalar_const_input_type scalar, model_const_input_type right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, scalar * left.get(index) +(scalar_type(1) - scalar) *right.get(index));
		}
	}

};
}

template< typename category_name, typename scalar_name >
void convex
(
	::color::_internal::model<category_name> & result
	,scalar_name const& scalar
	,color::_internal::model<category_name> const& right
) {
	::color::operation::_internal::convex<category_name>::process(result, scalar, right);
}

template< typename category_name, typename scalar_name >
void convex
(
	::color::_internal::model<category_name> & result
	,color::_internal::model<category_name> const& left
	,scalar_name const& scalar
	,color::_internal::model<category_name> const& right
) {
	::color::operation::_internal::convex<category_name>::process(result, left, scalar, right);
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
alpha(::color::_internal::model< category_name > const& color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef ::color::trait::bound< category_name > bound_type;
	return bound_type::template maximum< 0 >();
}

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
alpha
(
	::color::_internal::model< category_name > & color_parameter,
	typename ::color::_internal::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace operation {
namespace _internal {

template
<
typename category_name
>
struct blend {
public:
	typedef category_name category_type;
	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::operation::_internal::blend<category_type> this_type;

	typedef ::color::trait::container< category_type > container_trait_type;
	typedef ::color::trait::index< category_type > index_trait_type;
	typedef ::color::_internal::model<category_type> model_type;

	typedef typename index_trait_type::instance_type index_type;

	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::_internal::diverse< category_type > diverse_type;

	static void accumulate(model_type &result, scalar_type const& alpha, model_type const& upper) {
		this_type::template accumulate(result, result, alpha, upper);
	}

	static void accumulate(model_type &result, model_type const& lower, scalar_type const& alpha, model_type const& upper) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, (scalar_type(1) - alpha) * lower.get(index) + alpha * upper.get(index));
		}
	}

	template< index_type alpha_index >
	static void accumulate(model_type &result, model_type const& upper) {
		this_type::template accumulate<alpha_index>(result, result, upper);
	}

	template< index_type alpha_index >
	static void accumulate(model_type &result, model_type const& lower, model_type const& upper) {
		scalar_type aU = normalize_type::template process<alpha_index>(::color::get::alpha(upper));
		scalar_type aL = normalize_type::template process<alpha_index>(::color::get::alpha(lower));
		scalar_type divisor = aU + aL*(scalar_type(1) - aU);
		scalar_type cU = aU/divisor;
		scalar_type cL = aL * (scalar_type(1) - aU) / divisor;
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			result.set(index, cL * lower.get(index) + cU * upper.get(index));
		}
		::color::set::alpha(result, diverse_type::template process<alpha_index>(divisor));
	}

	static model_type mix(model_type const& lower, scalar_type const& alpha, model_type const& upper) {
		model_type result;
		this_type::template accumulate(result, lower, alpha, upper);
		return result;
	}

	template< index_type alpha_index >
	static model_type mix(model_type const& lower, model_type const& upper) {
		model_type result;
		this_type::template accumulate<alpha_index>(result, lower, upper);
		return result;
	}
};

}

template< typename category_name >
void blend
(
	::color::_internal::model<category_name> & result
	,::color::_internal::model<category_name> const& upper
) {
	enum { alpha_index = ::color::place::_internal::alpha<category_name>::position_enum };
	::color::operation::_internal::blend<category_name>::template accumulate< alpha_index >(result, upper);
}

template< typename category_name >
void blend
(
	::color::_internal::model<category_name> & result
	,::color::_internal::model<category_name> const& lower
	,::color::_internal::model<category_name> const& upper
) {
	enum { alpha_index = ::color::place::_internal::alpha<category_name>::position_enum };
	::color::operation::_internal::blend<category_name>::template accumulate< alpha_index >(result, lower, upper);
}

template< typename category_name >
::color::_internal::model<category_name>
mix
(
	::color::_internal::model<category_name> const& lower
	,::color::_internal::model<category_name> const& upper
) {
	enum { alpha_index = ::color::place::_internal::alpha<category_name>::position_enum };
	return ::color::operation::_internal::blend<category_name>::template mix< alpha_index >(lower, upper);
}

template< typename category_name, typename scalar_name = double >
void blend
(
	::color::_internal::model<category_name> & result
	,scalar_name const& alpha
	,::color::_internal::model<category_name> const& upper
) {
	enum { alpha_index = ::color::place::_internal::alpha<category_name>::position_enum };
	::color::operation::_internal::blend<category_name>::accumulate(result, alpha, upper);
}

template< typename category_name, typename scalar_name = double >
void blend
(
	::color::_internal::model<category_name> & result
	,::color::_internal::model<category_name> const& lower
	,scalar_name const& alpha
	,::color::_internal::model<category_name> const& upper
) {
	::color::operation::_internal::blend<category_name>::accumulate(result, lower, alpha, upper);
}

template< typename category_name, typename scalar_name = double >
::color::_internal::model<category_name>
mix
(
	::color::_internal::model<category_name> const& lower
	,scalar_name const& alpha
	,::color::_internal::model<category_name> const& upper
) {
	return ::color::operation::_internal::blend<category_name>::mix(lower, alpha, upper);
}

}
}

namespace color {
	namespace operation {

		template< typename category_name >
		inline
		typename ::color::trait::scalar< category_name >::instance_type
		normalize
		(
			::color::_internal::model<category_name> const& m
			,typename ::color::trait::index<category_name>::input_const_type index
) {
	return ::color::_internal::normalize<category_name>::process(m[index], index) ;
}

template
<
unsigned index_size
,typename category_name
>
inline
typename ::color::trait::scalar< category_name >::instance_type
normalize
(
	::color::_internal::model<category_name> const& m
) {
	return ::color::_internal::normalize<category_name>::template process<index_size>(m.template get<index_size>());
}

	}
}

namespace color {
	namespace set {

		template< typename tag_name >
		inline
		void
		gray
		(
			::color::_internal::model< ::color::category::cmy<tag_name> > & color_parameter,
			typename ::color::_internal::model< ::color::category::cmy<tag_name> >::component_input_const_type component_parameter
) {
	typedef ::color::category::cmy<tag_name> category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::normalize< category_type > normalize_cmy_type;
	typedef ::color::_internal::normalize< akin_type > normalize_akin_type;
	typedef ::color::constant::gray< akin_type > gray_const_type;
	scalar_type value =
	gray_const_type::Rc() * (scalar_type(1) - normalize_cmy_type::template process<0>(color_parameter.template get<0>()))
	+ gray_const_type::Gc() * (scalar_type(1) - normalize_cmy_type::template process<0>(color_parameter.template get<1>()))
	+ gray_const_type::Bc() * (scalar_type(1) - normalize_cmy_type::template process<0>(color_parameter.template get<2>()));
	value = normalize_akin_type::template process<0>(component_parameter) / value;
	::color::operation::scale(color_parameter, scalar_type(1) - value);
};

	}
}

namespace color {
	namespace make {

		inline
void black(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xff;
}

inline
void black(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xffff;
}

inline
void black(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffffffu;
}

inline
void black(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffffffffffffffful;
}

inline
void black(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 1, 1 });
}

inline
void black(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 1, 1 });
}

inline
void black(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 1, 1 });
}

	}
}

namespace color {
	namespace make {

		inline
void gray50(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x5b;
}

inline
void gray50(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x7def;
}

inline
void gray50(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f7f7fu;
}

inline
void gray50(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7fff7ffful;
}

inline
void gray50(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 0.5, 0.5 });
}

inline
void gray50(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 0.5, 0.5 });
}

inline
void gray50(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 0.5, 0.5 });
}

	}
}

namespace color {
	namespace make {

		inline
void white(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void white(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void white(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff000000u;
}

inline
void white(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff000000000000ul;
}

inline
void white(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 0 });
}

inline
void white(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 0 });
}

inline
void white(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 0 });
}

	}
}

namespace color {
	namespace make {

		inline
void red(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xf8;
}

inline
void red(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xffe0;
}

inline
void red(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff00u;
}

inline
void red(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffff0000ul;
}

inline
void red(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 1, 1 });
}

inline
void red(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 1, 1 });
}

inline
void red(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 1, 1 });
}

	}
}

namespace color {
	namespace make {

		inline
void green(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xdf;
}

inline
void green(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xfdff;
}

inline
void green(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff7fffu;
}

inline
void green(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff7ffffffful;
}

inline
void green(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0.5, 1 });
}

inline
void green(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0.5, 1 });
}

inline
void green(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0.5, 1 });
}

	}
}

namespace color {
	namespace make {

		inline
void blue(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x3f;
}

inline
void blue(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x3ff;
}

inline
void blue(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00ffffu;
}

inline
void blue(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000fffffffful;
}

inline
void blue(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 1, 0 });
}

inline
void blue(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 1, 0 });
}

inline
void blue(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 1, 0 });
}

	}
}

namespace color {
	namespace make {

		inline
void cyan(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x7;
}

inline
void cyan(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x1f;
}

inline
void cyan(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff0000ffu;
}

inline
void cyan(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff00000000fffful;
}

inline
void cyan(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0, 0 });
}

inline
void cyan(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0, 0 });
}

inline
void cyan(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0, 0 });
}

	}
}

namespace color {
	namespace make {

		inline
void magenta(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x38;
}

inline
void magenta(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x3e0;
}

inline
void magenta(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00ff00u;
}

inline
void magenta(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000ffff0000ul;
}

inline
void magenta(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 1, 0 });
}

inline
void magenta(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 1, 0 });
}

inline
void magenta(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 1, 0 });
}

	}
}

namespace color {
	namespace make {

		inline
void yellow(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xc0;
}

inline
void yellow(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xfc00;
}

inline
void yellow(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff0000u;
}

inline
void yellow(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff00000000ul;
}

inline
void yellow(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 1 });
}

inline
void yellow(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 1 });
}

inline
void yellow(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 1 });
}

	}
}

namespace color {
	namespace make {

		inline
void aqua(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x7;
}

inline
void aqua(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x1f;
}

inline
void aqua(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff0000ffu;
}

inline
void aqua(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff00000000fffful;
}

inline
void aqua(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0, 0 });
}

inline
void aqua(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0, 0 });
}

inline
void aqua(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0, 0 });
}

	}
}

namespace color {
	namespace make {

		inline
void fuchsia(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x38;
}

inline
void fuchsia(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x3e0;
}

inline
void fuchsia(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00ff00u;
}

inline
void fuchsia(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000ffff0000ul;
}

inline
void fuchsia(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 1, 0 });
}

inline
void fuchsia(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 1, 0 });
}

inline
void fuchsia(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 1, 0 });
}

	}
}

namespace color {
	namespace make {

		inline
void lime(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xc7;
}

inline
void lime(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xfc1f;
}

inline
void lime(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff00ffu;
}

inline
void lime(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff0000fffful;
}

inline
void lime(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0, 1 });
}

inline
void lime(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0, 1 });
}

inline
void lime(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0, 1 });
}

	}
}

namespace color {
	namespace make {

		inline
void maroon(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xfb;
}

inline
void maroon(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xffef;
}

inline
void maroon(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff7fu;
}

inline
void maroon(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffff7ffful;
}

inline
void maroon(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 1, 1 });
}

inline
void maroon(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 1, 1 });
}

inline
void maroon(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 1, 1 });
}

	}
}

namespace color {
	namespace make {

		inline
void navy(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x7f;
}

inline
void navy(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fff;
}

inline
void navy(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fffffu;
}

inline
void navy(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7ffffffffffful;
}

inline
void navy(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 1, 0.5 });
}

inline
void navy(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 1, 0.5 });
}

inline
void navy(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 1, 0.5 });
}

	}
}

namespace color {
	namespace make {

		inline
void olive(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xdb;
}

inline
void olive(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xfdef;
}

inline
void olive(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff7f7fu;
}

inline
void olive(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff7fff7ffful;
}

inline
void olive(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 0.5, 1 });
}

inline
void olive(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 0.5, 1 });
}

inline
void olive(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 0.5, 1 });
}

	}
}

namespace color {
	namespace make {

		inline
void orange(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xd0;
}

inline
void orange(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xfd40;
}

inline
void orange(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff5900u;
}

inline
void orange(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff59990000ul;
}

inline
void orange(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0.35, 1 });
}

inline
void orange(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0.35, 1 });
}

inline
void orange(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0.35, 1 });
}

	}
}

namespace color {
	namespace make {

		inline
void purple(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x7b;
}

inline
void purple(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fef;
}

inline
void purple(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff7fu;
}

inline
void purple(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff7ffful;
}

inline
void purple(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 1, 0.5 });
}

inline
void purple(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 1, 0.5 });
}

inline
void purple(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 1, 0.5 });
}

	}
}

namespace color {
	namespace make {

		inline
void silver(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x9;
}

inline
void silver(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x3ce7;
}

inline
void silver(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3f3f3fu;
}

inline
void silver(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3fff3fff3ffful;
}

inline
void silver(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.25, 0.25, 0.25 });
}

inline
void silver(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.25, 0.25, 0.25 });
}

inline
void silver(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.25, 0.25, 0.25 });
}

	}
}

namespace color {
	namespace make {

		inline
void teal(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x5f;
}

inline
void teal(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x7dff;
}

inline
void teal(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f7fffu;
}

inline
void teal(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7ffffffful;
}

inline
void teal(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0.5, 0.5 });
}

inline
void teal(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0.5, 0.5 });
}

inline
void teal(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0.5, 0.5 });
}

	}
}

namespace color {
	namespace make {

		inline
void violet(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x18;
}

inline
void violet(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x11e2;
}

inline
void violet(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff107d10u;
}

inline
void violet(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff11107d7d1110ul;
}

inline
void violet(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.0666667, 0.490196, 0.0666667 });
}

inline
void violet(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.0666667, 0.490196, 0.0666667 });
}

inline
void violet(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.0666667, 0.490196, 0.0666667 });
}

	}
}

namespace color {
	namespace make {

		inline
void aquamarine(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x3;
}

inline
void aquamarine(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x280f;
}

inline
void aquamarine(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff2a007fu;
}

inline
void aquamarine(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff2b2a00007ffful;
}

inline
void aquamarine(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 0, 0.168627 });
}

inline
void aquamarine(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 0, 0.168627 });
}

inline
void aquamarine(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 0, 0.168627 });
}

	}
}

namespace color {
	namespace make {

		inline
void azure(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void azure(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x1;
}

inline
void azure(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00000fu;
}

inline
void azure(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff000000000f0ful;
}

inline
void azure(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.0588235, 0, 0 });
}

inline
void azure(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.0588235, 0, 0 });
}

inline
void azure(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.0588235, 0, 0 });
}

	}
}

namespace color {
	namespace make {

		inline
void beige(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void beige(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x2021;
}

inline
void beige(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff220909u;
}

inline
void beige(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff23220a090a09ul;
}

inline
void beige(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.0392157, 0.0392157, 0.137255 });
}

inline
void beige(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.0392157, 0.0392157, 0.137255 });
}

inline
void beige(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.0392157, 0.0392157, 0.137255 });
}

	}
}

namespace color {
	namespace make {

		inline
void bisque(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void bisque(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x3860;
}

inline
void bisque(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3a1a00u;
}

inline
void bisque(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3b3a1b1a0000ul;
}

inline
void bisque(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0.105882, 0.231373 });
}

inline
void bisque(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0.105882, 0.231373 });
}

inline
void bisque(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0.105882, 0.231373 });
}

	}
}

namespace color {
	namespace make {

		inline
void brown(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xaa;
}

inline
void brown(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xd32a;
}

inline
void brown(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd5d559u;
}

inline
void brown(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd5d5d5d55a59ul;
}

inline
void brown(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.352941, 0.835294, 0.835294 });
}

inline
void brown(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.352941, 0.835294, 0.835294 });
}

inline
void brown(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.352941, 0.835294, 0.835294 });
}

	}
}

namespace color {
	namespace make {

		inline
void chocolate(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xa1;
}

inline
void chocolate(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xde45;
}

inline
void chocolate(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffe1962du;
}

inline
void chocolate(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffe1e196962d2dul;
}

inline
void chocolate(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.176471, 0.588235, 0.882353 });
}

inline
void chocolate(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.176471, 0.588235, 0.882353 });
}

inline
void chocolate(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.176471, 0.588235, 0.882353 });
}

	}
}

namespace color {
	namespace make {

		inline
void coral(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x98;
}

inline
void coral(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xade0;
}

inline
void coral(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffaf7f00u;
}

inline
void coral(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffb0a37fff0000ul;
}

inline
void coral(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0.5, 0.69 });
}

inline
void coral(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0.5, 0.69 });
}

inline
void coral(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0.5, 0.69 });
}

	}
}

namespace color {
	namespace make {

		inline
void crimson(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xb0;
}

inline
void crimson(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xc384;
}

inline
void crimson(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffc3eb22u;
}

inline
void crimson(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffc3c3ebeb2322ul;
}

inline
void crimson(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.137255, 0.921569, 0.764706 });
}

inline
void crimson(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.137255, 0.921569, 0.764706 });
}

inline
void crimson(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.137255, 0.921569, 0.764706 });
}

	}
}

namespace color {
	namespace make {

		inline
void gainsboro(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void gainsboro(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x2084;
}

inline
void gainsboro(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff232323u;
}

inline
void gainsboro(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff23d623d623d6ul;
}

inline
void gainsboro(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.14, 0.14, 0.14 });
}

inline
void gainsboro(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.14, 0.14, 0.14 });
}

inline
void gainsboro(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.14, 0.14, 0.14 });
}

	}
}

namespace color {
	namespace make {

		inline
void gold(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xc8;
}

inline
void gold(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xfc80;
}

inline
void gold(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff2800u;
}

inline
void gold(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff28280000ul;
}

inline
void gold(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0.156863, 1 });
}

inline
void gold(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0.156863, 1 });
}

inline
void gold(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0.156863, 1 });
}

	}
}

namespace color {
	namespace make {

		inline
void indigo(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x7c;
}

inline
void indigo(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x7bf5;
}

inline
void indigo(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7dffb3u;
}

inline
void indigo(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7d7dffffb4b3ul;
}

inline
void indigo(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.705882, 1, 0.490196 });
}

inline
void indigo(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.705882, 1, 0.490196 });
}

inline
void indigo(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.705882, 1, 0.490196 });
}

	}
}

namespace color {
	namespace make {

		inline
void ivory(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void ivory(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xc00;
}

inline
void ivory(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff0f0000u;
}

inline
void ivory(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0f0f00000000ul;
}

inline
void ivory(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 0.0588235 });
}

inline
void ivory(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 0.0588235 });
}

inline
void ivory(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 0.0588235 });
}

	}
}

namespace color {
	namespace make {

		inline
void khaki(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x40;
}

inline
void khaki(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x7061;
}

inline
void khaki(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff72180fu;
}

inline
void khaki(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff737219180f0ful;
}

inline
void khaki(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.0588235, 0.0980392, 0.45098 });
}

inline
void khaki(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.0588235, 0.0980392, 0.45098 });
}

inline
void khaki(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.0588235, 0.0980392, 0.45098 });
}

	}
}

namespace color {
	namespace make {

		inline
void lavender(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void lavender(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x463;
}

inline
void lavender(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff051818u;
}

inline
void lavender(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff050519181918ul;
}

inline
void lavender(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.0980392, 0.0980392, 0.0196078 });
}

inline
void lavender(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.0980392, 0.0980392, 0.0196078 });
}

inline
void lavender(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.0980392, 0.0980392, 0.0196078 });
}

	}
}

namespace color {
	namespace make {

		inline
void linen(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void linen(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x1820;
}

inline
void linen(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff180f05u;
}

inline
void linen(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff19180f0f0505ul;
}

inline
void linen(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.0196078, 0.0588235, 0.0980392 });
}

inline
void linen(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.0196078, 0.0588235, 0.0980392 });
}

inline
void linen(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.0196078, 0.0588235, 0.0980392 });
}

	}
}

namespace color {
	namespace make {

		inline
void moccasin(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void moccasin(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x4860;
}

inline
void moccasin(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff491a00u;
}

inline
void moccasin(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff4a491b1a0000ul;
}

inline
void moccasin(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0.105882, 0.290196 });
}

inline
void moccasin(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0.105882, 0.290196 });
}

inline
void moccasin(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0.105882, 0.290196 });
}

	}
}

namespace color {
	namespace make {

		inline
void orchid(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x19;
}

inline
void orchid(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x2a24;
}

inline
void orchid(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff288f25u;
}

inline
void orchid(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff29288f8f2525ul;
}

inline
void orchid(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.145098, 0.560784, 0.160784 });
}

inline
void orchid(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.145098, 0.560784, 0.160784 });
}

inline
void orchid(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.145098, 0.560784, 0.160784 });
}

	}
}

namespace color {
	namespace make {

		inline
void peru(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x99;
}

inline
void peru(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xbdc6;
}

inline
void peru(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffc07931u;
}

inline
void peru(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffc0c07a793231ul;
}

inline
void peru(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.196078, 0.478431, 0.752941 });
}

inline
void peru(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.196078, 0.478431, 0.752941 });
}

inline
void peru(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.196078, 0.478431, 0.752941 });
}

	}
}

namespace color {
	namespace make {

		inline
void pink(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x99;
}

inline
void pink(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xbdc6;
}

inline
void pink(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffbf7931u;
}

inline
void pink(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffc0bf7a793231ul;
}

inline
void pink(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.196078, 0.478431, 0.752941 });
}

inline
void pink(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.196078, 0.478431, 0.752941 });
}

inline
void pink(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.196078, 0.478431, 0.752941 });
}

	}
}

namespace color {
	namespace make {

		inline
void plum(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x10;
}

inline
void plum(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x2164;
}

inline
void plum(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff215f21u;
}

inline
void plum(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff22215f5f2221ul;
}

inline
void plum(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.133333, 0.372549, 0.133333 });
}

inline
void plum(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.133333, 0.372549, 0.133333 });
}

inline
void plum(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.133333, 0.372549, 0.133333 });
}

	}
}

namespace color {
	namespace make {

		inline
void salmon(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x10;
}

inline
void salmon(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x2164;
}

inline
void salmon(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff215e21u;
}

inline
void salmon(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff22215f5e2221ul;
}

inline
void salmon(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.133333, 0.372549, 0.133333 });
}

inline
void salmon(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.133333, 0.372549, 0.133333 });
}

inline
void salmon(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.133333, 0.372549, 0.133333 });
}

	}
}

namespace color {
	namespace make {

		inline
void sienna(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xa2;
}

inline
void sienna(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xceab;
}

inline
void sienna(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd2ad5fu;
}

inline
void sienna(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd2d2adad5f5ful;
}

inline
void sienna(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.372549, 0.678431, 0.823529 });
}

inline
void sienna(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.372549, 0.678431, 0.823529 });
}

inline
void sienna(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.372549, 0.678431, 0.823529 });
}

	}
}

namespace color {
	namespace make {

		inline
void snow(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void snow(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x400;
}

inline
void snow(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff050500u;
}

inline
void snow(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff050505050000ul;
}

inline
void snow(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0.0196078, 0.0196078 });
}

inline
void snow(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0.0196078, 0.0196078 });
}

inline
void snow(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0.0196078, 0.0196078 });
}

	}
}

namespace color {
	namespace make {

		inline
void tan(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x51;
}

inline
void tan(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x7125;
}

inline
void tan(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff724a2du;
}

inline
void tan(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff73724b4a2d2dul;
}

inline
void tan(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.176471, 0.294118, 0.45098 });
}

inline
void tan(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.176471, 0.294118, 0.45098 });
}

inline
void tan(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.176471, 0.294118, 0.45098 });
}

	}
}

namespace color {
	namespace make {

		inline
void thistle(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x9;
}

inline
void thistle(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x24e4;
}

inline
void thistle(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff274027u;
}

inline
void thistle(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff272740402727ul;
}

inline
void thistle(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.152941, 0.25098, 0.152941 });
}

inline
void thistle(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.152941, 0.25098, 0.152941 });
}

inline
void thistle(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.152941, 0.25098, 0.152941 });
}

	}
}

namespace color {
	namespace make {

		inline
void tomato(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0xa0;
}

inline
void tomato(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0xb640;
}

inline
void tomato(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xffb89c00u;
}

inline
void tomato(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffb8b89c9c0000ul;
}

inline
void tomato(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0.611765, 0.721569 });
}

inline
void tomato(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0.611765, 0.721569 });
}

inline
void tomato(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0.611765, 0.721569 });
}

	}
}

namespace color {
	namespace make {

		inline
void turquoise(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x5;
}

inline
void turquoise(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x2c77;
}

inline
void turquoise(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff2f1fbfu;
}

inline
void turquoise(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff2f2f1f1fbfbful;
}

inline
void turquoise(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.74902, 0.121569, 0.184314 });
}

inline
void turquoise(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.74902, 0.121569, 0.184314 });
}

inline
void turquoise(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.74902, 0.121569, 0.184314 });
}

	}
}

namespace color {
	namespace make {

		inline
void wheat(::color::_internal::model< color::category::cmy_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void wheat(::color::_internal::model< color::category::cmy_uint16 > & color_parameter) {
	color_parameter.container() = 0x4881;
}

inline
void wheat(::color::_internal::model< color::category::cmy_uint32 > & color_parameter) {
	color_parameter.container() = 0xff4c2009u;
}

inline
void wheat(::color::_internal::model< color::category::cmy_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff4c4c21200a09ul;
}

inline
void wheat(::color::_internal::model< color::category::cmy_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.0392157, 0.129412, 0.298039 });
}

inline
void wheat(::color::_internal::model< color::category::cmy_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.0392157, 0.129412, 0.298039 });
}

inline
void wheat(::color::_internal::model< color::category::cmy_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.0392157, 0.129412, 0.298039 });
}

	}
}

namespace color {
	namespace _internal {

		template< typename tag_left_name, typename tag_right_name >
		struct convert
		<
		::color::category::cmy< tag_left_name >
		,::color::category::cmy< tag_right_name>
		> {
			public:
			typedef ::color::category::cmy< tag_left_name > category_left_type;
			typedef ::color::category::cmy< tag_right_name> category_right_type;

			typedef double scalar_type;

			typedef ::color::trait::container<category_left_type> container_left_trait_type;
			typedef ::color::trait::container<category_right_type> container_right_trait_type;

			typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

			typedef typename container_left_trait_type::input_type container_left_input_type;
			typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

			static void process
			(
				container_left_input_type left
				,container_right_const_input_type right
) {
	container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
	container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
	container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
}
		};
	}
}

namespace color {
	namespace akin {

		template< >struct cmyk< ::color::category::cmy_uint8 > {
			typedef ::color::category::cmyk_uint8 akin_type;
		};
		template< >struct cmyk< ::color::category::cmy_uint16 > {
			typedef ::color::category::cmyk_uint16 akin_type;
		};
		template< >struct cmyk< ::color::category::cmy_uint32 > {
			typedef ::color::category::cmyk_uint32 akin_type;
		};
		template< >struct cmyk< ::color::category::cmy_uint64 > {
			typedef ::color::category::cmyk_uint64 akin_type;
		};
		template< >struct cmyk< ::color::category::cmy_float > {
			typedef ::color::category::cmyk_float akin_type;
		};
		template< >struct cmyk< ::color::category::cmy_double > {
			typedef ::color::category::cmyk_double akin_type;
		};
		template< >struct cmyk< ::color::category::cmy_ldouble > {
			typedef ::color::category::cmyk_ldouble akin_type;
		};

	}
}

namespace color {
	namespace akin {

		template< >struct cmyk< ::color::category::cmyk_uint8 > {
			typedef ::color::category::cmyk_uint8 akin_type;
		};
		template< >struct cmyk< ::color::category::cmyk_uint16 > {
			typedef ::color::category::cmyk_uint16 akin_type;
		};
		template< >struct cmyk< ::color::category::cmyk_uint32 > {
			typedef ::color::category::cmyk_uint32 akin_type;
		};
		template< >struct cmyk< ::color::category::cmyk_uint64 > {
			typedef ::color::category::cmyk_uint64 akin_type;
		};
		template< >struct cmyk< ::color::category::cmyk_float > {
			typedef ::color::category::cmyk_float akin_type;
		};
		template< >struct cmyk< ::color::category::cmyk_double > {
			typedef ::color::category::cmyk_double akin_type;
		};
		template< >struct cmyk< ::color::category::cmyk_ldouble > {
			typedef ::color::category::cmyk_ldouble akin_type;
		};

	}
}

namespace color {
	namespace akin {

		template< >struct cmyk< ::color::category::gray_uint8 > {
			typedef ::color::category::cmyk_uint8 akin_type;
		};
		template< >struct cmyk< ::color::category::gray_uint16 > {
			typedef ::color::category::cmyk_uint16 akin_type;
		};
		template< >struct cmyk< ::color::category::gray_uint32 > {
			typedef ::color::category::cmyk_uint32 akin_type;
		};
		template< >struct cmyk< ::color::category::gray_uint64 > {
			typedef ::color::category::cmyk_uint64 akin_type;
		};
		template< >struct cmyk< ::color::category::gray_float > {
			typedef ::color::category::cmyk_float akin_type;
		};
		template< >struct cmyk< ::color::category::gray_double > {
			typedef ::color::category::cmyk_double akin_type;
		};
		template< >struct cmyk< ::color::category::gray_ldouble > {
			typedef ::color::category::cmyk_ldouble akin_type;
		};

	}
}

namespace color {
	namespace akin {

		template< >struct cmyk< ::color::category::hsl_uint8 > {
			typedef ::color::category::cmyk_uint8 akin_type;
		};
		template< >struct cmyk< ::color::category::hsl_uint16 > {
			typedef ::color::category::cmyk_uint16 akin_type;
		};
		template< >struct cmyk< ::color::category::hsl_uint32 > {
			typedef ::color::category::cmyk_uint32 akin_type;
		};
		template< >struct cmyk< ::color::category::hsl_uint64 > {
			typedef ::color::category::cmyk_uint64 akin_type;
		};
		template< >struct cmyk< ::color::category::hsl_float > {
			typedef ::color::category::cmyk_float akin_type;
		};
		template< >struct cmyk< ::color::category::hsl_double > {
			typedef ::color::category::cmyk_double akin_type;
		};
		template< >struct cmyk< ::color::category::hsl_ldouble > {
			typedef ::color::category::cmyk_ldouble akin_type;
		};

	}
}

namespace color {
	namespace akin {

		template< >struct cmyk< ::color::category::hsv_uint8 > {
			typedef ::color::category::cmyk_uint8 akin_type;
		};
		template< >struct cmyk< ::color::category::hsv_uint16 > {
			typedef ::color::category::cmyk_uint16 akin_type;
		};
		template< >struct cmyk< ::color::category::hsv_uint32 > {
			typedef ::color::category::cmyk_uint32 akin_type;
		};
		template< >struct cmyk< ::color::category::hsv_uint64 > {
			typedef ::color::category::cmyk_uint64 akin_type;
		};
		template< >struct cmyk< ::color::category::hsv_float > {
			typedef ::color::category::cmyk_float akin_type;
		};
		template< >struct cmyk< ::color::category::hsv_double > {
			typedef ::color::category::cmyk_double akin_type;
		};
		template< >struct cmyk< ::color::category::hsv_ldouble > {
			typedef ::color::category::cmyk_ldouble akin_type;
		};

	}
}

namespace color {
	namespace akin {

		template< >struct cmyk< ::color::category::rgb_uint8 > {
			typedef ::color::category::cmyk_uint8 akin_type;
		};
		template< >struct cmyk< ::color::category::rgb_uint16 > {
			typedef ::color::category::cmyk_uint16 akin_type;
		};
		template< >struct cmyk< ::color::category::rgb_uint32 > {
			typedef ::color::category::cmyk_uint32 akin_type;
		};
		template< >struct cmyk< ::color::category::rgb_uint64 > {
			typedef ::color::category::cmyk_uint64 akin_type;
		};
		template< >struct cmyk< ::color::category::rgb_float > {
			typedef ::color::category::cmyk_float akin_type;
		};
		template< >struct cmyk< ::color::category::rgb_double > {
			typedef ::color::category::cmyk_double akin_type;
		};
		template< >struct cmyk< ::color::category::rgb_ldouble > {
			typedef ::color::category::cmyk_ldouble akin_type;
		};

	}
}

namespace color {
	namespace akin {

		template< >struct cmyk< ::color::category::yiq_uint8 > {
			typedef ::color::category::cmyk_uint8 akin_type;
		};
		template< >struct cmyk< ::color::category::yiq_uint16 > {
			typedef ::color::category::cmyk_uint16 akin_type;
		};
		template< >struct cmyk< ::color::category::yiq_uint32 > {
			typedef ::color::category::cmyk_uint32 akin_type;
		};
		template< >struct cmyk< ::color::category::yiq_uint64 > {
			typedef ::color::category::cmyk_uint64 akin_type;
		};
		template< >struct cmyk< ::color::category::yiq_float > {
			typedef ::color::category::cmyk_float akin_type;
		};
		template< >struct cmyk< ::color::category::yiq_double > {
			typedef ::color::category::cmyk_double akin_type;
		};
		template< >struct cmyk< ::color::category::yiq_ldouble > {
			typedef ::color::category::cmyk_ldouble akin_type;
		};

	}
}

namespace color {
	namespace akin {

		template< >struct cmyk< ::color::category::yuv_uint8 > {
			typedef ::color::category::cmyk_uint8 akin_type;
		};
		template< >struct cmyk< ::color::category::yuv_uint16 > {
			typedef ::color::category::cmyk_uint16 akin_type;
		};
		template< >struct cmyk< ::color::category::yuv_uint32 > {
			typedef ::color::category::cmyk_uint32 akin_type;
		};
		template< >struct cmyk< ::color::category::yuv_uint64 > {
			typedef ::color::category::cmyk_uint64 akin_type;
		};
		template< >struct cmyk< ::color::category::yuv_float > {
			typedef ::color::category::cmyk_float akin_type;
		};
		template< >struct cmyk< ::color::category::yuv_double > {
			typedef ::color::category::cmyk_double akin_type;
		};
		template< >struct cmyk< ::color::category::yuv_ldouble > {
			typedef ::color::category::cmyk_ldouble akin_type;
		};

	}
}

namespace color {
	namespace trait {

		template< >
		struct bound< ::color::category::cmyk_double >
		: public ::color::_internal::utility::bound::general< double, unsigned > {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct bound< ::color::category::cmyk_float >
		: public ::color::_internal::utility::bound::general< float, unsigned > {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct bound< ::color::category::cmyk_ldouble >
		: public ::color::_internal::utility::bound::general< long double, unsigned > {
		};

	}
}

namespace color {
	namespace trait {

		template< >
		struct bound< ::color::category::cmyk_uint16 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 4, unsigned > {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct bound< ::color::category::cmyk_uint32 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 8, unsigned > {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct bound< ::color::category::cmyk_uint64 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 16, unsigned > {
		};

	}
}

namespace color {
	namespace _internal {
		namespace utility {
			namespace bound {

				template< typename index_name >
				struct bound2222 {
					public:
					typedef std::uint8_t unsigned_type;
					typedef index_name index_type;

					typedef ::color::_internal::utility::type::traitP< unsigned_type > trait_type;
					typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

					typedef typename trait_type::instance_type instance_type;
					typedef typename trait_type::return_image_type return_image_type;

					typedef typename index_trait_type::instance_type index_instance_type;
					typedef typename index_trait_type::input_const_type index_input_const_type;

					template< index_instance_type index >
static return_image_type maximum() {
	static instance_type max_list[] = { 3, 3, 3, 3 };
	return max_list[index];
}

static return_image_type maximum(index_input_const_type index) {
	static instance_type max_list[] = { 3, 3, 3, 3 };
	return max_list[index];
}

template< index_instance_type index >
static return_image_type minimum() {
	static instance_type value=0;
	return value;
}

static return_image_type minimum(index_input_const_type index) {
	static instance_type value=0;
	return value;
}

template< index_instance_type index >
static return_image_type range() {
	static instance_type max_list[] = { 3, 3, 3, 3 };
	return max_list[index];
}

static return_image_type range(index_input_const_type index) {
	static instance_type max_list[] = { 3, 3, 3, 3 };
	return max_list[index];
}
				};

			}
		}
	}
}

namespace color {
	namespace trait {

		template< >
		struct bound< ::color::category::cmyk_uint8 >
		: public ::color::_internal::utility::bound::bound2222< unsigned > {
		};

	}
}

namespace color {
	namespace trait {

		template< >
		struct component< ::color::category::cmyk_double >
		: public ::color::_internal::utility::component::array< double, unsigned > {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct component< ::color::category::cmyk_float >
		: public ::color::_internal::utility::component::array< float, unsigned> {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct component< ::color::category::cmyk_ldouble >
		: public ::color::_internal::utility::component::array< long double, unsigned> {
		};

	}
}

namespace color {
	namespace trait {

		template< >
		struct component< ::color::category::cmyk_uint16 >
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned > {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct component< ::color::category::cmyk_uint32 >
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned> {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct component< ::color::category::cmyk_uint64 >
		: public ::color::_internal::utility::component::Unsigned< std::uint16_t, unsigned> {
		};

	}
}

namespace color {
	namespace _internal {
		namespace utility {
			namespace component {

				template< typename index_name >
				struct cnent2222
				: public ::color::_internal::utility::component::Unsigned< std::uint8_t, index_name > {
				};

			}
		}
	}
}

namespace color {
	namespace trait {

		template< >
		struct component< ::color::category::cmyk_uint8 >
		: public ::color::_internal::utility::component::cnent2222< unsigned > {
		};

	}
}

namespace color {
	namespace trait {

		template< >
		struct container< ::color::category::cmyk_double >
		: public ::color::_internal::utility::container::array< double, 4 > {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct container< ::color::category::cmyk_float >
		: public ::color::_internal::utility::container::array< float, 4 > {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct container< ::color::category::cmyk_ldouble >
		: public ::color::_internal::utility::container::array< long double, 4 > {
		};

	}
}

namespace color {
	namespace trait {

		template< >
		struct container< ::color::category::cmyk_uint16 >
		: public ::color::_internal::utility::container::Unsigned< std::uint16_t, std::uint8_t, unsigned, 4, 4 > {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct container< ::color::category::cmyk_uint32 >
		: public ::color::_internal::utility::container::Unsigned< std::uint32_t, std::uint8_t, unsigned, 4, 8 > {
		};

	}
}
namespace color {
	namespace trait {

		template< >
		struct container< ::color::category::cmyk_uint64 >
		: public ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint16_t, unsigned, 4, 16 > {
		};

	}
}

namespace color {
	namespace _internal {
		namespace utility {
			namespace container {

				template< typename index_name >
				struct cner2222 {
					public:

					typedef index_name index_type;

					typedef std::uint8_t value_type;
					typedef std::uint8_t instance_type;

					typedef instance_type const const_type;
					typedef instance_type const& return_image_type;
					typedef instance_type & return_type;
					typedef instance_type const& input_const_type;
					typedef instance_type & input_type;
					typedef instance_type & output_type;

					typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

					typedef typename index_trait_type::instance_type index_instance_type;
					typedef typename index_trait_type::input_const_type index_input_const_type;
					typedef typename index_trait_type::return_image_type index_return_image_type;

					typedef ::color::_internal::utility::type::traitP< value_type > component_trait_type;

					typedef typename component_trait_type::const_type component_const_type;
					typedef typename component_trait_type::instance_type component_type;
					typedef typename component_trait_type::return_image_type component_return_const_type;
					typedef typename component_trait_type::input_const_type component_input_const_type;

					typedef void set_return_type;

static component_return_const_type get(input_const_type container, index_input_const_type index) {
	switch(index) {
	case(0):
		return ((container >> 0) & 3);
	case(1):
		return ((container >> 2) & 3);
	case(2):
		return ((container >> 4) & 3);
	case(3):
		return ((container >> 4) & 3);
	}
	return 0;
}

template< index_instance_type index >
static component_return_const_type get(input_const_type container) {
	switch(index) {
	case(0):
		return ((container >> 0) & 3);
	case(1):
		return ((container >> 2) & 3);
	case(2):
		return ((container >> 4) & 3);
	case(3):
		return ((container >> 4) & 3);
	}
	return 0;
}

static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
	switch(index) {
	case(0) :
		container = (container & ~(3 << (0))) | (((instance_type)value) << (0));
		break;
	case(1) :
		container = (container & ~(3 << (2))) | (((instance_type)value) << (2));
		break;
	case(2) :
		container = (container & ~(3 << (4))) | (((instance_type)value) << (4));
		break;
	case(3) :
		container = (container & ~(3 << (6))) | (((instance_type)value) << (6));
		break;
	}
}

template< index_instance_type index >
static set_return_type set(input_type container, component_input_const_type value) {
	switch(index) {
	case(0) :
		container = (container & ~(3 << (0))) | (((instance_type)value) << (0));
		break;
	case(1) :
		container = (container & ~(3 << (2))) | (((instance_type)value) << (2));
		break;
	case(2) :
		container = (container & ~(3 << (4))) | (((instance_type)value) << (4));
		break;
	case(3) :
		container = (container & ~(3 << (6))) | (((instance_type)value) << (6));
		break;
	}
}

static index_return_image_type size() {
	static const index_instance_type local_length = 4;
	return local_length;
}
				};
			}
		}
	}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::cmyk_uint8 >
		: public ::color::_internal::utility::container::cner2222< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct index< ::color::category::cmyk_double >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmyk_float >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmyk_ldouble >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmyk_uint16 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmyk_uint32 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmyk_uint64 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::cmyk_uint8 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct cyan< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct magenta< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct yellow< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct key {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -5 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
key() {
	return ::color::place::_internal::key<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct key< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 4 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::cmyk<tag_name> >::akin_type >::return_type
gray(::color::_internal::model< ::color::category::cmyk<tag_name> > const& color_parameter) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::gray< akin_type > gray_const_type;
	scalar_type c = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type m = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type y = normalize_type::template process<2>(color_parameter.template get<2>());
	scalar_type k = normalize_type::template process<3>(color_parameter.template get<3>());
	scalar_type value =
		(gray_const_type::Rc() * (scalar_type(1)-c)
		 + gray_const_type::Gc() * (scalar_type(1)-m)
		 + gray_const_type::Bc() * (scalar_type(1)-y)) * (scalar_type(1)-k);
	return diverse_type::template process<0>(value);
}

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::cmyk_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::cmyk_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::cmyk_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::cmyk_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::cmyk_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::cmyk_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::cmyk_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}
namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::cmyk<tag_name> >::akin_type >::return_type
red(::color::_internal::model< ::color::category::cmyk<tag_name> > const& color_parameter) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type c = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type k = normalize_type::template process<3>(color_parameter.template get<3>());
	scalar_type r = (scalar_type(1)-c) * (scalar_type(1)-k);
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::cmyk< tag_name > >::akin_type >::return_type
green(::color::_internal::model< ::color::category::cmyk< tag_name > > const& color_parameter) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type m = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type k = normalize_type::template process<3>(color_parameter.template get<3>());
	scalar_type g = (1-m) * (1-k);
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::cmyk< tag_name > >::akin_type >::return_type
blue(::color::_internal::model< ::color::category::cmyk< tag_name > > const& color_parameter) {
	typedef ::color::category::cmyk< tag_name > category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type y = normalize_type::template process<2>(color_parameter.template get<2>());
	scalar_type k = normalize_type::template process<3>(color_parameter.template get<3>());
	scalar_type b = (1-y) * (1-k);
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace make {

inline
void black(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0xc0;
}

inline
void black(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xf000;
}

inline
void black(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xff000000u;
}

inline
void black(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff000000000000ul;
}

inline
void black(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0, 0, 1 });
}

inline
void black(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0, 0, 1 });
}

inline
void black(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0, 0, 1 });
}

}
}

namespace color {
namespace make {

inline
void gray50(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x40;
}

inline
void gray50(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x7000;
}

inline
void gray50(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x7f000000u;
}

inline
void gray50(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x7fff000000000000ul;
}

inline
void gray50(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0, 0, 0.5 });
}

inline
void gray50(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0, 0, 0.5 });
}

inline
void gray50(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0, 0, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void white(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void white(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void white(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x0u;
}

inline
void white(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x0ul;
}

inline
void white(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0, 0, 0 });
}

inline
void white(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0, 0, 0 });
}

inline
void white(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void red(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x3c;
}

inline
void red(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xff0;
}

inline
void red(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff00u;
}

inline
void red(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff0000ul;
}

inline
void red(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 1, 1, 0 });
}

inline
void red(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 1, 1, 0 });
}

inline
void red(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 1, 1, 0 });
}

}
}

namespace color {
namespace make {

inline
void green(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x73;
}

inline
void green(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x7f0f;
}

inline
void green(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x7fff00ffu;
}

inline
void green(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x7fffffff0000fffful;
}

inline
void green(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 1, 0, 1, 0.5 });
}

inline
void green(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 1, 0, 1, 0.5 });
}

inline
void green(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 1, 0, 1, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void blue(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0xf;
}

inline
void blue(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xff;
}

inline
void blue(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffu;
}

inline
void blue(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffffffful;
}

inline
void blue(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 1, 1, 0, 0 });
}

inline
void blue(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 1, 1, 0, 0 });
}

inline
void blue(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 1, 1, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void cyan(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x3;
}

inline
void cyan(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xf;
}

inline
void cyan(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xffu;
}

inline
void cyan(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffful;
}

inline
void cyan(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 1, 0, 0, 0 });
}

inline
void cyan(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 1, 0, 0, 0 });
}

inline
void cyan(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 1, 0, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void magenta(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0xc;
}

inline
void magenta(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xf0;
}

inline
void magenta(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00u;
}

inline
void magenta(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000ul;
}

inline
void magenta(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 1, 0, 0 });
}

inline
void magenta(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 1, 0, 0 });
}

inline
void magenta(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 1, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void yellow(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x30;
}

inline
void yellow(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xf00;
}

inline
void yellow(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xff0000u;
}

inline
void yellow(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff00000000ul;
}

inline
void yellow(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0, 1, 0 });
}

inline
void yellow(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0, 1, 0 });
}

inline
void yellow(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0, 1, 0 });
}

}
}

namespace color {
namespace make {

inline
void aqua(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x3;
}

inline
void aqua(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xf;
}

inline
void aqua(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xffu;
}

inline
void aqua(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffful;
}

inline
void aqua(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 1, 0, 0, 0 });
}

inline
void aqua(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 1, 0, 0, 0 });
}

inline
void aqua(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 1, 0, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void fuchsia(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0xc;
}

inline
void fuchsia(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xf0;
}

inline
void fuchsia(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00u;
}

inline
void fuchsia(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000ul;
}

inline
void fuchsia(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 1, 0, 0 });
}

inline
void fuchsia(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 1, 0, 0 });
}

inline
void fuchsia(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 1, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void lime(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x33;
}

inline
void lime(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xf0f;
}

inline
void lime(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00ffu;
}

inline
void lime(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000fffful;
}

inline
void lime(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 1, 0, 1, 0 });
}

inline
void lime(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 1, 0, 1, 0 });
}

inline
void lime(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 1, 0, 1, 0 });
}

}
}

namespace color {
namespace make {

inline
void maroon(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x7c;
}

inline
void maroon(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x7ff0;
}

inline
void maroon(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x7fffff00u;
}

inline
void maroon(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x7fffffffffff0000ul;
}

inline
void maroon(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 1, 1, 0.5 });
}

inline
void maroon(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 1, 1, 0.5 });
}

inline
void maroon(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 1, 1, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void navy(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x4f;
}

inline
void navy(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x70ff;
}

inline
void navy(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x7f00ffffu;
}

inline
void navy(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x7fff0000fffffffful;
}

inline
void navy(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 1, 1, 0, 0.5 });
}

inline
void navy(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 1, 1, 0, 0.5 });
}

inline
void navy(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 1, 1, 0, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void olive(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x70;
}

inline
void olive(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x7f00;
}

inline
void olive(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x7fff0000u;
}

inline
void olive(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x7fffffff00000000ul;
}

inline
void olive(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0, 1, 0.5 });
}

inline
void olive(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0, 1, 0.5 });
}

inline
void olive(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0, 1, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void orange(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x34;
}

inline
void orange(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xf50;
}

inline
void orange(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xff5900u;
}

inline
void orange(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff59990000ul;
}

inline
void orange(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.35, 1, 0 });
}

inline
void orange(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.35, 1, 0 });
}

inline
void orange(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.35, 1, 0 });
}

}
}

namespace color {
namespace make {

inline
void purple(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x4c;
}

inline
void purple(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x70f0;
}

inline
void purple(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x7f00ff00u;
}

inline
void purple(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x7fff0000ffff0000ul;
}

inline
void purple(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 1, 0, 0.5 });
}

inline
void purple(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 1, 0, 0.5 });
}

inline
void purple(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 1, 0, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void silver(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void silver(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x3000;
}

inline
void silver(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x3f000000u;
}

inline
void silver(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x3fff000000000000ul;
}

inline
void silver(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0, 0, 0.25 });
}

inline
void silver(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0, 0, 0.25 });
}

inline
void silver(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0, 0, 0.25 });
}

}
}

namespace color {
namespace make {

inline
void teal(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x43;
}

inline
void teal(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x700f;
}

inline
void teal(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x7f0000ffu;
}

inline
void teal(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x7fff00000000fffful;
}

inline
void teal(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 1, 0, 0, 0.5 });
}

inline
void teal(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 1, 0, 0, 0.5 });
}

inline
void teal(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 1, 0, 0, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void violet(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x4;
}

inline
void violet(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x60;
}

inline
void violet(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x10007300u;
}

inline
void violet(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x11100000742a0000ul;
}

inline
void violet(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.453782, 0, 0.0666667 });
}

inline
void violet(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.453782, 0, 0.0666667 });
}

inline
void violet(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.453782, 0, 0.0666667 });
}

}
}

namespace color {
namespace make {

inline
void aquamarine(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x1;
}

inline
void aquamarine(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x207;
}

inline
void aquamarine(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x2a007fu;
}

inline
void aquamarine(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x2b2a00007ffful;
}

inline
void aquamarine(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0.5, 0, 0.168627, 0 });
}

inline
void aquamarine(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0.5, 0, 0.168627, 0 });
}

inline
void aquamarine(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0.5, 0, 0.168627, 0 });
}

}
}

namespace color {
namespace make {

inline
void azure(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void azure(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void azure(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xfu;
}

inline
void azure(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xf0ful;
}

inline
void azure(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0.0588235, 0, 0, 0 });
}

inline
void azure(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0.0588235, 0, 0, 0 });
}

inline
void azure(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0.0588235, 0, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void beige(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void beige(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x100;
}

inline
void beige(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x91a0000u;
}

inline
void beige(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xa091a1f00000000ul;
}

inline
void beige(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0, 0.102041, 0.0392157 });
}

inline
void beige(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0, 0.102041, 0.0392157 });
}

inline
void beige(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0, 0.102041, 0.0392157 });
}

}
}

namespace color {
namespace make {

inline
void bisque(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void bisque(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x310;
}

inline
void bisque(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x3a1a00u;
}

inline
void bisque(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x3b3a1b1a0000ul;
}

inline
void bisque(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.105882, 0.231373, 0 });
}

inline
void bisque(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.105882, 0.231373, 0 });
}

inline
void bisque(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.105882, 0.231373, 0 });
}

}
}

namespace color {
namespace make {

inline
void brown(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x68;
}

inline
void brown(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x5bb0;
}

inline
void brown(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x59bebe00u;
}

inline
void brown(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x5a59bed5bed50000ul;
}

inline
void brown(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.745455, 0.745455, 0.352941 });
}

inline
void brown(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.745455, 0.745455, 0.352941 });
}

inline
void brown(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.745455, 0.745455, 0.352941 });
}

}
}

namespace color {
namespace make {

inline
void chocolate(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x24;
}

inline
void chocolate(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x2c70;
}

inline
void chocolate(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x2dda7f00u;
}

inline
void chocolate(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x2d2ddb6c7fff0000ul;
}

inline
void chocolate(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.5, 0.857143, 0.176471 });
}

inline
void chocolate(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.5, 0.857143, 0.176471 });
}

inline
void chocolate(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.5, 0.857143, 0.176471 });
}

}
}

namespace color {
namespace make {

inline
void coral(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x24;
}

inline
void coral(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xa70;
}

inline
void coral(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xaf7f00u;
}

inline
void coral(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xb0a37fff0000ul;
}

inline
void coral(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.5, 0.69, 0 });
}

inline
void coral(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.5, 0.69, 0 });
}

inline
void coral(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.5, 0.69, 0 });
}

}
}

namespace color {
namespace make {

inline
void crimson(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x28;
}

inline
void crimson(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x2ad0;
}

inline
void crimson(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x22b9e700u;
}

inline
void crimson(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x2322ba2de8b90000ul;
}

inline
void crimson(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.909091, 0.727273, 0.137255 });
}

inline
void crimson(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.909091, 0.727273, 0.137255 });
}

inline
void crimson(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.909091, 0.727273, 0.137255 });
}

}
}

namespace color {
namespace make {

inline
void gainsboro(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void gainsboro(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x2000;
}

inline
void gainsboro(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x23000000u;
}

inline
void gainsboro(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x23d6000000000000ul;
}

inline
void gainsboro(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0, 0, 0.14 });
}

inline
void gainsboro(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0, 0, 0.14 });
}

inline
void gainsboro(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0, 0, 0.14 });
}

}
}

namespace color {
namespace make {

inline
void gold(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x30;
}

inline
void gold(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xf20;
}

inline
void gold(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xff2800u;
}

inline
void gold(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff28280000ul;
}

inline
void gold(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.156863, 1, 0 });
}

inline
void gold(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.156863, 1, 0 });
}

inline
void gold(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.156863, 1, 0 });
}

}
}

namespace color {
namespace make {

inline
void indigo(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x4d;
}

inline
void indigo(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x70f6;
}

inline
void indigo(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x7d00ff6bu;
}

inline
void indigo(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x7d7d0000ffff6c4eul;
}

inline
void indigo(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0.423077, 1, 0, 0.490196 });
}

inline
void indigo(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0.423077, 1, 0, 0.490196 });
}

inline
void indigo(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0.423077, 1, 0, 0.490196 });
}

}
}

namespace color {
namespace make {

inline
void ivory(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void ivory(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void ivory(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xf0000u;
}

inline
void ivory(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xf0f00000000ul;
}

inline
void ivory(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0, 0.0588235, 0 });
}

inline
void ivory(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0, 0.0588235, 0 });
}

inline
void ivory(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0, 0.0588235, 0 });
}

}
}

namespace color {
namespace make {

inline
void khaki(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x10;
}

inline
void khaki(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x600;
}

inline
void khaki(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xf6a0a00u;
}

inline
void khaki(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xf0f6aaa0aaa0000ul;
}

inline
void khaki(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.0416667, 0.416667, 0.0588235 });
}

inline
void khaki(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.0416667, 0.416667, 0.0588235 });
}

inline
void khaki(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.0416667, 0.416667, 0.0588235 });
}

}
}

namespace color {
namespace make {

inline
void lavender(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void lavender(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x11;
}

inline
void lavender(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x5001414u;
}

inline
void lavender(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x5050000147a147aul;
}

inline
void lavender(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0.08, 0.08, 0, 0.0196078 });
}

inline
void lavender(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0.08, 0.08, 0, 0.0196078 });
}

inline
void lavender(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0.08, 0.08, 0, 0.0196078 });
}

}
}

namespace color {
namespace make {

inline
void linen(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void linen(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x100;
}

inline
void linen(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x5140a00u;
}

inline
void linen(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x505147a0a3d0000ul;
}

inline
void linen(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.04, 0.08, 0.0196078 });
}

inline
void linen(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.04, 0.08, 0.0196078 });
}

inline
void linen(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.04, 0.08, 0.0196078 });
}

}
}

namespace color {
namespace make {

inline
void moccasin(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void moccasin(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x410;
}

inline
void moccasin(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x491a00u;
}

inline
void moccasin(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x4a491b1a0000ul;
}

inline
void moccasin(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.105882, 0.290196, 0 });
}

inline
void moccasin(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.105882, 0.290196, 0 });
}

inline
void moccasin(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.105882, 0.290196, 0 });
}

}
}

namespace color {
namespace make {

inline
void orchid(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x4;
}

inline
void orchid(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x2070;
}

inline
void orchid(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x25047b00u;
}

inline
void orchid(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x252504b27c790000ul;
}

inline
void orchid(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.486239, 0.0183486, 0.145098 });
}

inline
void orchid(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.486239, 0.0183486, 0.145098 });
}

inline
void orchid(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.486239, 0.0183486, 0.145098 });
}

}
}

namespace color {
namespace make {

inline
void peru(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x24;
}

inline
void peru(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x2a50;
}

inline
void peru(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x31b05900u;
}

inline
void peru(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x3231b15259e90000ul;
}

inline
void peru(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.35122, 0.692683, 0.196078 });
}

inline
void peru(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.35122, 0.692683, 0.196078 });
}

inline
void peru(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.35122, 0.692683, 0.196078 });
}

}
}

namespace color {
namespace make {

inline
void pink(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x24;
}

inline
void pink(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x2a50;
}

inline
void pink(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x31b05900u;
}

inline
void pink(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x3231b15259e90000ul;
}

inline
void pink(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.351219, 0.692683, 0.196078 });
}

inline
void pink(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.351219, 0.692683, 0.196078 });
}

inline
void pink(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.351219, 0.692683, 0.196078 });
}

}
}

namespace color {
namespace make {

inline
void plum(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void plum(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x1040;
}

inline
void plum(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x21004600u;
}

inline
void plum(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x2221000046a80000ul;
}

inline
void plum(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.276018, 0, 0.133333 });
}

inline
void plum(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.276018, 0, 0.133333 });
}

inline
void plum(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.276018, 0, 0.133333 });
}

}
}

namespace color {
namespace make {

inline
void salmon(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void salmon(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x1040;
}

inline
void salmon(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x21004600u;
}

inline
void salmon(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x2221000046a80000ul;
}

inline
void salmon(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.276018, 0, 0.133333 });
}

inline
void salmon(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.276018, 0, 0.133333 });
}

inline
void salmon(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.276018, 0, 0.133333 });
}

}
}

namespace color {
namespace make {

inline
void sienna(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x64;
}

inline
void sienna(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x5a70;
}

inline
void sienna(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x5fb77c00u;
}

inline
void sienna(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x5f5fb7ff7ccc0000ul;
}

inline
void sienna(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.4875, 0.71875, 0.372549 });
}

inline
void sienna(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.4875, 0.71875, 0.372549 });
}

inline
void sienna(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.4875, 0.71875, 0.372549 });
}

}
}

namespace color {
namespace make {

inline
void snow(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void snow(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void snow(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x50500u;
}

inline
void snow(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x50505050000ul;
}

inline
void snow(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.0196078, 0.0196078, 0 });
}

inline
void snow(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.0196078, 0.0196078, 0 });
}

inline
void snow(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.0196078, 0.0196078, 0 });
}

}
}

namespace color {
namespace make {

inline
void tan(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void tan(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x2420;
}

inline
void tan(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x2d542400u;
}

inline
void tan(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x2d2d555424920000ul;
}

inline
void tan(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.142857, 0.333333, 0.176471 });
}

inline
void tan(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.142857, 0.333333, 0.176471 });
}

inline
void tan(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.142857, 0.333333, 0.176471 });
}

}
}

namespace color {
namespace make {

inline
void thistle(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void thistle(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x2010;
}

inline
void thistle(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x27001d00u;
}

inline
void thistle(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x272700001da10000ul;
}

inline
void thistle(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.115741, 0, 0.152941 });
}

inline
void thistle(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.115741, 0, 0.152941 });
}

inline
void thistle(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.115741, 0, 0.152941 });
}

}
}

namespace color {
namespace make {

inline
void tomato(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x24;
}

inline
void tomato(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0xa90;
}

inline
void tomato(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0xb89c00u;
}

inline
void tomato(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xb8b89c9c0000ul;
}

inline
void tomato(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.611765, 0.721569, 0 });
}

inline
void tomato(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.611765, 0.721569, 0 });
}

inline
void tomato(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.611765, 0.721569, 0 });
}

}
}

namespace color {
namespace make {

inline
void turquoise(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x2;
}

inline
void turquoise(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x110a;
}

inline
void turquoise(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x1f1200b6u;
}

inline
void turquoise(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0x1f1f12490000b6daul;
}

inline
void turquoise(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0.714286, 0, 0.0714286, 0.121569 });
}

inline
void turquoise(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0.714286, 0, 0.0714286, 0.121569 });
}

inline
void turquoise(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0.714286, 0, 0.0714286, 0.121569 });
}

}
}

namespace color {
namespace make {

inline
void wheat(::color::_internal::model< color::category::cmyk_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void wheat(::color::_internal::model< color::category::cmyk_uint16 > & color_parameter) {
	color_parameter.container() = 0x410;
}

inline
void wheat(::color::_internal::model< color::category::cmyk_uint32 > & color_parameter) {
	color_parameter.container() = 0x9441700u;
}

inline
void wheat(::color::_internal::model< color::category::cmyk_uint64 > & color_parameter) {
	color_parameter.container() = 0xa0944f618080000ul;
}

inline
void wheat(::color::_internal::model< color::category::cmyk_float > & color_parameter) {
	color_parameter.container() = std::array<float,4>({ 0, 0.0938776, 0.269388, 0.0392157 });
}

inline
void wheat(::color::_internal::model< color::category::cmyk_double> & color_parameter) {
	color_parameter.container() = std::array<double,4>({ 0, 0.0938776, 0.269388, 0.0392157 });
}

inline
void wheat(::color::_internal::model< color::category::cmyk_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,4>({ 0, 0.0938776, 0.269388, 0.0392157 });
}

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename cmy_tag_name >
struct convert
		<
		::color::category::cmyk< cmyk_tag_name >
		,::color::category::cmy< cmy_tag_name >
		> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar< category_left_type > scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type cc = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type cm = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type cy = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type k = std::min({ cc, cm, cy });
		scalar_type c = scalar_type(0);
		scalar_type m = scalar_type(0);
		scalar_type y = scalar_type(0);
		if(false == scalar_trait_type::is_small(1 - k)) {
			c = (cc-k) / (1-k);
			m = (cm-k) / (1-k);
			y = (cy-k) / (1-k);
		}
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(c));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(m));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(y));
		container_left_trait_type::template set<3>(left, diverse_type::template process<3>(k));
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
		<
		::color::category::cmyk< tag_left_name >
		,::color::category::cmyk< tag_right_name>
		> {
public:
	typedef ::color::category::cmyk< tag_left_name > category_left_type;
	typedef ::color::category::cmyk< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename gray_tag_name >
struct convert
		<
		::color::category::cmyk< cmyk_tag_name >
		,::color::category::gray< gray_tag_name >
		> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::operation::_internal::invert< category_right_type > invert_type;
	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, bound_left_trait_type::template minimum<0>());
		container_left_trait_type::template set<1>(left, bound_left_trait_type::template minimum<1>());
		container_left_trait_type::template set<2>(left, bound_left_trait_type::template minimum<2>());
		container_left_trait_type::template set<3>(left, reformat_type::template process<3,0>(invert_type::template component<0>(container_right_trait_type::template get<0>(right))));
	}
};

}
}

namespace color {
namespace type {

typedef std::array< std::uint8_t, 3 > uint24_t;

}
}

namespace color {
namespace type {

typedef std::array< std::uint8_t, 6 > uint48_t, uint48c_t;

typedef std::array< std::uint16_t, 3 > uint48s_t;

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::hsl_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::hsl_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::hsl_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::hsl_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::hsl_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::hsl_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::hsl_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::hsv_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::hsv_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::hsv_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::hsv_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::hsv_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::hsv_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::hsv_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::rgb_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::rgb_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::rgb_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::rgb_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::rgb_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::rgb_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::rgb_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::yiq_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::yiq_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::yiq_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::yiq_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::yiq_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::yiq_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::yiq_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct rgb< ::color::category::yuv_uint8 > {
	typedef ::color::category::rgb_uint8 akin_type;
};
template< >struct rgb< ::color::category::yuv_uint16 > {
	typedef ::color::category::rgb_uint16 akin_type;
};
template< >struct rgb< ::color::category::yuv_uint32 > {
	typedef ::color::category::rgb_uint32 akin_type;
};
template< >struct rgb< ::color::category::yuv_uint64 > {
	typedef ::color::category::rgb_uint64 akin_type;
};
template< >struct rgb< ::color::category::yuv_float > {
	typedef ::color::category::rgb_float akin_type;
};
template< >struct rgb< ::color::category::yuv_double > {
	typedef ::color::category::rgb_double akin_type;
};
template< >struct rgb< ::color::category::yuv_ldouble > {
	typedef ::color::category::rgb_ldouble akin_type;
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_double >
		: public ::color::_internal::utility::bound::general< double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_float >
		: public ::color::_internal::utility::bound::general< float, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_ldouble >
		: public ::color::_internal::utility::bound::general< long double, unsigned > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name >
struct bound655 {
public:
	typedef std::uint16_t unsigned_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitP< unsigned_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 63, 31, 31 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 63, 31, 31 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type value=0;
		return value;
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type value=0;
		return value;
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type max_list[] = { 63, 31, 31 };
		return max_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type max_list[] = { 63, 31, 31 };
		return max_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_uint16 >
		: public ::color::_internal::utility::bound::bound655< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_uint32 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 8, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_uint64 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 16, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_uint8 >
		: public ::color::_internal::utility::bound::bound332< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_uint24 >
		: public ::color::_internal::utility::bound::general< std::uint8_t, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::rgb_uint48 >
		: public ::color::_internal::utility::bound::general< std::uint16_t, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_double >
		: public ::color::_internal::utility::container::array< double, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_float >
		: public ::color::_internal::utility::container::array< float, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_ldouble >
		: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace container {

template< typename index_name >
struct cner655 {
public:

	typedef index_name index_type;

	typedef std::uint8_t value_type;
	typedef std::uint16_t instance_type;

	typedef instance_type const const_type;
	typedef instance_type const& return_image_type;
	typedef instance_type & return_type;
	typedef instance_type const& input_const_type;
	typedef instance_type & input_type;
	typedef instance_type & output_type;

	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;
	typedef typename index_trait_type::return_image_type index_return_image_type;

	typedef ::color::_internal::utility::type::traitP< value_type > component_trait_type;

	typedef typename component_trait_type::const_type component_const_type;
	typedef typename component_trait_type::instance_type component_type;
	typedef typename component_trait_type::return_image_type component_return_const_type;
	typedef typename component_trait_type::input_const_type component_input_const_type;

	typedef void set_return_type;

	static component_return_const_type get(input_const_type container, index_input_const_type index) {
		switch(index) {
		case(0):
			return ((container >> 0) & 63);
		case(1):
			return ((container >> 5) & 31);
		case(2):
			return ((container >> 10) & 31);
		}
		return 0;
	}

	template< index_instance_type index >
	static component_return_const_type get(input_const_type container) {
		switch(index) {
		case(0):
			return ((container >> 0) & 63);
		case(1):
			return ((container >> 5) & 31);
		case(2):
			return ((container >> 10) & 31);
		}
		return 0;
	}

	static set_return_type set(input_type container, index_input_const_type index, component_input_const_type value) {
		switch(index) {
		case(0) :
			container = (container & ~(63 << (0))) | (((instance_type)value) << (0));
			break;
		case(1) :
			container = (container & ~(31 << (6))) | (((instance_type)value) << (6));
			break;
		case(2) :
			container = (container & ~(31 << (11))) | (((instance_type)value) << (11));
			break;
		}
	}

	template< index_instance_type index >
	static set_return_type set(input_type container, component_input_const_type value) {
		switch(index) {
		case(0) :
			container = (container & ~(63 << (0))) | (((instance_type)value) << (0));
			break;
		case(1) :
			container = (container & ~(31 << (6))) | (((instance_type)value) << (6));
			break;
		case(2) :
			container = (container & ~(31 << (11))) | (((instance_type)value) << (11));
			break;
		}
	}

	static index_return_image_type size() {
		static const index_instance_type local_length = 3;
		return local_length;
	}
};
}
}
}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_uint16 >
		: public ::color::_internal::utility::container::cner655< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_uint32 >
		: public ::color::_internal::utility::container::Unsigned< std::uint32_t, std::uint8_t, unsigned, 3, 8 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_uint64 >
		: public ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint16_t, unsigned, 3, 16 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_uint8 >
		: public ::color::_internal::utility::container::cner332< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_uint24 >
		: public ::color::_internal::utility::container::array< std::uint8_t, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::rgb_uint48 >
		: public ::color::_internal::utility::container::array< std::uint16_t, 3 > {
};

}
}
namespace color {
namespace trait {

template< typename value_name, unsigned first_position, unsigned second_position, unsigned third_position >
struct container< ::color::category::rgb< ::color::category::rgb_scramble< value_name, first_position, second_position, third_position > > >
		: public ::color::_internal::utility::container::array< value_name, 3 > {
};

}
}
namespace color {
namespace trait {

template< typename value_name, unsigned first_position, unsigned second_position, unsigned third_position, unsigned fourth_position >
struct container< ::color::category::rgb< ::color::category::rgba_scramble< value_name, first_position, second_position, third_position,fourth_position > > >
		: public ::color::_internal::utility::container::array< value_name, 4 > {
};

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::_internal::model< ::color::category::rgb< tag_name> >::component_const_type
red(::color::_internal::model< ::color::category::rgb<tag_name> > const& color_parameter) {
	typedef ::color::category::rgb< tag_name> category_type;
	enum { red_p = ::color::place::_internal::red<category_type>::position_enum };
	return color_parameter.template get<red_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::_internal::model< ::color::category::rgb< tag_name> >::component_const_type
green(::color::_internal::model< ::color::category::rgb< tag_name> > const& color_parameter) {
	typedef ::color::category::rgb< tag_name> category_type;
	enum { green_p = ::color::place::_internal::green<category_type>::position_enum };
	return color_parameter.template get<green_p>();
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::_internal::model< ::color::category::rgb< tag_name> >::component_const_type
blue(::color::_internal::model< ::color::category::rgb< tag_name> > const& color_parameter) {
	typedef ::color::category::rgb< tag_name> category_type;
	enum { blue_p = ::color::place::_internal::blue<category_type>::position_enum };
	return color_parameter.template get<blue_p>();
}

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::rgb_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::rgb_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::rgb_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::rgb_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::rgb_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::rgb_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::rgb_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::_internal::model< typename ::color::akin::yiq< ::color::category::rgb<tag_name> >::akin_type >::component_const_type
inphase(::color::_internal::model< ::color::category::rgb<tag_name> > const& color_parameter) {
	typedef ::color::category::rgb<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::yiq<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::yiq< akin_type > yiq_const_type;
	scalar_type value =
		+ yiq_const_type::b21() * normalize_type::template process<0>(color_parameter.template get<0>())
	+ yiq_const_type::b22() * normalize_type::template process<1>(color_parameter.template get<1>())
	+ yiq_const_type::b23() * normalize_type::template process<2>(color_parameter.template get<2>())
	;
	value = value / yiq_const_type::i_range() + scalar_type(0.5);
	return diverse_type::template process<1>(value);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::_internal::model< typename ::color::akin::yiq< ::color::category::rgb<tag_name> >::akin_type >::component_const_type
quadrature(::color::_internal::model< ::color::category::rgb<tag_name> > const& color_parameter) {
	typedef ::color::category::rgb<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::yiq<category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::yiq< akin_type > yiq_const_type;
	scalar_type value =
		+ yiq_const_type::b31() * normalize_type::template process<0>(color_parameter.template get<0>())
	+ yiq_const_type::b32() * normalize_type::template process<1>(color_parameter.template get<1>())
	+ yiq_const_type::b33() * normalize_type::template process<2>(color_parameter.template get<2>())
	;
	value = value / yiq_const_type::q_range() + scalar_type(0.5);
	return diverse_type::template process<2>(value);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::rgb<tag_name> >::akin_type >::return_type
gray(::color::_internal::model< ::color::category::rgb<tag_name> > const& color_parameter) {
	typedef ::color::category::rgb< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	typedef ::color::constant::gray< akin_type > gray_const_type;
	scalar_type value =
		gray_const_type::Rc() * normalize_type::template process<0>(color_parameter.template get<0>())
	+ gray_const_type::Gc() * normalize_type::template process<1>(color_parameter.template get<1>())
	+ gray_const_type::Bc() * normalize_type::template process<2>(color_parameter.template get<2>())
	;
	return diverse_type::template process<0>(value);
}

}
}

namespace color {
namespace set {
template< typename tag_name >
inline
void
red
(
	::color::_internal::model< ::color::category::rgb<tag_name> > & color_parameter,
	typename ::color::_internal::model< ::color::category::rgb<tag_name> >::component_input_const_type component_parameter
) {
	typedef ::color::category::rgb<tag_name> category_type;
	enum { red_p = ::color::place::_internal::red<category_type>::position_enum };
	color_parameter.template set<red_p>(component_parameter);
}

}
}

namespace color {
namespace set {
template< typename tag_name >
inline
void
green
(
	::color::_internal::model< ::color::category::rgb<tag_name> > & color_parameter,
	typename ::color::_internal::model< ::color::category::rgb<tag_name> >::component_input_const_type component_parameter
) {
	typedef ::color::category::rgb<tag_name> category_type;
	enum { green_p = ::color::place::_internal::green<category_type>::position_enum };
	color_parameter.template set<green_p>(component_parameter);
}

}
}

namespace color {
namespace set {
template< typename tag_name >
inline
void
blue
(
	::color::_internal::model< ::color::category::rgb<tag_name> > & color_parameter,
	typename ::color::_internal::model< ::color::category::rgb<tag_name> >::component_input_const_type component_parameter
) {
	typedef ::color::category::rgb<tag_name> category_type;
	enum { blue_p = ::color::place::_internal::blue<category_type>::position_enum };
	color_parameter.template set<blue_p>(component_parameter);
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::_internal::model< ::color::category::rgb<tag_name> > & color_parameter
	,typename ::color::trait::component< typename ::color::akin::gray<::color::category::rgb<tag_name> >::akin_type >::input_const_type component_parameter
) {
	typedef ::color::category::rgb<tag_name> category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray<category_type >::akin_type akin_type;
	typedef ::color::_internal::normalize< category_type > normalize_rgb_type;
	typedef ::color::_internal::normalize< akin_type > normalize_akin_type;
	typedef ::color::constant::gray< akin_type > gray_const_type;
	scalar_type value =
		gray_const_type::Rc() * normalize_rgb_type::template process<0>(color_parameter.template get<0>())
	+ gray_const_type::Gc() * normalize_rgb_type::template process<1>(color_parameter.template get<1>())
	+ gray_const_type::Bc() * normalize_rgb_type::template process<2>(color_parameter.template get<2>());
	value = normalize_akin_type::template process<0>(component_parameter) / value;
	::color::operation::scale(color_parameter, value);
}

}
}

namespace color {
namespace make {

inline
void black(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void black(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void black(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff000000u;
}

inline
void black(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff000000000000ul;
}

inline
void black(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void gray50(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x5b;
}

inline
void gray50(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x7bdf;
}

inline
void gray50(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff808080;
}

inline
void gray50(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0xffff800080008000u);
}

inline
void gray50(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 0.5, 0.5 });
}

inline
void gray50(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 0.5, 0.5 });
}

inline
void gray50(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 0.5, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void white(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xff;
}

inline
void white(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xffff;
}

inline
void white(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffffffu;
}

inline
void white(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffffffffffffffful;
}

inline
void white(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 1, 1 });
}

inline
void white(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 1, 1 });
}

inline
void white(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 1, 1 });
}

}
}

namespace color {
namespace make {

inline
void red(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x7;
}

inline
void red(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x3f;
}

inline
void red(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff0000ffu;
}

inline
void red(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff00000000fffful;
}

inline
void red(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0, 0 });
}

inline
void red(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0, 0 });
}

inline
void red(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void green(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x18;
}

inline
void green(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x3c0;
}

inline
void green(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff007f00u;
}

inline
void green(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff00007fff0000ul;
}

inline
void green(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0.5, 0 });
}

inline
void green(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0.5, 0 });
}

inline
void green(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0.5, 0 });
}

}
}

namespace color {
namespace make {

inline
void blue(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 3 << 6;
}

inline
void blue(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xf800;
}

inline
void blue(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff0000u;
}

inline
void blue(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff00000000ul;
}

inline
void blue(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 1 });
}

inline
void blue(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 1 });
}

inline
void blue(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 1 });
}

}
}

namespace color {
namespace make {

inline
void cyan(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = (3 << 6) + (7 << 3);
}

inline
void cyan(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xffc0;
}

inline
void cyan(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff00u;
}

inline
void cyan(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0xffffFFFFFFFF0000u);
}

inline
void cyan(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 1, 1 });
}

inline
void cyan(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 1, 1 });
}

inline
void cyan(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 1, 1 });
}

}
}

namespace color {
namespace make {

inline
void magenta(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xc7;
}

inline
void magenta(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xfc1f;
}

inline
void magenta(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffFF00FF;
}

inline
void magenta(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0xffffFFFF0000FFFFu);
}

inline
void magenta(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0, 1 });
}

inline
void magenta(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0, 1 });
}

inline
void magenta(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0, 1 });
}

}
}

namespace color {
namespace make {

inline
void yellow(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x3f;
}

inline
void yellow(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x7ff;
}

inline
void yellow(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00ffffu;
}

inline
void yellow(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000fffffffful;
}

inline
void yellow(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 1, 0 });
}

inline
void yellow(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 1, 0 });
}

inline
void yellow(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 1, 0 });
}

}
}

namespace color {
namespace make {

inline
void aqua(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = (3 << 6) + (7 << 3);
}

inline
void aqua(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xffc0;
}

inline
void aqua(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffFFFF00;
}

inline
void aqua(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0xffffFFFFFFFF0000u);
}

inline
void aqua(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 1, 1 });
}

inline
void aqua(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 1, 1 });
}

inline
void aqua(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 1, 1 });
}

}
}

namespace color {
namespace make {

inline
void fuchsia(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xc7;
}

inline
void fuchsia(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xf83f;
}

inline
void fuchsia(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff00ffu;
}

inline
void fuchsia(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff0000fffful;
}

inline
void fuchsia(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0, 1 });
}

inline
void fuchsia(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0, 1 });
}

inline
void fuchsia(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0, 1 });
}

}
}

namespace color {
namespace make {

inline
void lime(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x38;
}

inline
void lime(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x7c0;
}

inline
void lime(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00ff00u;
}

inline
void lime(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000ffff0000ul;
}

inline
void lime(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 1, 0 });
}

inline
void lime(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 1, 0 });
}

inline
void lime(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 1, 0 });
}

}
}

namespace color {
namespace make {

inline
void maroon(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x3;
}

inline
void maroon(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xf;
}

inline
void maroon(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff000080;
}

inline
void maroon(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff000000007ffful;
}

inline
void maroon(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 0, 0 });
}

inline
void maroon(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 0, 0 });
}

inline
void maroon(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void navy(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x40;
}

inline
void navy(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x7800;
}

inline
void navy(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff800000;
}

inline
void navy(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff00000000ul;
}

inline
void navy(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 0.5 });
}

inline
void navy(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 0.5 });
}

inline
void navy(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void olive(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x1b;
}

inline
void olive(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x3df;
}

inline
void olive(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff008080;
}

inline
void olive(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff00007fff7ffful;
}

inline
void olive(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 0.5, 0 });
}

inline
void olive(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 0.5, 0 });
}

inline
void olive(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 0.5, 0 });
}

}
}

namespace color {
namespace make {

inline
void orange(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x27;
}

inline
void orange(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x53f;
}

inline
void orange(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00a5ffu;
}

inline
void orange(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000a665fffful;
}

inline
void orange(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0.65, 0 });
}

inline
void orange(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0.65, 0 });
}

inline
void orange(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0.65, 0 });
}

}
}

namespace color {
namespace make {

inline
void purple(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x43;
}

inline
void purple(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x781f;
}

inline
void purple(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff800080;
}

inline
void purple(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff00007ffful;
}

inline
void purple(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 0, 0.5 });
}

inline
void purple(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 0, 0.5 });
}

inline
void purple(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 0, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void silver(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xad;
}

inline
void silver(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xbdef;
}

inline
void silver(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffbfbfbfu;
}

inline
void silver(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffbfffbfffbffful;
}

inline
void silver(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.75, 0.75, 0.75 });
}

inline
void silver(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.75, 0.75, 0.75 });
}

inline
void silver(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.75, 0.75, 0.75 });
}

}
}

namespace color {
namespace make {

inline
void teal(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x58;
}

inline
void teal(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x7bc0;
}

inline
void teal(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff808000;
}

inline
void teal(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7fff0000ul;
}

inline
void teal(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0.5, 0.5 });
}

inline
void teal(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0.5, 0.5 });
}

inline
void teal(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0.5, 0.5 });
}

}
}

namespace color {
namespace make {

inline
void violet(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x9e;
}

inline
void violet(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xe3fa;
}

inline
void violet(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffee82eeu;
}

inline
void violet(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = std::uint64_t(0xffffeeee8282eeeeul);
}

inline
void violet(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 238/255.0, 130/255.0, 238/255.0 });
}

inline
void violet(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 238/255.0, 130/255.0, 238/255.0 });
}

inline
void violet(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 238/255.0, 130/255.0, 238/255.0 });
}

}
}

namespace color {
namespace make {

inline
void aquamarine(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xbb;
}

inline
void aquamarine(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xcfdf;
}

inline
void aquamarine(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd4ff7fu;
}

inline
void aquamarine(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd4d4ffff7ffful;
}

inline
void aquamarine(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 1, 212.0/255.0 });
}

inline
void aquamarine(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 1, 212.0/255.0 });
}

inline
void aquamarine(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 1, 212.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void azure(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xfe;
}

inline
void azure(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xfffb;
}

inline
void azure(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xfffffff0u;
}

inline
void azure(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffffffffffff0f0ul;
}

inline
void azure(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 240.0/255.0, 1, 1 });
}

inline
void azure(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 240.0/255.0, 1, 1 });
}

inline
void azure(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 240.0/255.0, 1, 1 });
}

}
}

namespace color {
namespace make {

inline
void beige(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xb6;
}

inline
void beige(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xd77c;
}

inline
void beige(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffdcf5f5u;
}

inline
void beige(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdcdcf5f5f5f5ul;
}

inline
void beige(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 245.0/255.0, 245.0/255.0, 220.0/255.0 });
}

inline
void beige(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 245.0/255.0, 245.0/255.0, 220.0/255.0 });
}

inline
void beige(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 245.0/255.0, 245.0/255.0, 220.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void bisque(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xb7;
}

inline
void bisque(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xbeff;
}

inline
void bisque(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffc4e4ffu;
}

inline
void bisque(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffc4c4e4e4fffful;
}

inline
void bisque(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 255.0/255.0, 228.0/255.0, 196.0/255.0 });
}

inline
void bisque(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 255.0/255.0, 228.0/255.0, 196.0/255.0 });
}

inline
void bisque(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 255.0/255.0, 228.0/255.0, 196.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void brown(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xc;
}

inline
void brown(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x2968;
}

inline
void brown(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff2a2aa5u;
}

inline
void brown(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff2a2a2a2aa5a5ul;
}

inline
void brown(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 165.0/255.0, 42.0/255.0, 42.0/255.0 });
}

inline
void brown(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 165.0/255.0, 42.0/255.0, 42.0/255.0 });
}

inline
void brown(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 165.0/255.0, 42.0/255.0, 42.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void chocolate(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x15;
}

inline
void chocolate(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x1b33;
}

inline
void chocolate(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff1e69d2u;
}

inline
void chocolate(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff1e1e6969d2d2ul;
}

inline
void chocolate(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 210.0/255.0, 105.0/255.0, 30.0/255.0 });
}

inline
void chocolate(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 210.0/255.0, 105.0/255.0, 30.0/255.0 });
}

inline
void chocolate(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 210.0/255.0, 105.0/255.0, 30.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void coral(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x1f;
}

inline
void coral(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x4bff;
}

inline
void coral(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff4f7fffu;
}

inline
void coral(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff4f5b7ffffffful;
}

inline
void coral(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0.5, 0.31 });
}

inline
void coral(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0.5, 0.31 });
}

inline
void coral(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0.5, 0.31 });
}

}
}

namespace color {
namespace make {

inline
void crimson(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x6;
}

inline
void crimson(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x38b6;
}

inline
void crimson(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3c14dcu;
}

inline
void crimson(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3c3c1414dcdcul;
}

inline
void crimson(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 220.0/255.0, 20.0/255.0, 60.0/255.0 });
}

inline
void crimson(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 220.0/255.0, 20.0/255.0, 60.0/255.0 });
}

inline
void crimson(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 220.0/255.0, 20.0/255.0, 60.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void gainsboro(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xb6;
}

inline
void gainsboro(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xd6b6;
}

inline
void gainsboro(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffdbdbdbu;
}

inline
void gainsboro(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdc28dc28dc28ul;
}

inline
void gainsboro(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.86, 0.86, 0.86 });
}

inline
void gainsboro(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.86, 0.86, 0.86 });
}

inline
void gainsboro(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.86, 0.86, 0.86 });
}

}
}

namespace color {
namespace make {

inline
void gold(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x2f;
}

inline
void gold(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x6bf;
}

inline
void gold(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00d7ffu;
}

inline
void gold(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000d7d7fffful;
}

inline
void gold(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 255.0/255.0, 215.0/255.0, 0.0/255.0 });
}

inline
void gold(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 255.0/255.0, 215.0/255.0, 0.0/255.0 });
}

inline
void gold(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 255.0/255.0, 215.0/255.0, 0.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void indigo(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x42;
}

inline
void indigo(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x7812;
}

inline
void indigo(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff82004bu;
}

inline
void indigo(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff828200004b4bul;
}

inline
void indigo(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 75.0/255.0, 0.0/255.0, 130.0/255.0 });
}

inline
void indigo(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 75.0/255.0, 0.0/255.0, 130.0/255.0 });
}

inline
void indigo(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 75.0/255.0, 0.0/255.0, 130.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void ivory(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xbf;
}

inline
void ivory(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xefff;
}

inline
void ivory(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xfff0ffffu;
}

inline
void ivory(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffff0f0fffffffful;
}

inline
void ivory(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 1, 240.0/255.0 });
}

inline
void ivory(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 1, 240.0/255.0 });
}

inline
void ivory(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 1, 240.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void khaki(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x76;
}

inline
void khaki(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x8efb;
}

inline
void khaki(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff8ce6f0u;
}

inline
void khaki(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff8c8ce6e6f0f0ul;
}

inline
void khaki(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 240.0/255.0, 230.0/255.0, 140.0/255.0 });
}

inline
void khaki(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 240.0/255.0, 230.0/255.0, 140.0/255.0 });
}

inline
void khaki(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 240.0/255.0, 230.0/255.0, 140.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void lavender(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xb6;
}

inline
void lavender(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xf6f8;
}

inline
void lavender(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xfffae6e6u;
}

inline
void lavender(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffffafae6e6e6e6ul;
}

inline
void lavender(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 230.0/255.0, 230.0/255.0, 250.0/255.0 });
}

inline
void lavender(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 230.0/255.0, 230.0/255.0, 250.0/255.0 });
}

inline
void lavender(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 230.0/255.0, 230.0/255.0, 250.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void linen(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xb6;
}

inline
void linen(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xdf7d;
}

inline
void linen(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffe6f0fau;
}

inline
void linen(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffe6e6f0f0fafaul;
}

inline
void linen(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 250.0/255.0, 240.0/255.0, 230.0/255.0 });
}

inline
void linen(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 250.0/255.0, 240.0/255.0, 230.0/255.0 });
}

inline
void linen(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 250.0/255.0, 240.0/255.0, 230.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void moccasin(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xb7;
}

inline
void moccasin(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xb37f;
}

inline
void moccasin(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffb5e4ffu;
}

inline
void moccasin(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffb5b5e4e4fffful;
}

inline
void moccasin(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 255.0/255.0, 228.0/255.0, 181.0/255.0 });
}

inline
void moccasin(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 255.0/255.0, 228.0/255.0, 181.0/255.0 });
}

inline
void moccasin(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 255.0/255.0, 228.0/255.0, 181.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void orchid(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x9d;
}

inline
void orchid(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xd375;
}

inline
void orchid(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd670dau;
}

inline
void orchid(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd6d67070dadaul;
}

inline
void orchid(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 218.0/255.0, 112.0/255.0, 214.0/255.0 });
}

inline
void orchid(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 218.0/255.0, 112.0/255.0, 214.0/255.0 });
}

inline
void orchid(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 218.0/255.0, 112.0/255.0, 214.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void peru(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x1d;
}

inline
void peru(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x3c32;
}

inline
void peru(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3f85cdu;
}

inline
void peru(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3f3f8585cdcdul;
}

inline
void peru(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 205.0/255.0, 133.0/255.0, 63.0/255.0 });
}

inline
void peru(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 205.0/255.0, 133.0/255.0, 63.0/255.0 });
}

inline
void peru(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 205.0/255.0, 133.0/255.0, 63.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void pink(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x1d;
}

inline
void pink(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x3c32;
}

inline
void pink(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3f85cdu;
}

inline
void pink(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3f3f8585cdcdul;
}

inline
void pink(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.803922, 0.521569, 0.247059 });
}

inline
void pink(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.803922, 0.521569, 0.247059 });
}

inline
void pink(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.803922, 0.521569, 0.247059 });
}

}
}

namespace color {
namespace make {

inline
void plum(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xa6;
}

inline
void plum(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xd4f6;
}

inline
void plum(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffdda0ddu;
}

inline
void plum(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdddda0a0ddddul;
}

inline
void plum(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 221.0/255.0, 160.0/255.0, 221.0/255.0 });
}

inline
void plum(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 221.0/255.0, 160.0/255.0, 221.0/255.0 });
}

inline
void plum(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 221.0/255.0, 160.0/255.0, 221.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void salmon(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xa6;
}

inline
void salmon(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xd4f6;
}

inline
void salmon(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffdda0ddu;
}

inline
void salmon(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdddda0a0ddddul;
}

inline
void salmon(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.866667, 0.627451, 0.866667 });
}

inline
void salmon(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.866667, 0.627451, 0.866667 });
}

inline
void salmon(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.866667, 0.627451, 0.866667 });
}

}
}

namespace color {
namespace make {

inline
void sienna(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x14;
}

inline
void sienna(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x2a67;
}

inline
void sienna(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff2d52a0u;
}

inline
void sienna(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff2d2d5252a0a0ul;
}

inline
void sienna(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 160.0/255.0, 82.0/255.0, 45.0/255.0 });
}

inline
void sienna(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 160.0/255.0, 82.0/255.0, 45.0/255.0 });
}

inline
void sienna(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 160.0/255.0, 82.0/255.0, 45.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void snow(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xb7;
}

inline
void snow(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xf7bf;
}

inline
void snow(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xfffafaffu;
}

inline
void snow(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffffafafafafffful;
}

inline
void snow(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 255.0/255.0, 250.0/255.0, 250.0/255.0 });
}

inline
void snow(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 255.0/255.0, 250.0/255.0, 250.0/255.0 });
}

inline
void snow(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 255.0/255.0, 250.0/255.0, 250.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void tan(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x65;
}

inline
void tan(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x8d73;
}

inline
void tan(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff8cb4d2u;
}

inline
void tan(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff8c8cb4b4d2d2ul;
}

inline
void tan(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 210.0/255.0, 180.0/255.0, 140.0/255.0 });
}

inline
void tan(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 210.0/255.0, 180.0/255.0, 140.0/255.0 });
}

inline
void tan(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 210.0/255.0, 180.0/255.0, 140.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void thistle(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xad;
}

inline
void thistle(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xd5f5;
}

inline
void thistle(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd8bfd8u;
}

inline
void thistle(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd8d8bfbfd8d8ul;
}

inline
void thistle(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 216.0/255.0, 191.0/255.0, 216.0/255.0 });
}

inline
void thistle(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 216.0/255.0, 191.0/255.0, 216.0/255.0 });
}

inline
void thistle(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 216.0/255.0, 191.0/255.0, 216.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void tomato(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0x17;
}

inline
void tomato(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0x433f;
}

inline
void tomato(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xff4763ffu;
}

inline
void tomato(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff47476363fffful;
}

inline
void tomato(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 255.0/255, 99.0/255, 71.0/255.0 });
}

inline
void tomato(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 255.0/255, 99.0/255, 71.0/255.0 });
}

inline
void tomato(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 255.0/255, 99.0/255, 71.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void turquoise(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xb1;
}

inline
void turquoise(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xcecf;
}

inline
void turquoise(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd0e040u;
}

inline
void turquoise(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd0d0e0e04040ul;
}

inline
void turquoise(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 64.0/255.0, 224.0/255.0, 208.0/255.0 });
}

inline
void turquoise(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 64.0/255.0, 224.0/255.0, 208.0/255.0 });
}

inline
void turquoise(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 64.0/255.0, 224.0/255.0, 208.0/255.0 });
}

}
}

namespace color {
namespace make {

inline
void wheat(::color::_internal::model< color::category::rgb_uint8 > & color_parameter) {
	color_parameter.container() = 0xb6;
}

inline
void wheat(::color::_internal::model< color::category::rgb_uint16 > & color_parameter) {
	color_parameter.container() = 0xaebc;
}

inline
void wheat(::color::_internal::model< color::category::rgb_uint32 > & color_parameter) {
	color_parameter.container() = 0xffb3def5u;
}

inline
void wheat(::color::_internal::model< color::category::rgb_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffb3b3dedef5f5ul;
}

inline
void wheat(::color::_internal::model< color::category::rgb_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 245.0/255.0, 222.0/255.0, 179.0/255.0 });
}

inline
void wheat(::color::_internal::model< color::category::rgb_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 245.0/255.0, 222.0/255.0, 179.0/255.0 });
}

inline
void wheat(::color::_internal::model< color::category::rgb_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 245.0/255.0, 222.0/255.0, 179.0/255.0 });
}

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename cmy_tag_name >
struct convert
		<
		::color::category::rgb< rgb_tag_name >
		,::color::category::cmy< cmy_tag_name >
		> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_left_type>::position_enum
					,green_p = ::color::place::_internal::green<category_left_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
		};
		typedef ::color::_internal::reformat< category_left_type, category_right_type, double > reformat_type;
		typedef ::color::operation::_internal::invert< category_right_type > invert_type;
		container_left_trait_type::template set<red_p >(left, reformat_type::template process<red_p ,0>(invert_type::template component<0>(container_right_trait_type::template get<0>(right))));
		container_left_trait_type::template set<green_p>(left, reformat_type::template process<green_p,1>(invert_type::template component<1>(container_right_trait_type::template get<1>(right))));
		container_left_trait_type::template set<blue_p >(left, reformat_type::template process<blue_p ,2>(invert_type::template component<2>(container_right_trait_type::template get<2>(right))));
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename cmyk_tag_name >
struct convert
		<
		::color::category::rgb< rgb_tag_name >
		,::color::category::cmyk<cmyk_tag_name>
		> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::cmyk<cmyk_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_left_type>::position_enum
					,green_p = ::color::place::_internal::green<category_left_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
		};
		enum {
			cyan_p = 0
					 ,yellow_p = 1
								 ,magenta_p = 2
											  ,key_p = 3
		};
		scalar_type c = normalize_type::template process<cyan_p >(container_right_trait_type::template get<cyan_p >(right));
		scalar_type m = normalize_type::template process<yellow_p >(container_right_trait_type::template get<yellow_p >(right));
		scalar_type y = normalize_type::template process<magenta_p>(container_right_trait_type::template get<magenta_p>(right));
		scalar_type k = normalize_type::template process<key_p >(container_right_trait_type::template get<key_p >(right));
		scalar_type r = (1-c) * (1-k);
		scalar_type g = (1-m) * (1-k);
		scalar_type b = (1-y) * (1-k);
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename gray_tag_name >
struct convert
		<
		::color::category::rgb< rgb_tag_name >
		,::color::category::gray<gray_tag_name>
		> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::gray<gray_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_left_type>::position_enum
					,green_p = ::color::place::_internal::green<category_left_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
		};
		enum {
			gray_p = 0
		};
		container_left_trait_type::template set<red_p >(left, reformat_type::template process<red_p ,gray_p>(container_right_trait_type::template get<gray_p>(right)));
		container_left_trait_type::template set<green_p>(left, reformat_type::template process<green_p,gray_p>(container_right_trait_type::template get<gray_p>(right)));
		container_left_trait_type::template set<blue_p >(left, reformat_type::template process<blue_p ,gray_p>(container_right_trait_type::template get<gray_p>(right)));
	}
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct hue {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -7 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
hue() {
	return ::color::place::_internal::hue<category_name>::position();
}

}
}

namespace color {
namespace trait {

template< >
struct index< ::color::category::hsl_double >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsl_float >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsl_ldouble >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsl_uint16 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsl_uint32 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsl_uint64 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsl_uint8 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct hue< ::color::category::hsl< tag_name > > {
public:
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct lightness {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -4 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
lightness() {
	return ::color::place::_internal::lightness<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct lightness< ::color::category::hsl< tag_name > > {
public:
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct saturation {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -4 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
saturation() {
	return ::color::place::_internal::saturation<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct saturation< ::color::category::hsl< tag_name > > {
public:
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::cmy_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::cmy_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::cmy_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::cmy_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::cmy_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::cmy_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::cmy_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::cmyk_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::cmyk_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::cmyk_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::cmyk_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::cmyk_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::cmyk_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::cmyk_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::gray_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::gray_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::gray_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::gray_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::gray_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::gray_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::gray_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::hsl_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::hsl_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::hsl_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::hsl_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::hsl_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::hsl_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::hsl_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::hsv_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::hsv_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::hsv_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::hsv_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::hsv_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::hsv_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::hsv_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::rgb_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::rgb_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::rgb_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::rgb_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::rgb_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::rgb_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::rgb_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsl< ::color::category::yiq_uint8 > {
	typedef ::color::category::hsl_uint8 akin_type;
};
template< >struct hsl< ::color::category::yiq_uint16 > {
	typedef ::color::category::hsl_uint16 akin_type;
};
template< >struct hsl< ::color::category::yiq_uint32 > {
	typedef ::color::category::hsl_uint32 akin_type;
};
template< >struct hsl< ::color::category::yiq_uint64 > {
	typedef ::color::category::hsl_uint64 akin_type;
};
template< >struct hsl< ::color::category::yiq_float > {
	typedef ::color::category::hsl_float akin_type;
};
template< >struct hsl< ::color::category::yiq_double > {
	typedef ::color::category::hsl_double akin_type;
};
template< >struct hsl< ::color::category::yiq_ldouble > {
	typedef ::color::category::hsl_ldouble akin_type;
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct hsl_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 360, 100, 100 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 360, 100, 100 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 360, 100, 100 };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 360, 100, 100 };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsl_double >
		: public ::color::_internal::utility::bound::hsl_scalar< unsigned, double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsl_float >
		: public ::color::_internal::utility::bound::hsl_scalar< unsigned, float > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsl_ldouble >
		: public ::color::_internal::utility::bound::hsl_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsl_uint16 >
		: public ::color::_internal::utility::bound::bound556< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsl_uint32 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 8, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsl_uint64 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 16, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsl_uint8 >
		: public ::color::_internal::utility::bound::bound332< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsl_double >
		: public ::color::_internal::utility::component::array< double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::hsl_float >
		: public ::color::_internal::utility::component::array< float, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::hsl_ldouble >
		: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsl_uint16 >
		: public ::color::_internal::utility::component::cnent556< unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsl_uint32 >
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::hsl_uint64 >
		: public ::color::_internal::utility::component::Unsigned< std::uint16_t, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsl_uint8 >
		: public ::color::_internal::utility::component::cnent332< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsl_double >
		: public ::color::_internal::utility::container::array< double, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::hsl_float >
		: public ::color::_internal::utility::container::array< float, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::hsl_ldouble >
		: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsl_uint16 >
		: public ::color::_internal::utility::container::cner556< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsl_uint32 >
		: public ::color::_internal::utility::container::Unsigned< std::uint32_t, std::uint8_t, unsigned, 3, 8 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::hsl_uint64 >
		: public ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint16_t, unsigned, 3, 16 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsl_uint8 >
		: public ::color::_internal::utility::container::cner332< unsigned > {
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct gray {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -9 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
gray() {
	return ::color::place::_internal::gray<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct gray< ::color::category::gray< tag_name > > {
public:
	typedef ::color::category::gray< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 0 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hsl<tag_name> >::akin_type >::return_type
gray(::color::_internal::model< ::color::category::hsl<tag_name> > const& color_parameter) {
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;
	scalar_type value =
		0.2126 * normalize_type::template process<0>(color_parameter.template get<0>())
	+ 0.7152 * normalize_type::template process<1>(color_parameter.template get<1>())
	+ 0.0722 * normalize_type::template process<2>(color_parameter.template get<2>());
	return diverse_type::template process<0>(value);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsl<tag_name> >::akin_type >::return_type
red(::color::_internal::model< ::color::category::hsl<tag_name> > const& color_parameter) {
	typedef ::color::category::hsl<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type r =
		0.2126 * normalize_type::template process<0>(color_parameter.template get<0>())
	+ 0.7152 * normalize_type::template process<1>(color_parameter.template get<1>())
	+ 0.0722 * normalize_type::template process<2>(color_parameter.template get<2>());
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsl<tag_name> >::akin_type >::return_type
green(::color::_internal::model< ::color::category::hsl<tag_name> > const& color_parameter) {
	typedef ::color::category::hsl<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type g =
		0.2126 * normalize_type::template process<0>(color_parameter.template get<0>())
	+ 0.7152 * normalize_type::template process<1>(color_parameter.template get<1>())
	+ 0.0722 * normalize_type::template process<2>(color_parameter.template get<2>());
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsl<tag_name> >::akin_type >::return_type
blue(::color::_internal::model< ::color::category::hsl<tag_name> > const& color_parameter) {
	typedef ::color::category::hsl<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type b =
		0.2126 * normalize_type::template process<0>(color_parameter.template get<0>())
	+ 0.7152 * normalize_type::template process<1>(color_parameter.template get<1>())
	+ 0.0722 * normalize_type::template process<2>(color_parameter.template get<2>());
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace make {

inline
void black(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void black(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void black(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff000000u;
}

inline
void black(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff000000000000ul;
}

inline
void black(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void gray50(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x40;
}

inline
void gray50(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7c00;
}

inline
void gray50(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f0000u;
}

inline
void gray50(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff00000000ul;
}

inline
void gray50(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 50 });
}

inline
void gray50(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 50 });
}

inline
void gray50(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 50 });
}

}
}

namespace color {
namespace make {

inline
void white(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xc0;
}

inline
void white(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xfc00;
}

inline
void white(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff0000u;
}

inline
void white(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff00000000ul;
}

inline
void white(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 100 });
}

inline
void white(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 100 });
}

inline
void white(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 100 });
}

}
}

namespace color {
namespace make {

inline
void red(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x78;
}

inline
void red(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fe0;
}

inline
void red(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff00u;
}

inline
void red(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff0000ul;
}

inline
void red(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 100, 50 });
}

inline
void red(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 100, 50 });
}

inline
void red(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void green(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x3a;
}

inline
void green(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x3fea;
}

inline
void green(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3fff55u;
}

inline
void green(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3fffffff5555ul;
}

inline
void green(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 120, 100, 25 });
}

inline
void green(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 120, 100, 25 });
}

inline
void green(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 120, 100, 25 });
}

}
}

namespace color {
namespace make {

inline
void blue(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x7c;
}

inline
void blue(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7ff4;
}

inline
void blue(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fffaau;
}

inline
void blue(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffffaaaaul;
}

inline
void blue(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 240, 100, 50 });
}

inline
void blue(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 240, 100, 50 });
}

inline
void blue(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 240, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void cyan(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x7b;
}

inline
void cyan(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fef;
}

inline
void cyan(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff7fu;
}

inline
void cyan(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff7ffful;
}

inline
void cyan(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 180, 100, 50 });
}

inline
void cyan(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 180, 100, 50 });
}

inline
void cyan(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 180, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void magenta(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x7d;
}

inline
void magenta(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7ff9;
}

inline
void magenta(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fffd4u;
}

inline
void magenta(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffffd554ul;
}

inline
void magenta(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 100, 50 });
}

inline
void magenta(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 100, 50 });
}

inline
void magenta(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void yellow(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x79;
}

inline
void yellow(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fe5;
}

inline
void yellow(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff2au;
}

inline
void yellow(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff2aaaul;
}

inline
void yellow(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 60, 100, 50 });
}

inline
void yellow(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 60, 100, 50 });
}

inline
void yellow(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 60, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void aqua(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x7b;
}

inline
void aqua(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fef;
}

inline
void aqua(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff7fu;
}

inline
void aqua(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff7ffful;
}

inline
void aqua(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 180, 100, 50 });
}

inline
void aqua(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 180, 100, 50 });
}

inline
void aqua(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 180, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void fuchsia(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x7d;
}

inline
void fuchsia(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7ff9;
}

inline
void fuchsia(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fffd4u;
}

inline
void fuchsia(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffffd554ul;
}

inline
void fuchsia(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 100, 50 });
}

inline
void fuchsia(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 100, 50 });
}

inline
void fuchsia(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void lime(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x7a;
}

inline
void lime(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fea;
}

inline
void lime(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff55u;
}

inline
void lime(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff5555ul;
}

inline
void lime(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 120, 100, 50 });
}

inline
void lime(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 120, 100, 50 });
}

inline
void lime(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 120, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void maroon(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x38;
}

inline
void maroon(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x3fe0;
}

inline
void maroon(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3fff00u;
}

inline
void maroon(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3fffffff0000ul;
}

inline
void maroon(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 100, 25 });
}

inline
void maroon(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 100, 25 });
}

inline
void maroon(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 100, 25 });
}

}
}

namespace color {
namespace make {

inline
void navy(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x3c;
}

inline
void navy(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x3ff4;
}

inline
void navy(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3fffaau;
}

inline
void navy(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3fffffffaaaaul;
}

inline
void navy(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 240, 100, 25 });
}

inline
void navy(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 240, 100, 25 });
}

inline
void navy(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 240, 100, 25 });
}

}
}

namespace color {
namespace make {

inline
void olive(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x39;
}

inline
void olive(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x3fe5;
}

inline
void olive(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3fff2au;
}

inline
void olive(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3fffffff2aaaul;
}

inline
void olive(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 60, 100, 25 });
}

inline
void olive(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 60, 100, 25 });
}

inline
void olive(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 60, 100, 25 });
}

}
}

namespace color {
namespace make {

inline
void orange(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x78;
}

inline
void orange(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fe3;
}

inline
void orange(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff1bu;
}

inline
void orange(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff1bbbul;
}

inline
void orange(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 39, 100, 50 });
}

inline
void orange(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 39, 100, 50 });
}

inline
void orange(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 39, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void purple(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x3d;
}

inline
void purple(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x3ff9;
}

inline
void purple(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3fffd4u;
}

inline
void purple(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3fffffffd554ul;
}

inline
void purple(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 100, 25 });
}

inline
void purple(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 100, 25 });
}

inline
void purple(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 100, 25 });
}

}
}

namespace color {
namespace make {

inline
void silver(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x80;
}

inline
void silver(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xbc00;
}

inline
void silver(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffbf0000u;
}

inline
void silver(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffbfff00000000ul;
}

inline
void silver(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 75 });
}

inline
void silver(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 75 });
}

inline
void silver(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 75 });
}

}
}

namespace color {
namespace make {

inline
void teal(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x3b;
}

inline
void teal(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x3fef;
}

inline
void teal(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3fff7fu;
}

inline
void teal(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3fffffff7ffful;
}

inline
void teal(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 180, 100, 25 });
}

inline
void teal(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 180, 100, 25 });
}

inline
void teal(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 180, 100, 25 });
}

}
}

namespace color {
namespace make {

inline
void violet(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xad;
}

inline
void violet(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xb6f9;
}

inline
void violet(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffb8c1d4u;
}

inline
void violet(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffb8b8c2b3d554ul;
}

inline
void violet(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 76.0563, 72.1569 });
}

inline
void violet(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 76.0563, 72.1569 });
}

inline
void violet(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 76.0563, 72.1569 });
}

}
}

namespace color {
namespace make {

inline
void aquamarine(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xbb;
}

inline
void aquamarine(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xbfed;
}

inline
void aquamarine(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffbfff71u;
}

inline
void aquamarine(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffbfffffff719bul;
}

inline
void aquamarine(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 159.765, 100, 75 });
}

inline
void aquamarine(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 159.765, 100, 75 });
}

inline
void aquamarine(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 159.765, 100, 75 });
}

}
}

namespace color {
namespace make {

inline
void azure(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xbb;
}

inline
void azure(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xf7ef;
}

inline
void azure(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xfff7ff7fu;
}

inline
void azure(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffff877ffff7ffful;
}

inline
void azure(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 180, 100, 97.0588 });
}

inline
void azure(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 180, 100, 97.0588 });
}

inline
void azure(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 180, 100, 97.0588 });
}

}
}

namespace color {
namespace make {

inline
void beige(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x99;
}

inline
void beige(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xe625;
}

inline
void beige(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffe88d2au;
}

inline
void beige(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffe9688e382aaaul;
}

inline
void beige(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 60, 55.5556, 91.1765 });
}

inline
void beige(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 60, 55.5556, 91.1765 });
}

inline
void beige(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 60, 55.5556, 91.1765 });
}

}
}

namespace color {
namespace make {

inline
void bisque(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xb0;
}

inline
void bisque(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xdfc2;
}

inline
void bisque(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffe1fe17u;
}

inline
void bisque(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffe261fffe1724ul;
}

inline
void bisque(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 32.5424, 100, 88.4314 });
}

inline
void bisque(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 32.5424, 100, 88.4314 });
}

inline
void bisque(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 32.5424, 100, 88.4314 });
}

}
}

namespace color {
namespace make {

inline
void brown(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x60;
}

inline
void brown(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x6640;
}

inline
void brown(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff679700u;
}

inline
void brown(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff67e7981d0000ul;
}

inline
void brown(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 59.4203, 40.5882 });
}

inline
void brown(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 59.4203, 40.5882 });
}

inline
void brown(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 59.4203, 40.5882 });
}

}
}

namespace color {
namespace make {

inline
void chocolate(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x68;
}

inline
void chocolate(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x76e2;
}

inline
void chocolate(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff78bf11u;
}

inline
void chocolate(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7878bfff11c7ul;
}

inline
void chocolate(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 25, 75, 47.0588 });
}

inline
void chocolate(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 25, 75, 47.0588 });
}

inline
void chocolate(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 25, 75, 47.0588 });
}

}
}

namespace color {
namespace make {

inline
void coral(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x78;
}

inline
void coral(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xa7e1;
}

inline
void coral(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffa7ff0bu;
}

inline
void coral(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffa7adffff0bbful;
}

inline
void coral(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 16.5217, 100, 65.5 });
}

inline
void coral(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 16.5217, 100, 65.5 });
}

inline
void coral(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 16.5217, 100, 65.5 });
}

}
}

namespace color {
namespace make {

inline
void crimson(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x6e;
}

inline
void crimson(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x773d;
}

inline
void crimson(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff78d4f6u;
}

inline
void crimson(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7878d554f776ul;
}

inline
void crimson(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 348, 83.3333, 47.0588 });
}

inline
void crimson(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 348, 83.3333, 47.0588 });
}

inline
void crimson(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 348, 83.3333, 47.0588 });
}

}
}

namespace color {
namespace make {

inline
void gainsboro(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x80;
}

inline
void gainsboro(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xd800;
}

inline
void gainsboro(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffdb0000u;
}

inline
void gainsboro(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdc2800000000ul;
}

inline
void gainsboro(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 86 });
}

inline
void gainsboro(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 86 });
}

inline
void gainsboro(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 86 });
}

}
}

namespace color {
namespace make {

inline
void gold(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x78;
}

inline
void gold(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fe4;
}

inline
void gold(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff23u;
}

inline
void gold(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff23f9ul;
}

inline
void gold(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 50.5882, 100, 50 });
}

inline
void gold(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 50.5882, 100, 50 });
}

inline
void gold(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 50.5882, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void indigo(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x3d;
}

inline
void indigo(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x43f7;
}

inline
void indigo(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff41ffc2u;
}

inline
void indigo(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff4141ffffc347ul;
}

inline
void indigo(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 274.615, 100, 25.4902 });
}

inline
void indigo(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 274.615, 100, 25.4902 });
}

inline
void indigo(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 274.615, 100, 25.4902 });
}

}
}

namespace color {
namespace make {

inline
void ivory(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xb9;
}

inline
void ivory(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xf7e5;
}

inline
void ivory(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xfff7ff2au;
}

inline
void ivory(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffff877ffff2aaaul;
}

inline
void ivory(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 60, 100, 97.0588 });
}

inline
void ivory(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 60, 100, 97.0588 });
}

inline
void ivory(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 60, 100, 97.0588 });
}

}
}

namespace color {
namespace make {

inline
void khaki(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xa9;
}

inline
void khaki(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xbae4;
}

inline
void khaki(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffbec426u;
}

inline
void khaki(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffbebec4eb2666ul;
}

inline
void khaki(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 54, 76.9231, 74.5098 });
}

inline
void khaki(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 54, 76.9231, 74.5098 });
}

inline
void khaki(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 54, 76.9231, 74.5098 });
}

}
}

namespace color {
namespace make {

inline
void lavender(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xa4;
}

inline
void lavender(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xee94;
}

inline
void lavender(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xfff0a9aau;
}

inline
void lavender(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffff0f0aaa9aaaaul;
}

inline
void lavender(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 240, 66.6667, 94.1176 });
}

inline
void lavender(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 240, 66.6667, 94.1176 });
}

inline
void lavender(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 240, 66.6667, 94.1176 });
}

}
}

namespace color {
namespace make {

inline
void linen(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xa0;
}

inline
void linen(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xee82;
}

inline
void linen(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xfff0a915u;
}

inline
void linen(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffff0f0aaa91555ul;
}

inline
void linen(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 30, 66.6667, 94.1176 });
}

inline
void linen(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 30, 66.6667, 94.1176 });
}

inline
void linen(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 30, 66.6667, 94.1176 });
}

}
}

namespace color {
namespace make {

inline
void moccasin(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xb8;
}

inline
void moccasin(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xd7e3;
}

inline
void moccasin(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffdaff1au;
}

inline
void moccasin(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdadaffff1b19ul;
}

inline
void moccasin(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 38.1081, 100, 85.4902 });
}

inline
void moccasin(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 38.1081, 100, 85.4902 });
}

inline
void moccasin(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 38.1081, 100, 85.4902 });
}

}
}

namespace color {
namespace make {

inline
void orchid(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x65;
}

inline
void orchid(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xa25a;
}

inline
void orchid(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffa496d6u;
}

inline
void orchid(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffa5a496c0d6f0ul;
}

inline
void orchid(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 302.264, 58.8889, 64.7059 });
}

inline
void orchid(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 302.264, 58.8889, 64.7059 });
}

inline
void orchid(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 302.264, 58.8889, 64.7059 });
}

}
}

namespace color {
namespace make {

inline
void peru(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x60;
}

inline
void peru(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x8642;
}

inline
void peru(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff869514u;
}

inline
void peru(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff868696361508ul;
}

inline
void peru(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 29.5775, 58.6777, 52.549 });
}

inline
void peru(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 29.5775, 58.6777, 52.549 });
}

inline
void peru(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 29.5775, 58.6777, 52.549 });
}

}
}

namespace color {
namespace make {

inline
void pink(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x60;
}

inline
void pink(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x8642;
}

inline
void pink(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff869514u;
}

inline
void pink(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff868696361508ul;
}

inline
void pink(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 29.5775, 58.6777, 52.549 });
}

inline
void pink(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 29.5775, 58.6778, 52.549 });
}

inline
void pink(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 29.5775, 58.6778, 52.549 });
}

}
}

namespace color {
namespace make {

inline
void plum(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x9d;
}

inline
void plum(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xbdd9;
}

inline
void plum(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffbe78d4u;
}

inline
void plum(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffbf3e790dd554ul;
}

inline
void plum(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 47.2868, 74.7059 });
}

inline
void plum(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 47.2868, 74.7059 });
}

inline
void plum(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 47.2868, 74.7059 });
}

}
}

namespace color {
namespace make {

inline
void salmon(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x9d;
}

inline
void salmon(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xbdd9;
}

inline
void salmon(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffbe78d4u;
}

inline
void salmon(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffbf3e790dd554ul;
}

inline
void salmon(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 47.2869, 74.7059 });
}

inline
void salmon(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 47.2869, 74.7059 });
}

inline
void salmon(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 47.2869, 74.7059 });
}

}
}

namespace color {
namespace make {

inline
void sienna(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x58;
}

inline
void sienna(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x6621;
}

inline
void sienna(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff668f0du;
}

inline
void sienna(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff66e68f9b0dbaul;
}

inline
void sienna(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 19.3043, 56.0976, 40.1961 });
}

inline
void sienna(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 19.3043, 56.0976, 40.1961 });
}

inline
void sienna(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 19.3043, 56.0976, 40.1961 });
}

}
}

namespace color {
namespace make {

inline
void snow(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xb8;
}

inline
void snow(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xfbe0;
}

inline
void snow(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xfffcff00u;
}

inline
void snow(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffffd7cffff0000ul;
}

inline
void snow(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 100, 99.0196 });
}

inline
void snow(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 100, 99.0196 });
}

inline
void snow(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 100, 99.0196 });
}

}
}

namespace color {
namespace make {

inline
void tan(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x98;
}

inline
void tan(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xada2;
}

inline
void tan(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffaf6f18u;
}

inline
void tan(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffafaf6fff1861ul;
}

inline
void tan(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 34.2857, 43.75, 68.6274 });
}

inline
void tan(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 34.2857, 43.75, 68.6275 });
}

inline
void tan(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 34.2857, 43.75, 68.6275 });
}

}
}

namespace color {
namespace make {

inline
void thistle(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x8d;
}

inline
void thistle(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xc8f9;
}

inline
void thistle(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffcb3dd4u;
}

inline
void thistle(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffcc4b3e22d554ul;
}

inline
void thistle(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 24.2718, 79.8039 });
}

inline
void thistle(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 24.2718, 79.8039 });
}

inline
void thistle(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 24.2718, 79.8039 });
}

}
}

namespace color {
namespace make {

inline
void tomato(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x70;
}

inline
void tomato(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xa3c0;
}

inline
void tomato(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffa3fe06u;
}

inline
void tomato(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffa3a3fffe067eul;
}

inline
void tomato(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 9.13043, 100, 63.9216 });
}

inline
void tomato(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 9.13043, 100, 63.9216 });
}

inline
void tomato(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 9.13043, 100, 63.9216 });
}

}
}

namespace color {
namespace make {

inline
void turquoise(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0x6b;
}

inline
void turquoise(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0x8ece;
}

inline
void turquoise(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xff90b77bu;
}

inline
void turquoise(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff9090b8807bbbul;
}

inline
void turquoise(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 174, 72.0721, 56.4706 });
}

inline
void turquoise(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 174, 72.0721, 56.4706 });
}

inline
void turquoise(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 174, 72.0721, 56.4706 });
}

}
}

namespace color {
namespace make {

inline
void wheat(::color::_internal::model< color::category::hsl_uint8 > & color_parameter) {
	color_parameter.container() = 0xa8;
}

inline
void wheat(::color::_internal::model< color::category::hsl_uint16 > & color_parameter) {
	color_parameter.container() = 0xd2e3;
}

inline
void wheat(::color::_internal::model< color::category::hsl_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd3c31bu;
}

inline
void wheat(::color::_internal::model< color::category::hsl_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd4d3c4761bccul;
}

inline
void wheat(::color::_internal::model< color::category::hsl_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 39.0909, 76.7442, 83.1373 });
}

inline
void wheat(::color::_internal::model< color::category::hsl_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 39.0909, 76.7442, 83.1373 });
}

inline
void wheat(::color::_internal::model< color::category::hsl_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 39.0909, 76.7442, 83.1373 });
}

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename cmy_tag_name >
struct convert
		<
		::color::category::hsl< hsl_tag_name >
		,::color::category::cmy< cmy_tag_name >
		> {
public:
	typedef ::color::category::hsl< hsl_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar<category_left_type> scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = scalar_type(1) - normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type g = scalar_type(1) - normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type b = scalar_type(1) - normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		const scalar_type hi = std::max<scalar_type>({ r, g, b });
		const scalar_type lo = std::min<scalar_type>({ r, g, b });
		scalar_type delta = hi - lo;
		scalar_type h = 0;
		scalar_type s = 0;
		scalar_type l = (hi + lo) / scalar_type(2);
		if(false == scalar_trait_type::is_small(delta)) {
			s = delta / (1 - fabs(2*l - 1));
			if(hi == r) {
				h = (scalar_type(60)/scalar_type(360)) * (g - b) / delta + (g < b ? scalar_type(1) : scalar_type(0));
			}
			if(hi == g) {
				h = (scalar_type(60)/scalar_type(360)) * (b - r) / delta + (scalar_type(120)/scalar_type(360));
			}
			if(hi == b) {
				h = (scalar_type(60)/scalar_type(360)) * (r - g) / delta + (scalar_type(240)/scalar_type(360));
			}
		}
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(h));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(s));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(l));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename gray_tag_name >
struct convert
		<
		::color::category::hsl< hsl_tag_name >
		,::color::category::gray< gray_tag_name >
		> {
public:
	typedef ::color::category::hsl< hsl_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, bound_left_trait_type::template minimum<0>());
		container_left_trait_type::template set<1>(left, bound_left_trait_type::template minimum<1>());
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,0>(container_right_trait_type::template get<0>(right)));
	}
};

}
}
namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
		<
		::color::category::hsl< tag_left_name >
		,::color::category::hsl< tag_right_name>
		> {
public:
	typedef ::color::category::hsl< tag_left_name > category_left_type;
	typedef ::color::category::hsl< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};
}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct value {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -11 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
value() {
	return ::color::place::_internal::value<category_name>::position();
}

}
}

namespace color {
namespace trait {

template< >
struct index< ::color::category::hsv_double >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsv_float >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsv_ldouble >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsv_uint16 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsv_uint32 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsv_uint64 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::hsv_uint8 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct value< ::color::category::hsl< tag_name > > {
public:
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::cmy_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::cmy_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::cmy_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::cmy_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::cmy_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::cmy_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::cmy_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::cmyk_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::cmyk_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::cmyk_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::cmyk_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::cmyk_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::cmyk_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::cmyk_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::gray_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::gray_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::gray_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::gray_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::gray_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::gray_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::gray_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::hsl_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::hsl_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::hsl_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::hsl_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::hsl_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::hsl_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::hsl_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::hsv_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::hsv_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::hsv_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::hsv_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::hsv_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::hsv_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::hsv_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::rgb_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::rgb_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::rgb_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::rgb_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::rgb_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::rgb_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::rgb_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::yiq_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::yiq_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::yiq_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::yiq_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::yiq_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::yiq_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::yiq_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct hsv< ::color::category::yuv_uint8 > {
	typedef ::color::category::hsv_uint8 akin_type;
};
template< >struct hsv< ::color::category::yuv_uint16 > {
	typedef ::color::category::hsv_uint16 akin_type;
};
template< >struct hsv< ::color::category::yuv_uint32 > {
	typedef ::color::category::hsv_uint32 akin_type;
};
template< >struct hsv< ::color::category::yuv_uint64 > {
	typedef ::color::category::hsv_uint64 akin_type;
};
template< >struct hsv< ::color::category::yuv_float > {
	typedef ::color::category::hsv_float akin_type;
};
template< >struct hsv< ::color::category::yuv_double > {
	typedef ::color::category::hsv_double akin_type;
};
template< >struct hsv< ::color::category::yuv_ldouble > {
	typedef ::color::category::hsv_ldouble akin_type;
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct hsv_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 360, 100, 100 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 360, 100, 100 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 360, 100, 100 };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 360, 100, 100 };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsv_double >
		: public ::color::_internal::utility::bound::hsv_scalar< unsigned, double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsv_float >
		: public ::color::_internal::utility::bound::hsv_scalar< unsigned, float > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsv_ldouble >
		: public ::color::_internal::utility::bound::hsv_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsv_uint16 >
		: public ::color::_internal::utility::bound::bound556< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsv_uint32 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 8, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsv_uint64 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 16, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::hsv_uint8 >
		: public ::color::_internal::utility::bound::bound332< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsv_double >
		: public ::color::_internal::utility::component::array< double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::hsv_float >
		: public ::color::_internal::utility::component::array< float, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::hsv_ldouble >
		: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsv_uint16 >
		: public ::color::_internal::utility::component::cnent556< unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsv_uint32 >
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::hsv_uint64 >
		: public ::color::_internal::utility::component::Unsigned< std::uint16_t, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::hsv_uint8 >
		: public ::color::_internal::utility::component::cnent332< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsv_double >
		: public ::color::_internal::utility::container::array< double, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::hsv_float >
		: public ::color::_internal::utility::container::array< float, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::hsv_ldouble >
		: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsv_uint16 >
		: public ::color::_internal::utility::container::cner556< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsv_uint32 >
		: public ::color::_internal::utility::container::Unsigned< std::uint32_t, std::uint8_t, unsigned, 3, 8 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::hsv_uint64 >
		: public ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint16_t, unsigned, 3, 16 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::hsv_uint8 >
		: public ::color::_internal::utility::container::cner332< unsigned > {
};

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hsv<tag_name> >::akin_type >::return_type
gray(::color::_internal::model< ::color::category::hsv<tag_name> > const& color_parameter) {
	typedef ::color::category::hsv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::gray<category_type>::akin_type akin_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type value =
		0.2126 * normalize_type::template process<0>(color_parameter.template get<0>())
	+ 0.7152 * normalize_type::template process<1>(color_parameter.template get<1>())
	+ 0.0722 * normalize_type::template process<2>(color_parameter.template get<2>());
	return diverse_type::template process<0>(value);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsv<tag_name> >::akin_type >::return_type
red(::color::_internal::model< ::color::category::hsv<tag_name> > const& color_parameter) {
	typedef ::color::category::hsv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type r =
		0.2126 * normalize_type::template process<0>(color_parameter.template get<0>())
	+ 0.7152 * normalize_type::template process<1>(color_parameter.template get<1>())
	+ 0.0722 * normalize_type::template process<2>(color_parameter.template get<2>());
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsv<tag_name> >::akin_type >::return_type
green(::color::_internal::model< ::color::category::hsv<tag_name> > const& color_parameter) {
	typedef ::color::category::hsv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type g =
		0.2126 * normalize_type::template process<0>(color_parameter.template get<0>())
	+ 0.7152 * normalize_type::template process<1>(color_parameter.template get<1>())
	+ 0.0722 * normalize_type::template process<2>(color_parameter.template get<2>());
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::hsv<tag_name> >::akin_type >::return_type
blue(::color::_internal::model< ::color::category::hsv<tag_name> > const& color_parameter) {
	typedef ::color::category::hsv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	scalar_type b =
		0.2126 * normalize_type::template process<0>(color_parameter.template get<0>())
	+ 0.7152 * normalize_type::template process<1>(color_parameter.template get<1>())
	+ 0.0722 * normalize_type::template process<2>(color_parameter.template get<2>());
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace make {

inline
void black(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void black(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void black(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff000000u;
}

inline
void black(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff000000000000ul;
}

inline
void black(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void gray50(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x40;
}

inline
void gray50(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7c00;
}

inline
void gray50(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f0000u;
}

inline
void gray50(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff00000000ul;
}

inline
void gray50(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 50 });
}

inline
void gray50(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 50 });
}

inline
void gray50(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 50 });
}

}
}

namespace color {
namespace make {

inline
void white(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xc0;
}

inline
void white(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfc00;
}

inline
void white(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff0000u;
}

inline
void white(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff00000000ul;
}

inline
void white(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 100 });
}

inline
void white(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 100 });
}

inline
void white(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 100 });
}

}
}

namespace color {
namespace make {

inline
void red(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xf8;
}

inline
void red(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xffe0;
}

inline
void red(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff00u;
}

inline
void red(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffff0000ul;
}

inline
void red(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 100, 100 });
}

inline
void red(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 100, 100 });
}

inline
void red(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 100, 100 });
}

}
}

namespace color {
namespace make {

inline
void green(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x7a;
}

inline
void green(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fea;
}

inline
void green(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff55u;
}

inline
void green(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff5555ul;
}

inline
void green(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 120, 100, 50 });
}

inline
void green(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 120, 100, 50 });
}

inline
void green(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 120, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void blue(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xfc;
}

inline
void blue(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfff4;
}

inline
void blue(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffffaau;
}

inline
void blue(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffffaaaaul;
}

inline
void blue(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 240, 100, 100 });
}

inline
void blue(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 240, 100, 100 });
}

inline
void blue(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 240, 100, 100 });
}

}
}

namespace color {
namespace make {

inline
void cyan(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xfb;
}

inline
void cyan(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xffef;
}

inline
void cyan(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff7fu;
}

inline
void cyan(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffff7ffful;
}

inline
void cyan(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 180, 100, 100 });
}

inline
void cyan(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 180, 100, 100 });
}

inline
void cyan(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 180, 100, 100 });
}

}
}

namespace color {
namespace make {

inline
void magenta(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xfd;
}

inline
void magenta(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfff9;
}

inline
void magenta(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffffd4u;
}

inline
void magenta(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffffd554ul;
}

inline
void magenta(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 100, 100 });
}

inline
void magenta(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 100, 100 });
}

inline
void magenta(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 100, 100 });
}

}
}

namespace color {
namespace make {

inline
void yellow(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xf9;
}

inline
void yellow(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xffe5;
}

inline
void yellow(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff2au;
}

inline
void yellow(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffff2aaaul;
}

inline
void yellow(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 60, 100, 100 });
}

inline
void yellow(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 60, 100, 100 });
}

inline
void yellow(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 60, 100, 100 });
}

}
}

namespace color {
namespace make {

inline
void aqua(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xfb;
}

inline
void aqua(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xffef;
}

inline
void aqua(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff7fu;
}

inline
void aqua(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffff7ffful;
}

inline
void aqua(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 180, 100, 100 });
}

inline
void aqua(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 180, 100, 100 });
}

inline
void aqua(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 180, 100, 100 });
}

}
}

namespace color {
namespace make {

inline
void fuchsia(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xfd;
}

inline
void fuchsia(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfff9;
}

inline
void fuchsia(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffffd4u;
}

inline
void fuchsia(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffffd554ul;
}

inline
void fuchsia(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 100, 100 });
}

inline
void fuchsia(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 100, 100 });
}

inline
void fuchsia(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 100, 100 });
}

}
}

namespace color {
namespace make {

inline
void lime(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xfa;
}

inline
void lime(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xffea;
}

inline
void lime(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff55u;
}

inline
void lime(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffff5555ul;
}

inline
void lime(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 120, 100, 100 });
}

inline
void lime(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 120, 100, 100 });
}

inline
void lime(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 120, 100, 100 });
}

}
}

namespace color {
namespace make {

inline
void maroon(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x78;
}

inline
void maroon(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fe0;
}

inline
void maroon(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff00u;
}

inline
void maroon(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff0000ul;
}

inline
void maroon(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 100, 50 });
}

inline
void maroon(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 100, 50 });
}

inline
void maroon(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void navy(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x7c;
}

inline
void navy(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7ff4;
}

inline
void navy(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fffaau;
}

inline
void navy(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffffaaaaul;
}

inline
void navy(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 240, 100, 50 });
}

inline
void navy(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 240, 100, 50 });
}

inline
void navy(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 240, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void olive(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x79;
}

inline
void olive(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fe5;
}

inline
void olive(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff2au;
}

inline
void olive(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff2aaaul;
}

inline
void olive(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 60, 100, 50 });
}

inline
void olive(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 60, 100, 50 });
}

inline
void olive(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 60, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void orange(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xf8;
}

inline
void orange(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xffe3;
}

inline
void orange(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff1bu;
}

inline
void orange(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffff1bbbul;
}

inline
void orange(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 39, 100, 100 });
}

inline
void orange(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 39, 100, 100 });
}

inline
void orange(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 39, 100, 100 });
}

}
}

namespace color {
namespace make {

inline
void purple(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x7d;
}

inline
void purple(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7ff9;
}

inline
void purple(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fffd4u;
}

inline
void purple(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffffd554ul;
}

inline
void purple(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 100, 50 });
}

inline
void purple(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 100, 50 });
}

inline
void purple(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void silver(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x80;
}

inline
void silver(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xbc00;
}

inline
void silver(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffbf0000u;
}

inline
void silver(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffbfff00000000ul;
}

inline
void silver(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 75 });
}

inline
void silver(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 75 });
}

inline
void silver(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 75 });
}

}
}

namespace color {
namespace make {

inline
void teal(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x7b;
}

inline
void teal(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7fef;
}

inline
void teal(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7fff7fu;
}

inline
void teal(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fffffff7ffful;
}

inline
void teal(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 180, 100, 50 });
}

inline
void teal(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 180, 100, 50 });
}

inline
void teal(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 180, 100, 50 });
}

}
}

namespace color {
namespace make {

inline
void violet(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x9d;
}

inline
void violet(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xe9d9;
}

inline
void violet(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffee73d4u;
}

inline
void violet(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffeeee742ad554ul;
}

inline
void violet(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 45.3782, 93.3333 });
}

inline
void violet(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 45.3782, 93.3333 });
}

inline
void violet(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 45.3782, 93.3333 });
}

}
}

namespace color {
namespace make {

inline
void aquamarine(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xdb;
}

inline
void aquamarine(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfded;
}

inline
void aquamarine(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff7f71u;
}

inline
void aquamarine(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff7fff719bul;
}

inline
void aquamarine(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 159.765, 50, 100 });
}

inline
void aquamarine(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 159.765, 50, 100 });
}

inline
void aquamarine(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 159.765, 50, 100 });
}

}
}

namespace color {
namespace make {

inline
void azure(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xc3;
}

inline
void azure(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfc2f;
}

inline
void azure(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff0f7fu;
}

inline
void azure(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff0f0f7ffful;
}

inline
void azure(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 180, 5.88235, 100 });
}

inline
void azure(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 180, 5.88235, 100 });
}

inline
void azure(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 180, 5.88235, 100 });
}

}
}

namespace color {
namespace make {

inline
void beige(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x81;
}

inline
void beige(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xf065;
}

inline
void beige(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xfff51a2au;
}

inline
void beige(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffff5f51a1f2aaaul;
}

inline
void beige(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 60, 10.2041, 96.0784 });
}

inline
void beige(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 60, 10.2041, 96.0784 });
}

inline
void beige(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 60, 10.2041, 96.0784 });
}

}
}

namespace color {
namespace make {

inline
void bisque(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xc8;
}

inline
void bisque(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfce2;
}

inline
void bisque(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff3a17u;
}

inline
void bisque(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff3b3a1724ul;
}

inline
void bisque(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 32.5424, 23.1373, 100 });
}

inline
void bisque(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 32.5424, 23.1373, 100 });
}

inline
void bisque(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 32.5424, 23.1373, 100 });
}

}
}

namespace color {
namespace make {

inline
void brown(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x68;
}

inline
void brown(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xa2e0;
}

inline
void brown(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffa5be00u;
}

inline
void brown(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffa5a5bed50000ul;
}

inline
void brown(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 74.5455, 64.7059 });
}

inline
void brown(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 74.5455, 64.7059 });
}

inline
void brown(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 74.5455, 64.7059 });
}

}
}

namespace color {
namespace make {

inline
void chocolate(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xb0;
}

inline
void chocolate(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xcf42;
}

inline
void chocolate(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd2da11u;
}

inline
void chocolate(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd2d2db6c11c7ul;
}

inline
void chocolate(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 25, 85.7143, 82.3529 });
}

inline
void chocolate(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 25, 85.7143, 82.3529 });
}

inline
void chocolate(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 25, 85.7143, 82.3529 });
}

}
}

namespace color {
namespace make {

inline
void coral(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xe0;
}

inline
void coral(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfea1;
}

inline
void coral(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffaf0bu;
}

inline
void coral(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffb0a30bbful;
}

inline
void coral(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 16.5217, 69, 100 });
}

inline
void coral(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 16.5217, 69, 100 });
}

inline
void coral(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 16.5217, 69, 100 });
}

}
}

namespace color {
namespace make {

inline
void crimson(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xb6;
}

inline
void crimson(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xdb9d;
}

inline
void crimson(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffdce7f6u;
}

inline
void crimson(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdcdce8b9f776ul;
}

inline
void crimson(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 348, 90.9091, 86.2745 });
}

inline
void crimson(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 348, 90.9091, 86.2745 });
}

inline
void crimson(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 348, 90.9091, 86.2745 });
}

}
}

namespace color {
namespace make {

inline
void gainsboro(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x80;
}

inline
void gainsboro(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xd800;
}

inline
void gainsboro(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffdb0000u;
}

inline
void gainsboro(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdc2800000000ul;
}

inline
void gainsboro(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 86 });
}

inline
void gainsboro(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 86 });
}

inline
void gainsboro(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 86 });
}

}
}

namespace color {
namespace make {

inline
void gold(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xf8;
}

inline
void gold(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xffe4;
}

inline
void gold(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffff23u;
}

inline
void gold(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffffff23f9ul;
}

inline
void gold(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 50.5882, 100, 100 });
}

inline
void gold(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 50.5882, 100, 100 });
}

inline
void gold(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 50.5882, 100, 100 });
}

}
}

namespace color {
namespace make {

inline
void indigo(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x7d;
}

inline
void indigo(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0x83f7;
}

inline
void indigo(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff82ffc2u;
}

inline
void indigo(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff8282ffffc347ul;
}

inline
void indigo(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 274.615, 100, 50.9804 });
}

inline
void indigo(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 274.615, 100, 50.9804 });
}

inline
void indigo(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 274.615, 100, 50.9804 });
}

}
}

namespace color {
namespace make {

inline
void ivory(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xc1;
}

inline
void ivory(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfc25;
}

inline
void ivory(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff0f2au;
}

inline
void ivory(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff0f0f2aaaul;
}

inline
void ivory(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 60, 5.88235, 100 });
}

inline
void ivory(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 60, 5.88235, 100 });
}

inline
void ivory(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 60, 5.88235, 100 });
}

}
}

namespace color {
namespace make {

inline
void khaki(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x91;
}

inline
void khaki(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xed84;
}

inline
void khaki(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xfff06a26u;
}

inline
void khaki(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffff0f06aaa2666ul;
}

inline
void khaki(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 54, 41.6667, 94.1176 });
}

inline
void khaki(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 54, 41.6667, 94.1176 });
}

inline
void khaki(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 54, 41.6667, 94.1176 });
}

}
}

namespace color {
namespace make {

inline
void lavender(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x84;
}

inline
void lavender(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xf454;
}

inline
void lavender(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xfffa14aau;
}

inline
void lavender(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffffafa147aaaaaul;
}

inline
void lavender(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 240, 8, 98.0392 });
}

inline
void lavender(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 240, 8, 98.0392 });
}

inline
void lavender(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 240, 8, 98.0392 });
}

}
}

namespace color {
namespace make {

inline
void linen(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x80;
}

inline
void linen(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xf442;
}

inline
void linen(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xfffa1415u;
}

inline
void linen(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffffafa147a1555ul;
}

inline
void linen(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 30, 8, 98.0392 });
}

inline
void linen(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 30, 8, 98.0392 });
}

inline
void linen(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 30, 8, 98.0392 });
}

}
}

namespace color {
namespace make {

inline
void moccasin(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xd0;
}

inline
void moccasin(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfd03;
}

inline
void moccasin(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff491au;
}

inline
void moccasin(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff4a491b19ul;
}

inline
void moccasin(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 38.1081, 29.0196, 100 });
}

inline
void moccasin(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 38.1081, 29.0196, 100 });
}

inline
void moccasin(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 38.1081, 29.0196, 100 });
}

}
}

namespace color {
namespace make {

inline
void orchid(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x9d;
}

inline
void orchid(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xd5fa;
}

inline
void orchid(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffda7bd6u;
}

inline
void orchid(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdada7c79d6f0ul;
}

inline
void orchid(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 302.264, 48.6239, 85.4902 });
}

inline
void orchid(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 302.264, 48.6239, 85.4902 });
}

inline
void orchid(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 302.264, 48.6239, 85.4902 });
}

}
}

namespace color {
namespace make {

inline
void peru(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xa0;
}

inline
void peru(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xcaa2;
}

inline
void peru(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffcdb014u;
}

inline
void peru(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffcdcdb1521508ul;
}

inline
void peru(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 29.5775, 69.2683, 80.3922 });
}

inline
void peru(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 29.5775, 69.2683, 80.3922 });
}

inline
void peru(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 29.5775, 69.2683, 80.3922 });
}

}
}

namespace color {
namespace make {

inline
void pink(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xa0;
}

inline
void pink(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xcaa2;
}

inline
void pink(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffcdb014u;
}

inline
void pink(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffcdcdb1521508ul;
}

inline
void pink(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 29.5775, 69.2683, 80.3922 });
}

inline
void pink(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 29.5775, 69.2683, 80.3922 });
}

inline
void pink(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 29.5775, 69.2683, 80.3922 });
}

}
}

namespace color {
namespace make {

inline
void plum(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x8d;
}

inline
void plum(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xd919;
}

inline
void plum(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffdd46d4u;
}

inline
void plum(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdddd46a8d554ul;
}

inline
void plum(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 27.6018, 86.6667 });
}

inline
void plum(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 27.6018, 86.6667 });
}

inline
void plum(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 27.6018, 86.6667 });
}

}
}

namespace color {
namespace make {

inline
void salmon(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x8d;
}

inline
void salmon(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xd919;
}

inline
void salmon(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffdd46d4u;
}

inline
void salmon(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffdddd46a8d554ul;
}

inline
void salmon(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 27.6018, 86.6667 });
}

inline
void salmon(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 27.6018, 86.6667 });
}

inline
void salmon(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 27.6018, 86.6667 });
}

}
}

namespace color {
namespace make {

inline
void sienna(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x68;
}

inline
void sienna(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0x9ec1;
}

inline
void sienna(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffa0b70du;
}

inline
void sienna(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffa0a0b7ff0dbaul;
}

inline
void sienna(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 19.3043, 71.875, 62.7451 });
}

inline
void sienna(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 19.3043, 71.875, 62.7451 });
}

inline
void sienna(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 19.3043, 71.875, 62.7451 });
}

}
}

namespace color {
namespace make {

inline
void snow(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xc0;
}

inline
void snow(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfc00;
}

inline
void snow(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff0500u;
}

inline
void snow(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff05050000ul;
}

inline
void snow(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 1.96078, 100 });
}

inline
void snow(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 1.96078, 100 });
}

inline
void snow(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 1.96078, 100 });
}

}
}

namespace color {
namespace make {

inline
void tan(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x90;
}

inline
void tan(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xcd42;
}

inline
void tan(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd25418u;
}

inline
void tan(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd2d255541861ul;
}

inline
void tan(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 34.2857, 33.3333, 82.3529 });
}

inline
void tan(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 34.2857, 33.3333, 82.3529 });
}

inline
void tan(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 34.2857, 33.3333, 82.3529 });
}

}
}

namespace color {
namespace make {

inline
void thistle(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x85;
}

inline
void thistle(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xd479;
}

inline
void thistle(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd81dd4u;
}

inline
void thistle(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd8d81da1d554ul;
}

inline
void thistle(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 300, 11.5741, 84.7059 });
}

inline
void thistle(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 300, 11.5741, 84.7059 });
}

inline
void thistle(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 300, 11.5741, 84.7059 });
}

}
}

namespace color {
namespace make {

inline
void tomato(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xe8;
}

inline
void tomato(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfec0;
}

inline
void tomato(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffb806u;
}

inline
void tomato(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffb8b8067eul;
}

inline
void tomato(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 9.13043, 72.1569, 100 });
}

inline
void tomato(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 9.13043, 72.1569, 100 });
}

inline
void tomato(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 9.13043, 72.1569, 100 });
}

}
}

namespace color {
namespace make {

inline
void turquoise(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0xab;
}

inline
void turquoise(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xdece;
}

inline
void turquoise(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffe0b67bu;
}

inline
void turquoise(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffe0e0b6da7bbbul;
}

inline
void turquoise(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 174, 71.4286, 87.8431 });
}

inline
void turquoise(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 174, 71.4286, 87.8431 });
}

inline
void turquoise(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 174, 71.4286, 87.8431 });
}

}
}

namespace color {
namespace make {

inline
void wheat(::color::_internal::model< color::category::hsv_uint8 > & color_parameter) {
	color_parameter.container() = 0x88;
}

inline
void wheat(::color::_internal::model< color::category::hsv_uint16 > & color_parameter) {
	color_parameter.container() = 0xf103;
}

inline
void wheat(::color::_internal::model< color::category::hsv_uint32 > & color_parameter) {
	color_parameter.container() = 0xfff5441bu;
}

inline
void wheat(::color::_internal::model< color::category::hsv_uint64 > & color_parameter) {
	color_parameter.container() = 0xfffff5f544f61bccul;
}

inline
void wheat(::color::_internal::model< color::category::hsv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 39.0909, 26.9388, 96.0784 });
}

inline
void wheat(::color::_internal::model< color::category::hsv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 39.0909, 26.9388, 96.0784 });
}

inline
void wheat(::color::_internal::model< color::category::hsv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 39.0909, 26.9388, 96.0784 });
}

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename cmy_tag_name >
struct convert
		<
		::color::category::hsv< hsv_tag_name >
		,::color::category::cmy< cmy_tag_name >
		> {
public:
	typedef ::color::category::hsv< hsv_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar<category_left_type> scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type r = scalar_type(1) - normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type g = scalar_type(1) - normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type b = scalar_type(1) - normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type lo = std::min<scalar_type>({r,g,b});
		scalar_type v = std::max<scalar_type>({r,g,b});
		scalar_type delta = v - lo;
		scalar_type h = 0;
		scalar_type s = 0;
		if((false == scalar_trait_type::is_small(v))
		   && (false == scalar_trait_type::is_small(delta))) {
			s = delta / v;
			if(v == r) {
				h = (scalar_type(60)/scalar_type(360)) * (g - b) / delta + (g < b ? scalar_type(1) : scalar_type(0));
			}
			if(v == g) {
				h = (scalar_type(60)/scalar_type(360)) * (b - r) / delta + (scalar_type(120)/scalar_type(360));
			}
			if(v == b) {
				h = (scalar_type(60)/scalar_type(360)) * (r - g) / delta + (scalar_type(240)/scalar_type(360));
			}
		}
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(h));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(s));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(v));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename gray_tag_name >
struct convert
		<
		::color::category::hsv< hsv_tag_name >
		,::color::category::gray< gray_tag_name >
		> {
public:
	typedef ::color::category::hsv< hsv_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, bound_left_trait_type::template minimum<0>());
		container_left_trait_type::template set<1>(left, bound_left_trait_type::template minimum<1>());
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,0>(container_right_trait_type::template get<0>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename hsl_tag_name >
struct convert
		<
		::color::category::hsv< hsv_tag_name >
		,::color::category::hsl< hsl_tag_name >
		> {
public:
	typedef ::color::category::hsv< hsv_tag_name > category_left_type;
	typedef ::color::category::hsl< hsl_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type ss = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type l = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type v = (2 * l + ss*(1 - fabs(2*l-1))) /2;
		scalar_type s = 2*(v - l) / v;
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(h));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(s));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(v));
	}
};

}
}
namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
		<
		::color::category::hsv< tag_left_name >
		,::color::category::hsv< tag_right_name>
		> {
public:
	typedef ::color::category::hsv< tag_left_name > category_left_type;
	typedef ::color::category::hsv< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};
}
}

namespace color {
namespace _internal {

template< typename hsv_tag_name, typename rgb_tag_name >
struct convert
		<
		::color::category::hsv< hsv_tag_name >
		,::color::category::rgb< rgb_tag_name >
		> {
public:
	typedef ::color::category::hsv< hsv_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar<category_left_type> scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_right_type>::position_enum
					,green_p = ::color::place::_internal::green<category_right_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type lo = std::min<scalar_type>({r,g,b});
		scalar_type v = std::max<scalar_type>({r,g,b});
		scalar_type delta = v - lo;
		scalar_type h = 0;
		scalar_type s = 0;
		if((false == scalar_trait_type::is_small(v))
		   && (false == scalar_trait_type::is_small(delta))) {
			s = delta / v;
			if(v == r) {
				h = (scalar_type(60)/scalar_type(360)) * (g - b) / delta + (g < b ? scalar_type(1) : scalar_type(0));
			}
			if(v == g) {
				h = (scalar_type(60)/scalar_type(360)) * (b - r) / delta + (scalar_type(120)/scalar_type(360));
			}
			if(v == b) {
				h = (scalar_type(60)/scalar_type(360)) * (r - g) / delta + (scalar_type(240)/scalar_type(360));
			}
		}
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(h));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(s));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(v));
	}
};

}
}

namespace color {
namespace check {
namespace _internal {

template<>
struct integrity< ::color::category::hsv_float> {
public:
	typedef ::color::category::hsv_float category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	static bool process(model_type const& m) {
		if(m.template get<0>() < bound_type::template minimum<0>()) {
			return false;
		}
		if(bound_type::template maximum<0>() < m.template get<0>()) {
			return false;
		}
		return true;
	}
};

template<>
struct integrity< ::color::category::hsv_double > {
public:
	typedef ::color::category::hsv_double category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	static bool process(model_type const& m) {
		if(m.template get<0>() < bound_type::template minimum<0>()) {
			return false;
		}
		if(bound_type::template maximum<0>() < m.template get<0>()) {
			return false;
		}
		return true;
	}
};

template<>
struct integrity< ::color::category::hsv_ldouble > {
public:
	typedef ::color::category::hsv_ldouble category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	static bool process(model_type const& m) {
		if(m.template get<0>() < bound_type::template minimum<0>()) {
			return false;
		}
		if(bound_type::template maximum<0>() < m.template get<0>()) {
			return false;
		}
		return true;
	}
};

}
}
}

namespace color {
namespace check {
namespace _internal {

template< typename category_name >
struct unique {
public:
	typedef category_name category_type;

	typedef ::color::_internal::model<category_type> model_type;

	static bool process(model_type const& m) {
		return true;
	}

};
}

template< typename category_name >
inline
bool unique(::color::_internal::model<category_name> const& m) {
	return ::color::check::_internal::unique<category_name>::process(m);
}

}
}

namespace color {
namespace check {
namespace _internal {

template< typename tag_name >
struct unique< ::color::category::hsv< tag_name > > {
public:
	typedef ::color::category::hsv< tag_name > category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	static bool process(model_type const& m) {
		if(m.template get<1>() == bound_type::template minimum<1>()) {
			return false;
		}
		if(m.template get<2>() == bound_type::template minimum<2>()) {
			return false;
		}
		if(m.template get<2>() == bound_type::template maximum<2>()) {
			return false;
		}
		return true;
	}
};

}
}
}

namespace color {
namespace fix {
namespace _internal {

template< typename category_name >
struct unique {
public:
	typedef category_name category_type;

	typedef ::color::_internal::model<category_type> model_type;

	static void process(model_type & m) {
	}

	static void process(model_type & result, model_type const& right) {
	}
};

}

template< typename category_name >
void unique
(
	::color::_internal::model<category_name> & result
) {
	::color::fix::_internal::unique<category_name>::process(result);
}

template< typename category_name >
void unique
(
	::color::_internal::model<category_name> & result
	,::color::_internal::model<category_name> const& right
) {
	::color::fix::_internal::unique<category_name>::process(result, right);
}

}
}

namespace color {
namespace fix {
namespace _internal {

template< typename tag_name >
struct unique< ::color::category::hsv< tag_name > > {
public:
	typedef ::color::category::hsv< tag_name > category_type;

	typedef typename ::color::_internal::model<category_type> model_type;
	typedef typename ::color::trait::bound<category_type> bound_type;

	static void process(model_type &result) {
		if(result.template get<2>() == bound_type::template minimum<2>()) {
			result.template set<0>(bound_type::template minimum<0>());
			result.template set<1>(bound_type::template minimum<1>());
			return;
		}
		if(result.template get<1>() == bound_type::template minimum<1>()) {
			result.template set<0>(bound_type::template minimum<0>());
			return;
		}
	}

	static void process(model_type &result, model_type const& right) {
		if(result.template get<2>() == bound_type::template minimum<2>()) {
			result.template set<0>(bound_type::template minimum<0>());
			result.template set<1>(bound_type::template minimum<1>());
			return;
		}
		if(result.template get<1>() == bound_type::template minimum<1>()) {
			result.template set<0>(bound_type::template minimum<0>());
			return;
		}
		result = right;
		return;
	}

};

}
}
}

namespace color {
namespace fix {
namespace _internal {

template< typename category_name >
struct integrity {
public:
	typedef category_name category_type;

	typedef ::color::_internal::model<category_type> model_type;

	static void process(model_type & m) {
	}

	static void process(model_type & result, model_type const& right) {
	}
};
}

template< typename category_name >
void integrity
(
	::color::_internal::model<category_name> & result
) {
	::color::fix::_internal::integrity<category_name>::process(result);
}

template< typename category_name >
void integrity
(
	::color::_internal::model<category_name> & result
	,::color::_internal::model<category_name> const& right
) {
	::color::fix::_internal::integrity<category_name>::process(result, right);
}

}
}

namespace color {
namespace fix {
namespace _internal {
namespace _privateHSV {

template< typename category_name >
struct integrity {
public:
	typedef category_name category_type;

	typedef typename ::color::_internal::model<category_type> model_type;
	typedef typename ::color::trait::bound<category_type> bound_type;

	static void process(model_type &result) {
		if(result.template get<0>() < bound_type::template minimum<0>()) {
			result.template set<0>(bound_type::template minimum<0>());
			return;
		}
		if(bound_type::template maximum<0>() < result.template get<0>()) {
			result.template set<0>(bound_type::template maximum<0>());
			return;
		}
	}

	static void process(model_type &result, model_type const& right) {
		result = right;
		if(result.template get<0>() < bound_type::template minimum<0>()) {
			result.template set<0>(bound_type::template minimum<0>());
			return;
		}
		if(bound_type::template maximum<0>() < result.template get<0>()) {
			result.template set<0>(bound_type::template maximum<0>());
			return;
		}
	}

};

}

template<> struct integrity< ::color::category::hsv_float > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_float > { };
template<> struct integrity< ::color::category::hsv_double > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_double > { };
template<> struct integrity< ::color::category::hsv_ldouble > : public ::color::fix::_internal::_privateHSV::integrity<::color::category::hsv_ldouble> { };

}
}
}

namespace color {
namespace _internal {

template< typename type_name >
struct pick_hsv {
	typedef ::color::category::hsv_uint32 category_type;
};

template<> struct pick_hsv< std::uint8_t > {
	typedef ::color::category::hsv_uint8 category_type;
};
template<> struct pick_hsv< std::uint16_t > {
	typedef ::color::category::hsv_uint16 category_type;
};
template<> struct pick_hsv< std::uint32_t > {
	typedef ::color::category::hsv_uint32 category_type;
};
template<> struct pick_hsv< std::uint64_t > {
	typedef ::color::category::hsv_uint64 category_type;
};
template<> struct pick_hsv< float > {
	typedef ::color::category::hsv_float category_type;
};
template<> struct pick_hsv< double > {
	typedef ::color::category::hsv_double category_type;
};
template<> struct pick_hsv< long double > {
	typedef ::color::category::hsv_ldouble category_type;
};
}

template< typename type_name >
using hsv = ::color::_internal::model< typename ::color::_internal::pick_hsv< type_name >::category_type >;

}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename hsv_tag_name >
struct convert
		<
		::color::category::hsl< hsl_tag_name >
		,::color::category::hsv< hsv_tag_name >
		> {
public:
	typedef ::color::category::hsl< hsl_tag_name > category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type ss = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type v = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type l = v * (2-ss) / 2;
		scalar_type s = 0 ;
		{
			s = v*ss/(1- fabs(2 * l - 1));
		}
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(h));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(s));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(l));
	}
};

}
}

namespace color {
namespace _internal {

template< typename hsl_tag_name, typename rgb_tag_name >
struct convert
		<
		::color::category::hsl< hsl_tag_name >
		,::color::category::rgb< rgb_tag_name >
		> {
public:
	typedef ::color::category::hsl< hsl_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar<category_left_type> scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_right_type>::position_enum
					,green_p = ::color::place::_internal::green<category_right_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		const scalar_type hi = std::max<scalar_type>({ r, g, b });
		const scalar_type lo = std::min<scalar_type>({ r, g, b });
		scalar_type delta = hi - lo;
		scalar_type h = 0;
		scalar_type s = 0;
		scalar_type l = (hi + lo) / scalar_type(2);
		if(false == scalar_trait_type::is_small(delta)) {
			s = delta / (1 - fabs(2*l - 1));
			if(hi == r) {
				h = (scalar_type(60)/scalar_type(360)) * (g - b) / delta + (g < b ? scalar_type(1) : scalar_type(0));
			}
			if(hi == g) {
				h = (scalar_type(60)/scalar_type(360)) * (b - r) / delta + (scalar_type(120)/scalar_type(360));
			}
			if(hi == b) {
				h = (scalar_type(60)/scalar_type(360)) * (r - g) / delta + (scalar_type(240)/scalar_type(360));
			}
		}
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(h));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(s));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(l));
	}
};

}
}

namespace color {
namespace check {
namespace _internal {

template<>
struct integrity< ::color::category::hsl_float> {
public:
	typedef ::color::category::hsl_float category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	static bool process(model_type const& m) {
		if(m.template get<0>() < bound_type::template minimum<0>()) {
			return false;
		}
		if(bound_type::template maximum<0>() < m.template get<0>()) {
			return false;
		}
		return true;
	}
};

template<>
struct integrity< ::color::category::hsl_double > {
public:
	typedef ::color::category::hsl_double category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	static bool process(model_type const& m) {
		if(m.template get<0>() < bound_type::template minimum<0>()) {
			return false;
		}
		if(bound_type::template maximum<0>() < m.template get<0>()) {
			return false;
		}
		return true;
	}
};

template<>
struct integrity< ::color::category::hsl_ldouble > {
public:
	typedef ::color::category::hsl_ldouble category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	static bool process(model_type const& m) {
		if(m.template get<0>() < bound_type::template minimum<0>()) {
			return false;
		}
		if(bound_type::template maximum<0>() < m.template get<0>()) {
			return false;
		}
		return true;
	}
};

}
}
}

namespace color {
namespace check {
namespace _internal {

template< typename tag_name >
struct unique< ::color::category::hsl< tag_name> > {
public:
	typedef ::color::category::hsl<tag_name> category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;

	static bool process(model_type const& m) {
		if(m.template get<1>() == bound_type::template minimum<1>()) {
			return false;
		}
		if(m.template get<2>() == bound_type::template minimum<2>()) {
			return false;
		}
		if(m.template get<2>() == bound_type::template maximum<2>()) {
			return false;
		}
		return true;
	}
};

}
}
}

namespace color {
namespace _internal {

template< typename type_name >
struct pick_hsl {
	typedef ::color::category::hsl_uint32 category_type;
};

template<> struct pick_hsl< std::uint8_t > {
	typedef ::color::category::hsl_uint8 category_type;
};
template<> struct pick_hsl< std::uint16_t > {
	typedef ::color::category::hsl_uint16 category_type;
};
template<> struct pick_hsl< std::uint32_t > {
	typedef ::color::category::hsl_uint32 category_type;
};
template<> struct pick_hsl< std::uint64_t > {
	typedef ::color::category::hsl_uint64 category_type;
};
template<> struct pick_hsl< float > {
	typedef ::color::category::hsl_float category_type;
};
template<> struct pick_hsl< double > {
	typedef ::color::category::hsl_double category_type;
};
template<> struct pick_hsl< long double > {
	typedef ::color::category::hsl_ldouble category_type;
};
}

template< typename type_name >
using hsl = ::color::_internal::model< typename ::color::_internal::pick_hsl< type_name >::category_type >;

}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename hsl_tag_name >
struct convert
		<
		::color::category::rgb< rgb_tag_name >
		,::color::category::hsl<hsl_tag_name>
		> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::hsl<hsl_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::_internal::convert< category_left_type, category_right_type > this_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_left_type>::position_enum
					,green_p = ::color::place::_internal::green<category_left_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
		};
		scalar_type h = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type s = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type l = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type r;
		scalar_type g;
		scalar_type b;
		if(s == 0) {
			r = l;
			g = l;
			b = l;
		} else {
			scalar_type q = l < scalar_type(0.5) ? (l * (1 + s)) : (l + s - l * s);
			scalar_type p = scalar_type(2) * l - q;
			r = this_type::value(p, q, h + (scalar_type(1) / scalar_type(3)) + (scalar_type(2) / scalar_type(3) < h ? -1 :0));
			g = this_type::value(p, q, h);
			b = this_type::value(p, q, h - (scalar_type(1) / scalar_type(3)) + (h < scalar_type(1) / scalar_type(3) ? +1 :0));
		}
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}

private:
	static scalar_type value(scalar_type const& p, scalar_type const& q, scalar_type const& t) {
		if(t < scalar_type(1)/scalar_type(6)) {
			return (p + (q - p) * scalar_type(6) * t);
		}
		if(t < scalar_type(1)/scalar_type(2)) {
			return (q);
		}
		if(t < scalar_type(2)/scalar_type(3)) {
			return (p + (q - p) * ((scalar_type(2)/scalar_type(3)) - t) * scalar_type(6));
		}
		return p ;
	}
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename hsv_tag_name >
struct convert
		<
		::color::category::rgb< rgb_tag_name >
		,::color::category::hsv< hsv_tag_name >
		> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::hsv< hsv_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_left_type>::position_enum
					,green_p = ::color::place::_internal::green<category_left_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
		};
		scalar_type h = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type s = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type v = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		int region = int(6 * h);
		scalar_type f = h * 6 - region ;
		scalar_type p = v * (1 - s);
		scalar_type q = v * (1 - f * s);
		scalar_type t = v * (1 - (1 - f) * s);
		scalar_type r;
		scalar_type g;
		scalar_type b;
		switch(region % 6) {
		case 0:
			r = v, g = t, b = p;
			break;
		case 1:
			r = q, g = v, b = p;
			break;
		case 2:
			r = p, g = v, b = t;
			break;
		case 3:
			r = p, g = q, b = v;
			break;
		case 4:
			r = t, g = p, b = v;
			break;
		case 5:
			r = v, g = p, b = q;
			break;
		}
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
		<
		::color::category::rgb< tag_left_name >
		,::color::category::rgb< tag_right_name>
		> {
public:
	typedef ::color::category::rgb< tag_left_name > category_left_type;
	typedef ::color::category::rgb< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			rl = ::color::place::_internal::red<category_left_type>::position_enum
				 ,gl = ::color::place::_internal::green<category_left_type>::position_enum
					   ,bl = ::color::place::_internal::blue<category_left_type>::position_enum
							 ,rr = ::color::place::_internal::red<category_right_type>::position_enum
								   ,gr = ::color::place::_internal::green<category_right_type>::position_enum
										 ,br = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		container_left_trait_type::template set<rl>(left, reformat_type::template process<rl,rr>(container_right_trait_type::template get<rr>(right)));
		container_left_trait_type::template set<gr>(left, reformat_type::template process<gr,gr>(container_right_trait_type::template get<gr>(right)));
		container_left_trait_type::template set<bl>(left, reformat_type::template process<bl,br>(container_right_trait_type::template get<br>(right)));
	}
};
}
}

namespace color {
namespace category {

namespace _internal {
struct xyz_bool {};
struct xyz_uint8 {};
struct xyz_uint16 {};
struct xyz_uint24 {};
struct xyz_uint32 {};
struct xyz_uint48 {};
struct xyz_uint64 {};
struct xyz_float {};
struct xyz_double {};
struct xyz_ldouble {};
}

template< typename tag_name >
struct xyz {
	typedef void category_name;
};

using xyz_bool = xyz< ::color::category::_internal::xyz_bool >;
using xyz_uint8 = xyz< ::color::category::_internal::xyz_uint8 >;
using xyz_uint16 = xyz< ::color::category::_internal::xyz_uint16 >;
using xyz_uint24 = xyz< ::color::category::_internal::xyz_uint24 >;
using xyz_uint32 = xyz< ::color::category::_internal::xyz_uint32 >;
using xyz_uint48 = xyz< ::color::category::_internal::xyz_uint48 >;
using xyz_uint64 = xyz< ::color::category::_internal::xyz_uint64 >;
using xyz_float = xyz< ::color::category::_internal::xyz_float >;
using xyz_double = xyz< ::color::category::_internal::xyz_double >;
using xyz_ldouble = xyz< ::color::category::_internal::xyz_ldouble >;

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::xyz_uint8 >
		: public ::color::_internal::utility::bound::bound332< unsigned > {
};

template< >
struct index< ::color::category::xyz_uint8 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

template< >
struct component< ::color::category::xyz_uint8 >
		: public ::color::_internal::utility::component::cnent332< unsigned > {
};

template< >
struct container< ::color::category::xyz_uint8 >
		: public ::color::_internal::utility::container::cner332< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::xyz_uint16 >
		: public ::color::_internal::utility::bound::bound556< unsigned > {
};

template< >
struct index< ::color::category::xyz_uint16 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

template< >
struct component< ::color::category::xyz_uint16 >
		: public ::color::_internal::utility::component::cnent556< unsigned> {
};

template< >
struct container< ::color::category::xyz_uint16 >
		: public ::color::_internal::utility::container::cner556< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::xyz_uint32 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 8, unsigned > {
};

template< >
struct index< ::color::category::xyz_uint32 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

template< >
struct component< ::color::category::xyz_uint32 >
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned> {
};

template< >
struct container< ::color::category::xyz_uint32 >
		: public ::color::_internal::utility::container::Unsigned< std::uint32_t, std::uint8_t, unsigned, 3, 8 > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::xyz_uint64 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 16, unsigned > {
};

template< >
struct index< ::color::category::xyz_uint64 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

template< >
struct component< ::color::category::xyz_uint64 >
		: public ::color::_internal::utility::component::Unsigned< std::uint16_t, unsigned> {
};

template< >
struct container< ::color::category::xyz_uint64 >
		: public ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint16_t, unsigned, 3, 16 > {
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct xyz_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 1/scalar_type(0.17697), 1/scalar_type(0.17697), 1/scalar_type(0.17697) };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 1/scalar_type(0.17697), 1/scalar_type(0.17697), 1/scalar_type(0.17697) };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, 0, 0 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 1/scalar_type(0.17697), 1/scalar_type(0.17697), 1/scalar_type(0.17697) };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 1/scalar_type(0.17697), 1/scalar_type(0.17697), 1/scalar_type(0.17697) };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::xyz_float >
		: public ::color::_internal::utility::bound::xyz_scalar< unsigned, float > {
};

template< >
struct index< ::color::category::xyz_float >
		: public ::color::_internal::utility::type::index< unsigned > {
};

template< >
struct component< ::color::category::xyz_float >
		: public ::color::_internal::utility::component::array< float, unsigned> {
};

template< >
struct container< ::color::category::xyz_float >
		: public ::color::_internal::utility::container::array< float, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::xyz_double >
		: public ::color::_internal::utility::bound::xyz_scalar< unsigned, double > {
};

template< >
struct index< ::color::category::xyz_double >
		: public ::color::_internal::utility::type::index< unsigned > {
};

template< >
struct component< ::color::category::xyz_double >
		: public ::color::_internal::utility::component::array< double, unsigned > {
};

template< >
struct container< ::color::category::xyz_double >
		: public ::color::_internal::utility::container::array< double, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::xyz_ldouble >
		: public ::color::_internal::utility::bound::xyz_scalar< unsigned, long double > {
};

template< >
struct index< ::color::category::xyz_ldouble >
		: public ::color::_internal::utility::type::index< unsigned > {
};

template< >
struct component< ::color::category::xyz_ldouble >
		: public ::color::_internal::utility::component::array< long double, unsigned> {
};

template< >
struct container< ::color::category::xyz_ldouble >
		: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace make {

inline
void black(::color::_internal::model< color::category::xyz_uint8 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void black(::color::_internal::model< color::category::xyz_uint16 > & color_parameter) {
	color_parameter.container() = 0x0;
}

inline
void black(::color::_internal::model< color::category::xyz_uint32 > & color_parameter) {
	color_parameter.container() = 0xff000000u;
}

inline
void black(::color::_internal::model< color::category::xyz_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff000000000000ul;
}

inline
void black(::color::_internal::model< color::category::xyz_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::xyz_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::xyz_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void gray50(::color::_internal::model< color::category::xyz_uint8 > & color_parameter) {
	color_parameter.container() = 0x1b;
}

inline
void gray50(::color::_internal::model< color::category::xyz_uint16 > & color_parameter) {
	color_parameter.container() = 0xc6f7;
}

inline
void gray50(::color::_internal::model< color::category::xyz_uint32 > & color_parameter) {
	color_parameter.container() = 0xffd0d0d0u;
}

inline
void gray50(::color::_internal::model< color::category::xyz_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffd346d346d346ul;
}

inline
void gray50(::color::_internal::model< color::category::xyz_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 15.9651, 15.9651, 15.9651 });
}

inline
void gray50(::color::_internal::model< color::category::xyz_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 15.9651, 15.9651, 15.9651 });
}

inline
void gray50(::color::_internal::model< color::category::xyz_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 15.9651, 15.9651, 15.9651 });
}

}
}

namespace color {
namespace make {

inline
void white(::color::_internal::model< color::category::xyz_uint8 > & color_parameter) {
	color_parameter.container() = 0x3f;
}

inline
void white(::color::_internal::model< color::category::xyz_uint16 > & color_parameter) {
	color_parameter.container() = 0x8def;
}

inline
void white(::color::_internal::model< color::category::xyz_uint32 > & color_parameter) {
	color_parameter.container() = 0xffa0a0a0u;
}

inline
void white(::color::_internal::model< color::category::xyz_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffa68da68da68dul;
}

inline
void white(::color::_internal::model< color::category::xyz_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 31.9301, 31.9301, 31.9301 });
}

inline
void white(::color::_internal::model< color::category::xyz_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 31.9301, 31.9301, 31.9301 });
}

inline
void white(::color::_internal::model< color::category::xyz_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 31.9301, 31.9301, 31.9301 });
}

}
}

namespace color {
namespace make {

inline
void red(::color::_internal::model< color::category::xyz_uint8 > & color_parameter) {
	color_parameter.container() = 0x3b;
}

inline
void red(::color::_internal::model< color::category::xyz_uint16 > & color_parameter) {
	color_parameter.container() = 0x3f5;
}

inline
void red(::color::_internal::model< color::category::xyz_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00ffc2u;
}

inline
void red(::color::_internal::model< color::category::xyz_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000ffffc4cful;
}

inline
void red(::color::_internal::model< color::category::xyz_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 15.6458, 5.65068, 0 });
}

inline
void red(::color::_internal::model< color::category::xyz_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 15.6458, 5.65068, 0 });
}

inline
void red(::color::_internal::model< color::category::xyz_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 15.6458, 5.65068, 0 });
}

}
}

namespace color {
namespace make {

inline
void green(::color::_internal::model< color::category::xyz_uint8 > & color_parameter) {
	color_parameter.container() = 0x6;
}

inline
void green(::color::_internal::model< color::category::xyz_uint16 > & color_parameter) {
	color_parameter.container() = 0x4fb;
}

inline
void green(::color::_internal::model< color::category::xyz_uint32 > & color_parameter) {
	color_parameter.container() = 0xff0749dfu;
}

inline
void green(::color::_internal::model< color::category::xyz_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff073b4b96e037ul;
}

inline
void green(::color::_internal::model< color::category::xyz_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 4.94917, 12.97, 0.159651 });
}

inline
void green(::color::_internal::model< color::category::xyz_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 4.94917, 12.97, 0.159651 });
}

inline
void green(::color::_internal::model< color::category::xyz_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 4.94917, 12.97, 0.159651 });
}

}
}

namespace color {
namespace make {

inline
void blue(::color::_internal::model< color::category::xyz_uint8 > & color_parameter) {
	color_parameter.container() = 0x7;
}

inline
void blue(::color::_internal::model< color::category::xyz_uint16 > & color_parameter) {
	color_parameter.container() = 0x8023;
}

inline
void blue(::color::_internal::model< color::category::xyz_uint32 > & color_parameter) {
	color_parameter.container() = 0xff920f20u;
}

inline
void blue(::color::_internal::model< color::category::xyz_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff98150f60214ful;
}

inline
void blue(::color::_internal::model< color::category::xyz_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 6.38603, 0.339417, 31.6108 });
}

inline
void blue(::color::_internal::model< color::category::xyz_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 6.38603, 0.339417, 31.6108 });
}

inline
void blue(::color::_internal::model< color::category::xyz_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 6.38603, 0.339417, 31.6108 });
}

}
}

namespace color {
namespace _internal {

template< typename xyz_tag_name, typename gray_tag_name >
struct convert
		<
		::color::category::xyz< xyz_tag_name >
		,::color::category::gray< gray_tag_name >
		> {
public:
	typedef ::color::category::xyz< xyz_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
	}
};

}
}

namespace color {
namespace _internal {

template< typename xyz_tag_name, typename rgb_tag_name >
struct convert
		<
		::color::category::xyz< xyz_tag_name >
		,::color::category::rgb< rgb_tag_name >
		> {
public:
	typedef ::color::category::xyz< xyz_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_right_type>::position_enum
					,green_p = ::color::place::_internal::green<category_right_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		static scalar_type mc = 0.17697;
		static scalar_type b11 = 0.49000/mc, b12 = 0.31000/mc, b13 = 0.20000/mc;
		static scalar_type b21 = 0.17697/mc, b22 = 0.81240/mc, b23 = 0.01063/mc;
		static scalar_type b31 = 0.00000/mc, b32 = 0.01000/mc, b33 = 0.99000/mc;
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(b11 * r + b12 * g + b13 * b));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(b21 * r + b22 * g + b23 * b));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(b31 * r + b32 * g + b33 * b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
		<
		::color::category::xyz< tag_left_name >
		,::color::category::xyz< tag_right_name>
		> {
public:
	typedef ::color::category::xyz< tag_left_name > category_left_type;
	typedef ::color::category::xyz< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};
}
}

namespace color {
namespace _internal {
template< typename type_name >
struct pick_xyz {
	typedef ::color::category::xyz_uint32 category_type;
};

template<> struct pick_xyz< std::uint8_t > {
	typedef ::color::category::xyz_uint8 category_type;
};
template<> struct pick_xyz< std::uint16_t > {
	typedef ::color::category::xyz_uint16 category_type;
};
template<> struct pick_xyz< std::uint32_t > {
	typedef ::color::category::xyz_uint32 category_type;
};
template<> struct pick_xyz< std::uint64_t > {
	typedef ::color::category::xyz_uint64 category_type;
};
template<> struct pick_xyz< float > {
	typedef ::color::category::xyz_float category_type;
};
template<> struct pick_xyz< double > {
	typedef ::color::category::xyz_double category_type;
};
template<> struct pick_xyz< long double > {
	typedef ::color::category::xyz_ldouble category_type;
};
}

template< typename type_name >
using xyz = ::color::_internal::model< typename ::color::_internal::pick_xyz< type_name >::category_type >;

}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename xyz_tag_name >
struct convert
		<
		::color::category::rgb< rgb_tag_name >
		,::color::category::xyz<xyz_tag_name>
		> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::xyz<xyz_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_left_type>::position_enum
					,green_p = ::color::place::_internal::green<category_left_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
		};
		static scalar_type mc = 0.17697;
		static scalar_type b11 = 473041/scalar_type(200050)*mc, b12 = -60980/scalar_type(68017)*mc, b13 = -1591847/scalar_type(3400850)*mc;
		static scalar_type b21 = -103059/scalar_type(200050)*mc, b22 = 97020/scalar_type(68017)*mc, b23 = 301853/scalar_type(3400850)*mc;
		static scalar_type b31 = 1041/scalar_type(200050)*mc, b32 = -980/scalar_type(68017)*mc, b33 = 3432153/scalar_type(3400850)*mc;
		scalar_type x = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type y = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type z = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(b11 * x + b12 * y + b13 * z));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(b21 * x + b22 * y + b23 * z));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b31 * x + b32 * y + b33 * z));
	}
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::yiq_double >
		: public ::color::_internal::utility::container::array< double, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::yiq_float >
		: public ::color::_internal::utility::container::array< float, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::yiq_ldouble >
		: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::yiq_uint16 >
		: public ::color::_internal::utility::container::cner556< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::yiq_uint32 >
		: public ::color::_internal::utility::container::Unsigned< std::uint32_t, std::uint8_t, unsigned, 3, 8 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::yiq_uint64 >
		: public ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint16_t, unsigned, 3, 16 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::yiq_uint8 >
		: public ::color::_internal::utility::container::cner332< unsigned > {
};

}
}

namespace color {
namespace _internal {

template< typename rgb_tag_name, typename yiq_tag_name >
struct convert
		<
		::color::category::rgb< rgb_tag_name >
		,::color::category::yiq<yiq_tag_name>
		> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::yiq<yiq_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::yiq< category_right_type > yiq_const_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_left_type>::position_enum
					,green_p = ::color::place::_internal::green<category_left_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
		};
		static scalar_type a11 = yiq_const_type::a11(), a12 = yiq_const_type::a12(), a13 = yiq_const_type::a13();
		static scalar_type a21 = yiq_const_type::a21(), a22 = yiq_const_type::a22(), a23 = yiq_const_type::a23();
		static scalar_type a31 = yiq_const_type::a31(), a32 = yiq_const_type::a32(), a33 = yiq_const_type::a33();
		scalar_type y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type i = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type q = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		i = yiq_const_type::i_deverse(i);
		q = yiq_const_type::q_deverse(q);
		scalar_type r = a11 * y + a12 * i + a13 * q;
		scalar_type g = a21 * y + a22 * i + a23 * q;
		scalar_type b = a31 * y + a32 * i + a33 * q;
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::yuv_double >
		: public ::color::_internal::utility::container::array< double, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::yuv_float >
		: public ::color::_internal::utility::container::array< float, 3 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::yuv_ldouble >
		: public ::color::_internal::utility::container::array< long double, 3 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::yuv_uint16 >
		: public ::color::_internal::utility::container::cner556< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::yuv_uint32 >
		: public ::color::_internal::utility::container::Unsigned< std::uint32_t, std::uint8_t, unsigned, 3, 8 > {
};

}
}
namespace color {
namespace trait {

template< >
struct container< ::color::category::yuv_uint64 >
		: public ::color::_internal::utility::container::Unsigned< std::uint64_t, std::uint16_t, unsigned, 3, 16 > {
};

}
}

namespace color {
namespace trait {

template< >
struct container< ::color::category::yuv_uint8 >
		: public ::color::_internal::utility::container::cner332< unsigned > {
};

}
}

namespace color {
namespace constant {

template< typename category_name >
struct yuv {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::constant::yuv<category_type> this_type;

	static scalar_type const half() {
		return 0.5;
	}
	static scalar_type const one() {
		return 1;
	}
	static scalar_type const Wr() {
		return 0.299;
	}
	static scalar_type const Wb() {
		return 0.114;
	}
	static scalar_type const Wg() {
		return this_type::one() - this_type::Wr()-this_type::Wb();
	}
	static scalar_type const Umax() {
		return 0.436;
	}
	static scalar_type const Vmax() {
		return 0.615;
	}

	static scalar_type const u_min() {
		return -this_type::Umax();
	}
	static scalar_type const u_max() {
		return this_type::Umax();
	}
	static scalar_type const u_range() {
		return 2*this_type::Umax();
	}

	static scalar_type const v_min() {
		return -this_type::Vmax();
	}
	static scalar_type const v_max() {
		return this_type::Vmax();
	}
	static scalar_type const v_range() {
		return 2*this_type::Vmax();
	}

	static scalar_type u_deverse(scalar_type const& normal) {
		return this_type::u_range() * normal + this_type::u_min();
	}
	static scalar_type u_normalize(scalar_type const& divert) {
		return (divert + this_type::u_min()) /this_type::u_range();
	}

	static scalar_type v_deverse(scalar_type const& normal) {
		return this_type::v_range() * normal + this_type::v_min();
	}
	static scalar_type v_normalize(scalar_type const& divert) {
		return (divert + this_type::v_min()) /this_type::v_range();
	}
};

}
}
namespace color {
namespace _internal {

template< typename rgb_tag_name, typename yuv_tag_name >
struct convert
		<
		::color::category::rgb< rgb_tag_name >
		,::color::category::yuv< yuv_tag_name>
		> {
public:
	typedef ::color::category::rgb< rgb_tag_name > category_left_type;
	typedef ::color::category::yuv<yuv_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::yuv< category_right_type > yuv_const_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_left_type>::position_enum
					,green_p = ::color::place::_internal::green<category_left_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_left_type>::position_enum
		};
		static scalar_type const Wr = yuv_const_type::Wr();
		static scalar_type const Wb = yuv_const_type::Wb();
		static scalar_type const Wg = yuv_const_type::Wg();
		static scalar_type const Umax = yuv_const_type::Umax();
		static scalar_type const Vmax = yuv_const_type::Vmax();
		static scalar_type const b11 = 1, b12 = 0, b13 = (1 - Wr) / Vmax;
		static scalar_type const b21 = 1, b22 = - Wb*(1 - Wb) / Umax / Wg, b23 = -Wr*(1 - Wr) / Vmax / Wg;
		static scalar_type const b31 = 1, b32 = ((1 - Wb) / Umax), b33 = 0;
		scalar_type y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type u = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type v = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		u = (u - scalar_type(0.5)) * scalar_type(2) * Umax;
		v = (v - scalar_type(0.5)) * scalar_type(2) * Vmax;
		scalar_type r = y + v * b13;
		scalar_type g = y + u * b22 + v * b23;
		scalar_type b = y + u * b32;
		container_left_trait_type::template set<red_p >(left, diverse_type::template process<red_p >(r));
		container_left_trait_type::template set<green_p>(left, diverse_type::template process<green_p>(g));
		container_left_trait_type::template set<blue_p >(left, diverse_type::template process<blue_p >(b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename type_name >
struct pick_rgb {
	typedef ::color::category::rgb_uint32 category_type;
};

template<> struct pick_rgb< std::uint8_t > {
	typedef ::color::category::rgb_uint8 category_type;
};
template<> struct pick_rgb< std::uint16_t > {
	typedef ::color::category::rgb_uint16 category_type;
};
template<> struct pick_rgb< std::uint32_t > {
	typedef ::color::category::rgb_uint32 category_type;
};
template<> struct pick_rgb< std::uint64_t > {
	typedef ::color::category::rgb_uint64 category_type;
};
template<> struct pick_rgb< float > {
	typedef ::color::category::rgb_float category_type;
};
template<> struct pick_rgb< double > {
	typedef ::color::category::rgb_double category_type;
};
template<> struct pick_rgb< long double > {
	typedef ::color::category::rgb_ldouble category_type;
};

template<> struct pick_rgb< ::color::type::uint24_t > {
	typedef ::color::category::rgb_uint24 category_type;
};
template<> struct pick_rgb< ::color::type::uint48_t > {
	typedef ::color::category::rgb_uint48 category_type;
};

}

template< typename type_name >
using rgb = ::color::_internal::model< typename ::color::_internal::pick_rgb< type_name >::category_type >;

template< typename value_name >
using bgr = ::color::_internal::model< ::color::category::rgb< ::color::category::rgb_scramble< value_name, 2, 1, 0 > > >;

template< typename value_name >
using bgra = ::color::_internal::model< ::color::category::rgb< ::color::category::rgba_scramble< value_name, 2, 1, 0, 3 > > >;

template< typename value_name >
using abgr = ::color::_internal::model< ::color::category::rgb< ::color::category::rgba_scramble< value_name, 3, 2, 1, 0 > > >;

template< typename value_name >
using rgba = ::color::_internal::model< ::color::category::rgb< ::color::category::rgba_scramble< value_name, 0, 1, 2, 3 > > >;

template< typename value_name >
using argb = ::color::_internal::model< ::color::category::rgb< ::color::category::rgba_scramble< value_name, 1, 2, 3, 0 > > >;

}

namespace color {
namespace _internal {

template< typename cmyk_tag_name, typename rgb_tag_name >
struct convert
		<
		::color::category::cmyk< cmyk_tag_name >
		,::color::category::rgb< rgb_tag_name >
		> {
public:
	typedef ::color::category::cmyk< cmyk_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::scalar< category_left_type > scalar_trait_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_right_type>::position_enum
					,green_p = ::color::place::_internal::green<category_right_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type k = scalar_type(1) - std::max({ r, g, b });
		scalar_type c = scalar_type(0);
		scalar_type m = scalar_type(0);
		scalar_type y = scalar_type(0);
		if(false == scalar_trait_type::is_small(1 - k)) {
			c = (1-r-k) / (1-k);
			m = (1-g-k) / (1-k);
			y = (1-b-k) / (1-k);
		}
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(c));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(m));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(y));
		container_left_trait_type::template set<3>(left, diverse_type::template process<3>(k));
	}
};

}
}

namespace color {
namespace check {
namespace _internal {
namespace _privateCMYK {

template< typename category_name >
struct unique {
public:
	typedef category_name category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;
	typedef ::color::trait::scalar< category_type > scalar_trait_type;

	static bool process(model_type const& m) {
		if(m.template get<3>() == bound_type::template maximum<3>()) {
			return false;
		}
		if(m.template get<0>() == bound_type::template minimum<0>()) {
			return true;
		}
		if(m.template get<1>() == bound_type::template minimum<1>()) {
			return true;
		}
		if(m.template get<2>() == bound_type::template minimum<2>()) {
			return true;
		}
		return false;
	}
};

}

template< > struct unique< ::color::category::cmyk_uint8 > : public ::color::check::_internal::_privateCMYK::unique< ::color::category::cmyk_uint8 > { };
template< > struct unique< ::color::category::cmyk_uint16 > : public ::color::check::_internal::_privateCMYK::unique< ::color::category::cmyk_uint16 > { };
template< > struct unique< ::color::category::cmyk_uint32 > : public ::color::check::_internal::_privateCMYK::unique< ::color::category::cmyk_uint32 > { };
template< > struct unique< ::color::category::cmyk_uint64 > : public ::color::check::_internal::_privateCMYK::unique< ::color::category::cmyk_uint64 > { };

template<>
struct unique< ::color::category::cmyk_float> {
public:
	typedef ::color::category::cmyk_float category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;
	typedef ::color::trait::scalar< category_type > scalar_trait_type;

	static bool process(model_type const& m) {
		if(m.template get<3>() == bound_type::template maximum<3>()) {
			return false;
		}
		if(true == scalar_trait_type::is_small(m.template get<0>() - bound_type::template minimum<0>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get<1>() - bound_type::template minimum<1>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get<2>() - bound_type::template minimum<2>())) {
			return true;
		}
		return false;
	}
};

template<>
struct unique< ::color::category::cmyk_double > {
public:
	typedef ::color::category::cmyk_double category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;
	typedef ::color::trait::scalar< category_type > scalar_trait_type;

	static bool process(model_type const& m) {
		if(m.template get<3>() == bound_type::template maximum<3>()) {
			return false;
		}
		if(true == scalar_trait_type::is_small(m.template get<0>() - bound_type::template minimum<0>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get<1>() - bound_type::template minimum<1>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get<2>() - bound_type::template minimum<2>())) {
			return true;
		}
		return false;
	}
};

template<>
struct unique< ::color::category::cmyk_ldouble > {
public:
	typedef ::color::category::cmyk_ldouble category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound< category_type > bound_type;
	typedef ::color::trait::scalar< category_type > scalar_trait_type;

	static bool process(model_type const& m) {
		if(m.template get<3>() == bound_type::template maximum<3>()) {
			return false;
		}
		if(true == scalar_trait_type::is_small(m.template get<0>() - bound_type::template minimum<0>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get<1>() - bound_type::template minimum<1>())) {
			return true;
		}
		if(true == scalar_trait_type::is_small(m.template get<2>() - bound_type::template minimum<2>())) {
			return true;
		}
		return false;
	}
};

}
}
}

namespace color {
namespace fix {
namespace _internal {

template< typename tag_name >
struct unique< ::color::category::cmyk< tag_name > > {
public:
	typedef ::color::category::cmyk< tag_name > category_type;

	typedef ::color::_internal::model<category_type> model_type;
	typedef ::color::trait::bound<category_type> bound_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef ::color::operation::_internal::invert< category_type > invert_type;
	typedef ::color::_internal::diverse< category_type > diverse_type;
	typedef ::color::_internal::normalize< category_type > normalize_type;

	static void process(model_type &result) {
		if(result.template get<3>() == bound_type::template maximum<3>()) {
			result.template set<0>(bound_type::template minimum<0>());
			result.template set<1>(bound_type::template minimum<1>());
			result.template set<2>(bound_type::template minimum<2>());
			return ;
		}
		if(result.template get<0>() != result.template get<1>()) {
			return;
		}
		if(result.template get<0>() != result.template get<2>()) {
			return;
		}
		if(result.template get<1>() != result.template get<2>()) {
			return;
		}
		scalar_type cyan = normalize_type::template process<0>(result.template get<0>());
		scalar_type key = normalize_type::template process<3>(result.template get<3>());
		result.template set<0>(bound_type::template minimum<0>());
		result.template set<1>(bound_type::template minimum<1>());
		result.template set<2>(bound_type::template minimum<2>());
		result.template set<3>(diverse_type::template process<3>((1- (1- cyan)*(1-key))));
	}

	static void process(model_type &result, model_type const& right) {
		if(result.template get<3>() == bound_type::template maximum<3>()) {
			result.template set<0>(bound_type::template minimum<0>());
			result.template set<1>(bound_type::template minimum<1>());
			result.template set<2>(bound_type::template minimum<2>());
			result.template set<3>(bound_type::template maximum<3>());
			return ;
		}
		result = right;
		if(result.template get<0>() != result.template get<1>()) {
			return;
		}
		if(result.template get<0>() != result.template get<2>()) {
			return;
		}
		if(result.template get<1>() != result.template get<2>()) {
			return;
		}
		scalar_type cyan = normalize_type::template process<0>(result.template get<0>());
		scalar_type key = normalize_type::template process<3>(result.template get<3>());
		result.template set<0>(bound_type::template minimum<0>());
		result.template set<1>(bound_type::template minimum<1>());
		result.template set<2>(bound_type::template minimum<2>());
		result.template set<3>(diverse_type::template process<3>((1- (1- cyan)*(1-key))));
	}

};

}
}
}

namespace color {
namespace _internal {

template< typename type_name >
struct pick_cmyk {
	typedef ::color::category::cmyk_uint32 category_type;
};

template<> struct pick_cmyk< std::uint8_t > {
	typedef ::color::category::cmyk_uint8 category_type;
};
template<> struct pick_cmyk< std::uint16_t > {
	typedef ::color::category::cmyk_uint16 category_type;
};
template<> struct pick_cmyk< std::uint32_t > {
	typedef ::color::category::cmyk_uint32 category_type;
};
template<> struct pick_cmyk< std::uint64_t > {
	typedef ::color::category::cmyk_uint64 category_type;
};
template<> struct pick_cmyk< float > {
	typedef ::color::category::cmyk_float category_type;
};
template<> struct pick_cmyk< double > {
	typedef ::color::category::cmyk_double category_type;
};
template<> struct pick_cmyk< long double > {
	typedef ::color::category::cmyk_ldouble category_type;
};
}

template< typename type_name >
using cmyk = ::color::_internal::model< typename ::color::_internal::pick_cmyk< type_name >::category_type >;

}

namespace color {
namespace _internal {
template< typename cmy_tag_name, typename cmyk_tag_name >
struct convert
		<
		::color::category::cmy< cmy_tag_name >
		,::color::category::cmyk<cmyk_tag_name>
		> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::cmyk<cmyk_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type cc = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type cm = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type cy = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type ck = normalize_type::template process<3>(container_right_trait_type::template get<3>(right));
		scalar_type c = cc * (1-ck) + ck;
		scalar_type m = cm * (1-ck) + ck;
		scalar_type y = cy * (1-ck) + ck;
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(c));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(m));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(y));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename gray_tag_name >
struct convert
		<
		::color::category::cmy< cmy_tag_name >
		,::color::category::gray<gray_tag_name>
		> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::gray<gray_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::operation::_internal::invert< category_right_type > invert_type;
	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(invert_type::template component<0>(container_right_trait_type::template get<0>(right))));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,0>(invert_type::template component<0>(container_right_trait_type::template get<0>(right))));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,0>(invert_type::template component<0>(container_right_trait_type::template get<0>(right))));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename hsl_tag_name >
struct convert
		<
		::color::category::cmy< cmy_tag_name >
		,::color::category::hsl<hsl_tag_name>
		> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::hsl<hsl_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::_internal::convert< category_left_type, category_right_type > this_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type s = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type l = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type r;
		scalar_type g;
		scalar_type b;
		if(s == 0) {
			r = l;
			g = l;
			b = l;
		} else {
			scalar_type q = l < scalar_type(0.5) ? (l * (1 + s)) : (l + s - l * s);
			scalar_type p = scalar_type(2) * l - q;
			r = this_type::value(p, q, h + (scalar_type(1) / scalar_type(3)) + (scalar_type(2) / scalar_type(3) < h ? -1 :0));
			g = this_type::value(p, q, h);
			b = this_type::value(p, q, h - (scalar_type(1) / scalar_type(3)) + (h < scalar_type(1) / scalar_type(3) ? +1 :0));
		}
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(scalar_type(1) - r));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(scalar_type(1) - g));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(scalar_type(1) - b));
	}

private:
	static scalar_type value(scalar_type const& p, scalar_type const& q, scalar_type const& t) {
		if(t < scalar_type(1)/scalar_type(6)) {
			return (p + (q - p) * scalar_type(6) * t);
		}
		if(t < scalar_type(1)/scalar_type(2)) {
			return (q);
		}
		if(t < scalar_type(2)/scalar_type(3)) {
			return (p + (q - p) * ((scalar_type(2)/scalar_type(3)) - t) * scalar_type(6));
		}
		return p ;
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename hsv_tag_name >
struct convert
		<
		::color::category::cmy< cmy_tag_name >
		,::color::category::hsv<hsv_tag_name>
		> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::hsv<hsv_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type h = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type s = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type v = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		int region = int(6 * h);
		scalar_type f = h * 6 - region ;
		scalar_type p = v * (scalar_type(1) - s);
		scalar_type q = v * (scalar_type(1) - f * s);
		scalar_type t = v * (scalar_type(1) - (1 - f) * s);
		scalar_type r;
		scalar_type g;
		scalar_type b;
		switch(region % 6) {
		case 0:
			r = v, g = t, b = p;
			break;
		case 1:
			r = q, g = v, b = p;
			break;
		case 2:
			r = p, g = v, b = t;
			break;
		case 3:
			r = p, g = q, b = v;
			break;
		case 4:
			r = t, g = p, b = v;
			break;
		case 5:
			r = v, g = p, b = q;
			break;
		}
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(scalar_type(1) - r));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(scalar_type(1) - g));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(scalar_type(1) - b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename rgb_tag_name >
struct convert
		<
		::color::category::cmy< cmy_tag_name >
		,::color::category::rgb<rgb_tag_name>
		> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::rgb<rgb_tag_name> category_right_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_right_type>::position_enum
					,green_p = ::color::place::_internal::green<category_right_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		typedef ::color::_internal::reformat< category_left_type, category_right_type > reformat_type;
		typedef ::color::operation::_internal::invert< category_right_type > invert_type;
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,red_p >(invert_type::template component<red_p >(container_right_trait_type::template get<red_p >(right))));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,green_p>(invert_type::template component<green_p>(container_right_trait_type::template get<green_p>(right))));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,blue_p >(invert_type::template component<blue_p >(container_right_trait_type::template get<blue_p >(right))));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename yiq_tag_name >
struct convert
		<
		::color::category::cmy< cmy_tag_name >
		,::color::category::yiq<yiq_tag_name>
		> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::yiq<yiq_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::yiq< category_right_type > yiq_const_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type a11 = yiq_const_type::a11(), a12 = yiq_const_type::a12(), a13 = yiq_const_type::a13();
		static scalar_type a21 = yiq_const_type::a21(), a22 = yiq_const_type::a22(), a23 = yiq_const_type::a23();
		static scalar_type a31 = yiq_const_type::a31(), a32 = yiq_const_type::a32(), a33 = yiq_const_type::a33();
		scalar_type y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type i = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type q = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		i = yiq_const_type::i_deverse(i);
		q = yiq_const_type::q_deverse(q);
		scalar_type r = a11 * y + a12 * i + a13 * q;
		scalar_type g = a21 * y + a22 * i + a23 * q;
		scalar_type b = a31 * y + a32 * i + a33 * q;
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(scalar_type(1) - r));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(scalar_type(1) - g));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(scalar_type(1) - b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename cmy_tag_name, typename yuv_tag_name >
struct convert
		<
		::color::category::cmy< cmy_tag_name >
		,::color::category::yuv<yuv_tag_name>
		> {
public:
	typedef ::color::category::cmy< cmy_tag_name > category_left_type;
	typedef ::color::category::yuv<yuv_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::yuv< category_right_type > yuv_const_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type const Wr = yuv_const_type::Wr();
		static scalar_type const Wb = yuv_const_type::Wb();
		static scalar_type const Wg = yuv_const_type::Wg();
		static scalar_type const Umax = yuv_const_type::Umax();
		static scalar_type const Vmax = yuv_const_type::Vmax();
		static scalar_type const b11 = 1, b12 = 0, b13 = (1 - Wr) / Vmax;
		static scalar_type const b21 = 1, b22 = - Wb*(1 - Wb) / Umax / Wg, b23 = -Wr*(1 - Wr) / Vmax / Wg;
		static scalar_type const b31 = 1, b32 = ((1 - Wb) / Umax), b33 = 0;
		scalar_type y = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type u = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type v = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		u = (u - scalar_type(0.5)) * scalar_type(2) * Umax;
		v = (v - scalar_type(0.5)) * scalar_type(2) * Vmax;
		scalar_type r = y + v * b13;
		scalar_type g = y + u * b22 + v * b23;
		scalar_type b = y + u * b32 ;
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(scalar_type(1) - r));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(scalar_type(1) - g));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(scalar_type(1) - b));
	}
};

}
}

namespace color {
namespace _internal {

template< typename type_name >
struct pick_cmy {
	typedef ::color::category::cmy_uint32 category_type;
};

template<> struct pick_cmy< std::uint8_t > {
	typedef ::color::category::cmy_uint8 category_type;
};
template<> struct pick_cmy< std::uint16_t > {
	typedef ::color::category::cmy_uint16 category_type;
};
template<> struct pick_cmy< std::uint32_t > {
	typedef ::color::category::cmy_uint32 category_type;
};
template<> struct pick_cmy< std::uint64_t > {
	typedef ::color::category::cmy_uint64 category_type;
};
template<> struct pick_cmy< float > {
	typedef ::color::category::cmy_float category_type;
};
template<> struct pick_cmy< double > {
	typedef ::color::category::cmy_double category_type;
};
template<> struct pick_cmy< long double > {
	typedef ::color::category::cmy_ldouble category_type;
};
}

template< typename type_name >
using cmy = ::color::_internal::model< typename ::color::_internal::pick_cmy< type_name >::category_type >;

}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename cmy_tag_name >
struct convert
		<
		::color::category::gray< gray_tag_name >
		,::color::category::cmy<cmy_tag_name>
		> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::cmy<cmy_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::gray< category_left_type > gray_const_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type value =
			gray_const_type::Rc() * (1 - normalize_type::template process<0> (container_right_trait_type::template get<0>(right)))
			+ gray_const_type::Gc() * (1 - normalize_type::template process<1> (container_right_trait_type::template get<1>(right)))
			+ gray_const_type::Bc() * (1 - normalize_type::template process<2> (container_right_trait_type::template get<2>(right)));
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(value));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename cmyk_tag_name >
struct convert
		<
		::color::category::gray< gray_tag_name >
		,::color::category::cmyk<cmyk_tag_name>
		> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::cmyk<cmyk_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::gray< category_left_type > gray_const_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type c = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type m = normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type y = normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type k = normalize_type::template process<3>(container_right_trait_type::template get<3>(right));
		scalar_type value =
			(gray_const_type::Rc() * (1-c)
			 + gray_const_type::Gc() * (1-m)
			 + gray_const_type::Bc() * (1-y)) * (1-k);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(value));
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
		<
		::color::category::gray< tag_left_name >
		,::color::category::gray< tag_right_name>
		> {
public:
	typedef ::color::category::gray< tag_left_name > category_left_type;
	typedef ::color::category::gray< tag_right_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			gl = ::color::place::_internal::gray<category_left_type>::position_enum
				 ,gr = ::color::place::_internal::gray<category_right_type>::position_enum
		};
		container_left_trait_type::template set<gl>(left, reformat_type::template process<gl,gr>(container_right_trait_type::template get<gr>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename hsl_tag_name >
struct convert
		<
		::color::category::gray< gray_tag_name >
		,::color::category::hsl<hsl_tag_name>
		> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::hsl<hsl_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,2>(container_right_trait_type::template get<2>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename hsv_tag_name >
struct convert
		<
		::color::category::gray< gray_tag_name >
		,::color::category::hsv<hsv_tag_name>
		> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::hsv<hsv_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,2>(container_right_trait_type::template get<2>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename rgb_tag_name >
struct convert
		<
		::color::category::gray< gray_tag_name >
		,::color::category::rgb< rgb_tag_name >
		> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::constant::gray< category_left_type > gray_const_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_right_type>::position_enum
					, green_p = ::color::place::_internal::green<category_right_type>::position_enum
								, blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		scalar_type value =
			gray_const_type::Rc() * normalize_type::template process<red_p > (container_right_trait_type::template get<red_p >(right))
		+ gray_const_type::Gc() * normalize_type::template process<green_p> (container_right_trait_type::template get<green_p>(right))
		+ gray_const_type::Bc() * normalize_type::template process<blue_p > (container_right_trait_type::template get<blue_p >(right));
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(value));
	}
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct quadrature {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -2 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
quadrature() {
	return ::color::place::_internal::quadrature<category_name>::position();
}

}
}

namespace color {
namespace trait {

template< >
struct index< ::color::category::yiq_double >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yiq_float >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yiq_ldouble >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yiq_uint16 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yiq_uint32 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yiq_uint64 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yiq_uint8 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct quadrature< ::color::category::hsl< tag_name > > {
public:
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 2 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace place {
namespace _internal {

template< typename category_name >
struct inphase {
public:
	typedef typename ::color::trait::index< category_name >::instance_type index_instance_type;

	enum { position_enum = -6 };
	enum { has_enum = false };

	static index_instance_type position() {
		return position_enum;
	}
};

}

template< typename category_name >
inline

typename ::color::trait::index< category_name >::instance_type
inphase() {
	return ::color::place::_internal::inphase<category_name>::position();
}

}
}

namespace color {
namespace place {
namespace _internal {

template< typename tag_name >
struct inphase< ::color::category::hsl< tag_name > > {
public:
	typedef ::color::category::hsl< tag_name > category_type;
	typedef typename ::color::trait::index< category_type >::instance_type index_instance_type;

	enum { position_enum = 1 };
	enum { has_enum = true };

	static index_instance_type position() {
		return position_enum;
	}
};

}
}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::cmyk_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::cmyk_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::cmyk_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::cmyk_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::cmyk_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::cmyk_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::cmyk_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::gray_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::gray_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::gray_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::gray_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::gray_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::gray_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::gray_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::hsl_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::hsl_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::hsl_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::hsl_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::hsl_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::hsl_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::hsl_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::hsv_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::hsv_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::hsv_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::hsv_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::hsv_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::hsv_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::hsv_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::yiq_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::yiq_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::yiq_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::yiq_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::yiq_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::yiq_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::yiq_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yiq< ::color::category::yuv_uint8 > {
	typedef ::color::category::yiq_uint8 akin_type;
};
template< >struct yiq< ::color::category::yuv_uint16 > {
	typedef ::color::category::yiq_uint16 akin_type;
};
template< >struct yiq< ::color::category::yuv_uint32 > {
	typedef ::color::category::yiq_uint32 akin_type;
};
template< >struct yiq< ::color::category::yuv_uint64 > {
	typedef ::color::category::yiq_uint64 akin_type;
};
template< >struct yiq< ::color::category::yuv_float > {
	typedef ::color::category::yiq_float akin_type;
};
template< >struct yiq< ::color::category::yuv_double > {
	typedef ::color::category::yiq_double akin_type;
};
template< >struct yiq< ::color::category::yuv_ldouble > {
	typedef ::color::category::yiq_ldouble akin_type;
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct yiq_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 1, 0.5957161349127745527, 0.5225910452916111683 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 1, 0.5957161349127745527, 0.5225910452916111683 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, -0.5957161349127745527, -0.5225910452916111683 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, -0.5957161349127745527, -0.5225910452916111683 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 1, 2*0.5957161349127745527, 2 * 0.5225910452916111683 };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 1, 2*0.5957161349127745527, 2*0.5225910452916111683 };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yiq_double >
		: public ::color::_internal::utility::bound::yiq_scalar< unsigned, double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yiq_float >
		: public ::color::_internal::utility::bound::yiq_scalar< unsigned, float > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::yiq_ldouble >
		: public ::color::_internal::utility::bound::yiq_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yiq_uint16 >
		: public ::color::_internal::utility::bound::bound556< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yiq_uint32 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 8, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::yiq_uint64 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 16, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yiq_uint8 >
		: public ::color::_internal::utility::bound::bound332< unsigned > {
};

}
}

namespace color {
namespace get {

inline
::color::_internal::model< ::color::category::yiq_uint8 >::component_const_type
inphase(::color::_internal::model< ::color::category::yiq_uint8 > const& color_parameter) {
	return color_parameter.template get<1>();
}

inline
::color::_internal::model< ::color::category::yiq_uint16 >::component_const_type
inphase(::color::_internal::model< ::color::category::yiq_uint16 > const& color_parameter) {
	return color_parameter.template get<1>();
};

inline
::color::_internal::model< ::color::category::yiq_uint32 >::component_const_type
inphase(::color::_internal::model< ::color::category::yiq_uint32 > const& color_parameter) {
	return color_parameter.template get<1>();
};

inline
::color::_internal::model< ::color::category::yiq_uint64 >::component_const_type
inphase(::color::_internal::model< ::color::category::yiq_uint64 > const& color_parameter) {
	return color_parameter.template get<1>();
};

inline
::color::_internal::model< ::color::category::yiq_float >::component_const_type
inphase(::color::_internal::model< ::color::category::yiq_float > const& color_parameter) {
	return color_parameter.template get<1>();
};

inline
::color::_internal::model< ::color::category::yiq_double >::component_const_type
inphase(::color::_internal::model< ::color::category::yiq_double > const& color_parameter) {
	return color_parameter.template get<1>();
};

inline
::color::_internal::model< ::color::category::yiq_ldouble >::component_const_type
inphase(::color::_internal::model< ::color::category::yiq_ldouble > const& color_parameter) {
	return color_parameter.template get<1>();
};

}
}

namespace color {
namespace get {

inline
::color::_internal::model< ::color::category::yiq_uint8 >::component_const_type
quadrature(::color::_internal::model< ::color::category::yiq_uint8 > const& color_parameter) {
	return color_parameter.template get<2>();
}

inline
::color::_internal::model< ::color::category::yiq_uint16 >::component_const_type
quadrature(::color::_internal::model< ::color::category::yiq_uint16 > const& color_parameter) {
	return color_parameter.template get<2>();
};

inline
::color::_internal::model< ::color::category::yiq_uint32 >::component_const_type
quadrature(::color::_internal::model< ::color::category::yiq_uint32 > const& color_parameter) {
	return color_parameter.template get<2>();
};

inline
::color::_internal::model< ::color::category::yiq_uint64 >::component_const_type
quadrature(::color::_internal::model< ::color::category::yiq_uint64 > const& color_parameter) {
	return color_parameter.template get<2>();
};

inline
::color::_internal::model< ::color::category::yiq_float >::component_const_type
quadrature(::color::_internal::model< ::color::category::yiq_float > const& color_parameter) {
	return color_parameter.template get<2>();
};

inline
::color::_internal::model< ::color::category::yiq_double >::component_const_type
quadrature(::color::_internal::model< ::color::category::yiq_double > const& color_parameter) {
	return color_parameter.template get<2>();
};

inline
::color::_internal::model< ::color::category::yiq_ldouble >::component_const_type
quadrature(::color::_internal::model< ::color::category::yiq_ldouble > const& color_parameter) {
	return color_parameter.template get<2>();
};

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yiq<tag_name> >::akin_type >::return_type
red(::color::_internal::model< ::color::category::yiq<tag_name> > const& color_parameter) {
	typedef ::color::category::yiq<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::constant::yiq<category_type> yiq_const_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	static scalar_type a11 = yiq_const_type::a11(), a12 = yiq_const_type::a12(), a13 = yiq_const_type::a13();
	scalar_type y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type i = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type q = normalize_type::template process<2>(color_parameter.template get<2>());
	i = (scalar_type(2) * i - scalar_type(1)) * yiq_const_type::i_max();
	q = (scalar_type(2) * q - scalar_type(1)) * yiq_const_type::q_max();
	scalar_type r = a11 * y + a12 * i + a13 * q;
	return diverse_type::template process<0>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yiq<tag_name> >::akin_type >::return_type
green(::color::_internal::model< ::color::category::yiq<tag_name> > const& color_parameter) {
	typedef ::color::category::yiq<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::constant::yiq<category_type> yiq_const_type;
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	static scalar_type a21 = yiq_const_type::a21(), a22 = yiq_const_type::a22(), a23 = yiq_const_type::a23();
	scalar_type y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type i = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type q = normalize_type::template process<2>(color_parameter.template get<2>());
	i = (scalar_type(2) * i - scalar_type(1)) * yiq_const_type::i_max();
	q = (scalar_type(2) * q - scalar_type(1)) * yiq_const_type::q_max();
	scalar_type g = a21 * y + a22 * i + a23 * q;
	return diverse_type::template process<1>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yiq<tag_name> >::akin_type >::return_type
blue(::color::_internal::model< ::color::category::yiq<tag_name> > const& color_parameter) {
	typedef ::color::category::yiq<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	typedef ::color::constant::yiq<category_type> yiq_const_type;
	typedef ::color::_internal::diverse<akin_type> diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	static scalar_type a31 = yiq_const_type::a31(), a32 = yiq_const_type::a32(), a33 = yiq_const_type::a33();
	scalar_type y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type i = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type q = normalize_type::template process<2>(color_parameter.template get<2>());
	i = (scalar_type(2) * i - scalar_type(1)) * yiq_const_type::i_max();
	q = (scalar_type(2) * q - scalar_type(1)) * yiq_const_type::q_max();
	scalar_type b = a31 * y + a32 * i + a33 * q;
	return diverse_type::template process<2>(b);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::yiq<tag_name> >::akin_type >::return_type
gray(::color::_internal::model< ::color::category::yiq<tag_name> > const& color_parameter) {
	typedef ::color::category::yiq< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type > ::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<0,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
red
(
	::color::_internal::model< ::color::category::yiq< tag_name > > & color_parameter,
	typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::yiq<tag_name> >::akin_type >::input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
green
(
	::color::_internal::model< ::color::category::yiq<tag_name> > & color_parameter,
	typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::yiq<tag_name> >::akin_type >::input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
blue
(
	::color::_internal::model< ::color::category::yiq<tag_name> > & color_parameter,
	typename ::color::trait::component< typename ::color::akin::rgb< ::color::category::yiq<tag_name> >::akin_type >::input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename tag_name >
inline
void
gray
(
	::color::_internal::model< ::color::category::yiq< tag_name > > & color_parameter,
	typename ::color::trait::component< typename ::color::akin::gray< ::color::category::yiq<tag_name> >::akin_type >::input_const_type component_parameter
) {
};

}
}

namespace color {
namespace make {

inline
void black(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x58;
}

inline
void black(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x7de0;
}

inline
void black(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f7f00u;
}

inline
void black(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7fff0000ul;
}

inline
void black(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void gray50(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x5b;
}

inline
void gray50(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x7def;
}

inline
void gray50(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f7f7fu;
}

inline
void gray50(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7fff7ffful;
}

inline
void gray50(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 0, 0 });
}

inline
void gray50(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 0, 0 });
}

inline
void gray50(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void white(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x5f;
}

inline
void white(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x7dff;
}

inline
void white(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f7fffu;
}

inline
void white(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7ffffffful;
}

inline
void white(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0, 0 });
}

inline
void white(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0, 0 });
}

inline
void white(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void red(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0xba;
}

inline
void red(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0xb3e9;
}

inline
void red(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xffb3ff4cu;
}

inline
void red(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffb3caffff4c8aul;
}

inline
void red(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.299, 0.595716, 0.211456 });
}

inline
void red(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.299, 0.595716, 0.211456 });
}

inline
void red(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.299, 0.595716, 0.211456 });
}

}
}

namespace color {
namespace make {

inline
void green(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x12;
}

inline
void green(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x3d69;
}

inline
void green(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3f624au;
}

inline
void green(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3fff62834b22ul;
}

inline
void green(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.2935, -0.137226, -0.261296 });
}

inline
void green(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.2935, -0.137226, -0.261296 });
}

inline
void green(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.2935, -0.137226, -0.261296 });
}

}
}

namespace color {
namespace make {

inline
void blue(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x88;
}

inline
void blue(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0xc8e3;
}

inline
void blue(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xffcb3a1du;
}

inline
void blue(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffcc343af81d2eul;
}

inline
void blue(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.114, -0.321263, 0.311135 });
}

inline
void blue(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.114, -0.321263, 0.311135 });
}

inline
void blue(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.114, -0.321263, 0.311135 });
}

}
}

namespace color {
namespace make {

inline
void cyan(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x4;
}

inline
void cyan(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x4815;
}

inline
void cyan(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff4b00b2u;
}

inline
void cyan(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff4c340000b374ul;
}

inline
void cyan(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.701, -0.595716, -0.211456 });
}

inline
void cyan(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.701, -0.595716, -0.211456 });
}

inline
void cyan(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.701, -0.595716, -0.211456 });
}

}
}

namespace color {
namespace make {

inline
void magenta(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0xea;
}

inline
void magenta(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0xfecc;
}

inline
void magenta(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffba69u;
}

inline
void magenta(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffbaf769b9ul;
}

inline
void magenta(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.413, 0.274453, 0.522591 });
}

inline
void magenta(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.413, 0.274453, 0.522591 });
}

inline
void magenta(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.413, 0.274453, 0.522591 });
}

}
}

namespace color {
namespace make {

inline
void yellow(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x2e;
}

inline
void yellow(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x32fb;
}

inline
void yellow(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff33c4e1u;
}

inline
void yellow(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff33cac506e2d0ul;
}

inline
void yellow(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.886, 0.321263, -0.311135 });
}

inline
void yellow(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.886, 0.321263, -0.311135 });
}

inline
void yellow(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.886, 0.321263, -0.311135 });
}

}
}

namespace color {
namespace make {

inline
void aqua(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x4;
}

inline
void aqua(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x4815;
}

inline
void aqua(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff4b00b2u;
}

inline
void aqua(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff4c340000b374ul;
}

inline
void aqua(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.701, -0.595716, -0.211456 });
}

inline
void aqua(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.701, -0.595716, -0.211456 });
}

inline
void aqua(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.701, -0.595716, -0.211456 });
}

}
}

namespace color {
namespace make {

inline
void fuchsia(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0xea;
}

inline
void fuchsia(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0xfecc;
}

inline
void fuchsia(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xffffba69u;
}

inline
void fuchsia(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffffbaf769b9ul;
}

inline
void fuchsia(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.413, 0.274453, 0.522591 });
}

inline
void fuchsia(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.413, 0.274453, 0.522591 });
}

inline
void fuchsia(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.413, 0.274453, 0.522591 });
}

}
}

namespace color {
namespace make {

inline
void lime(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0xc;
}

inline
void lime(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x112;
}

inline
void lime(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff004495u;
}

inline
void lime(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff000045079645ul;
}

inline
void lime(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.587, -0.274453, -0.522591 });
}

inline
void lime(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.587, -0.274453, -0.522591 });
}

inline
void lime(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.587, -0.274453, -0.522591 });
}

}
}

namespace color {
namespace make {

inline
void maroon(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x69;
}

inline
void maroon(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x96e4;
}

inline
void maroon(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff99bf26u;
}

inline
void maroon(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff99e4bfff2645ul;
}

inline
void maroon(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.1495, 0.297858, 0.105728 });
}

inline
void maroon(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.1495, 0.297858, 0.105728 });
}

inline
void maroon(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.1495, 0.297858, 0.105728 });
}

}
}

namespace color {
namespace make {

inline
void navy(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x50;
}

inline
void navy(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0xa161;
}

inline
void navy(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xffa55d0eu;
}

inline
void navy(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffa6195d7b0e97ul;
}

inline
void navy(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.057, -0.160632, 0.155567 });
}

inline
void navy(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.057, -0.160632, 0.155567 });
}

inline
void navy(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.057, -0.160632, 0.155567 });
}

}
}

namespace color {
namespace make {

inline
void olive(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x63;
}

inline
void olive(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x5a6d;
}

inline
void olive(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff59a170u;
}

inline
void olive(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff59e5a2837168ul;
}

inline
void olive(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.443, 0.160632, -0.155567 });
}

inline
void olive(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.443, 0.160632, -0.155567 });
}

inline
void olive(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.443, 0.160632, -0.155567 });
}

}
}

namespace color {
namespace make {

inline
void orange(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x6c;
}

inline
void orange(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x5f55;
}

inline
void orange(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff60d8adu;
}

inline
void orange(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff6097d9aaae37ul;
}

inline
void orange(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.68055, 0.417322, -0.128228 });
}

inline
void orange(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.68055, 0.417322, -0.128228 });
}

inline
void orange(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.68055, 0.417322, -0.128228 });
}

}
}

namespace color {
namespace make {

inline
void purple(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0xa1;
}

inline
void purple(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0xbe66;
}

inline
void purple(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xffbf9c34u;
}

inline
void purple(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffbfff9d7b34dcul;
}

inline
void purple(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.2065, 0.137226, 0.261296 });
}

inline
void purple(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.2065, 0.137226, 0.261296 });
}

inline
void purple(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.2065, 0.137226, 0.261296 });
}

}
}

namespace color {
namespace make {

inline
void silver(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x5d;
}

inline
void silver(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x7df7;
}

inline
void silver(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f7fbfu;
}

inline
void silver(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7fffbffful;
}

inline
void silver(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.75, 0, 0 });
}

inline
void silver(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.75, 0, 0 });
}

inline
void silver(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.75, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void teal(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0x4a;
}

inline
void teal(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0x64ea;
}

inline
void teal(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xff653f59u;
}

inline
void teal(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff661a3fff59baul;
}

inline
void teal(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.3505, -0.297858, -0.105728 });
}

inline
void teal(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.3505, -0.297858, -0.105728 });
}

inline
void teal(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.3505, -0.297858, -0.105728 });
}

}
}

namespace color {
namespace make {

inline
void violet(::color::_internal::model< color::category::yiq_uint8 > & color_parameter) {
	color_parameter.container() = 0xa4;
}

inline
void violet(::color::_internal::model< color::category::yiq_uint16 > & color_parameter) {
	color_parameter.container() = 0xb255;
}

inline
void violet(::color::_internal::model< color::category::yiq_uint32 > & color_parameter) {
	color_parameter.container() = 0xffb598aeu;
}

inline
void violet(::color::_internal::model< color::category::yiq_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffb63598f9af49ul;
}

inline
void violet(::color::_internal::model< color::category::yiq_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.684722, 0.116239, 0.221333 });
}

inline
void violet(::color::_internal::model< color::category::yiq_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.684722, 0.116239, 0.221333 });
}

inline
void violet(::color::_internal::model< color::category::yiq_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.684722, 0.116239, 0.221333 });
}

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename cmy_tag_name >
struct convert
		<
		::color::category::yiq< yiq_tag_name >
		,::color::category::cmy< cmy_tag_name >
		> {
public:
	typedef ::color::category::yiq< yiq_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::constant::yiq< category_left_type > yiq_const_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type b11 = yiq_const_type::b11(), b12 = yiq_const_type::b12(), b13 = yiq_const_type::b13();
		static scalar_type b21 = yiq_const_type::b21(), b22 = yiq_const_type::b22(), b23 = yiq_const_type::b23();
		static scalar_type b31 = yiq_const_type::b31(), b32 = yiq_const_type::b32(), b33 = yiq_const_type::b33();
		static scalar_type const b32n = -b32;
		scalar_type r = scalar_type(1) - normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type g = scalar_type(1) - normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type b = scalar_type(1) - normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type y = b11 * r + b12 * g + b13 * b;
		scalar_type i = b21 * r + b22 * g + b23 * b;
		scalar_type q = b31 * r + b32 * g + b33 * b;
		i = (i / b21 + scalar_type(1)) / scalar_type(2);
		q = (q / b32n + scalar_type(1)) / scalar_type(2);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(i));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(q));
	}
};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename gray_tag_name >
struct convert
		<
		::color::category::yiq< yiq_tag_name >
		,::color::category::gray< gray_tag_name >
		> {
public:
	typedef ::color::category::yiq< yiq_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type g = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(g));
		container_left_trait_type::template set<1>(left, bound_left_trait_type::template minimum<1>());
		container_left_trait_type::template set<2>(left, bound_left_trait_type::template minimum<2>());
	}

};

}
}

namespace color {
namespace _internal {

template< typename yiq_tag_name, typename rgb_tag_name >
struct convert
		<
		::color::category::yiq< yiq_tag_name >
		,::color::category::rgb< rgb_tag_name >
		> {
public:
	typedef ::color::category::yiq< yiq_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::constant::yiq< category_left_type > yiq_const_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_right_type>::position_enum
					,green_p = ::color::place::_internal::green<category_right_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		static scalar_type b11 = yiq_const_type::b11(), b12 = yiq_const_type::b12(), b13 = yiq_const_type::b13();
		static scalar_type b21 = yiq_const_type::b21(), b22 = yiq_const_type::b22(), b23 = yiq_const_type::b23();
		static scalar_type b31 = yiq_const_type::b31(), b32 = yiq_const_type::b32(), b33 = yiq_const_type::b33();
		static scalar_type const b32n = -b32;
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type y = b11 * r + b12 * g + b13 * b;
		scalar_type i = b21 * r + b22 * g + b23 * b;
		scalar_type q = b31 * r + b32 * g + b33 * b;
		i = (i / b21 + scalar_type(1)) / scalar_type(2);
		q = (q / b32n + scalar_type(1)) / scalar_type(2);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(i));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(q));
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
		<
		::color::category::yiq< tag_left_name >
		,::color::category::yiq< tag_right_name>
		> {
public:
	typedef ::color::category::yiq< tag_left_name > category_left_type;
	typedef ::color::category::yiq< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};
}
}

namespace color {
namespace _internal {

template< typename type_name >
struct pick_yiq {
	typedef ::color::category::yiq_uint32 category_type;
};

template<> struct pick_yiq< std::uint8_t > {
	typedef ::color::category::yiq_uint8 category_type;
};
template<> struct pick_yiq< std::uint16_t > {
	typedef ::color::category::yiq_uint16 category_type;
};
template<> struct pick_yiq< std::uint32_t > {
	typedef ::color::category::yiq_uint32 category_type;
};
template<> struct pick_yiq< std::uint64_t > {
	typedef ::color::category::yiq_uint64 category_type;
};
template<> struct pick_yiq< float > {
	typedef ::color::category::yiq_float category_type;
};
template<> struct pick_yiq< double > {
	typedef ::color::category::yiq_double category_type;
};
template<> struct pick_yiq< long double > {
	typedef ::color::category::yiq_ldouble category_type;
};
}

template< typename type_name >
using yiq = ::color::_internal::model< typename ::color::_internal::pick_yiq< type_name >::category_type >;

}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename yiq_tag_name >
struct convert
		<
		::color::category::gray< gray_tag_name >
		,::color::category::yiq<yiq_tag_name>
		> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::yiq<yiq_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
	}
};

}
}

namespace color {
namespace akin {

template< >struct yuv< ::color::category::cmy_uint8 > {
	typedef ::color::category::yuv_uint8 akin_type;
};
template< >struct yuv< ::color::category::cmy_uint16 > {
	typedef ::color::category::yuv_uint16 akin_type;
};
template< >struct yuv< ::color::category::cmy_uint32 > {
	typedef ::color::category::yuv_uint32 akin_type;
};
template< >struct yuv< ::color::category::cmy_uint64 > {
	typedef ::color::category::yuv_uint64 akin_type;
};
template< >struct yuv< ::color::category::cmy_float > {
	typedef ::color::category::yuv_float akin_type;
};
template< >struct yuv< ::color::category::cmy_double > {
	typedef ::color::category::yuv_double akin_type;
};
template< >struct yuv< ::color::category::cmy_ldouble > {
	typedef ::color::category::yuv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yuv< ::color::category::cmyk_uint8 > {
	typedef ::color::category::yuv_uint8 akin_type;
};
template< >struct yuv< ::color::category::cmyk_uint16 > {
	typedef ::color::category::yuv_uint16 akin_type;
};
template< >struct yuv< ::color::category::cmyk_uint32 > {
	typedef ::color::category::yuv_uint32 akin_type;
};
template< >struct yuv< ::color::category::cmyk_uint64 > {
	typedef ::color::category::yuv_uint64 akin_type;
};
template< >struct yuv< ::color::category::cmyk_float > {
	typedef ::color::category::yuv_float akin_type;
};
template< >struct yuv< ::color::category::cmyk_double > {
	typedef ::color::category::yuv_double akin_type;
};
template< >struct yuv< ::color::category::cmyk_ldouble > {
	typedef ::color::category::yuv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yuv< ::color::category::gray_uint8 > {
	typedef ::color::category::yuv_uint8 akin_type;
};
template< >struct yuv< ::color::category::gray_uint16 > {
	typedef ::color::category::yuv_uint16 akin_type;
};
template< >struct yuv< ::color::category::gray_uint32 > {
	typedef ::color::category::yuv_uint32 akin_type;
};
template< >struct yuv< ::color::category::gray_uint64 > {
	typedef ::color::category::yuv_uint64 akin_type;
};
template< >struct yuv< ::color::category::gray_float > {
	typedef ::color::category::yuv_float akin_type;
};
template< >struct yuv< ::color::category::gray_double > {
	typedef ::color::category::yuv_double akin_type;
};
template< >struct yuv< ::color::category::gray_ldouble > {
	typedef ::color::category::yuv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yuv< ::color::category::hsl_uint8 > {
	typedef ::color::category::yuv_uint8 akin_type;
};
template< >struct yuv< ::color::category::hsl_uint16 > {
	typedef ::color::category::yuv_uint16 akin_type;
};
template< >struct yuv< ::color::category::hsl_uint32 > {
	typedef ::color::category::yuv_uint32 akin_type;
};
template< >struct yuv< ::color::category::hsl_uint64 > {
	typedef ::color::category::yuv_uint64 akin_type;
};
template< >struct yuv< ::color::category::hsl_float > {
	typedef ::color::category::yuv_float akin_type;
};
template< >struct yuv< ::color::category::hsl_double > {
	typedef ::color::category::yuv_double akin_type;
};
template< >struct yuv< ::color::category::hsl_ldouble > {
	typedef ::color::category::yuv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yuv< ::color::category::hsv_uint8 > {
	typedef ::color::category::yuv_uint8 akin_type;
};
template< >struct yuv< ::color::category::hsv_uint16 > {
	typedef ::color::category::yuv_uint16 akin_type;
};
template< >struct yuv< ::color::category::hsv_uint32 > {
	typedef ::color::category::yuv_uint32 akin_type;
};
template< >struct yuv< ::color::category::hsv_uint64 > {
	typedef ::color::category::yuv_uint64 akin_type;
};
template< >struct yuv< ::color::category::hsv_float > {
	typedef ::color::category::yuv_float akin_type;
};
template< >struct yuv< ::color::category::hsv_double > {
	typedef ::color::category::yuv_double akin_type;
};
template< >struct yuv< ::color::category::hsv_ldouble > {
	typedef ::color::category::yuv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yuv< ::color::category::rgb_uint8 > {
	typedef ::color::category::yuv_uint8 akin_type;
};
template< >struct yuv< ::color::category::rgb_uint16 > {
	typedef ::color::category::yuv_uint16 akin_type;
};
template< >struct yuv< ::color::category::rgb_uint32 > {
	typedef ::color::category::yuv_uint32 akin_type;
};
template< >struct yuv< ::color::category::rgb_uint64 > {
	typedef ::color::category::yuv_uint64 akin_type;
};
template< >struct yuv< ::color::category::rgb_float > {
	typedef ::color::category::yuv_float akin_type;
};
template< >struct yuv< ::color::category::rgb_double > {
	typedef ::color::category::yuv_double akin_type;
};
template< >struct yuv< ::color::category::rgb_ldouble > {
	typedef ::color::category::yuv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yuv< ::color::category::yiq_uint8 > {
	typedef ::color::category::yuv_uint8 akin_type;
};
template< >struct yuv< ::color::category::yiq_uint16 > {
	typedef ::color::category::yuv_uint16 akin_type;
};
template< >struct yuv< ::color::category::yiq_uint32 > {
	typedef ::color::category::yuv_uint32 akin_type;
};
template< >struct yuv< ::color::category::yiq_uint64 > {
	typedef ::color::category::yuv_uint64 akin_type;
};
template< >struct yuv< ::color::category::yiq_float > {
	typedef ::color::category::yuv_float akin_type;
};
template< >struct yuv< ::color::category::yiq_double > {
	typedef ::color::category::yuv_double akin_type;
};
template< >struct yuv< ::color::category::yiq_ldouble > {
	typedef ::color::category::yuv_ldouble akin_type;
};

}
}

namespace color {
namespace akin {

template< >struct yuv< ::color::category::yuv_uint8 > {
	typedef ::color::category::yuv_uint8 akin_type;
};
template< >struct yuv< ::color::category::yuv_uint16 > {
	typedef ::color::category::yuv_uint16 akin_type;
};
template< >struct yuv< ::color::category::yuv_uint32 > {
	typedef ::color::category::yuv_uint32 akin_type;
};
template< >struct yuv< ::color::category::yuv_uint64 > {
	typedef ::color::category::yuv_uint64 akin_type;
};
template< >struct yuv< ::color::category::yuv_float > {
	typedef ::color::category::yuv_float akin_type;
};
template< >struct yuv< ::color::category::yuv_double > {
	typedef ::color::category::yuv_double akin_type;
};
template< >struct yuv< ::color::category::yuv_ldouble > {
	typedef ::color::category::yuv_ldouble akin_type;
};

}
}

namespace color {
namespace _internal {
namespace utility {
namespace bound {

template< typename index_name, typename scalar_name >
struct yuv_scalar {
public:
	typedef scalar_name scalar_type;
	typedef index_name index_type;

	typedef ::color::_internal::utility::type::traitC< scalar_type > trait_type;
	typedef ::color::_internal::utility::type::index< index_type > index_trait_type;

	typedef typename trait_type::instance_type instance_type;
	typedef typename trait_type::return_image_type return_image_type;

	typedef typename index_trait_type::instance_type index_instance_type;
	typedef typename index_trait_type::input_const_type index_input_const_type;

	template< index_instance_type index >
	static return_image_type maximum() {
		static instance_type max_list[] = { 1, 0.436, 0.615 };
		return max_list[index];
	}

	static return_image_type maximum(index_input_const_type index) {
		static instance_type max_list[] = { 1, 0.436, 0.615 };
		return max_list[index];
	}

	template< index_instance_type index >
	static return_image_type minimum() {
		static instance_type min_list[] = { 0, -0.436, -0.615 };
		return min_list[index];
	}

	static return_image_type minimum(index_input_const_type index) {
		static instance_type min_list[] = { 0, -0.436, -0.615 };
		return min_list[index];
	}

	template< index_instance_type index >
	static return_image_type range() {
		static instance_type range_list[] = { 1, 2*0.436, 2 * 0.615 };
		return range_list[index];
	}

	static return_image_type range(index_input_const_type index) {
		static instance_type range_list[] = { 1, 2*0.436, 2*0.615 };
		return range_list[index];
	}
};

}
}
}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yuv_double >
		: public ::color::_internal::utility::bound::yuv_scalar< unsigned, double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yuv_float >
		: public ::color::_internal::utility::bound::yuv_scalar< unsigned, float > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::yuv_ldouble >
		: public ::color::_internal::utility::bound::yuv_scalar< unsigned, long double > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yuv_uint16 >
		: public ::color::_internal::utility::bound::bound556< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yuv_uint32 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 8, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct bound< ::color::category::yuv_uint64 >
		: public ::color::_internal::utility::bound::intrinsic< std::uint16_t, 16, unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct bound< ::color::category::yuv_uint8 >
		: public ::color::_internal::utility::bound::bound332< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::yuv_double >
		: public ::color::_internal::utility::component::array< double, unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::yuv_float >
		: public ::color::_internal::utility::component::array< float, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::yuv_ldouble >
		: public ::color::_internal::utility::component::array< long double, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::yuv_uint16 >
		: public ::color::_internal::utility::component::cnent556< unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::yuv_uint32 >
		: public ::color::_internal::utility::component::Unsigned< std::uint8_t, unsigned> {
};

}
}
namespace color {
namespace trait {

template< >
struct component< ::color::category::yuv_uint64 >
		: public ::color::_internal::utility::component::Unsigned< std::uint16_t, unsigned> {
};

}
}

namespace color {
namespace trait {

template< >
struct component< ::color::category::yuv_uint8 >
		: public ::color::_internal::utility::component::cnent332< unsigned > {
};

}
}

namespace color {
namespace trait {

template< >
struct index< ::color::category::yuv_double >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yuv_float >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yuv_ldouble >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yuv_uint16 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yuv_uint32 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yuv_uint64 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}
namespace color {
namespace trait {

template< >
struct index< ::color::category::yuv_uint8 >
		: public ::color::_internal::utility::type::index< unsigned > {
};

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::gray< ::color::category::hsv<tag_name> >::akin_type >::return_type
gray(::color::_internal::model< ::color::category::yuv<tag_name> > const& color_parameter) {
	typedef ::color::category::yuv< tag_name > category_type;
	typedef typename ::color::trait::scalar< category_type >::instance_type scalar_type;
	typedef typename ::color::akin::gray< category_type >::akin_type akin_type;
	typedef ::color::_internal::reformat< akin_type, category_type, scalar_type > reformat_type;
	return reformat_type::template process<0,0>(color_parameter.template get<0>());
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yuv<tag_name> >::akin_type >::return_type
red(::color::_internal::model< ::color::category::yuv<tag_name> > const& color_parameter) {
	typedef ::color::category::yuv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { red_p = ::color::place::_internal::red<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::yuv< category_type > yuv_const_type;
	static scalar_type const Wr = yuv_const_type::Wr();
	static scalar_type const Vmax = yuv_const_type::Vmax();
	static scalar_type const b11 = 1, b12 = 0, b13 = (1 - Wr) / Vmax;
	scalar_type y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type v = normalize_type::template process<2>(color_parameter.template get<2>());
	v = (v - scalar_type(0.5)) * scalar_type(2) * Vmax;
	scalar_type r = y + v * b13;
	return diverse_type::template process<red_p>(r);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yuv<tag_name> >::akin_type >::return_type
green(::color::_internal::model< ::color::category::yuv<tag_name> > const& color_parameter) {
	typedef ::color::category::yuv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { green_p = ::color::place::_internal::green<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::yuv< category_type > yuv_const_type;
	static scalar_type const Wr = yuv_const_type::Wr();
	static scalar_type const Wb = yuv_const_type::Wb();
	static scalar_type const Wg = yuv_const_type::Wg();
	static scalar_type const Umax = yuv_const_type::Umax();
	static scalar_type const Vmax = yuv_const_type::Vmax();
	static scalar_type const b21 = 1, b22 = - Wb*(1 - Wb) / Umax / Wg, b23 = -Wr*(1 - Wr) / Vmax / Wg;
	scalar_type y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type u = normalize_type::template process<1>(color_parameter.template get<1>());
	scalar_type v = normalize_type::template process<2>(color_parameter.template get<2>());
	u = (u - scalar_type(0.5)) * scalar_type(2) * Umax;
	v = (v - scalar_type(0.5)) * scalar_type(2) * Vmax;
	scalar_type g = y + u * b22 + v * b23;
	return diverse_type::template process<green_p>(g);
}

}
}

namespace color {
namespace get {

template< typename tag_name >
inline
typename ::color::trait::component< typename ::color::akin::rgb<::color::category::yuv<tag_name> >::akin_type >::return_type
blue(::color::_internal::model< ::color::category::yuv<tag_name> > const& color_parameter) {
	typedef ::color::category::yuv<tag_name> category_type;
	typedef typename ::color::trait::scalar<category_type>::instance_type scalar_type;
	typedef typename ::color::akin::rgb<category_type>::akin_type akin_type;
	enum { blue_p = ::color::place::_internal::blue<akin_type>::position_enum };
	typedef ::color::_internal::diverse< akin_type > diverse_type;
	typedef ::color::_internal::normalize<category_type> normalize_type;
	typedef ::color::constant::yuv< category_type > yuv_const_type;
	static scalar_type const Wb = yuv_const_type::Wb();
	static scalar_type const Umax = yuv_const_type::Umax();
	static scalar_type const b31 = 1, b32 = ((1 - Wb) / Umax), b33 = 0;
	scalar_type y = normalize_type::template process<0>(color_parameter.template get<0>());
	scalar_type u = normalize_type::template process<1>(color_parameter.template get<1>());
	u = (u - scalar_type(0.5)) * scalar_type(2) * Umax;
	scalar_type b = y + u * b32;
	return diverse_type::template process<blue_p>(b);
}

}
}

namespace color {
namespace make {

inline
void black(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x58;
}

inline
void black(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7de0;
}

inline
void black(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f7f00u;
}

inline
void black(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7fff0000ul;
}

inline
void black(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0, 0, 0 });
}

inline
void black(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void gray50(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x5b;
}

inline
void gray50(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7def;
}

inline
void gray50(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f7f7fu;
}

inline
void gray50(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7fff7ffful;
}

inline
void gray50(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.5, 0, 0 });
}

inline
void gray50(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.5, 0, 0 });
}

inline
void gray50(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.5, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void white(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x5f;
}

inline
void white(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7dff;
}

inline
void white(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f7fffu;
}

inline
void white(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7ffffffful;
}

inline
void white(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 1, 0, 0 });
}

inline
void white(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 1, 0, 0 });
}

inline
void white(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 1, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void red(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0xd2;
}

inline
void red(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0xfd49;
}

inline
void red(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffff544cu;
}

inline
void red(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffffff54cd4c8aul;
}

inline
void red(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.299, -0.147138, 0.615 });
}

inline
void red(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.299, -0.147138, 0.615 });
}

inline
void red(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.299, -0.147138, 0.615 });
}

}
}

namespace color {
namespace make {

inline
void green(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x12;
}

inline
void green(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x4949;
}

inline
void green(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff4a554au;
}

inline
void green(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff4a6855984b22ul;
}

inline
void green(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.2935, -0.144431, -0.257493 });
}

inline
void green(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.2935, -0.144431, -0.257493 });
}

inline
void green(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.2935, -0.144431, -0.257493 });
}

}
}

namespace color {
namespace make {

inline
void blue(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x78;
}

inline
void blue(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x6be3;
}

inline
void blue(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff6aff1du;
}

inline
void blue(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff6b2effff1d2eul;
}

inline
void blue(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.114, 0.436, -0.100014 });
}

inline
void blue(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.114, 0.436, -0.100014 });
}

inline
void blue(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.114, 0.436, -0.100014 });
}

}
}

namespace color {
namespace make {

inline
void cyan(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x24;
}

inline
void cyan(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x295;
}

inline
void cyan(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00aab2u;
}

inline
void cyan(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000ab31b374ul;
}

inline
void cyan(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.701, 0.147138, -0.615 });
}

inline
void cyan(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.701, 0.147138, -0.615 });
}

inline
void cyan(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.701, 0.147138, -0.615 });
}

}
}

namespace color {
namespace make {

inline
void magenta(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0xaa;
}

inline
void magenta(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0xe72c;
}

inline
void magenta(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffead369u;
}

inline
void magenta(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffeb2ed4cc69b9ul;
}

inline
void magenta(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.413, 0.288862, 0.514986 });
}

inline
void magenta(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.413, 0.288862, 0.514986 });
}

inline
void magenta(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.413, 0.288862, 0.514986 });
}

}
}

namespace color {
namespace make {

inline
void yellow(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x46;
}

inline
void yellow(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x901b;
}

inline
void yellow(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff9400e1u;
}

inline
void yellow(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff94d00000e2d0ul;
}

inline
void yellow(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.886, -0.436, 0.100014 });
}

inline
void yellow(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.886, -0.436, 0.100014 });
}

inline
void yellow(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.886, -0.436, 0.100014 });
}

}
}

namespace color {
namespace make {

inline
void aqua(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x24;
}

inline
void aqua(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x295;
}

inline
void aqua(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff00aab2u;
}

inline
void aqua(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff0000ab31b374ul;
}

inline
void aqua(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.701, 0.147138, -0.615 });
}

inline
void aqua(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.701, 0.147138, -0.615 });
}

inline
void aqua(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.701, 0.147138, -0.615 });
}

}
}

namespace color {
namespace make {

inline
void fuchsia(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0xaa;
}

inline
void fuchsia(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0xe72c;
}

inline
void fuchsia(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffead369u;
}

inline
void fuchsia(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffeb2ed4cc69b9ul;
}

inline
void fuchsia(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.413, 0.288862, 0.514986 });
}

inline
void fuchsia(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.413, 0.288862, 0.514986 });
}

inline
void fuchsia(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.413, 0.288862, 0.514986 });
}

}
}

namespace color {
namespace make {

inline
void lime(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0xc;
}

inline
void lime(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x14b2;
}

inline
void lime(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff142b95u;
}

inline
void lime(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff14d02b329645ul;
}

inline
void lime(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.587, -0.288862, -0.514986 });
}

inline
void lime(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.587, -0.288862, -0.514986 });
}

inline
void lime(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.587, -0.288862, -0.514986 });
}

}
}

namespace color {
namespace make {

inline
void maroon(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x91;
}

inline
void maroon(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0xbd84;
}

inline
void maroon(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffbf6926u;
}

inline
void maroon(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffbfff6a662645ul;
}

inline
void maroon(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.1495, -0.0735688, 0.3075 });
}

inline
void maroon(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.1495, -0.0735688, 0.3075 });
}

inline
void maroon(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.1495, -0.0735688, 0.3075 });
}

}
}

namespace color {
namespace make {

inline
void navy(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x68;
}

inline
void navy(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x72e1;
}

inline
void navy(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff75bf0eu;
}

inline
void navy(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7597bfff0e97ul;
}

inline
void navy(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.057, 0.218, -0.0500071 });
}

inline
void navy(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.057, 0.218, -0.0500071 });
}

inline
void navy(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.057, 0.218, -0.0500071 });
}

}
}

namespace color {
namespace make {

inline
void olive(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x4b;
}

inline
void olive(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x88ed;
}

inline
void olive(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff893f70u;
}

inline
void olive(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff8a673fff7168ul;
}

inline
void olive(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.443, -0.218, 0.0500071 });
}

inline
void olive(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.443, -0.218, 0.0500071 });
}

inline
void olive(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.443, -0.218, 0.0500071 });
}

}
}

namespace color {
namespace make {

inline
void orange(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x84;
}

inline
void orange(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0xb475;
}

inline
void orange(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffb91dadu;
}

inline
void orange(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffba531daeae37ul;
}

inline
void orange(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.68055, -0.334898, 0.280259 });
}

inline
void orange(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.68055, -0.334898, 0.280259 });
}

inline
void orange(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.68055, -0.334898, 0.280259 });
}

}
}

namespace color {
namespace make {

inline
void purple(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0xa1;
}

inline
void purple(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0xb286;
}

inline
void purple(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffb4a934u;
}

inline
void purple(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffb596aa6634dcul;
}

inline
void purple(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.2065, 0.144431, 0.257493 });
}

inline
void purple(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.2065, 0.144431, 0.257493 });
}

inline
void purple(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.2065, 0.144431, 0.257493 });
}

}
}

namespace color {
namespace make {

inline
void silver(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x5d;
}

inline
void silver(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x7df7;
}

inline
void silver(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff7f7fbfu;
}

inline
void silver(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff7fff7fffbffful;
}

inline
void silver(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.75, 0, 0 });
}

inline
void silver(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.75, 0, 0 });
}

inline
void silver(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.75, 0, 0 });
}

}
}

namespace color {
namespace make {

inline
void teal(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0x22;
}

inline
void teal(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0x3e4a;
}

inline
void teal(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xff3f9559u;
}

inline
void teal(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffff3fff959859baul;
}

inline
void teal(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.3505, 0.0735688, -0.3075 });
}

inline
void teal(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.3505, 0.0735688, -0.3075 });
}

inline
void teal(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.3505, 0.0735688, -0.3075 });
}

}
}

namespace color {
namespace make {

inline
void violet(::color::_internal::model< color::category::yuv_uint8 > & color_parameter) {
	color_parameter.container() = 0xa4;
}

inline
void violet(::color::_internal::model< color::category::yuv_uint16 > & color_parameter) {
	color_parameter.container() = 0xaa75;
}

inline
void violet(::color::_internal::model< color::category::yuv_uint32 > & color_parameter) {
	color_parameter.container() = 0xffaca3aeu;
}

inline
void violet(::color::_internal::model< color::category::yuv_uint64 > & color_parameter) {
	color_parameter.container() = 0xffffad64a3eaaf49ul;
}

inline
void violet(::color::_internal::model< color::category::yuv_float > & color_parameter) {
	color_parameter.container() = std::array<float,3>({ 0.684722, 0.122342, 0.218112 });
}

inline
void violet(::color::_internal::model< color::category::yuv_double> & color_parameter) {
	color_parameter.container() = std::array<double,3>({ 0.684722, 0.122342, 0.218112 });
}

inline
void violet(::color::_internal::model< color::category::yuv_ldouble> & color_parameter) {
	color_parameter.container() = std::array<long double,3>({ 0.684722, 0.122342, 0.218112 });
}

}
}

namespace color {
namespace _internal {

template< typename yuv_tag_name, typename cmy_tag_name >
struct convert
		<
		::color::category::yuv< yuv_tag_name >
		,::color::category::cmy< cmy_tag_name >
		> {
public:
	typedef ::color::category::yuv< yuv_tag_name > category_left_type;
	typedef ::color::category::cmy< cmy_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::yuv< category_left_type > yuv_const_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		static scalar_type const Wr = yuv_const_type::Wr();
		static scalar_type const Wb = yuv_const_type::Wb();
		static scalar_type const Wg = yuv_const_type::Wg();
		static scalar_type const Umax = yuv_const_type::Umax();
		static scalar_type const Vmax = yuv_const_type::Vmax();
		scalar_type r = scalar_type(1) - normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		scalar_type g = scalar_type(1) - normalize_type::template process<1>(container_right_trait_type::template get<1>(right));
		scalar_type b = scalar_type(1) - normalize_type::template process<2>(container_right_trait_type::template get<2>(right));
		scalar_type y = Wr * r + Wg * g + Wb * b;
		scalar_type u = ((b - y) / (1 - Wb) + scalar_type(1)) / scalar_type(2);
		scalar_type v = ((r - y) / (1 - Wr) + scalar_type(1)) / scalar_type(2);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(u));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(v));
	}
};

}
}

namespace color {
namespace _internal {

template< typename yuv_tag_name, typename gray_tag_name >
struct convert
		<
		::color::category::yuv< yuv_tag_name >
		,::color::category::gray< gray_tag_name >
		> {
public:
	typedef ::color::category::yuv< yuv_tag_name > category_left_type;
	typedef ::color::category::gray< gray_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::bound<category_left_type> bound_left_trait_type;
	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		scalar_type g = normalize_type::template process<0>(container_right_trait_type::template get<0>(right));
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(g));
		container_left_trait_type::template set<1>(left, bound_left_trait_type::template minimum<1>());
		container_left_trait_type::template set<2>(left, bound_left_trait_type::template minimum<2>());
	}
};

}
}

namespace color {
namespace _internal {
template< typename yuv_tag_name, typename rgb_tag_name >
struct convert
		<
		::color::category::yuv< yuv_tag_name >
		,::color::category::rgb< rgb_tag_name >
		> {
public:
	typedef ::color::category::yuv< yuv_tag_name > category_left_type;
	typedef ::color::category::rgb< rgb_tag_name > category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	typedef ::color::_internal::diverse< category_left_type > diverse_type;
	typedef ::color::_internal::normalize< category_right_type > normalize_type;

	typedef ::color::constant::yuv< category_left_type > yuv_const_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		enum {
			red_p = ::color::place::_internal::red<category_right_type>::position_enum
					,green_p = ::color::place::_internal::green<category_right_type>::position_enum
							   ,blue_p = ::color::place::_internal::blue<category_right_type>::position_enum
		};
		static scalar_type const Wr = yuv_const_type::Wr();
		static scalar_type const Wb = yuv_const_type::Wb();
		static scalar_type const Wg = yuv_const_type::Wg();
		static scalar_type const Umax = yuv_const_type::Umax();
		static scalar_type const Vmax = yuv_const_type::Vmax();
		scalar_type r = normalize_type::template process<red_p >(container_right_trait_type::template get<red_p >(right));
		scalar_type g = normalize_type::template process<green_p>(container_right_trait_type::template get<green_p>(right));
		scalar_type b = normalize_type::template process<blue_p >(container_right_trait_type::template get<blue_p >(right));
		scalar_type y = Wr * r + Wg * g + Wb * b;
		scalar_type u = ((b - y) / (1 - Wb) + scalar_type(1)) / scalar_type(2);
		scalar_type v = ((r - y) / (1 - Wr) + scalar_type(1)) / scalar_type(2);
		container_left_trait_type::template set<0>(left, diverse_type::template process<0>(y));
		container_left_trait_type::template set<1>(left, diverse_type::template process<1>(u));
		container_left_trait_type::template set<2>(left, diverse_type::template process<2>(v));
	}
};

}
}

namespace color {
namespace _internal {

template< typename tag_left_name, typename tag_right_name >
struct convert
		<
		::color::category::yuv< tag_left_name >
		,::color::category::yuv< tag_right_name>
		> {
public:
	typedef ::color::category::yuv< tag_left_name > category_left_type;
	typedef ::color::category::yuv< tag_right_name> category_right_type;

	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
		container_left_trait_type::template set<1>(left, reformat_type::template process<1,1>(container_right_trait_type::template get<1>(right)));
		container_left_trait_type::template set<2>(left, reformat_type::template process<2,2>(container_right_trait_type::template get<2>(right)));
	}
};
}
}

namespace color {
namespace _internal {

template< typename type_name >
struct pick_yuv {
	typedef ::color::category::yuv_uint32 category_type;
};

template<> struct pick_yuv< std::uint8_t > {
	typedef ::color::category::yuv_uint8 category_type;
};
template<> struct pick_yuv< std::uint16_t > {
	typedef ::color::category::yuv_uint16 category_type;
};
template<> struct pick_yuv< std::uint32_t > {
	typedef ::color::category::yuv_uint32 category_type;
};
template<> struct pick_yuv< std::uint64_t > {
	typedef ::color::category::yuv_uint64 category_type;
};
template<> struct pick_yuv< float > {
	typedef ::color::category::yuv_float category_type;
};
template<> struct pick_yuv< double > {
	typedef ::color::category::yuv_double category_type;
};
template<> struct pick_yuv< long double > {
	typedef ::color::category::yuv_ldouble category_type;
};
}

template< typename type_name >
using yuv = ::color::_internal::model< typename ::color::_internal::pick_yuv< type_name >::category_type >;

}

namespace color {
namespace _internal {

template< typename gray_tag_name, typename yuv_tag_name >
struct convert
		<
		::color::category::gray< gray_tag_name >
		,::color::category::yuv<yuv_tag_name>
		> {
public:
	typedef ::color::category::gray< gray_tag_name > category_left_type;
	typedef ::color::category::yuv<yuv_tag_name> category_right_type;
	typedef double scalar_type;

	typedef ::color::trait::container<category_left_type> container_left_trait_type;
	typedef ::color::trait::container<category_right_type> container_right_trait_type;

	typedef ::color::_internal::reformat< category_left_type, category_right_type, scalar_type > reformat_type;

	typedef typename container_left_trait_type::input_type container_left_input_type;
	typedef typename container_right_trait_type::input_const_type container_right_const_input_type;

	static void process
	(
		container_left_input_type left
		,container_right_const_input_type right
	) {
		container_left_trait_type::template set<0>(left, reformat_type::template process<0,0>(container_right_trait_type::template get<0>(right)));
	}
};

}
}

namespace color {
namespace _internal {

template< typename type_name >
struct pick_gray {
	typedef ::color::category::gray_uint32 category_type;
};

template<> struct pick_gray< bool > {
	typedef ::color::category::gray_bool category_type;
};
template<> struct pick_gray< std::uint8_t > {
	typedef ::color::category::gray_uint8 category_type;
};
template<> struct pick_gray< std::uint16_t > {
	typedef ::color::category::gray_uint16 category_type;
};
template<> struct pick_gray< std::uint32_t > {
	typedef ::color::category::gray_uint32 category_type;
};
template<> struct pick_gray< std::uint64_t > {
	typedef ::color::category::gray_uint64 category_type;
};
template<> struct pick_gray< float > {
	typedef ::color::category::gray_float category_type;
};
template<> struct pick_gray< double > {
	typedef ::color::category::gray_double category_type;
};
template<> struct pick_gray< long double > {
	typedef ::color::category::gray_ldouble category_type;
};
}

template< typename type_name >
using gray = ::color::_internal::model< typename ::color::_internal::pick_gray< type_name >::category_type >;

}

namespace color {
namespace compare {
template < typename category_name >
bool darker(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return ::color::gray<float>(left) < ::color::gray<float>(right);
}
}
}

namespace color {
namespace compare {
template < typename category_name >
bool lighter(::color::_internal::model< category_name > const& left, ::color::_internal::model< category_name > const& right) {
	return ::color::gray<float>(left) > ::color::gray<float>(right);
}
}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
red(::color::_internal::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
green(::color::_internal::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
blue(::color::_internal::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
gray(::color::_internal::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace get {

template< typename category_name >
inline
typename ::color::trait::component< category_name >::return_image_type
hue(::color::_internal::model< category_name > const& color_parameter) {
	return color_parameter.template get<0>();
}

}
}

namespace color {
namespace make {

template< typename category_name >
inline
void
black(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef ::color::trait::bound< category_name > bound_type;
	typedef typename model_type::index_type index_type;
	for(index_type index=0; index < model_type::size() ; ++index) {
		color_parameter.set(index, bound_type::minimum(index));
	}
}

template< typename category_name >
inline
::color::_internal::model< category_name >
black() {
	typedef ::color::_internal::model< category_name > model_type;
	typedef ::color::trait::bound< category_name > bound_type;
	typedef typename model_type::index_type index_type;
	model_type color;
	for(index_type index=0; index < model_type::size() ; ++index) {
		color.set(index, bound_type::minimum(index));
	}
	return color;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void gray50(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef ::color::trait::bound< category_name > bound_type;
	typedef typename model_type::index_type index_type;
	for(index_type index=0; index < model_type::size() ; ++index) {
		color_parameter.set(index, bound_type::minimum(index) + bound_type::range(index)/2);
	}
}

template< typename category_name >
inline
::color::_internal::model< category_name >
gray50() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::gray50(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void white(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef ::color::trait::bound< category_name > bound_type;
	typedef typename model_type::index_type index_type;
	for(index_type index=0; index < model_type::size() ; ++index) {
		color_parameter.set(index, bound_type::maximum(index));
	}
}

template< typename category_name >
inline
::color::_internal::model< category_name >
white() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::white(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void red(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
red() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::red(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void green(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
green() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::green(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void blue(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
blue() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::blue(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void cyan(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
cyan() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::cyan(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void magenta(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
magenta() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::magenta(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void yellow(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef typename model_type::index_type index_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
yellow() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::yellow(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void aqua(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef typename model_type::index_type index_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
aqua() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::aqua(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void fuchsia(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
fuchsia() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::fuchsia(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void lime(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
lime() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::lime(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void maroon(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
maroon() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::maroon(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void navy(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
navy() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::navy(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void olive(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
olive() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::olive(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void orange(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
orange() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::orange(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void purple(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
purple() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::purple(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void silver(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
silver() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::silver(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void teal(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef typename model_type::index_type index_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
teal() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::teal(dummy);
	return dummy;
}

}
}
namespace color {
namespace make {

template< typename category_name >
void violet(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef typename model_type::index_type index_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
violet() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::violet(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void aquamarine(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef typename model_type::index_type index_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
aquamarine() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::aquamarine(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void azure(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
azure() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::azure(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void beige(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
beige() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::beige(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void bisque(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
bisque() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::bisque(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void brown(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
brown() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::brown(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void chocolate(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
chocolate() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::chocolate(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void coral(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
coral() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::coral(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void crimson(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
crimson() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::crimson(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void gainsboro(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
gainsboro() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::gainsboro(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void gold(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
gold() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::gold(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void indigo(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
indigo() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::indigo(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void ivory(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
ivory() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::ivory(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void khaki(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
khaki() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::khaki(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void lavender(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
lavender() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::lavender(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void linen(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
linen() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::linen(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void moccasin(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
moccasin() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::moccasin(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void orchid(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
orchid() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::orchid(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void peru(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
peru() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::peru(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void pink(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
pink() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::pink(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void plum(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
plum() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::plum(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void salmon(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
salmon() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::salmon(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void sienna(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
sienna() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::sienna(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void snow(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
snow() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::snow(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void tan(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
tan() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::tan(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void thistle(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef typename model_type::index_type index_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
thistle() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::thistle(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void tomato(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef typename model_type::index_type index_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
tomato() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::tomato(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void turquoise(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef typename model_type::index_type index_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
turquoise() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::turquoise(dummy);
	return dummy;
}

}
}

namespace color {
namespace make {

template< typename category_name >
void wheat(::color::_internal::model< category_name > & color_parameter) {
	typedef ::color::_internal::model< category_name > model_type;
	typedef typename model_type::index_type index_type;
}

template< typename category_name >
inline
::color::_internal::model< category_name >
wheat() {
	typedef ::color::_internal::model< category_name > model_type;
	static model_type dummy;
	::color::make::wheat(dummy);
	return dummy;
}

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
red
(
	::color::_internal::model< category_name > & color_parameter,
	typename ::color::_internal::model< category_name >::component_input_const_type component_parameter
) {
}
}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
green
(
	::color::_internal::model< category_name > & color_parameter,
	typename ::color::_internal::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
blue
(
	::color::_internal::model< category_name > & color_parameter,
	typename ::color::_internal::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace set {

template< typename category_name >
inline
void
gray
(
	::color::_internal::model< category_name > & color_parameter,
	typename ::color::_internal::model< category_name >::component_input_const_type component_parameter
) {
};

}
}

namespace color {
namespace fix {
namespace _internal {

template< typename category_name >
struct overburn {
public:
	typedef category_name category_type;

	typedef ::color::trait::index<category_type> index_trait_type;
	typedef ::color::trait::bound< category_type > bound_type;
	typedef ::color::trait::component<category_type> component_trait_type;
	typedef ::color::trait::container< category_type > container_trait_type;

	typedef typename ::color::_internal::model<category_type> model_type;

	typedef typename component_trait_type::instance_type component_type;

	typedef typename index_trait_type::instance_type index_type;

	static void process(model_type &result) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			if(result.get(index) < bound_type::minimum(index)) {
				result.set(index, bound_type::minimum(index));
				continue;
			}
			if(bound_type::maximum(index) < result.get(index)) {
				result.set(index, bound_type::maximum(index));
				continue;
			}
		}
	}

	static void process(model_type & result, model_type const& right) {
		for(index_type index = 0; index < container_trait_type::size(); index ++) {
			if(right.get(index) < bound_type::minimum(index)) {
				result.set(index, bound_type::minimum(index));
				continue;
			}
			if(bound_type::maximum(index) < right.get(index)) {
				result.set(index, bound_type::maximum(index));
				continue;
			}
			result.set(index, right.get(index));
		}
	}

};
}

template< typename category_name >
void overburn
(
	::color::_internal::model<category_name> & result
) {
	::color::fix::_internal::overburn<category_name>::process(result);
}

template< typename category_name >
void overburn
(
	::color::_internal::model<category_name> & result
	,::color::_internal::model<category_name> const& right
) {
	::color::fix::_internal::overburn<category_name>::process(result, right);
}

}
}

namespace color {
namespace category {

struct generic_bool {};
template< unsigned length > struct generic_number {};
template< unsigned length > struct generic_uint8 {};
template< unsigned length > struct generic_uint16 {};
template< unsigned length > struct generic_uint32 {};
template< unsigned length > struct generic_uint64 {};
template< unsigned length > struct generic_float {};
template< unsigned length > struct generic_double {};
template< unsigned length > struct generic_ldouble {};
}

}

namespace color {
namespace constant {

template< typename category_name>
struct generic {
public:
	typedef category_name category_type;

	typedef typename ::color::trait::scalar< category_name >::instance_type scalar_type;

	typedef ::color::constant::yuv<category_type> this_type;

	static scalar_type const zero() {
		return 0;
	}
	static scalar_type const one() {
		return 1;
	}
	static scalar_type const two() {
		return 2;
	}
};

}
}

using namespace ::color::operation::arithmetic;
using namespace ::color::compare;
