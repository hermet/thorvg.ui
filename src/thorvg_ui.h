#ifndef _THORVG_UI_H_
#define _THORVG_UI_H_

#include <thorvg-1/thorvg.h>

#define TVG_UI_VERSION_MAJOR 0  // for compile-time checks
#define TVG_UI_VERSION_MINOR 0  // for compile-time checks
#define TVG_UI_VERSION_MICRO 1  // for compile-time checks

namespace tvg
{

struct TVG_API App
{
    struct Delegate
    {
        virtual ~Delegate() = default;

        // prepare the application content
        virtual bool init(tvg::Canvas* canvas, uint32_t w, uint32_t h) = 0;

        // update the content per frame
        virtual bool update(tvg::Canvas* canvas) { return false; }
    };

    static Result run(Delegate& delegate, uint32_t w, uint32_t h, uint32_t threads = 0)
    {
        Initializer::init(threads);

        // TODO:

        Initializer::term();

        return Result::Success;
    }
};

} // namespace

#endif // _THORVG_UI_H_
