#ifndef OBJECT_PROPERTY_TREE_OBJECT_HH_INCLUDED
#define OBJECT_PROPERTY_TREE_OBJECT_HH_INCLUDED

#include <opt/detail/object.hpp>

namespace opt {
namespace km = kvasir::mpl;

template <typename ObjectType, typename... Elements>
struct node;
template<typename ItemType, typename...Elements>
constexpr node<ItemType, Elements...> item(Elements&&... args) noexcept;
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

    template<typename...Inits>
    constexpr auto
    operator()(Inits &&... is)  noexcept -> decltype(item<object<Elements...>>(std::forward<Inits>(is)...))
    { return item<object<Elements...>>(std::forward<Inits>(is)...);}
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
