#ifndef OBJECT_PROPERTY_TREE_DETAIL_OBJECT_HH_INCLUDED
#define OBJECT_PROPERTY_TREE_DETAIL_OBJECT_HH_INCLUDED

namespace opt {
namespace detail {

template<typename What, typename Value>
struct initialization {
    Value value;
};

template<typename Name, typename Signature>
struct method {
    template<typename Value>
    constexpr auto operator = (Value && v) noexcept {
        return initialization<method<Name,Signature>, std::decay_t<Value>>{std::forward<Value>(v)};
    }
};

template<typename Name, typename Type>
struct property {
    template<typename Value>
    constexpr auto operator = (Value && v) noexcept {
        return initialization<property<Name,Type>, std::decay_t<Value>>{std::forward<Value>(v)};
    }
};

template<typename Type>
struct derived {};

namespace km = kvasir::mpl;

struct is_derived {
    template <typename T>
    struct f : km::false_ {};
    template <typename T>
    struct f<derived<T>> : km::true_ {};
};

struct is_property {
    template <typename T>
    struct f : km::false_ {};
    template <typename Name, typename T>
    struct f<property<Name, T>> : km::true_ {};
};

struct is_method {
    template <typename T>
    struct f : km::false_ {};
    template <typename Name, typename Signature>
    struct f<method<Name, Signature>> : km::true_ {};
};

struct expand_derived_properties {
    template <typename T>
    struct f_impl { using type = T; };
    template <typename T>
    struct f_impl<derived<T>> { using type = typename T::properties; };
    template <typename T>
    using f = typename f_impl<T>::type;

};

struct expand_derived_methods {
    template <typename T>
    struct f_impl { using type = T; };
    template <typename T>
    struct f_impl<derived<T>> { using type = typename T::methods; };
    template <typename T>
    using f = typename f_impl<T>::type;
};

}
}

#endif
