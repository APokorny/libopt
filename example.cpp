#include "opt/opt.hpp"
#include <string>

template <typename... Ts>
struct impl
{};

struct Point
{
    int x, y;

    constexpr Point translate(Point const& m) const { return {x + m.x, y + m.y}; }
};

struct Size
{
    int width, height;
    constexpr Size reduce(Size const& m) const { return {width - m.width, height - m.height}; }
};

struct Color
{ int rgba; };

using namespace opt::literals;

auto size = "size"_p;

struct Widget : decltype(opt::basic(opt::property<Point>("pos"_p), opt::property<Size>(size)))
{};

struct Label : decltype(opt::derived_from<Widget>(opt::property<std::string>("text"_p)))
{};

struct Container : decltype(opt::derived_from<Widget>())
{};

struct Rectangle: decltype(opt::derived_from<Widget>(opt::property<Color>("color"_p)))
{};

struct ClickReaction : decltype(opt::basic(
        opt::method<void(int button_state, Point const& pos)>("on_press"_p),
        opt::method<void(int button_state, Point const& pos)>("on_release"_p),
        opt::method<void(int button_state, Point const& pos)>("on_move"_p)))
{};

int main() {
    opt::detail::properties_of<Rectangle> foo;
#if 0
    auto widget_tree = opt::item<Container>(
            "root_widget"_id,
            "size"_p = Size{640, 480},
             opt::item<Container>(
                 "pos"_p = [](auto& tree) -> Point {
                     return tree["root_widget"_id]["pos"_p].translate(Point{5, 5});
                 },
                 "size"_p = [](auto& tree) -> Size {
                     return tree["root_widget"_id]["size"_p].reduce(Size{5, 5});
                 },
                 opt::item<Rectangle>(
                     "background"_id,
                     "color"_p = 0xFF000000FFUL,
                     "pos"_p = Point{0,0},
                     size = Size{300,90},
                     opt::method<void()>("my_call"_p) = [counter = int{0}] (auto& widget_tree) mutable {++counter;},
                     opt::item<Label>(
                         "thing"_id,
                         "text"_p = "click it",
                         "size"_p = Size{200,50},
                         "pos"_p = Point{5,5}
                         ),
                     opt::item<ClickReaction>(
                         "on_release"_p =[](auto& widget_tree, int button_state, Point const& pos) {
                             widget_tree["thing"_id]["text"_p] = "Clicked";
                             widget_tree["background"_id]["my_call"_p](widget_tree); // todo should we wrap calls
                         }
                         )
                     )
                     ));

    opt::construct(widget_tree);
#endif
}
