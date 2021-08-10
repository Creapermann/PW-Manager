#include "UI_Start.h"
#include "../Model/ProgramInfo.h"
#include "UI_Login.h"
#include "UI_Signup.h"
#include "UI_Credits.h"

#include "../Shared.h"


void showStartWindow() {

    // Components
    ftxui::ButtonOption creditsOptions;
    creditsOptions.border = false;
    auto creditsButton = ftxui::Button(" credits ", [&] { showCreditsWindow(); }, creditsOptions);

    // Menu
    std::vector<std::wstring> entries = {
        L"Login",
        L"Create New Account",
        L"Exit"
    };

    // Selected item
    int selected = 0;
    
    // Menu
    ftxui::MenuOption option;
    option.on_enter = [&]
    {
        switch (selected)
        {
        case 0:
            showLoginWindow();
            break;
        case 1:
            showSignupWindow();
            break;
        case 2:
            screen.ExitLoopClosure();
            _Exit(0);
            break;
        }
    };

    option.style_focused = ftxui::bgcolor(ftxui::Color::Blue);

    auto menu = ftxui::Menu(&entries, &selected, option);


    // Container
    ftxui::Component container = ftxui::Container::Vertical(
    {
        menu,
        creditsButton
    });

    auto renderer = ftxui::Renderer(container, [&] {
        return ftxui::vbox
        (
            ftxui::hbox
            (
                // Title
                ftxui::text(std::wstring(pInfo::name.begin(), pInfo::name.end())) |
                ftxui::flex | ftxui::bold | ftxui::color(ftxui::Color::Green) | ftxui::center,

                // Version
                ftxui::text(L"v_" + std::wstring(pInfo::version.begin(), pInfo::version.end()))

            ) | ftxui::border,

            // Separator
            ftxui::separator() | ftxui::color(ftxui::Color::GrayDark),

            // Menu
            ftxui::vbox
            (
                menu->Render() | ftxui::border
            ) | ftxui::size(ftxui::HEIGHT, ftxui::GREATER_THAN, 6),

            ftxui::vbox
            (
                creditsButton->Render() | ftxui::size(ftxui::WIDTH, ftxui::LESS_THAN, 10) | ftxui::size(ftxui::HEIGHT, ftxui::LESS_THAN, 4)
                                        | ftxui::align_right | ftxui::color(ftxui::Color::Gold3)
            )
        );
    });

    screen.Loop(renderer);
}
