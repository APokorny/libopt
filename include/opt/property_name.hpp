#ifndef OBJECT_PROPERTY_TREE_PROPERTY_NAME_HH_INCLUDED
#define OBJECT_PROPERTY_TREE_PROPERTY_NAME_HH_INCLUDED

#include <opt/assignment.hpp>

namespace opt {

template <char... String>
struct property_name {
    template<typename Value>
    constexpr assignment<property_name<String...>, std::decay_t<Value>> operator = (Value && v) noexcept {
        return {std::forward<Value>(v)};
    }
};

namespace literals {
template <typename CharT, CharT... String>
constexpr property_name<String...> operator""_p() noexcept {
    return {};
}
}

using opt::literals::operator""_p;

}

#endif
