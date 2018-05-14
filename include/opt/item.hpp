#ifndef OBJECT_PROPERTY_TREE_ITEM_HH_INCLUDED
#define OBJECT_PROPERTY_TREE_ITEM_HH_INCLUDED

namespace opt {

template<typename ItemType, typename...Elements>
auto item(Elements&&... args) noexcept {
    return node<ItemType, Elements...>{std::forward<Elements>(args)...};
}

}

#endif
