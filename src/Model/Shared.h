#include "FtxuiIncludes.h"


class Shared
{
private:
	Shared() = default;

	Shared(const Shared&) = delete;
	Shared& operator=(const Shared&) = delete;
	Shared(Shared&&) = delete;
	Shared& operator=(const Shared&&) = delete;
public:
	static Shared& GetInstance() {
		static Shared* shared = new Shared();
		return *shared;
	}
	//run and see
	ftxui::ScreenInteractive screen = ftxui::ScreenInteractive::Fullscreen();  //errorrss
};