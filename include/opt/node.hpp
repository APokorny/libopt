#ifndef OBJECT_PROPERTY_TREE_NODE_HH_INCLUDED
#define OBJECT_PROPERTY_TREE_NODE_HH_INCLUDED

#include <opt/detail/node.hpp>

namespace opt {
template <typename ObjectType, typename... Elements>
struct node {
///    using properties_tuple  = kvasir::mpl::call<kvasir::mpl::cfe<std::tuple>, kvasir::mpl::join<properties_of<ObjectType>, detail::new_initialization_of<Elements>>;
  ///  properties_tuple properties; 
    /*template<typename...Initors>
    node(Initors &&... initthings) : properties{} noexcept {
        assign(properties, std::forward<Initors>(initthings)...);
    }*/
};

}

#endif
