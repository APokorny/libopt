#ifndef OBJECT_PROPERTY_TREE_ITEM_HH_INCLUDED
#define OBJECT_PROPERTY_TREE_ITEM_HH_INCLUDED

namespace opt {

template <typename ObjectType, typename... Elements>
struct node;
template<typename ItemType, typename...Elements>
constexpr auto item(Elements&&... args) noexcept {
    return node<ItemType, Elements...>{std::forward<Elements>(args)...};
}

}

#endif
