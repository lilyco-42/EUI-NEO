#include "eui_neo.h"
#include <cstdio>
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
        .padding(40.0f)
        .gap(16.0f)
        .content([&] {
            ui.text("title")
                .text("EUI-NEO Demo")
                .fontSize(24.0f)
                .build();

            ui.text_input("name_input")
                .placeholder("Enter your name...")
                .text(g_name)
                .onChange([](const std::string& value) {
                    g_name = value;
                })
                .build();

            ui.button("say_hello")
                .text("Say Hello")
                .onClick([]() {
                    g_greeting = "Hello, " + g_name + "!";
                })
                .build();

            if (!g_greeting.empty()) {
                ui.text("greeting")
                    .text(g_greeting)
                    .fontSize(20.0f)
                    .build();
            }
        })
        .build();
}

} // namespace app
