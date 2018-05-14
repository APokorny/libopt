#ifndef OBJECT_PROPERTY_TREE_ITEM_NAME_HH_INCLUDED
#define OBJECT_PROPERTY_TREE_ITEM_NAME_HH_INCLUDED

namespace opt {

struct no_item_name {};

template <char... String>
struct item_name {};

namespace literals {
template <typename CharT, CharT... String>
constexpr item_name<String...> operator""_id() noexcept {
    return {};
}
}
}

#endif
