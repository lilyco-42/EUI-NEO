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
    add_packages("eui-neo")
```

## 3. Create `app.cpp`

```cpp
#include "eui_neo.h"
#include <string>

static std::string g_name;
static std::string g_greeting;

namespace app {

const DslAppConfig& dslAppConfig() {
    static const DslAppConfig config = DslAppConfig{}
        .title("Hello Demo")
        .windowSize(480, 320);
    return config;
}

void compose(eui::Ui& ui, const eui::Screen& screen) {
    ui.column("root")
        .size(screen.width, screen.height)
        .content([&] {
            ui.text("title")
                .x(40.0f)
                .y(32.0f)
                .text("EUI-NEO Demo")
                .fontSize(24.0f)
                .build();

            components::input(ui, "name_input")
                .x(40.0f)
                .y(88.0f)
                .size(400.0f, 40.0f)
                .placeholder("Enter your name...")
                .value(g_name)
                .onChange([](const std::string& value) {
                    g_name = value;
                })
                .build();

            components::button(ui, "say_hello")
                .x(40.0f)
                .y(148.0f)
                .size(160.0f, 44.0f)
                .text("Say Hello")
                .onClick([]() {
                    g_greeting = "Hello, " + g_name + "!";
                })
                .build();

            if (!g_greeting.empty()) {
                ui.text("greeting")
                    .x(40.0f)
                    .y(216.0f)
                    .text(g_greeting)
                    .fontSize(20.0f)
                    .build();
            }
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

## Included demo

Run the included `hello_demo` example:

```sh
xmake run hello_demo
```

Type a name, click "Say Hello", and see the greeting appear.
