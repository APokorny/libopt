#ifndef OBJECT_PROPERTY_TREE_OBJECT_HH_INCLUDED
#define OBJECT_PROPERTY_TREE_OBJECT_HH_INCLUDED

#include <opt/detail/object.hpp>

namespace opt {
namespace km = kvasir::mpl;

template <typename ...Elements>
struct object;
template <typename ...Elements>
struct object
{
    using properties = km::call<
       km::flatten<
           km::cfe<opt::object>,
           km::filter<
               detail::is_property, 
               km::listify
               >
           >, Elements...>;
    using methods = km::call<km::flatten<km::cfe<opt::object>, km::filter<detail::is_method, km::listify>>, Elements...>;
};

template <typename Signature, typename Name>
auto method(Name const &) -> opt::detail::method<Name, Signature> {
    return {};
}

template <typename Type, typename Name>
auto property(Name const &) -> opt::detail::property<Name, Type> {
    return {};
}

template <typename Type, typename ... Elements>
auto derived_from(Elements...) -> opt::object<Type, Elements...> {
    return {};
}

template <typename... Elements>
auto basic(Elements &&...) -> opt::object<Elements...> {}
}

#endif
