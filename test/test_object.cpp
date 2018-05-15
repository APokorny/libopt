#include "example_system.h"

template<typename T, typename Name>
using p_t = opt::detail::property<T, Name>;

int main()
{
    static_assert(
            std::is_same<
                kvasir::mpl::list<
                    p_t<decltype(pos), Point>,
                    p_t<decltype(size), Size>
                    >,
                Widget::properties>::value,
                "Test that property filter captures all properties of the given type");

    static_assert(
            std::is_same<
                kvasir::mpl::list<
                    p_t<decltype(pos), Point>,
                    p_t<decltype(size), Size>,
                    p_t<decltype(text), std::string>
                    >,
                Label::properties>::value,
                "Test that derived properites are exposed too");

    static_assert(
            std::is_same<
                kvasir::mpl::list<
                    p_t<decltype(pos), Point>,
                    p_t<decltype(size), Size>,
                    p_t<decltype(text), std::string>,
                    p_t<decltype(stroke), Color>
                    >,
                ColoredLabel::properties>::value,
                "Test that derived properites are exposed too");



    return 0;
}
