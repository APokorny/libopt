#include <opt/opt.hpp>
#include <string>

using namespace opt::literals;
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

struct Color {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};

auto size = "size"_p;
auto pos = "pos"_p;
auto text = "text"_p;
auto stroke = "stroke"_p;

using Widget = decltype(opt::basic(        //
            opt::property<Point>(pos),  //
            opt::property<Size>(size)   //
            ));

using Label = decltype(opt::derived_from<Widget>( //
            opt::property<std::string>(text)  ///
            ));

using ColoredLabel = decltype(opt::derived_from<Label>( //
            opt::property<Color>(stroke)  ///
            ));

