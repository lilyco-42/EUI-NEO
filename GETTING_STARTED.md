# Quick Start: Create an EUI-NEO Project

## 1. Create project directory

```sh
mkdir my-eui-app && cd my-eui-app
```

## 2. Create `xmake.lua`

```lua
set_languages("cxx17")
add_requires("eui-neo")

target("myapp")
    set_kind("binary")
    add_files("app.cpp")
    add_rules("eui.app")
    add_includedirs(".")
```

## 3. Create `app.cpp`

```cpp
#include "eui_neo.h"

namespace app {

const DslAppConfig& dslAppConfig() {
    static const DslAppConfig config = DslAppConfig{}
        .title("My App")
        .windowSize(960, 640);
    return config;
}

void compose(eui::Ui& ui, const eui::Screen& screen) {
    ui.column("root")
        .size(screen.width, screen.height)
        .padding(32.0f)
        .content([&] {
            ui.text("hello")
                .text("Hello EUI-NEO!")
                .fontSize(28.0f)
                .build();
        })
        .build();
}

} // namespace app
```

## 4. Build and run

```sh
xmake f -m release -y
xmake
xmake run myapp
```

## Options

```sh
# SDL2 backend
xmake f --window_backend=sdl2

# Vulkan renderer
xmake f --render_backend=vulkan

# Shared library
xmake f --shared=y
```

## Minimal CMake alternative

```cmake
cmake_minimum_required(VERSION 3.14)
project(MyApp LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(external/EUI-NEO)

add_executable(myapp
    external/EUI-NEO/core/app/glfw_app_main.cpp
    app.cpp
)
eui_neo_configure_app(myapp)
```
